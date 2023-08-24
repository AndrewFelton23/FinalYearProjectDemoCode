
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  myservo.write(pos);
}

void loop() {
  delay(3);  //delay to allow buffer to fill 
 Serial.println("Enter data:");
 Serial.println(pos);
  while (Serial.available() == 0) {}     //wait for data available
  String command = Serial.readString();  //read until timeout
  command.trim();                        // remove any \r \n whitespace at the end of the String
   if (command == "close") {
      if (pos < 45) {
        Serial.println("closing"); //see what was received
        for (pos = 0; pos < 45; pos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(5);                       // waits 15ms for the servo to reach the position
        }
      }
      else {
        Serial.println("already closed"); //see what was received
      }
    }
    else if (command == "open") {
      if (pos > 0) {
        Serial.println("opening"); //see what was received
        for (pos = 45; pos > 0; pos += -1) { // goes from 180 degrees to 0 degrees
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(5);                       // waits 15ms for the servo to reach the position
        }
     }
     else {
      Serial.println("already open"); //see what was received
     }
    }
}
