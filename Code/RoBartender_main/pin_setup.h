#ifndef PIN_SETUP
#define PIN_SETUP

  
  // ----------Motor Driver 1---------
     //  Pump
  const int motor1PWMA = 5;         // Pulse Width Modulation Motor A
     // valve 1
  const int motor1PWMB = 7;         // Pulse Width Modulation Motor B

    // ----------Motor Driver 2---------
     //  valve 2
  const int motor2PWMA = 23;         // Pulse Width Modulation Motor A
     // valve 3
  const int motor2PWMB = 22;         // Pulse Width Modulation Motor B

    // ----------Motor Driver 3---------
     //  valve 4
  const int motor3PWMA = 3;         // Pulse Width Modulation Motor A
     // valve 5
  const int motor3PWMB = 10;         // Pulse Width Modulation Motor B


  // LCD and Button


  const int RIGHT_BUTTON = 25;
  const int CENTER_BUTTON = 29;
  const int LEFT_BUTTON = 33;

  const int Drink1 = 2;
  const int Drink2 = 9;
  const int Drink3 = 3;
  const int Drink4 = 10;
  const int Drink5 = 4;
  


 // const int enablePin = 2;    // H-bridge enable pin
  //const int ledPin = 13;      // LED 

  void setPinModes();
  bool openValve(int aValve);
  bool closeAllValves();
  bool turnOnPump();
  bool turnOffPump();





  #endif