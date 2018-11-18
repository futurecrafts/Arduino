#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;
int joyX = 0;
int joyY = 1;
int joyValX, joyValY;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (!driver.init())
    Serial.println("init failed");
}

void loop() {
  // put your main code here, to run repeatedly:
  //const char *msg = "Hello World!";
  //driver.send((uint8_t*)msg, strlen(msg));
  uint8_t values[2];

  joyValX = analogRead(joyX);
  Serial.print("joyValX is ");
  Serial.println(joyValX);
  joyValX = map(joyValX, 0, 1023, 0, 180);
  Serial.print(" Mapped:: ");
  Serial.println(joyValX);

  joyValY = analogRead(joyY);
  Serial.print("joyValY is ");
  Serial.println(joyValY);
  joyValY = map(joyValY, 0, 1023, 0, 180);
  Serial.print(" Mapped:: ");
  Serial.println(joyValY);
  
  values[0] = joyValX;
  values[1] = joyValY;
  driver.send(values, 2);
  
  driver.waitPacketSent();
  Serial.println("msg sent!");
  delay(15);
}
