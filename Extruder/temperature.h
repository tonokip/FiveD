#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#ifdef USE_THERMISTOR

//Settings for MakerBot Thermistor - B57560 G0104F
//http://store.makerbot.com/electronics/components/100k-thermistor.html
//http://www.epcos.com/inf/50/db/ntc_06/GESensors__B57560__G560.pdf

// Thermistor lookup table for RepRap Temperature Sensor Boards 
// See this page:  http://dev.www.reprap.org/bin/view/Main/Thermistor

// RS thermistor 528-8592; EPCOS NTC G540 
// ./createTemperatureLookup.py --r0=100000 --t0=25 --r1=0 --r2=4700 --beta=4036 --max-adc=1023
// r0: 100000
// t0: 25
// r1: 0
// r2: 4700
// beta: 4036
// max adc: 1023
#define NUMTEMPS 20
short temptable[NUMTEMPS][2] = {
   {1, 864},
   {54, 258},
   {107, 211},
   {160, 185},
   {213, 168},
   {266, 154},
   {319, 143},
   {372, 133},
   {425, 125},
   {478, 116},
   {531, 109},
   {584, 101},
   {637, 94},
   {690, 87},
   {743, 79},
   {796, 70},
   {849, 61},
   {902, 50},
   {955, 34},
   {1008, 2}
};
#endif
#endif


