#include <ESP32Servo.h>
#include <DabbleESP32.h>


#define INCLUDE_GAMEPAD_MODULE


int dirPin2 = 32;
int dirPin1 = 33;

int dirPin4 = 25;
int dirPin3 = 26;
int x = 90;
int y = 90;

Servo myservo;
Servo myservo2;
void setup() {


  myservo.attach(5);
  myservo.write(y);
  myservo2.attach(18);
  myservo2.write(x);

  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(dirPin3, OUTPUT);
  pinMode(dirPin4, OUTPUT);
  Serial.begin(250000);    // Set your Serial Monitor is set at 250000
  Dabble.begin("My Esp32");      // This is the baude rate of the HM-10
}

void loop() {
  Dabble.processInput(); { // This line is crucial in grabbing our data

    if (GamePad.isUpPressed())
    {
      Serial.println("Forward");
      digitalWrite(dirPin1, HIGH);
      digitalWrite(dirPin2, LOW);
      digitalWrite(dirPin3, HIGH);
      digitalWrite(dirPin4, LOW);
    }

    else if (GamePad.isDownPressed())
    {
      Serial.println("Backward");
      digitalWrite(dirPin1, LOW);
      digitalWrite(dirPin2, HIGH);
      digitalWrite(dirPin3, LOW);
      digitalWrite(dirPin4, HIGH);
    }
    else if (GamePad.isLeftPressed())
    {
      Serial.println("Left");
      digitalWrite(dirPin3, LOW);
      digitalWrite(dirPin4, HIGH);
      digitalWrite(dirPin1, HIGH);
      digitalWrite(dirPin2, LOW);
    }
    else if (GamePad.isRightPressed())
    {
      Serial.println("Right");
      digitalWrite(dirPin3, HIGH);
      digitalWrite(dirPin4, LOW);
      digitalWrite(dirPin1, LOW);
      digitalWrite(dirPin2, HIGH);
    }
    else if (GamePad.isStartPressed())
    {

    }
    else if (GamePad.isSelectPressed())
    {

    }
    else if (GamePad.isTrianglePressed())
    {
      if(x<170)
      {
      x++;
    myservo2.write(x);
    delay(10);
      }
    }
    else if (GamePad.isCrossPressed())
    {
      if(x>10)
      {
      x--;
    myservo2.write(x);
    delay(10);
      }
    }
    else if (GamePad.isSquarePressed())
    {
      if(y<170)
      {
      y++;
      myservo.write(y);
      delay(10);
      }
    }
    else if (GamePad.isCirclePressed())
    {
      if(y>10)
      {
      y--;
      myservo.write(y);
      delay(10);
      }
    }
    else
    {
      Serial.println("Stopped");
      digitalWrite(dirPin1, LOW);
      digitalWrite(dirPin2, LOW);
      digitalWrite(dirPin3, LOW);
      digitalWrite(dirPin4, LOW);
      
    }
  }
}
