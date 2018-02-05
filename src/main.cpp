#include <Arduino.h>

#include <Servo.h>

/*
 * PIR sensor tester
 */
 
int pir1pin = 2;               // choose the input pin (for PIR sensor)
int pir1State = LOW;             // we start, assuming no motion detected
int pir2pin = 3;
int pir2State = LOW;
int pir3pin = 4;
int pir3State = LOW;
int val1 = 0;                    // variable for reading the pin status
int val2 = 0;
int val3 = 0;
Servo myservo;

void setup() {
  pinMode(pir1pin, INPUT);     // declare sensor as input
  pinMode(pir2pin, INPUT);
  pinMode(pir3pin, INPUT);
  myservo.attach(5, 795, 2180); 
  Serial.begin(9600);
}
 
void loop(){
  val1 = digitalRead(pir1pin);  // read input value
  val2 = digitalRead(pir2pin); // read second sensor
  val3 = digitalRead(pir3pin);
  Serial.print(val1);
  Serial.print(val2);
  Serial.println(val3);

  if (val1 == HIGH) {            // check if the input is HIGH
    myservo.write(1);
  } else {
    myservo.write(90);
  }
}