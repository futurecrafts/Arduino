#include <Servo.h>

int ServoPin1 = 3;
int ServoPin2 = 5;
int joyX = 0;
int joyY = 1;
int joyVal;

Servo servo1;
Servo servo2;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(ServoPin1);
  servo2.attach(ServoPin2);
}

void loop() {
  // put your main code here, to run repeatedly:
  joyVal = analogRead(joyX);
  joyVal = map(joyVal, 0, 1023, 0, 180);
  servo1.write(joyVal);
  
  joyVal = analogRead(joyY);
  joyVal = map(joyVal, 0, 1023, 0, 180);
  servo2.write(joyVal);
  delay(15);
}
}
