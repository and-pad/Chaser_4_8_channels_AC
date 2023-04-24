/*
 * handle_chaser.h
 *
 * Created: 31/03/2023 01:03:50 p. m.
 *  Author: Andres Padilla Sandoval
 */ 


#ifndef HANDLE_CHASER_H_
#define HANDLE_CHASER_H_

extern "C" {
#include <avr/io.h>
#include "display.h"
#include "signal_led.h"
#include "velocity.h"
#include "timers.h"
#include "eeprom.h"
}

class HandleChaser
{
	public:
	HandleChaser();
	void DisplayOut(uint8_t KindOfDisplay, uint8_t Digit);
	void SignalLedOut(uint8_t step);	
	void PowerSignalOut(uint8_t step);
	void SetVelocity(uint8_t velocity);	
	void SaveEeprom(uint8_t addres, uint8_t data);
	uint8_t ReadEeprom(uint8_t addres);
	
	private:
	void putSignalPower(uint8_t step);
	uint8_t invert_bits(uint8_t byte);
	
	};


extern HandleChaser Handler;

#endif /* HANDLE_CHASER_H_ */