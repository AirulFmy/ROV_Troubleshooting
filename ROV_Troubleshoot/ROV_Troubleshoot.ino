#include <SoftwareSerial.h>
#include "Cytron_PS2Shield.h"
#include "AFMotor.h"

Cytron_PS2Shield ps2(2, 3); // SoftwareSerial: Rx and Tx pin
//Cytron_PS2Shield ps2; // HardwareSerial

AF_DCMotor MRight     (1, MOTOR12_1KHZ);
AF_DCMotor MLeft      (2, MOTOR12_1KHZ);
AF_DCMotor MVertical  (3, MOTOR34_1KHZ);

void setup()
{
  ps2.begin(9600);
  
}

void loop()
{
  if(ps2.readButton(PS2_UP) == 0)
  {
    Forward(200);
  }
  else if(ps2.readButton(PS2_DOWN) == 0)
  {
    Backward(200);
  }
  else if(ps2.readButton(PS2_RIGHT) == 0)
  {
    TurnRight90Deg(200);
  }
  else if(ps2.readButton(PS2_LEFT) == 0)
  {
    TurnLeft90Deg(200);
  }
}

/*
 * ::::::::::::::::::::::::::::::::::::::::::::::::::::::
 *                   Function Variable
 *::::::::::::::::::::::::::::::::::::::::::::::::::::::
 */

void Forward(int pwm_forward)
{
  MRight.run(FORWARD);
  MLeft.run(FORWARD);
  
  MRight.setSpeed(pwm_forward);
  MLeft.setSpeed(pwm_forward);
}

void Backward(int pwm_backward)
{
  MRight.run(BACKWARD);
  MLeft.run(BACKWARD);
  
  MRight.setSpeed(pwm_backward);
  MLeft.setSpeed(pwm_backward);
}

void TurnRight90Deg(int pwm_90Right)
{
  MRight.run(FORWARD);
  MLeft.run(BACKWARD);
  
  MRight.setSpeed(pwm_90Right);
  MLeft.setSpeed(pwm_90Right);  
}

void TurnLeft90Deg(int pwm_90Left)
{
  MRight.run(BACKWARD);
  MLeft.run(FORWARD);
  
  MRight.setSpeed(pwm_90Left);
  MLeft.setSpeed(pwm_90Left);  
}

