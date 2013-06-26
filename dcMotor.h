/*
  dcMotor.h - Library for controling a dc motor
  Created by Mahmoud Abdrabo, June 26, 2013.
*/
#ifndef dcMotor
#define dcMotor

#include "Arduino.h"

class dcMotor
{
  public:
    dcMotor(boolean direction_pwm, int motor_0, int motor_1);
    void update(int direction, int pwm);
    void stop();
  private:
    int _motor_0;
    int _motor_1;
    int _direction_pwm;
};

#endif