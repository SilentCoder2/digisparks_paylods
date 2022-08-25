#include <DigiKeyboard.h>

#define link "https://google.com/" //add your link to open

void setup() {
  
}

void loop() {

  digitalWrite(1, LOW);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  delay(250);    
  DigiKeyboard.print(link);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  digitalWrite(1, HIGH); 
  delay(500);
  digitalWrite(1, LOW);
  delay(200);
}