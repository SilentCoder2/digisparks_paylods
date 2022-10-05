#include "DigiKeyboard.h"

#define link "https://google.com/"
void setup() {
  // don't need to set anything up to use DigiKeyboard
}


void loop() {
  
  DigiKeyboard.sendKeyStroke(0);
  delay(500);
  DigiKeyboard.sendKeyStroke(KEY_B, MOD_GUI_LEFT); 
  delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_N, MOD_CONTROL_LEFT | MOD_SHIFT_LEFT);
  delay(500);
  DigiKeyboard.sendKeyPress(0, MOD_CONTROL_LEFT);
  delay(200);
  DigiKeyboard.sendKeyStroke(KEY_L, MOD_CONTROL_LEFT);
  delay(1000);
  DigiKeyboard.print(link); 
  delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(10000);
}