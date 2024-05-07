 #include "pin_setup.h"
 #include "Wire.h"
 #include "Adafruit_LiquidCrystal.h"
 //#include "BasicStepperDriver.h"
 #include "cart_mover.h"



  
  bool right_bottle = true;
  double cur_time_switch = 0;
  int valve_open = 2;
  int current_bottle = 0;

  bool left_button_state;
  bool center_button_state;
  bool right_button_state;
  bool left_button_processed = false;
  bool right_button_processed = false;

  // int LCD_CLK = 46;
  // int LCD_DAT = 50;
  // int LCD_LAT = 53;

  #define LCD_CLK 41
  #define LCD_DAT 49
  #define LCD_LAT 37
   

  // Adafruit_LiquidCrystal lcd(LCD_DAT, LCD_CLK, LCD_LAT);
  Adafruit_LiquidCrystal lcd(49, 41, 37); // for some odd reason you need to input the actual values here
  
  String drink_name(int aDrink){
    switch (aDrink){
      case 1:
        return "Jack & Coke";
      case 2:
        return "Gin & Tonic";
      case 3:
        return "Jack Clean";
      case 4:
        return "Rum & Coke";
     }
  }

  void setup() {
   setPinModes();

   //lcd.setBacklight(HIGH);


    Serial.begin(9600);
    
    cur_time_switch = millis()+2000;

    //stepper.begin(RPM, MICROSTEPS);

   
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 4);
  // Print a message to the LCD.
  lcd.setCursor(0,0);
  lcd.print("Please Select Drink");
  lcd.setCursor(0, 3);
  lcd.print("Previous Select Next");
  lcd.setBacklight(HIGH);
  delay(2000);
  }

  void loop() {
    while(1){
    Serial.println(!digitalRead(Drink1));
    Serial.println(digitalRead(Drink2));
    Serial.println(digitalRead(Drink3));
    Serial.println(digitalRead(Drink4));
    Serial.println("-------");
    delay(500);
    }
   //Serial.println(digitalRead(Drink5));
  //  Serial.println("-------");
  //   delay(200);
  // //   int i = 0;
  //  while(digitalRead(Drink2)){
  //    stepper.rotate(-10);
  //    delay(5);
  //  }
  //  delay(500);
  //  stepper.rotate(-20);
  //  delay(500);
  //  while(digitalRead(Drink3)){
  //    stepper.rotate(10);
  //    delay(5);
  //  }
  //  delay(500);
  //  stepper.rotate(20);
  //  delay(500);
  // int jj = 3;
  // int kk = -1;
  // while(1){
  //    GoToBottle(jj);
  //    jj = jj + 1;
  //    if(jj==5){
  //     jj = 2;
  //    }
  // }

    // Serial.println("turning one way");
    // stepper.rotate(360*5);
    // delay(1000);
    // Serial.println("turning other way");
    // stepper.rotate(-360*5);
    // delay(1000);

    // while(1){

    // }

    // delay(1000);
    // Serial.println("dispensing valve " + String(valve_open) + " in one second");
    // delay(1000);

    // turnOffPump();
    // closeAllValves();
    // openValve(valve_open);
    // delay(10);
    // turnOnPump();   
    // delay(6000);
    // turnOffPump();
    // closeAllValves();
    // valve_open = valve_open +1;
    // if(valve_open==6){
    //   valve_open = 1;
    // }
    
    //Serial.println("here");
    left_button_state   = !digitalRead(LEFT_BUTTON);
    center_button_state = !digitalRead(CENTER_BUTTON);
    right_button_state  = !digitalRead(RIGHT_BUTTON);

    //Serial.println(left_button_state);
  

    if(left_button_state){
      if(!left_button_processed){
        valve_open -= 1;
        if(valve_open==0){
          valve_open = 4;
        }
        Serial.println(valve_open);
        left_button_processed = true;
      }
    }else{
      left_button_processed = false;
    }
    if(right_button_state){
      if(!right_button_processed){
        valve_open += 1;
        if(valve_open==5){
          valve_open = 1;
        }
        Serial.println(valve_open);
        right_button_processed = true;
      }
    }else{
      right_button_processed = false;
    }
   



  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(String(valve_open));
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(drink_name(valve_open));
  //Serial.println((valve_open));

    if(center_button_state){
        valve_open = 1;
        lcd.setCursor(0, 1);
        lcd.print("Enjoy Drink ");
        lcd.setCursor(4, 2);
        lcd.print(drink_name(valve_open));
        //delay(3000);
        GoToBottle(valve_open);
        // turnOffPump();
        // closeAllValves();
        // openValve(valve_open);
        // delay(10);
        // turnOnPump();   
        // delay(3000);
        // turnOffPump();
        // closeAllValves();
        lcd.setCursor(0, 1);
        lcd.print("                ");

        valve_open = 3;
        lcd.setCursor(0, 1);
        lcd.print("Enjoy Drink "+ String(valve_open));
        GoToBottle(valve_open);
        // turnOffPump();
        // closeAllValves();
        // openValve(valve_open);
        // delay(10);
        // turnOnPump();   
        // delay(6000);
        // turnOffPump();
        // closeAllValves();
        lcd.setCursor(0, 2);
        lcd.print("                  ");
        lcd.setCursor(0, 1);
        lcd.print("                ");
    }

    // if(millis()>cur_time_switch){
    //   valve_open += 1;
    //   if (valve_open==6){
    //     valve_open = 1;
    //   }
    //   Serial.println("changing to valve " + String(valve_open));
    //   turnOffPump();
    //   closeAllValves();
    //   cur_time_switch += 4000; 
    // }
    // openValve(valve_open);
    // delay(10);
    // turnOnPump();

}


