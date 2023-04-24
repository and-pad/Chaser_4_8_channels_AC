extern "C"{
#include "timers.h"
#include "chaser_steps.h"

}
int time_counter;
int cambio;
int has_changed;

uint8_t program_counter;
uint8_t velocity_counter;
uint8_t velocity_value;

uint8_t on_off_velocity;
uint8_t blink_time;

uint8_t n_elements;
uint8_t *actual;

#define CONF4OUTS 4
#define CONF8OUTS 8

void select_program(uint8_t cnt)
{	
	
	 switch(outConfig)
	 {
		 
	 case CONF4OUTS:  
	
			switch(cnt)
			{
				case 1:
				actual = SAL4.uno;
				n_elements = sizeof(SAL4.uno);
				break;
				case 2:
				actual = SAL4.dos;
				n_elements = sizeof(SAL4.dos);
				break;
				case 3:		
				actual = SAL4.tres;
				 n_elements = sizeof(SAL4.tres);
				break;
				case 4:
				actual = SAL4.cuatro;
				 n_elements = sizeof(SAL4.cuatro);
				break;
				case 5:
				actual = SAL4.cinco;
				 n_elements = sizeof(SAL4.cinco);
				break;
				case 6:
				actual = SAL4.seis;
				 n_elements = sizeof(SAL4.seis);
				break;
				case 7:
				actual = SAL4.siete;
				 n_elements = sizeof(SAL4.siete);
				break;
				case 8:
				actual = SAL4.ocho;
				 n_elements = sizeof(SAL4.ocho);
				break;
				case 9:
				actual = SAL4.nueve;
				 n_elements = sizeof(SAL4.nueve);
				break;
				case 10:
				actual = SAL4.diez;
				 n_elements = sizeof(SAL4.diez);
				break;
 			}
		   break;
		   
	 case CONF8OUTS:
			
			switch(cnt)
			{
				case 1:
				actual = SAL8.uno;
				n_elements = sizeof(SAL8.uno);
				break;
				case 2:
				actual = SAL8.dos;
				n_elements = sizeof(SAL8.dos);
				break;
				case 3:
				actual = SAL8.tres;
				n_elements = sizeof(SAL8.tres);
				break;
				case 4:
				actual = SAL8.cuatro;
				n_elements = sizeof(SAL8.cuatro);
				break;
				case 5:
				actual = SAL8.cinco;
				n_elements = sizeof(SAL8.cinco);
				break;
				case 6:
				actual = SAL8.seis;
				n_elements = sizeof(SAL8.seis);
				break;
				case 7:
				actual = SAL8.siete;
				n_elements = sizeof(SAL8.siete);
				break;
				case 8:
				actual = SAL8.ocho;
				n_elements = sizeof(SAL8.ocho);
				break;
				case 9:
				actual = SAL8.nueve;
				n_elements = sizeof(SAL8.nueve);
				break;
				
			}
			
			 
 }
	 
	 
}

void select_velocity(uint8_t vel)
{
	switch(vel)	
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

//El timer 1 esta configurado para interrumpir cada 1/8 de segundo
ISR(TIMER1_COMPA_vect)
{
	
       time_counter++;
	  
	
	switch(has_changed)
	{
		case PROGRAM:
			select_program(program_counter);
			cambio= 0;		
			has_changed = false;
			break;
		
		case VELOCITY:
		    time_counter = 0;
			select_velocity(velocity_counter);		
			has_changed = false;
		break;
		
		case INIT:
			time_counter=0;
			cambio=0;
			
			uint8_t read_vel = Handler.ReadEeprom(EE_SPEED);
			velocity_counter = read_vel;
			select_velocity(read_vel);
			Handler.DisplayOut(VELOCITY,read_vel);
			
			
			
			uint8_t read_prg = Handler.ReadEeprom(EE_PROGRAM);			
			program_counter= read_prg;
			Handler.DisplayOut(PROGRAM,read_prg);
			select_program(read_prg);
			
			
			has_changed=false;
		break;	
	}	
	
	
	   if(time_counter >= velocity_value)   
	   {
			   time_counter=0;
			   cambio++;
			   
			   if(cambio <= n_elements-1)
			   {	
				   uint8_t Actual = actual[cambio-1];    			   
				   Handler.SignalLedOut(Actual);
				   Handler.PowerSignalOut(Actual);
			   }
			   else
			   {
				   uint8_t Actual = actual[cambio-1];
				   Handler.SignalLedOut(Actual);
				   Handler.PowerSignalOut(Actual);
				   cambio = 0;
			   }	
			   
	   }       
	    
	   
}

ISR(TIMER0_COMP_vect)
{	
	
	blink_time++; // Incrementar el contador de interrupciones
	if (blink_time == 3) // Si han pasado 300 milisegundos (30 * 10ms)
	{
		if (displaying_velocity==true)
		{
			
			on_off_velocity = on_off_velocity ? false: true;
			
			if(on_off_velocity == true)
			Handler.DisplayOut(VELOCITY, velocity_counter);
			else
			PORTDisplay = DSP_OFF;
			
		}				
		
		blink_time = 0; // Reiniciar el contador
	}
	
	
}


