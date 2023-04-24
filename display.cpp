/*
 * display.c
 *
 * Created: 16/03/2023 02:55:35 a. m.
 *  Author: Andres Padilla Sandoval
 */ 
extern "C"{
#include "display.h"
}
#define Display_Off 11
#define DIGIT_OFF 11

void selectDigit(unsigned char digit)
{
	switch (digit)
	{
		case 0:
		PORTDisplay = DIGIT_0;
		break;
		case 1:
		PORTDisplay = DIGIT_1;
		break;
		case 2:
		PORTDisplay = DIGIT_2;
		break;
		case 3:
		PORTDisplay = DIGIT_3;
		break;
		case 4:
		PORTDisplay = DIGIT_4;
		break;
		case 5:
		PORTDisplay = DIGIT_5;
		break;
		case 6:
		PORTDisplay = DIGIT_6;
		break;
		case 7:
		PORTDisplay = DIGIT_7;
		break;
		case 8:
		PORTDisplay = DIGIT_8;
		break;
		case 9:
		PORTDisplay = DIGIT_9;
		break;
		case Display_Off:
		PORTDisplay = DSP_OFF;
		
		default:
		PORTDisplay = CHAR_A;
		break;
	}
	
}

void PutFlashDigit(unsigned char digit)
{
	on_off_velocity ? selectDigit(digit) : selectDigit(DIGIT_OFF);
}


void PutDigit(unsigned char digit)
{
	selectDigit(digit);
}
