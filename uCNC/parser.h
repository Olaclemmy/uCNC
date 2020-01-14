/*
	Name: parser.h
	Description: Parses Grbl system commands and RS274NGC (GCode) commands
        The RS274NGC parser tries to follow the standard document version 3 as close as possible.
        The parsing is done in 3 steps:
            - Tockenization; Converts the command string to a structure with GCode parameters
            - Validation; Validates the command by checking all the parameters (part 3.5 - 3.7 of the document)
            - Execution; Executes the command by the orther set in part 3.8 of the document.
			
	Copyright: Copyright (c) João Martins 
	Author: João Martins
	Date: 07/12/2019

	uCNC is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version. Please see <http://www.gnu.org/licenses/>

	uCNC is distributed WITHOUT ANY WARRANTY;
	Also without the implied warranty of	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See the	GNU General Public License for more details.
*/

#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "config.h"
#include "machinedefs.h"

void parser_init();
//void parser_reset();
uint8_t parser_gcode_command();
uint8_t parser_grbl_command();
void parser_get_modes(uint8_t* modalgroups, uint16_t* feed, uint16_t* spindle);
float* parser_get_coordsys(uint8_t system_num);
void parser_get_wco(float* axis);
void parser_sync_probe();
uint8_t parser_get_probe_result();
void parser_parameters_load();
void parser_parameters_reset();
void parser_parameters_save();

#endif
