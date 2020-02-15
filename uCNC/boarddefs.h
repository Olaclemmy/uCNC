/*
	Name: boarddefs.h
	Description: Defines the available board types.

	Copyright: Copyright (c) Jo�o Martins
	Author: Jo�o Martins
	Date: 07/02/2020

	�CNC is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version. Please see <http://www.gnu.org/licenses/>

	�CNC is distributed WITHOUT ANY WARRANTY;
	Also without the implied warranty of	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See the	GNU General Public License for more details.
*/

#ifndef BOARDDEFS_H
#define BOARDDEFS_H

#include "boards.h"

/*
	MCU port map
*/
#if(BOARD != 0)
#else
#error Invalid board configuration
#endif

#if(BOARD == BOARD_GRBL)
#include "mcus\avr\boardmap_grbl.h"
#endif

#if(BOARD == BOARD_RAMBO14)
#include "mcus\avr\boardmap_rambo14.h"
#endif

#if(BOARD == BOARD_RAMPS14)
#include "mcus\avr\boardmap_ramps14.h"
#endif

#if(BOARD == BOARD_VIRTUAL)

#endif

#ifndef BOARD
#error Undefined board
#endif

#endif