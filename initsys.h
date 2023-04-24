#ifndef INITSYS_H_
#define INITSYS_H_


extern "C"{
#include <avr/io.h>
#include <avr/interrupt.h>
#include "config_ports.h"
#include "display.h"
}

extern uint8_t outConfig;

class Initsys
{
public:
    Initsys();
    void initAll();
	void ConfigureChaserOutputs();

private:
    void InitPortDisplay();
    void InitButtonsAndTypeSelector();
    void InitSignalOutputs();
    void InitSignalLeds();
    void InitTimer();
};

#endif // INITSYS_H