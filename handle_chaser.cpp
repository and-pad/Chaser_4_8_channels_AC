/*
 * handle_chaser.cpp
 *
 * Created: 31/03/2023 01:18:09 p. m.
 *  Author: andre
 */ 

extern "C" {
#include "handle_chaser.h"

}

HandleChaser Handler;


HandleChaser::HandleChaser() {}


void HandleChaser::DisplayOut(uint8_t KindOfDisplay, uint8_t Digit){
	
	switch(KindOfDisplay)
	{
		case PROGRAM:
			PutDigit(Digit);
			break;
		case VELOCITY:
			PutFlashDigit(Digit);
			break;
		case INIT:
			PutDigit(Digit);
			break;
	}	 
	 
}


void HandleChaser::SetVelocity(uint8_t velocity)
{
		switch(velocity)
		{
			case 1:
			velocity_value = VEL1;
			break;
			case 2:
			velocity_value = VEL2;
			break;
			case 3:
			velocity_value = VEL3;
			break;
			case 4:
			velocity_value = VEL4;
			break;
			case 5:
			velocity_value = VEL5;
			break;
			case 6:
			velocity_value = VEL6;
			break;
			case 7:
			velocity_value = VEL7;
			break;
			case 8:
			velocity_value = VEL8;
			break;
			case 9:
			velocity_value = VEL9;
			break;
			
		}
	
}


void HandleChaser::SignalLedOut(uint8_t step){			
	
	putSignalLed(step);	
		
}

void HandleChaser::SaveEeprom(uint8_t addres, uint8_t data){	
	 
eeprom_write_byte((uint8_t*)(uintptr_t)addres,data);	
	
}

uint8_t HandleChaser::ReadEeprom(uint8_t addres){
	
	uint8_t readed_value = eeprom_read_byte((uint8_t*)(uintptr_t)addres);	
	return readed_value;
	
}

void HandleChaser::PowerSignalOut(uint8_t step){
	
	putSignalPower(step);
	
}


void HandleChaser::putSignalPower(uint8_t step){
		
	uint8_t inverted_step = invert_bits(step);	
	PORTSignals = inverted_step;	
	
}
	
uint8_t HandleChaser::invert_bits(uint8_t byte) {
	
	uint8_t result = 0;
	int i;
	for (i = 0; i < 8; i++) {
		result <<= 1;
		result |= byte & 0x01;
		byte >>= 1;
	}
	return result;
}



