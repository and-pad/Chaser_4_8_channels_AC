/*
 * IncFile1.h
 *
 * Created: 16/03/2023 02:47:44 a. m.
 *  Author: Andres Padilla Sandoval
 */ 

#ifndef DISPLAY_H_
#define DISPLAY_H_
extern "C" {
#include "config_ports.h"
#include "timers.h"
}

#define DIGIT_1 ~0x06
#define DIGIT_2 ~0x5B
#define DIGIT_3 ~0x4F
#define DIGIT_4 ~0x66
#define DIGIT_5 ~0x6D
#define DIGIT_6 ~0x7D
#define DIGIT_7 ~0x07
#define DIGIT_8 ~0x7F
#define DIGIT_9 ~0x6F
#define DIGIT_0 ~0x3F
#define CHAR_E ~0x79
#define DSP_OFF ~0x0

#define CHAR_T 0x04
#define CHAR_A 0x41



/* prototypes */
void PutDigit(unsigned char digit);
void PutFlashDigit(unsigned char digit);



#endif /* DISPLAY_H_ */