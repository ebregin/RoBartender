 #include "pin_setup.h"
 #include <Arduino.h>


   void setPinModes(){
    // set outputs:

    // Motor Driver 1
       // Pump
      pinMode(motor1PWMA, OUTPUT);

      // valve 1
      pinMode(motor1PWMB, OUTPUT);


    // Motor Driver 2
       // valve 2
      pinMode(motor2PWMA, OUTPUT);

      // valve 3
      pinMode(motor2PWMB, OUTPUT);

    // Motor Driver 3
       // valve 4
      pinMode(motor3PWMA, OUTPUT);

      // valve 5
      pinMode(motor3PWMB, OUTPUT);

   // LCD and Buttons
      
  // const int LCD_CLK = 46;
  // const int LCD_DAT = 50;
  // const int LCD_LAT = 53;

    pinMode(RIGHT_BUTTON,INPUT_PULLUP);
    pinMode(CENTER_BUTTON,INPUT_PULLUP);
    pinMode(LEFT_BUTTON,INPUT_PULLUP);

    pinMode(Drink1,INPUT);
    pinMode(Drink2,INPUT);
    pinMode(Drink3,INPUT);
    pinMode(Drink4,INPUT);
    pinMode(Drink5,INPUT);


  }

  bool turnOnPump(){
    analogWrite(motor1PWMA, 155);
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
        analogWrite(motor1PWMB, 220);
        break;
      case 2:
         analogWrite(motor2PWMA, 220);
         break;
      case 3:
         analogWrite(motor2PWMB, 220);
         break;
      case 4:
         analogWrite(motor3PWMA, 220);
         break;
      case 5:
         analogWrite(motor3PWMB, 220);
         break;
      default:
      return 0;
    }
    return 1;
  }

  bool closeAllValves(){
    analogWrite(motor1PWMB, 0);
    analogWrite(motor2PWMA, 0);
    analogWrite(motor2PWMB, 0);
    analogWrite(motor3PWMA, 0);
    analogWrite(motor3PWMB, 0);
    return 1;
  }