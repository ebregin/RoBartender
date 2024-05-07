 #include "pin_setup.h"
 #include "BasicStepperDriver.h"
 #include "cart_mover.h"
 #include <Arduino.h>

int last_known_bottle;
bool defined_stepper = false;
BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);
//stepper.begin(RPM, MICROSTEPS);

void GoToBottle(int aBottle){
   int start_time = millis();
  if(!defined_stepper){
     stepper.begin(RPM, MICROSTEPS);
    defined_stepper = true;
  }
  Serial.println("trying to go to " + String(aBottle));

  if (GetCurrentBottle()==aBottle){
    return;
  }
  int direction = 1;


// if we dont know where we are move until we hit something 
  if (last_known_bottle == aBottle || last_known_bottle == 0 ){
    while(GetCurrentBottle()==0){
     stepper.rotate(10);
     direction = 1;
     delay(5);
     if(millis()-start_time>5000){
      Serial.println("aborting");
      return;
     }
   }
  }
  if (last_known_bottle > aBottle){
    direction = 1;
  }else if(last_known_bottle < aBottle){
    direction = -1;
  }
  Serial.println(GetCurrentBottle());
  delay(1000);
Serial.println(GetCurrentBottle());
Serial.println("im here");
Serial.println(last_known_bottle);
  while(GetCurrentBottle()!=aBottle){
     stepper.rotate(direction*10);
     delay(5);
   }
   delay(500);
   stepper.rotate(direction*20);
   delay(500);


}

int GetCurrentBottle(){

    if (digitalRead(Drink1)){
      last_known_bottle = 1;
      return 1;
    }
    if (digitalRead(Drink2)){
      last_known_bottle = 2;
      return 2;
    }
    if (!digitalRead(Drink3)){
      last_known_bottle = 3;
      return 3;
    }
    if (digitalRead(Drink4)){
      last_known_bottle = 4;
      return 4;
    }
    // if (!digitalRead(Drink5)){
    //   last_known_bottle = 5;
    //   return 5;
    // }
    return 0;
}