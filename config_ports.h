/*
 * config_ports.h
 *
 * Created: 16/03/2023 03:01:04 a. m.
 *  Author: andre
 */

#ifndef CONFIG_PORTS_H_
#define CONFIG_PORTS_H_

extern "C"{
#include <avr/io.h>
}
#define DDRDisplay DDRB
#define PORTDisplay PORTB

#define DDRButtons DDRD
#define DDRTypeSelector DDRD
#define PORTTypeSelector PORTD
#define PORTButtons PORTD

#define STATE_BTN_UP (PIND  & (1 << PD4))
#define STATE_BTN_DOWN (PIND & (1 << PD5))

#define PINBUTTONS PIND

#define BTNDWN 0x20
#define BTNUP 0x10

#define PORTLEDSignals PORTC
#define DDRLeds DDRC

#define PORTSignals PORTA
#define DDRSignals DDRA

#define CIN4 PD0
#define CIN8 PD1

#endif /* CONFIG_PORTS_H_ */