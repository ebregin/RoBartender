//#include "BasicStepperDriver.h"

#ifndef CART_MOVER
#define CART_MOVER



 #define MOTOR_STEPS 200
 #define RPM 60
 #define MICROSTEPS 16
 #define DIR 12
 #define STEP 13
 //BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);


//int last_known_bottle = 0;

void GoToBottle(int aBottle);

int GetCurrentBottle();

#endif