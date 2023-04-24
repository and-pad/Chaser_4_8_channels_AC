extern "C"{
#include "initsys.h"
}

uint8_t outConfig;

Initsys::Initsys() {}

void Initsys::initAll()
{
    InitPortDisplay();
    InitButtonsAndTypeSelector();
    InitSignalOutputs();
    InitSignalLeds();
    InitTimer();
}

void Initsys::InitPortDisplay()
{
	PORTDisplay=0;
    DDRDisplay = 0b11111111;
}

void Initsys::InitButtonsAndTypeSelector()
{
    PORTButtons = 0x0;
	
    DDRButtons &= 0b00000000;
    DDRTypeSelector &= 0b11111100;
	
	PORTTypeSelector |= (1 << PD0);
	PORTTypeSelector |= (1 << PD1);
	PORTButtons |= (1 << PD2);
	PORTButtons |= (1 << PD5);
	
	
}

void Initsys::InitSignalOutputs()
{
    PORTSignals = 0xFF;
    DDRSignals = 0b11111111;
}

void Initsys::InitSignalLeds()
{
    PORTLEDSignals = 0x0;
    DDRLeds = 0b11111111;
}



void Initsys::InitTimer()
{
    cli();
    // Configurar Timer 1 para generar interrupción cada octavo de segundo
    TCCR1B |= (1 << WGM12); // Modo CTC
    // TCCR1B configurado para intewrumpir cada 1024 ciclos de reloj (1/16MHz)*1024 = 64us
    TCCR1B |= (1 << CS12) | (1 << CS10);
    // contar un octavo de segundo 1/8 = 0.125s = 125ms = 125000us = 125000/64 = 1953.125
    OCR1A = 1953;
    TIMSK |= (1 << OCIE1A); // Habilitar interrupción por comparación
	
	// Configurar Timer 0 para generar interrupción cada 100 milisegundos
	TCCR0 = 0;              // Configurar Timer 0 en modo normal
	TCCR0 |= (1 << CS02) | (1 << CS00); // Preescalador de 1024
	// Para que el Timer0 interrumpa cada 100ms:
	// Frecuencia del clock / (Preescalador * Frecuencia de interrupción) - 1
	// 16MHz / (1024 * 10Hz) - 1 = 156
	OCR0 = 156;             // Valor de comparación para interrupción
	TIMSK |= (1 << OCIE0);  // Habilitar interrupción por comparación	
	
    sei();                  // Habilitar interrupciones globales
	
	
	
	
}



void Initsys::ConfigureChaserOutputs(){
	
		uint8_t out4;
		uint8_t out8;
		
		
		out4 = (PIND & 0x1);
		out8 = (PIND & 0x2);
		
		
		if(out8==0x2 && out4 == 0x0)
		outConfig = 8;		
		else if(out4==0x1 && out8 == 0x0)
		outConfig = 4;
		
		else{ /*if(out4 == 0x0 && out8 == 0x0)*/
		PORTDisplay= CHAR_E;
		PORTLEDSignals = 0x0;
		PORTSignals = 0x0;
		while(1){
			PORTDisplay= CHAR_E;
			PORTLEDSignals = 0x0;
			PORTSignals = 0x0;
			}		
			
		}	
		
		
		
	}
	
	
	
	
	
