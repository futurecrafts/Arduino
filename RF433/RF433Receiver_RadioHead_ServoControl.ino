#include <Servo.h>
#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;
Servo servo1;
Servo servo2;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(3);
  servo2.attach(5);
  Serial.begin(9600);
  if (!driver.init())
    Serial.println("init failed");
}

void loop() {
  // put your main code here, to run repeatedly:
  //uint8_t buf[12];
  uint8_t buf[2];
  uint8_t buflen = sizeof(buf);
  if(driver.recv(buf, &buflen))
  {
    int i;
    Serial.print("message: ");
    //Serial.println((char*)buf);
    Serial.println(buf[0]);
    Serial.println(buf[1]);
    servo1.write(buf[0]);
    servo2.write(buf[1]);
  }else
  {
    //Serial.println("not msg yet");
  }
  delay(15);
}
