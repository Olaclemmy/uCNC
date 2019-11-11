/*
	Name: 
	Copyright: 
	Author: 
	Date: 23/09/19 23:14
	Description: 
*/

#ifndef PLANNER_H
#define PLANNER_H

#include <stdint.h>
#include <stdbool.h>
#include "config.h"
#include "machinedefs.h"

#define PLANNER_BUFFER_SIZE 5

typedef struct
{
	uint8_t dirbits;
	float pos[AXIS_COUNT];
	float dir_vect[AXIS_COUNT];

	float distance;
	float angle_factor;

	float entry_speed_sqr;
	float entry_max_speed_sqr;

	float max_speed;
	float target_speed;
	float acceleration;

	bool optimal;
} PLANNER_BLOCK;

void planner_init();
bool planner_buffer_full();
bool planner_buffer_empty();
PLANNER_BLOCK* planner_get_block();
float planner_get_block_exit_speed_sqr();
float planner_get_block_top_speed(float exit_speed_sqr);
void planner_discard_block();
void planner_add_line(float* axis, float feed);
void planner_add_analog_output(uint8_t output, uint8_t value);
void planner_add_digital_output(uint8_t output, uint8_t value);

//REMOVE TO THE MOTION CONTROLLER COMPILATION UNIT (TO BE CREATED)
//void planner_add_arc(float* axis, float* center, uint8_t clockwise, uint8_t plane, float feed);

#endif
