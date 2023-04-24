/*
 * IncFile1.h
 *
 * Created: 15/03/2023 11:44:16 p. m.
 *  Author: Andres Padilla Sandoval
 */ 


#ifndef	EEPROM_H_
#define EEPROM_H_

extern "C"{
	#include "avr/eeprom.h"
	}

#define EE_PROGRAM 0X00
#define EE_SPEED   0X01

#define CUSTOM_PRGS 0X02




#endif /* INCFILE1_H_ */