#include <dcMotor.h>

dcMotor motor1(true, 52, 2);

void setup()
{
}

void loop()
{
  motor1.update(0, 200);
  delay(5000);
  motor1.update(1, 200);
  delay(5000);
  motor1.stop();
  delay(5000);
}