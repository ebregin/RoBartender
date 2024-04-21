 #include "pin_setup.h"
 #include <Arduino.h>


   void setPinModes(){
    // set outputs:

    // Motor Driver 1
       // Pump
      pinMode(motor1APin1, OUTPUT); digitalWrite(motor1APin1, HIGH);
      pinMode(motor1APin2, OUTPUT); digitalWrite(motor1APin2, LOW);
      pinMode(motor1PWMA, OUTPUT);

      // valve 1
      pinMode(motor1BPin1, OUTPUT); digitalWrite(motor1BPin1, HIGH);
      pinMode(motor1BPin2, OUTPUT); digitalWrite(motor1BPin2, LOW);
      pinMode(motor1PWMB, OUTPUT);


    // Motor Driver 2
       // valve 2
      pinMode(motor2APin1, OUTPUT); digitalWrite(motor2APin1, HIGH);
      pinMode(motor2APin2, OUTPUT); digitalWrite(motor2APin2, LOW);
      pinMode(motor2PWMA, OUTPUT);

      // valve 3
      pinMode(motor2BPin1, OUTPUT); digitalWrite(motor2BPin1, HIGH);
      pinMode(motor2BPin2, OUTPUT); digitalWrite(motor2BPin2, LOW);
      pinMode(motor2PWMB, OUTPUT);

    // Motor Driver 3
       // valve 4
      pinMode(motor3APin1, OUTPUT); digitalWrite(motor3APin1, HIGH);
      pinMode(motor3APin2, OUTPUT); digitalWrite(motor3APin2, LOW);
      pinMode(motor3PWMA, OUTPUT);

      // valve 5
      pinMode(motor3BPin1, OUTPUT); digitalWrite(motor3BPin1, HIGH);
      pinMode(motor3BPin2, OUTPUT); digitalWrite(motor3BPin2, LOW);
      pinMode(motor3PWMB, OUTPUT);

   // LCD and Buttons
      
  // const int LCD_CLK = 46;
  // const int LCD_DAT = 50;
  // const int LCD_LAT = 53;

    pinMode(RIGHT_BUTTON,INPUT_PULLUP);
    pinMode(CENTER_BUTTON,INPUT_PULLUP);
    pinMode(LEFT_BUTTON,INPUT_PULLUP);


  }

  bool turnOnPump(){
    analogWrite(motor1PWMA, 255);
    return 1;
  }

  bool turnOffPump(){
    analogWrite(motor1PWMA, 0);
    return 1;
  }
  bool turnOffPump();

  bool openValve(int aValve){
    switch (aValve){
      case 1:
        digitalWrite(motor1PWMB, HIGH);
        break;
      case 2:
         digitalWrite(motor2PWMA, HIGH);
         break;
      case 3:
         digitalWrite(motor2PWMB, HIGH);
         break;
      case 4:
         digitalWrite(motor3PWMA, HIGH);
         break;
      case 5:
         digitalWrite(motor3PWMB, HIGH);
         break;
      default:
      return 0;
    }
    return 1;
  }

  bool closeAllValves(){
    digitalWrite(motor1PWMB, LOW);
    digitalWrite(motor2PWMA, LOW);
    digitalWrite(motor2PWMB, LOW);
    digitalWrite(motor3PWMA, LOW);
    digitalWrite(motor3PWMB, LOW);
    return 1;
  }