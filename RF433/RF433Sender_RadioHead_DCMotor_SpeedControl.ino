#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;
int joyX = 0;
int joyY = 1;
int joyValX, joyValY, Direction;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (!driver.init())
    Serial.println("init failed");
}

void loop() {
  uint8_t values[2];

  joyValX = analogRead(joyX);
  Serial.print("joyValX is ");
  Serial.println(joyValX);

  joyValY = analogRead(joyY);
  Serial.print("joyValY is ");
  Serial.println(joyValY);
  
  //values[0] = joyValX;
  //values[1] = joyValY;
  values[0] = map(joyValX, 0, 1023, 0, 255);
  values[1] = map(joyValY, 0, 1023, 0, 255);
  Serial.println(values[0]);
  Serial.println(values[1]);
  driver.send(values, 2);
  
  driver.waitPacketSent();
  Serial.println("msg sent!");
  delay(15);
}
