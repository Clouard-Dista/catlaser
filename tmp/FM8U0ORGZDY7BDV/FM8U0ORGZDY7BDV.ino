#include <Arduino.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#define MOTOR01 D5
#define MOTOR02 D6

Servo vert; 
Servo hor;

void setup() { 
  Serial.begin(9600);
  vert.attach(MOTOR01);
  hor.attach(MOTOR02); 
}

void migrate(Servo &myServo, int newPos) {
  int wait=random(30,60); //randomize the wait to make it more interesting
  int pos = myServo.read(); //Read the current servo position
  if (pos < newPos) { 
    for (int i=pos; i < newPos; i++) {
      myServo.write(i);
      delay(wait); 
    }
  } else { 
    for (int i=pos; i > newPos; i--) { 
      myServo.write(i);
      delay(wait);
    }
  }
}
    
  
void randomPosition() {
  int rand=random(40,120); //The range is limited to 60 deg for better cat action
  migrate(hor, rand);
  
  rand=random(90,135); //The vertical range is limited to 45 deg also for better cat action. 
  migrate(vert, rand);
}
   
void loop() { 
  randomPosition();
  delay(2000);
}
