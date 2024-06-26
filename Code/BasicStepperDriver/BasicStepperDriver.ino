
/*
 * Simple demo, should work with any driver board
 *
 * Connect STEP, DIR as indicated
 *
 * Copyright (C)2015-2017 Laurentiu Badea
 *
 * This file may be redistributed under the terms of the MIT license.
 * A copy of this license has been included with this distribution in the file LICENSE.
 */
#include <Arduino.h>
#include "BasicStepperDriver.h"

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
#define RPM 60

// Since microstepping is set externally, make sure this matches the selected mode
// If it doesn't, the motor will move at a different RPM than chosen
// 1=full step, 2=half step etc.
#define MICROSTEPS 16

// All the wires needed for full functionality
#define DIR 3
#define STEP 2
#define DRINK2 4
#define DRINK3 5
//Uncomment line to use enable/disable functionality
//#define SLEEP 13

// 2-wire basic config, microstepping is hardwired on the driver
BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);

//Uncomment line to use enable/disable functionality
//BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP, SLEEP);

void setup() {
    stepper.begin(RPM, MICROSTEPS);
    Serial.begin(9600);
    // if using enable/disable on ENABLE pin (active LOW) instead of SLEEP uncomment next line
    // stepper.setEnableActiveState(LOW);
}

void loop() {
  
    // energize coils - the motor will hold position
    // stepper.enable();
  
    /*
     * Moving motor one full revolution using the degree notation
     */
     int degree_steps = 360*5;

      int i = 0;
      at_drink = false;
      while(!at_drink && i<360*5){
        at_drink =  !digitalRead(DRINK2);
        stepper.rotate(1);
        i += 1;
      }
      delay(1000);

      int i = 0;
      at_drink = false;
      while(!at_drink && i<360*5){
        at_drink =  !digitalRead(DRINK3);
        stepper.rotate(-1);
        i += 1;
      }
  
     //Serial.println("turning one way");
    //stepper.rotate(360*5);

    /*
     * Moving motor to original position using steps
     */
    //stepper.move(-MOTOR_STEPS*MICROSTEPS);

    // pause and allow the motor to be moved by hand
    // stepper.disable();

    //delay(1000);
    //Serial.println("turning other way");
  //  stepper.rotate(-360*5);
// delay(1000);
}
