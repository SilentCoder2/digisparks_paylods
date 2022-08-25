#include <DigiKeyboard.h>

#define link "https://google.com/"

void setup() {
  
}

void loop() {
  
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  delay(250);    
  DigiKeyboard.print(link);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  //delay(200);


    digitalWrite(1, HIGH);
    delay(500);
    digitalWrite(1, LOW);
   // delay(200);
}