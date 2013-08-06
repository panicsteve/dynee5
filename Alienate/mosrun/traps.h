/*
 mosrun - the MacOS MPW runtime emulator
 Copyright (C) 2013  Matthias Melcher
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
 The author can be contacted at mosrun AT matthiasm DOT com.
 The latest source code can be found at http://code.google.com/p/dynee5/
 */

#ifndef mosrun_traps_h
#define mosrun_traps_h

#include "main.h"

extern unsigned short gCurrentTrap;
extern unsigned int trapDispatchTrap;
extern unsigned int trapExitApp;

void trapGoNative(unsigned short instr);
void trapBreakpoint(unsigned short instr);
void trapDispatch(unsigned short);
mosPtr createGlue(mosTrap trap, unsigned short index = 0);
void mosSetupTrapTable();


#endif