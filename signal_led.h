/*
 * signal_led.h
 *
 * Created: 31/03/2023 09:15:04 p. m.
 *  Author: andre
 */ 


#ifndef SIGNAL_LED_H_
#define SIGNAL_LED_H_

extern "C" {
	#include "config_ports.h"
	#include <avr/io.h>

	}

void putSignalLed(uint8_t step);

#endif /* SIGNAL_LED_H_ */