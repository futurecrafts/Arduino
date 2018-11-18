#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

int joyX = 0;
int joyY = 1;

int joyValX, joyValY, Direction;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySwitch.enableTransmit(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  joyValX = analogRead(joyX);
  Serial.print("joyValX is ");
  Serial.println(joyValX);
  //joyValX = map(joyValX, 0, 1023, 0, 180);
  //Serial.print(" Mapped:: ");
  //Serial.println(joyValX);
  //servo1.write(joyVal);
  //mySwitch.send(joyValX, 24);

  joyValY = analogRead(joyY);
  Serial.print("joyValY is ");
  Serial.println(joyValY);
  //joyValY = map(joyValY, 0, 1023, 0, 180);
  //Serial.print(" Mapped:: ");
  //Serial.println(joyValY);
  //servo2.write(joyVal);
  //mySwitch.send(joyValY, 24);
  Direction = 0;
  if ((joyValX < 100) && (joyValY > 400) && (joyValY < 600)) {
    Direction = 1;
  }else if ((joyValX < 100) && (joyValY < 100)) {
    Direction = 2;
  }else if ((joyValX > 400) && (joyValX < 600) && (joyValY < 100)) {
    Direction = 3;
  }else if ((joyValX > 900) && (joyValY < 100)) {
    Direction = 4;
  }else if ((joyValX > 900) && (joyValY > 400) && (joyValY < 600)) {
    Direction = 5;
  }else if ((joyValX > 900) && (joyValY > 900)) {
    Direction = 6;
  }else if ((joyValX > 400) && (joyValX < 600) && (joyValY > 900)) {
    Direction = 7;
  }else if ((joyValX < 100) && (joyValY > 900)) {
    Direction = 8;
  }
  Serial.print("Direction is ");
  Serial.println(Direction);
  mySwitch.send(Direction, 24);  
  delay(15);
}
