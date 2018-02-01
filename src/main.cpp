#include <Arduino.h>

/*
 * PIR sensor tester
 */
 
int ledPin = 9;                // choose the pin for the LED
int pir1pin = 2;               // choose the input pin (for PIR sensor)
int pir1State = LOW;             // we start, assuming no motion detected
int pir2pin = 3;
int pir2State = LOW;
int pir3pin = 4;
int pir3State = LOW;
int val1 = 0;                    // variable for reading the pin status
int val2 = 0;
int val3 = 0;

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(pir1pin, INPUT);     // declare sensor as input
  pinMode(pir2pin, INPUT);
  pinMode(pir3pin, INPUT);
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
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pir1State == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pir1State = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pir1State == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pir1State = LOW;
    }
  }
}