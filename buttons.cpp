extern "C"
{
	#include "buttons.h"
}

uint8_t stateUpBtn;
uint8_t stateDownBtn;
uint8_t still_pressed_up;
uint8_t still_pressed_dwn;
uint8_t displaying_velocity;

void check_buttons(void)
{	
	stateUpBtn =  (PINBUTTONS & BTNUP) ? true : false;
    if (stateUpBtn == true)
    {		
		if (still_pressed_up == true)	
		{	
			program_counter++;	
			program_counter = program_counter > 9 ? 1 : program_counter;
			still_pressed_up = false;						
			has_changed = PROGRAM;
			displaying_velocity = false;
			Handler.DisplayOut(PROGRAM, program_counter);
			// todo, salvar despues de un tiempo de dejar de apretar el boton
			Handler.SaveEeprom(EE_PROGRAM,program_counter);
			_delay_ms(3);	  	   
		}   		
    }
    else
    {		
		if( still_pressed_up == false )
			{		
				_delay_ms(160);
			}			
		still_pressed_up = true;	
    }
	
    stateDownBtn =  (PINBUTTONS & BTNDWN) ? true : false;
    
	if (stateDownBtn == true)
    {
			if (still_pressed_dwn == true)
			{
				velocity_counter++;								
				velocity_counter = velocity_counter > 9 ? 1 : velocity_counter;				
				still_pressed_dwn = false;
				has_changed = VELOCITY;				
				
				displaying_velocity = true;
				
				Handler.DisplayOut(VELOCITY, velocity_counter);
				Handler.SaveEeprom(EE_SPEED, velocity_counter);
				
				Handler.SetVelocity(velocity_counter);
				_delay_ms(3);				
			}     
    }
    else
    {
       if( still_pressed_dwn == false )
       {
	       _delay_ms(160);
       }       
       still_pressed_dwn = true;       
    }    
}
