/*
 * signal_led.cpp
 *
 * Created: 31/03/2023 09:14:37 p. m.
 *  Author: Andres Padilla Sandoval
 */ 
extern "C"{
#include "signal_led.h"
}

void putSignalLed(uint8_t step)
{
	PORTLEDSignals = step;
}