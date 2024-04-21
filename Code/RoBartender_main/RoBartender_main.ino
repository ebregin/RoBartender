 #include "pin_setup.h"
 #include "Wire.h"
 #include "Adafruit_LiquidCrystal.h"

  
  bool right_bottle = true;
  double cur_time_switch = 0;
  int valve_open = 1;

  bool left_button_state;
  bool center_button_state;
  bool right_button_state;
  bool left_button_processed = false;
  bool right_button_processed = false;

  // int LCD_CLK = 46;
  // int LCD_DAT = 50;
  // int LCD_LAT = 53;

  #define LCD_CLK 46
  #define LCD_DAT 50
  #define LCD_LAT 53
   

  // Adafruit_LiquidCrystal lcd(LCD_DAT, LCD_CLK, LCD_LAT);
  Adafruit_LiquidCrystal lcd(50, 46, 52); // for some odd reason you need to input the actual values here


  void setup() {
   setPinModes();

   //lcd.setBacklight(HIGH);


    Serial.begin(9600);
    
    cur_time_switch = millis()+2000;

   
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 4);
  // Print a message to the LCD.
  lcd.print("Please Select Drink");
  lcd.setCursor(0, 3);
  lcd.print("Previous Select Next");
  lcd.setBacklight(HIGH);

  }

  void loop() {

    left_button_state   = !digitalRead(LEFT_BUTTON);
    center_button_state = !digitalRead(CENTER_BUTTON);
    right_button_state  = !digitalRead(RIGHT_BUTTON);
  

    if(left_button_state){
      if(!left_button_processed){
        valve_open -= 1;
        if(valve_open==0){
          valve_open = 5;
        }
        left_button_processed = true;
      }
    }else{
      left_button_processed = false;
    }
    if(right_button_state){
      if(!right_button_processed){
        valve_open += 1;
        if(valve_open==6){
          valve_open = 1;
        }
        right_button_processed = true;
      }
    }else{
      right_button_processed = false;
    }
   



  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(String(valve_open));
  Serial.println((valve_open));

    if(center_button_state){
        lcd.setCursor(0, 1);
        lcd.print("Enjoy Drink "+ String(valve_open));
        turnOffPump();
        closeAllValves();
        openValve(valve_open);
        delay(10);
        turnOnPump();   
        delay(3000);
        turnOffPump();
        closeAllValves();
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
