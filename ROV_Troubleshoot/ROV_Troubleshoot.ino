#include <SoftwareSerial.h>
#include "Cytron_PS2Shield.h"

Cytron_PS2Shield ps2(2, 3); // SoftwareSerial: Rx and Tx pin
//Cytron_PS2Shield ps2; // HardwareSerial

#define LEDPIN  13

void setup()
{
  ps2.begin(9600);
  
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW);
}

void loop()
{
  
  if(ps2.readButton(PS2_UP) == 0)
  {
    digitalWrite(LEDPIN, HIGH);
    delay(500);
    digitalWrite(LEDPIN, LOW);
    delay(500); 
  }
  else if(ps2.readButton(PS2_DOWN) == 0)
  {
    digitalWrite(LEDPIN, HIGH);
    delay(1500);
    digitalWrite(LEDPIN, LOW);
    delay(1500);
  }
  else if(ps2.readButton(PS2_RIGHT) == 0)
  {
    digitalWrite(LEDPIN, HIGH);
    delay(300);
    digitalWrite(LEDPIN, LOW);
    delay(300);
    digitalWrite(LEDPIN, HIGH);
    delay(300);
    digitalWrite(LEDPIN, LOW);
    delay(300);

    digitalWrite(LEDPIN, HIGH);
    delay(1500);
    digitalWrite(LEDPIN, LOW);
    delay(1500);
    digitalWrite(LEDPIN, HIGH);
    delay(1500);
    digitalWrite(LEDPIN, LOW);
    delay(1500);
  }
  else if(ps2.readButton(PS2_LEFT) == 0)
  {
    digitalWrite(LEDPIN, HIGH);
    delay(300);
    digitalWrite(LEDPIN, LOW);
    delay(300);
    digitalWrite(LEDPIN, HIGH);
    delay(300);
    digitalWrite(LEDPIN, LOW);
    delay(300);
    digitalWrite(LEDPIN, LOW);
    delay(300);

    digitalWrite(LEDPIN, HIGH);
    delay(1500);
    digitalWrite(LEDPIN, LOW);
    delay(1500);
    digitalWrite(LEDPIN, HIGH);
    delay(1500);
    digitalWrite(LEDPIN, LOW);
    delay(1500);
    digitalWrite(LEDPIN, HIGH);
    delay(1500);
    digitalWrite(LEDPIN, LOW);
    delay(1500);
  }
  else
  {
    digitalWrite(LEDPIN, LOW);
  }
}
