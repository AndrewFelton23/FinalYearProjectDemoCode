#define stepPin 2
#define dirPin 5 
#define PullOne 8
#define PullTwo 9
#define PullThree 10
 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(PullOne,OUTPUT); 
  pinMode(PullTwo,OUTPUT);
  pinMode(PullThree,OUTPUT); 
  digitalWrite(PullOne,HIGH); 
  digitalWrite(PullTwo,HIGH);
  digitalWrite(PullThree,LOW);  
}
void loop() {
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(200);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(200); 
  }
}
