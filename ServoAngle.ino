//find servo pulse when using servo board 
// use Adafruit servo board, the servo is on channel 0 
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver myServo = Adafruit_PWMServoDriver(0x40); 
#define SERVOMIN 80 //from 80 to 600
#define SERVOMAX 600
int pulselength;
uint8_t servonum = 0; //servo location on servo board
void setup() {
  Serial.begin(9600);
  myServo.begin();
  myServo.setPWMFreq(60);
  pulselength = int (map(90, 0, 180, SERVOMIN, SERVOMAX));//convert 
  myServo.setPWM(servonum, 0, pulselength);//initial angle 90 degree
  delay(10);
  Serial.println("Input an angle between 0 and 180 degree  > "); 
}
void loop() {
  while (Serial.available()){
    int angle = Serial.parseInt();
    pulselength = int (map(angle, 0, 180, SERVOMIN, SERVOMAX));
    if (pulselength >= 80 && pulselength <= 600){
      myServo.setPWM(servonum, 0, pulselength);
      Serial.println("> turning servo to "+ String(angle) +" degrees");
      Serial.println("Input an angle between 0 and 180 degree  > ");
    }
  }
}
