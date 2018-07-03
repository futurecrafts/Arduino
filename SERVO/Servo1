#include <Servo.h>

int ServoPin = 7;

Servo MyServo;

void setup() {
  MyServo.attach(ServoPin);
}

void loop() {
  MyServo.write(0);
  delay(1000); // 0 degrees
  MyServo.write(45);
  delay(1000); // 45 degrees
  MyServo.write(90);
  delay(1000); // 90 degrees
  MyServo.write(135);
  delay(1000); // 135 degrees
  MyServo.write(180);
  delay(1000); // 180 degrees
}
