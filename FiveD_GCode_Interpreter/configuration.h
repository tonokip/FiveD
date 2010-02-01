#ifndef PARAMETERS_H
#define PARAMETERS_H

#define USE_RELATIVE_ECODES

#define MOTHERBOARD 2 // ARDUINO 0, SANGUINO 1, RS485 2, MEGA 3

#define E_STEPS_PER_MM   (2.12 * 16) // 1/16 Microstepping
// (200 full-steps-per-revolution / (5mm diameter shaft * 3.14) / (3 mm filament / 0.5 mm nozzle) = (200 / (5 * 3.14)) / (3 / 0.5) = 2.12314225 full steps per mm extruded

#define X_STEPS_PER_MM   10.047
#define Y_STEPS_PER_MM   20.094 // 0.9deg/step
#define Z_STEPS_PER_MM   1487.5 // 0.9def/step UNC 5/16 - 18 Threads Per Inch


#define FAST_XY_FEEDRATE 3000.0
#define FAST_Z_FEEDRATE  50.0


#define HOST_BAUD 19200 // *RO

#define ENDSTOPS_MIN_ENABLED 1
#define ENDSTOPS_MAX_ENABLED 0

#define INVERT_X_DIR 0
#define INVERT_Y_DIR 0
#define INVERT_Z_DIR 0

//#define ACCELERATION_ON  // Comment this line to turn accelerations off
#define SLOW_XY_FEEDRATE 1000.0 // Speed from which to start accelerating
#define SLOW_Z_FEEDRATE 20

#define ENABLE_ON LOW  //Inverting LOW, Non-Inverting HIGH, for Stepper Enable PIN
#define DISABLE_X 0
#define DISABLE_Y 0
#define DISABLE_Z 1 //Turns off Z motor when not used.
#define DISABLE_E 0

#define ENDSTOPS_INVERTING 1


#define WAIT_AT_TEMPERATURE 10 // 5-second intervals to wait at the target temperature to stabilise.
#define INCHES_TO_MM 25.4 // *RO
#define SMALL_DISTANCE 0.01 // *RO  // The number of mm below which distances are insignificant
#define SMALL_DISTANCE2 (SMALL_DISTANCE*SMALL_DISTANCE) // *RO  // Useful to have its square
#define X_STEPS_PER_INCH (X_STEPS_PER_MM*INCHES_TO_MM) // *RO
#define Y_STEPS_PER_INCH (Y_STEPS_PER_MM*INCHES_TO_MM) // *RO
#define Z_STEPS_PER_INCH (Z_STEPS_PER_MM*INCHES_TO_MM) // *RO
#define E_STEPS_PER_INCH (E_STEPS_PER_MM*INCHES_TO_MM) // *RO
#define COMMAND_SIZE 128 // *RO  //our command string length
#define BUFFER_SIZE 4 // *RO  // The size of the movement buffer
#define DEFAULT_TICK (long)1000 // *RO  // Number of microseconds between timer interrupts when no movement is happening
#define WAITING_DELAY 1 // *RO // What delay() value to use when waiting for things to free up in milliseconds
#if MOTHERBOARD > 1
#define MY_NAME 'H'           // Byte representing the name of this device
#define E0_NAME '0'           // Byte representing the name of extruder 0
#define E1_NAME '1'           // Byte representing the name of extruder 1
#define RS485_MASTER  1       // *RO
#endif

//******************************************************************************
// You probably only want to edit things below this line if you really really
// know what you are doing...

extern char debugstring[];

void delayMicrosecondsInterruptible(unsigned int us);

// Inline interrupt control functions
inline void enableTimerInterrupt() 
{
   TIMSK1 |= (1<<OCIE1A);
}
	
inline void disableTimerInterrupt() 
{
     TIMSK1 &= ~(1<<OCIE1A);
}
        
inline void setTimerCeiling(unsigned int c) 
{
    OCR1A = c;
}

inline void resetTimer()
{
  TCNT2 = 0;
}

#endif

//*************************************************************************

