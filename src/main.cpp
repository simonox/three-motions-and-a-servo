#include <Arduino.h>

#include <Servo.h>

/*
 * PIR sensor tester
 */
 
int leftPirPin = 2;               // choose the input pin (for PIR sensor)
int leftPirState = LOW;             // we start, assuming no motion detected
int rightPirPin = 3;
int rightPirState = LOW;
int centerPirPin = 4;
int centerPirState = LOW;
int leftValue = 0;                    // variable for reading the pin status
int rightValue = 0;
int centerValue = 0;
int ledPin = 13;  

int leftRotation = 359;
int rightRotation = 2;
int centerRotation = 90;

Servo myservo;

void setup() {
  pinMode(leftPirPin, INPUT);     // declare sensor as input
  pinMode(rightPirPin, INPUT);
  pinMode(centerPirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  myservo.attach(5, 795, 2180); 
  Serial.begin(9600);
}
 
void loop(){
  leftValue = digitalRead(leftPirPin);  // read input value
  rightValue = digitalRead(rightPirPin); // read second sensor
  centerValue = digitalRead(centerPirPin);
  Serial.print(leftValue);
  Serial.print(rightValue);
  Serial.println(centerValue);
  if (leftValue == HIGH) {            // check if,the input is HIGH
    Serial.println("moving left");
    myservo.write(leftRotation);
    digitalWrite(ledPin, HIGH);
    delay(500);
  } else if (rightValue == HIGH) {
    Serial.println("moving right");
    myservo.write(rightRotation);
    digitalWrite(ledPin, HIGH);
    delay(500);
  } else if (centerValue == HIGH) {
    Serial.println("moving center");
    myservo.write(centerRotation);
    digitalWrite(ledPin, HIGH);
    delay(500);
  } else {
     Serial.println("sleeeeeep");
     digitalWrite(ledPin, LOW);
  }
}