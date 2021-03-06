/*
	Name: kinematics.h
	Description: Declares the functions needed to implement the machine kinematics and homing motion.
		This defines an opac interface that allows to adapt �CNC to different architectures/mechanics of
		different machines.

	Copyright: Copyright (c) Jo�o Martins
	Author: Jo�o Martins
	Date: 26/09/2019

	�CNC is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version. Please see <http://www.gnu.org/licenses/>

	�CNC is distributed WITHOUT ANY WARRANTY;
	Also without the implied warranty of	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See the	GNU General Public License for more details.
*/
#ifndef KINEMATICS_H
#define KINEMATICS_H

#include <stdint.h>

/*
	Converts from machine absolute coordinates to step position.
	This is done after computing position relative to the active coordinate system
*/
void kinematics_apply_inverse(float* axis, uint32_t* steps);


/*
	Converts from step position to machine absolute coordinates
	This is done after computing position relative to the active coordinate system
*/
void kinematics_apply_forward(uint32_t* steps, float* axis);

/*
	Executes the homing motion for the machine
	The homing motion for each axis is defined in the motion control
	In the kinematics home function the axis order of the homing motion and other custom motions can be defined
*/
uint8_t kinematics_home();

/*
	In dual drive machines this translates which drive is locked when a particular limit switch is triggered during homing motion
*/
void kinematics_lock_step(uint8_t limits_mask);

/*
	Aplies a transformation to the position sent to planner.
	This is aplied only on normal and jog moves. Homing motions go directly to planner.
*/
void kinematics_apply_transform(float* axis);

/*
	Aplies a reverse transformation to the position returned from the planner.
	This is aplied only on normal and jog moves. Homing motions go directly to planner.
*/
void kinematics_apply_reverse_transform(float* axis);

#endif
