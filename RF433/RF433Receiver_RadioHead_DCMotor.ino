#include <RH_ASK.h>
#include <SPI.h>

int MPin1 = 17;
int MPin2 = 22;
int MPin3 = 23;
int MPin4 = 24;

RH_ASK driver;

void setup() {
  Serial.begin(9600);
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
	
	if ((x > 250) && (x < 750) && (y > 250) && (y < 750)) {
	  stop();
	}else if ((x < 250) && (y > 250) && (y < 750)) {
      forward();
    }else if ((x > 750) && (y > 250) && (y < 750)) {
	  backward();
	}else if ((x > 250) && (x < 750) && (y > 750)) {
	  left();
	}else if ((x > 250) && (x < 750) && (y < 250)) {
	  right();
	}else if ((x < 250) && (y > 750)) {
	  forwardleft();
	}else if ((x < 250) && (y < 250)) {
	  forwardright();
	}else if ((x > 750) && (y > 750)) {
	  backwardleft();
	}else if ((x > 750) && (y < 250)) {
	  backwardright();
	}
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

void left() {
  digitalWrite(MPin1, LOW);
  digitalWrite(MPin2, HIGH);
  digitalWrite(MPin3, HIGH);
  digitalWrite(MPin4, LOW);
}

void right() {
  digitalWrite(MPin1, HIGH);
  digitalWrite(MPin2, LOW);
  digitalWrite(MPin3, LOW);
  digitalWrite(MPin4, HIGH);
}

void forwardleft() {
  digitalWrite(MPin1, LOW);
  digitalWrite(MPin2, LOW);
  digitalWrite(MPin3, HIGH);
  digitalWrite(MPin4, LOW);
}

void forwardright() {
  digitalWrite(MPin1, HIGH);
  digitalWrite(MPin2, LOW);
  digitalWrite(MPin3, LOW);
  digitalWrite(MPin4, LOW);
}

void backwardleft() {
  digitalWrite(MPin1, LOW);
  digitalWrite(MPin2, LOW);
  digitalWrite(MPin3, LOW);
  digitalWrite(MPin4, HIGH);
}

void backwardright() {
  digitalWrite(MPin1, LOW);
  digitalWrite(MPin2, HIGH);
  digitalWrite(MPin3, LOW);
  digitalWrite(MPin4, LOW);
}