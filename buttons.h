#ifndef BUTTONS_H
#define BUTTONS_H

extern "C"{
#include "display.h"
#include "config_ports.h"
#include "timers.h"
#include "config_ports.h"
#include "handle_chaser.h"
#include <util/delay.h>
#include <stdbool.h>
#include <avr/io.h>
#include "eeprom.h"
}

extern uint8_t stateUpBtn;
extern uint8_t stateDownBtn;

extern uint8_t still_pressed_up;
extern uint8_t still_pressed_dwn;

/*Prototypes*/
void check_buttons(void);

#endif // Button definitions