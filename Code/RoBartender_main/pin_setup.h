#ifndef PIN_SETUP
#define PIN_SETUP

  
  // ----------Motor Driver 1---------
     //  Pump
  const int motor1APin1 = 7;   // AIN1
  const int motor1APin2 = 6;   // AIN2
  const int motor1PWMA = 5;         // Pulse Width Modulation Motor A
     // valve 1
  const int motor1BPin1 = 2;  // BIN1
  const int motor1BPin2 = 3;  // BIN2
  const int motor1PWMB = 4;         // Pulse Width Modulation Motor B

    // ----------Motor Driver 2---------
     //  valve 2
  const int motor2APin1 = 16;   // AIN1
  const int motor2APin2 = 15;   // AIN2
  const int motor2PWMA = 14;         // Pulse Width Modulation Motor A
     // valve 3
  const int motor2BPin1 = 17;  // BIN1
  const int motor2BPin2 = 18;  // BIN2
  const int motor2PWMB = 19;         // Pulse Width Modulation Motor B

    // ----------Motor Driver 3---------
     //  valve 4
  const int motor3APin1 = 25;   // AIN1
  const int motor3APin2 = 27;   // AIN2
  const int motor3PWMA = 23;         // Pulse Width Modulation Motor A
     // valve 5
  const int motor3BPin1 = 29;  // BIN1
  const int motor3BPin2 = 31;  // BIN2
  const int motor3PWMB = 33;         // Pulse Width Modulation Motor B


  // LCD and Button


  const int RIGHT_BUTTON = 41;
  const int CENTER_BUTTON = 39;
  const int LEFT_BUTTON = 37;
  


 // const int enablePin = 2;    // H-bridge enable pin
  const int ledPin = 13;      // LED 

  void setPinModes();
  bool openValve(int aValve);
  bool closeAllValves();
  bool turnOnPump();
  bool turnOffPump();





  #endif