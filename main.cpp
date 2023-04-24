/*
 * main.c
 *
 * Created: 3/15/2023 11:25:07 PM
 *  Author: Andres Padilla Sandoval
 */

#define F_CPU 16000000UL // Definir frecuencia del CPU
extern "C" {
#include <avr/io.h>
#include <string.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "eeprom.h"
#include "config_ports.h"
#include "timers.h"
#include "initsys.h"
#include "display.h"
#include "buttons.h"
#include "velocity.h"
#include "handle_chaser.h"
}



int main(void)
{
	Initsys Sys;
	Sys.initAll();		
	Sys.ConfigureChaserOutputs();	
		
	has_changed = INIT;
	//Handler.DisplayOut(INIT, 1);
	
	while (1)
	{	
		check_buttons();			
	}
}