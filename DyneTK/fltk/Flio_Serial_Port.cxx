//
// "$Id$"
//
// Flio_Serial_Port implementation for the FLIO extension to FLTK.
//
// Copyright 2002-2007 by Matthias Melcher.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
//
// Please report all bugs and problems to "flio@matthiasm.com".
//


#ifdef _MSC_VER
#pragma warning(disable : 4996)
#endif

//#define DEBUG_SEND
//#define DEBUG_RECV

#include "Flio_Serial_Port.h"
#include "globals.h"

#include <FL/Fl.H>
#include <FL/fl_draw.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef WIN32
# include <process.h>
#else
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <termios.h>
# include <fcntl.h>
# include <ctype.h>
# include <errno.h>
#endif


Flio_Serial_Port::Flio_Serial_Port(int X, int Y, int W, int H, const char *L)
: Flio_Stream(X, Y, W, H, L),
  ring_(0L),
  NRing_(0),
  ringHead_(0),
  ringTail_(0),
  portname_(0L),
  rxActive_(0),
  pRxActive_(0),
  txActive_(0),
  pTxActive_(0)
#ifdef WIN32
, port_(INVALID_HANDLE_VALUE),
  thread_(0)
#else
, port_(-1)
#endif
{
  NRing_ = 2048;
  ring_ = (unsigned char *)malloc(NRing_);
}


Flio_Serial_Port::Flio_Serial_Port(Flio_Stream *super)
: Flio_Stream(super),
  ring_(0L),
  NRing_(0),
  ringHead_(0),
  ringTail_(0),
  portname_(0L),
  rxActive_(0),
  pRxActive_(0),
  txActive_(0),
  pTxActive_(0)
#ifdef WIN32
, port_(INVALID_HANDLE_VALUE),
  thread_(0)
#else
, port_(-1)
#endif
{
  NRing_ = 2048;
  ring_ = (unsigned char *)malloc(NRing_);
}


Flio_Serial_Port::~Flio_Serial_Port()
{
  close();
  if (ring_)
    ::free(ring_);
  if (portname_)
    ::free(portname_);
}


int Flio_Serial_Port::open(const char *portname, int bps)
{
  close();
  if (portname_) {
    free(portname_);
    portname_ = 0L;
  }
  ringHead_ = ringTail_ = 0;

  if (!portname)
    return -1;

  portname_ = strdup(portname);
  
#ifdef WIN32
  port_ = CreateFile(portname, GENERIC_READ|GENERIC_WRITE, 
    0, 0L, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, 0L ); 
  if (port_ == INVALID_HANDLE_VALUE) {
    return -1;
  }
  //SetupComm(port_, 2048, 2048);

  DCB arg; arg.DCBlength = sizeof(DCB);
  GetCommState(port_, &arg);
  int speed;
  switch (bps) {
    case 9600: speed = CBR_9600; break;
    case 19200: speed = CBR_19200; break;
    case 38400: speed = CBR_38400; break;
    default: return -1;
  }
  arg.BaudRate = speed;
  arg.fBinary = TRUE;
  arg.fParity = FALSE;
  arg.fOutxCtsFlow = FALSE;
  arg.fOutxDsrFlow = TRUE;
  arg.fDtrControl = DTR_CONTROL_HANDSHAKE;
  arg.fDsrSensitivity = TRUE;
  arg.fRtsControl = RTS_CONTROL_DISABLE;
  arg.fAbortOnError = FALSE;
  arg.ByteSize = 8;
  arg.Parity = NOPARITY;
  arg.StopBits = ONESTOPBIT;
  SetCommState( port_, &arg );

  static COMMTIMEOUTS timeout = { MAXDWORD, 0, 0, 0, 0 };
  SetCommTimeouts( port_, &timeout );
  PurgeComm( port_, PURGE_TXCLEAR|PURGE_RXCLEAR );
  ClearCommBreak(port_);
  SetCommMask(port_, EV_RXCHAR);

  //EscapeCommFunction(port_, CLRRTS);
  //EscapeCommFunction(port_, SETDTR);

  memset(&overlapped_, 0, sizeof(overlapped_));
  event_ = CreateEvent(0, true, 0, 0);
  overlapped_.hEvent = event_;

  if (!thread_)
    _beginthread(reader_thread_, 0, this);
#else
  port_ = ::open(portname, O_RDWR|O_NOCTTY|O_NONBLOCK|O_NDELAY);
  if (port_==-1)
    return -1;
  fcntl(port_, F_SETFL, FNDELAY);
  struct termios tio = { 0 };
  tcgetattr(port_, &tio);
  // no modem support at all please
  //cfmakeraw(&tio);
  // now set the remaining flags to allow handshake via DTR/DSR
  tio.c_iflag = (IGNPAR | IGNBRK); // don't do any of the modem stuff
  tio.c_oflag = 0; // nothing to change here
  tio.c_cflag = (CS8 | CREAD); // tfr is 8n1, not setting CLOCAL should enable DTR/DSR handshake
  tio.c_lflag = 0; // and no terminal stuff either
  // FIXME: which flow control is actually used?
  //tio.c_cflag = B38400 | CRTSCTS | CS8 | CLOCAL | CREAD;
  //tio.c_cflag = B38400 | CS8 | CLOCAL | CREAD;
  //tio.c_iflag = IGNPAR | IGNBRK;
  //tio.c_oflag = 0;
  //tio.c_lflag = 0;
  cfsetspeed(&tio, bps);
  tio.c_cc[VMIN] = 1;
  tio.c_cc[VTIME] = 0;
  tcflush(port_, TCIFLUSH);
  int ret = tcsetattr(port_, TCSANOW, &tio);
  if (ret==-1)
    return -1;
  Fl::add_fd(port_, FL_READ, reader_cb, this);
#endif
  
  rxActive_ = txActive_ = 0;
  pRxActive_ = pTxActive_ = 0;
	redraw();
  Fl::add_timeout(0.2, lights_cb, this);

#if (defined DEBUG_SEND) || (defined DEBUG_RCV)
  printf("DEBUG: serial port \"%s\" at %dbps openend\n", portname, bps);
#endif

  return 0;
}


/**
 * Manage blinking status lights.
 *
 * This function works by checking the state of the line very 1/10th
 * of a second. If data was sent or received, the corresponding
 * LED will be set to red for the next 1/10th of a second. If nothing
 * was sent, it will be set to green.
 *
 * If the state has not changed, nothing is drawn!
 */
void Flio_Serial_Port::lights_cb(void *u) 
{
  Flio_Serial_Port *This = (Flio_Serial_Port*)u;
  if ((This->rxActive_!=This->pRxActive_) || (This->txActive_!=This->pTxActive_)) {
    This->pTxActive_ = This->txActive_;
    This->pRxActive_ = This->rxActive_;
    This->redraw();
  }
  This->txActive_ = This->rxActive_ = 0;
  Fl::repeat_timeout(0.1, lights_cb, This);
}


int Flio_Serial_Port::write(const unsigned char *data, int n)
{
#ifdef DEBUG_SEND
  printf("DEBUG: ---> writing %d bytes to serial port\n", n);
  DebugDumpBuffer((uint8_t*)data, n);
#endif

  txActive_ = 1;
#ifdef WIN32
  DWORD result;
  BOOL ret = WriteFile( port_, data, n, &result, &overlapped_ );
  if (ret) {
    return result;
  } else {
    return -1;
  }
#else
  int ret = ::write(port_, data, n);
  return ret;
#endif
}


int Flio_Serial_Port::available()
{
  int n = ringHead_ - ringTail_;
  if (n<0)
    n += NRing_;
  return n;
}


int Flio_Serial_Port::read(unsigned char *dest, int n)
{
  int nMax = available();
  if (nMax==0)
    return 0;
  if (n>nMax) 
    n = nMax;
  int n1 = available_to_end();
  if (n1>=n) {
    memcpy(dest, ring_+ringTail_, n);
    ringTail_ += n;
  } else {
    memcpy(dest, ring_+ringTail_, n1);
    memcpy(dest+n1, ring_, n-n1);
    ringTail_ = n-n1;
  }
#ifdef DEBUG_RECV
  printf("DEBUG: <<-- read %d bytes from serial port buffer\n", n);
  DebugDumpBuffer(dest, n);
#endif
  return n;
}


int Flio_Serial_Port::available_to_end()
{
  if (ringHead_>=ringTail_) {
    return ringHead_ - ringTail_;
  } else {
    return NRing_ - ringTail_;
  }
}


void Flio_Serial_Port::close()
{
  Fl::remove_timeout(lights_cb, this);
#ifdef WIN32
  if (port_ != INVALID_HANDLE_VALUE) {
    CloseHandle(port_);
    port_ = INVALID_HANDLE_VALUE;
  }
#else
  if (port_ != -1) {
    Fl::remove_fd(port_, FL_READ);
    Fl::remove_fd(port_);
    ::close(port_);
    port_ = -1;
  }
#endif
  redraw();
}


int Flio_Serial_Port::free_to_end() 
{
  if (ringHead_>=ringTail_) {
    return NRing_ - ringHead_;
  } else {
    return ringTail_ - ringHead_ - 1;
  }
}

#ifdef WIN32

void Flio_Serial_Port::reader_thread() 
{
  for(;;) {
    DWORD nw;
    DWORD mask;
    WaitCommEvent(port_, &mask, &overlapped_);
    WaitForSingleObject(event_, INFINITE);
    // FIXME: what happens when we close the COM port?
    // Will we ever leave the thread?
    DWORD nc = 0, na;
    for (;;) {
      int n = free_to_end();
      ReadFile(port_, ring_+ringHead_, n, &na, &overlapped_);
      if (na==0) 
        break;
      ringHead_ += na;
      if (ringHead_ == NRing_)
        ringHead_ = 0;
      nc += na;
    }
    ResetEvent(event_);
    if (nc) {
      rxActive_ = 1;
      Fl::awake(on_read_cb, this);
    }
  }
}


void Flio_Serial_Port::reader_thread_(void *u) 
{
  Flio_Serial_Port *This = (Flio_Serial_Port*)u;
  This->reader_thread();
}

#else

void Flio_Serial_Port::reader_cb(int, void *u)
{
  Flio_Serial_Port *This = (Flio_Serial_Port*)u;
  This->reader();
}

void Flio_Serial_Port::reader()
{
  int nc = 0;
  for (;;) {
    int n = free_to_end(); 
    int na = ::read(port_, ring_+ringHead_, n);
    if (na<=0)
      break;
#ifdef DEBUG_RECV
    else {
      printf("DEBUG: <--- received %d bytes from serial port\n", na);
      DebugDumpBuffer(ring_+ringHead_, na);
    }
#endif
    ringHead_ += na;
    if (ringHead_ == NRing_)
      ringHead_ = 0;
    nc += na;
  }
  if (nc) {
    rxActive_ = 1;
    on_read_cb(this);
  }
}

#endif

void Flio_Serial_Port::draw()
{
  Fl_Box::draw();
  int r = (h()+2)/4, cx = x()+w()/2, cy = y()+h()/2;
  Fl_Color rxd, txd;
  if (is_open()) {
    if (pRxActive_) rxd = FL_RED; else rxd = FL_GREEN;
    if (pTxActive_) txd = FL_RED; else txd = FL_GREEN;
  } else {
    rxd = txd = color();
  }
  fl_draw_symbol("@circle", cx-2*r-2, cy-r, 2*r+1, 2*r+1, rxd);
  fl_draw_symbol("@circle", cx+0*r+2, cy-r, 2*r+1, 2*r+1, txd);
}


int Flio_Serial_Port::on_read() {
	if (super_)
		return super_->on_read();
	else
		return 0;
}


int Flio_Serial_Port::on_read_() {
	return on_read();
}


void Flio_Serial_Port::on_read_cb(void *u) {
  Flio_Serial_Port *This = (Flio_Serial_Port*)u;
  if (!This->on_read_() && This->callback()) {
    This->do_callback();
  }
}


int Flio_Serial_Port::is_open() 
{
#ifdef WIN32
  return (port_!=INVALID_HANDLE_VALUE);
#else
  return (port_!=-1);
#endif
}


void Flio_Serial_Port::redraw() 
{
	if (super_)
		super_->redraw();
	else 
		Flio_Stream::redraw();
}


//
// End of "$Id$".
//
