#include <RH_ASK.h>
#include <SPI.h>

#define enA 9
#define enB 10
#define MPin1 5
#define MPin2 4
#define MPin3 7
#define MPin4 6

int motorSpeedA = 0;
int motorSpeedB = 0;

RH_ASK driver;

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(MPin1,OUTPUT);
  pinMode(MPin2,OUTPUT);
  pinMode(MPin3,OUTPUT);
  pinMode(MPin4,OUTPUT);
  if (!driver.init())
    Serial.println("init failed");
}

void loop() {
  uint8_t buf[2];
  uint8_t buflen = sizeof(buf);
  if(driver.recv(buf, &buflen))
  {
    Serial.print("message: ");
    Serial.println(buf[0]);
    Serial.println(buf[1]);
	
    int x = buf[0];
	int y = buf[1];
	
	// Y-axis used for forward and backward control
    if (y < 470) {
      backward();
      // Convert the declining Y-axis readings for going backward from 470 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed
      motorSpeedA = map(y, 470, 0, 0, 255);
      motorSpeedB = map(y, 470, 0, 0, 255);
    }else if (y > 550) {
      forward();
      // Convert the increasing Y-axis readings for going forward from 550 to 1023 into 0 to 255 value for the PWM signal for increasing the motor speed
      motorSpeedA = map(y, 550, 1023, 0, 255);
      motorSpeedB = map(y, 550, 1023, 0, 255);
    }else { // If joystick stays in middle the motors are not moving
      motorSpeedA = 0;
      motorSpeedB = 0;
    }
	
	// X-axis used for left and right control
    if (x < 470) {
      // Convert the declining X-axis readings from 470 to 0 into increasing 0 to 255 value
      int xMapped = map(x, 470, 0, 0, 255);
      // Move to left - decrease left motor speed, increase right motor speed
      motorSpeedA = motorSpeedA - xMapped;
      motorSpeedB = motorSpeedB + xMapped;
      // Confine the range from 0 to 255
      if (motorSpeedA < 0) {
        motorSpeedA = 0;
      }
      if (motorSpeedB > 255) {
        motorSpeedB = 255;
      }
    }
    if (x > 550) {
      // Convert the increasing X-axis readings from 550 to 1023 into 0 to 255 value
      int xMapped = map(x, 550, 1023, 0, 255);
      // Move right - decrease right motor speed, increase left motor speed
      motorSpeedA = motorSpeedA + xMapped;
      motorSpeedB = motorSpeedB - xMapped;
      // Confine the range from 0 to 255
      if (motorSpeedA > 255) {
        motorSpeedA = 255;
      }
      if (motorSpeedB < 0) {
        motorSpeedB = 0;
      }
    }
	
	// Prevent buzzing at low speeds (Adjust according to your motors. My motors couldn't start moving if PWM value was below value of 70)
    if (motorSpeedA < 70) {
      motorSpeedA = 0;
    }
    if (motorSpeedB < 70) {
      motorSpeedB = 0;
    }
    analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
    analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
  
  }else
  {
    //Serial.println("not msg yet");
  }
  //delay(15);
}

void stop() {
  digitalWrite(MPin1, LOW);
  digitalWrite(MPin2, LOW);
  digitalWrite(MPin3, LOW);
  digitalWrite(MPin4, LOW);
}

void forward() {
  digitalWrite(MPin1, HIGH);
  digitalWrite(MPin2, LOW);
  digitalWrite(MPin3, HIGH);
  digitalWrite(MPin4, LOW);
}

void backward() {
  digitalWrite(MPin1, LOW);
  digitalWrite(MPin2, HIGH);
  digitalWrite(MPin3, LOW);
  digitalWrite(MPin4, HIGH);
}