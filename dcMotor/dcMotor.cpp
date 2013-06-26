/*
  	dcMotor.h - Library for controling a dc motor
  	Created by Mahmoud Abdrabo, June 26, 2013.
	

	Constructor Parameters

	motor_0    is the direction pin when direction_pwm is set TRUE
	motor_1    is always pwm pin


	update function parameters
	
	direction    forward is 0, backward is 1
	pwm          desired speed 0-255
*/

#include "Arduino.h"
#include "dcMotor.h"

dcMotor::dcMotor(bool direction_pwm, int motor_0, int motor_1)
{
  pinMode(motor_0, OUTPUT);
  pinMode(motor_1, OUTPUT);
  _motor_0 = motor_0;
  _motor_1 = motor_1;
  _direction_pwm = direction_pwm;
}

void dcMotor::update(int direction, int pwm)
{
	if (_direction_pwm)
	{
		digitalWrite(_motor_0, direction);
		analogWrite(_motor_1, pwm);
	}
	else
	{
		if (_direction_pwm)
		{
			analogWrite(_motor_0, pwm);
			analogWrite(_motor_1, 0);
		}
		else
		{
			analogWrite(_motor_0, 0);
			analogWrite(_motor_1, pwm);
		}
	}
}

void dcMotor::stop()
{
	if (_direction_pwm)
	{
		analogWrite(_motor_1, 0);
	}
	else
	{
		analogWrite(_motor_0, 0);
		analogWrite(_motor_1, 0);
	}
}