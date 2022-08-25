#include <DigiKeyboard.h>

#define link "https://google.com/" // You can change the link

void setup()
{
    // blank
}

void loop()
{

    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // send key window + r to start the rum command
    delay(250);                                      /// wait for 250 mili second
    DigiKeyboard.print(link);
    DigiKeyboard.sendKeyStroke(KEY_ENTER); // send enter key
                                           // delay(200);

    /* led blink after one cycle is completed*/
    digitalWrite(1, HIGH);
    delay(500);
    digitalWrite(1, LOW);
    // delay(200);
}