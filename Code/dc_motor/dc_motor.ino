 const int motorAPin1 = 7;   // AIN1
  const int motorAPin2 = 6;   // AIN2
  const int motorBPin1 = 2;  // BIN1
  const int motorBPin2 = 3;  // BIN2
  const int enablePin = 2;    // H-bridge enable pin
  const int ledPin = 13;      // LED 
  const int PWMA = 5;         // Pulse Width Modulation Motor A
  const int PWMB = 4;         // Pulse Width Modulation Motor B

  bool right_bottle = true;
  double cur_time_switch = 0;

  // pressure sensor
  #include "HX711.h"

HX711 scale;

uint8_t dataPin = 20;
uint8_t clockPin = 21;

uint32_t start, stop;
volatile float f;




  void setup() {
   
    // set outputs:
    pinMode(motorAPin1, OUTPUT); 
    pinMode(motorAPin2, OUTPUT); 
    pinMode(motorBPin1, OUTPUT);
    pinMode(motorBPin2, OUTPUT);
    pinMode(enablePin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);

    // set enablePin high so that motor can turn on:
    digitalWrite(enablePin, HIGH); 

    digitalWrite(motorAPin1, HIGH);
    digitalWrite(motorAPin2, LOW);

    digitalWrite(motorBPin1, HIGH);
    digitalWrite(motorBPin2, LOW);

    Serial.begin(9600);
    
    cur_time_switch = millis()+2000;



    //pressure sensor
 // Serial.begin(115200);
  // Serial.println(__FILE__);
  // Serial.print("LIBRARY VERSION: ");
  // Serial.println(HX711_LIB_VERSION);
  // Serial.println();

  scale.begin(dataPin, clockPin);

  // TODO find a nice solution for this calibration..
  // load cell factor 20 KG
  // scale.set_scale(127.15);
  // load cell factor 5 KG
  scale.set_scale(420.0983);       // TODO you need to calibrate this yourself.
  // reset the scale to zero = 0
  scale.tare();

  }

  void loop() {

    if(millis()>cur_time_switch){
      right_bottle=!right_bottle;
      cur_time_switch += 4000; 
      //Serial.println(right_bottle);
      delay(2000);
    }


    digitalWrite(PWMA, right_bottle);
    

    if(right_bottle){
    analogWrite(PWMB, 255);
    }else{
      analogWrite(PWMB, 0);
    }

    // pressure sensor
      f = scale.get_units(5);
      Serial.println(f);
}