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
    myservo.write(1);
    digitalWrite(ledPin, LOW);

  } else {
    myservo.write(90);
    digitalWrite(ledPin, HIGH);

  }
}