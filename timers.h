#ifndef TIMERS_H
#define TIMERS_H
extern "C"{
	
	#include "config_ports.h"
	#include "handle_chaser.h"
	#include "velocity.h"	
	#include "initsys.h"
	#include <avr/interrupt.h>
	#include <avr/io.h>
	#include <stdbool.h>
}

#define PROGRAM 1
#define VELOCITY 2
#define INIT 3


extern int time_counter;
extern int cambio;

extern uint8_t program_counter;
extern uint8_t velocity_counter;
extern uint8_t velocity_value;

extern uint8_t on_off_velocity;
extern uint8_t blink_time;

extern uint8_t displaying_velocity;


extern int has_changed;



#endif /* TIMERS_H_ */