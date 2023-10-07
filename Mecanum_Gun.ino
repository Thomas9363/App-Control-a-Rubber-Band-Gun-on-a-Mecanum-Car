//mega (RX,TX)> (0,1), (19,18), (17,16), (15, 14)
#include <AccelStepper.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver myServo = Adafruit_PWMServoDriver(0x40); 
int pulsePan=370; //initial position
int pulseTilt=335; 
int pulseFire=0; 
uint8_t servoPan = 0;
uint8_t servoTilt = 1;
uint8_t servoFire = 2;

AccelStepper LB_Motor(1, 2, 5);
AccelStepper LF_Motor(1, 3, 6);
AccelStepper RB_Motor(1, 4, 7);
AccelStepper RF_Motor(1, 12, 13);

int bullet=0;
bool bulletState=false; 
#define EN 8
#define Laser 49 
int MotorSpeed = 1500, MaxSpeed=4000;
//------------------------------
void setup(){   /****** SETUP: RUNS ONCE ******/
  Serial1.begin(38400);
  Serial.begin(9600);
  pinMode(Laser, OUTPUT);
  pinMode (EN, OUTPUT);
  myServo.begin();
  myServo.setPWMFreq(60);
  myServo.setPWM(servoPan, 0, pulsePan); 
  myServo.setPWM(servoTilt, 0, pulseTilt); 
  myServo.setPWM(servoFire, 0, pulseFire); 
  delay(10); 
  LB_Motor.setEnablePin(EN);// Set the enable pin for the LB_Motor stepper motor
  LB_Motor.setPinsInverted(false, false, true); //Set the pins inversion for LB motor
  LB_Motor.setMaxSpeed(MaxSpeed);//Set the maximum speed of the LB_Motor stepper motor
  LB_Motor.setSpeed(0); // Set the speed of the LB_Motor stepper motor to stop
  LB_Motor.enableOutputs();//allows the motor to receive commands and move
  LF_Motor.setEnablePin(EN);
  LF_Motor.setPinsInverted(false, false, true);
  LF_Motor.setMaxSpeed(MaxSpeed);
  LF_Motor.setSpeed(0);  
  LF_Motor.enableOutputs();
  RB_Motor.setEnablePin(EN);
  RB_Motor.setPinsInverted(false, false, true);
  RB_Motor.setMaxSpeed(MaxSpeed);
  RB_Motor.setSpeed(0);  
  RB_Motor.enableOutputs();
  RF_Motor.setEnablePin(EN);
  RF_Motor.setPinsInverted(false, false, true);
  RF_Motor.setMaxSpeed(MaxSpeed);
  RF_Motor.setSpeed(0);  
  RF_Motor.enableOutputs();
}
//------------------------------
void loop(){
  if (Serial1.available() > 0) {
    char val = Serial1.read();
     switch(val){
     case 'A': MotorSpeed=1500; break;
     case 'B': leftforward();break;
     case 'C': forward(); Serial.println("forward"); break;
     case 'D': rightforward ();break;
     case 'E': MotorSpeed=3000; break;
     case 'F': left();  break;
     case 'G': sstop(); break;
     case 'H': right(); break;
     case 'I': counterclockwise();break;
     case 'J': leftbackward();break;
     case 'K': backward();  break;
     case 'L': rightbackward();break;
     case 'M': clockwise();break;
     case 'N': gunup(); break;
     case 'O': laser(); Serial.println("laser"); break;
     case 'P': gunleft(); break;      
     case 'Q': break;
     case 'R': gunright(); break;      
     case 'S': fire(); break;
     case 'T': gundown(); break;
     default: 
     Serial.println(" other button   ");
     }// End Case   
   }
  LB_Motor.runSpeed(); 
  LF_Motor.runSpeed();
  RB_Motor.runSpeed();
  RF_Motor.runSpeed(); 
}
//------------------------------
void forward(){
  LB_Motor.setSpeed(-MotorSpeed);
  LF_Motor.setSpeed(-MotorSpeed);
  RB_Motor.setSpeed(MotorSpeed);
  RF_Motor.setSpeed(MotorSpeed);
  delay(100);
}//end forward
//------------------------------
void backward(){
  LB_Motor.setSpeed(MotorSpeed);
  LF_Motor.setSpeed(MotorSpeed);
  RB_Motor.setSpeed(-MotorSpeed);
  RF_Motor.setSpeed(-MotorSpeed);
  delay(100);
}//end backward
//------------------------------
void right(){
  LB_Motor.setSpeed(MotorSpeed);
  LF_Motor.setSpeed(-MotorSpeed);
  RB_Motor.setSpeed(MotorSpeed);
  RF_Motor.setSpeed(-MotorSpeed);
  delay(100);
}//end right
//------------------------------
void left(){
  LB_Motor.setSpeed(-MotorSpeed);
  LF_Motor.setSpeed(MotorSpeed);
  RB_Motor.setSpeed(-MotorSpeed);
  RF_Motor.setSpeed(MotorSpeed);  
  delay(100);
}//end left
//------------------------------
void rightbackward(){
  LB_Motor.setSpeed(MotorSpeed);
  LF_Motor.setSpeed(0);
  RB_Motor.setSpeed(0);
  RF_Motor.setSpeed(-MotorSpeed);  
  delay(100);
}//end rightbackward
//------------------------------
void leftbackward(){
  LB_Motor.setSpeed(0);
  LF_Motor.setSpeed(MotorSpeed);
  RB_Motor.setSpeed(-MotorSpeed);
  RF_Motor.setSpeed(0);  
  delay(100);
}//end leftbackward
//------------------------------
void rightforward(){
  LB_Motor.setSpeed(0);
  LF_Motor.setSpeed(-MotorSpeed);
  RB_Motor.setSpeed(MotorSpeed);
  RF_Motor.setSpeed(0);
  delay(100);
}//end rightforward
//------------------------------
void leftforward(){
  LB_Motor.setSpeed(-MotorSpeed);
  LF_Motor.setSpeed(0);
  RB_Motor.setSpeed(0);
  RF_Motor.setSpeed(MotorSpeed);  
  delay(100);
}//end leftforward
//------------------------------
void counterclockwise(){
  LB_Motor.setSpeed(MotorSpeed);
  LF_Motor.setSpeed(MotorSpeed);
  RB_Motor.setSpeed(MotorSpeed);
  RF_Motor.setSpeed(MotorSpeed);
  delay(100);
}//end counterclockwise
//------------------------------
void clockwise(){
  LB_Motor.setSpeed(-MotorSpeed);
  LF_Motor.setSpeed(-MotorSpeed);
  RB_Motor.setSpeed(-MotorSpeed);
  RF_Motor.setSpeed(-MotorSpeed);  
  delay(100);
}//end clockwise
//------------------------------
void sstop(){
  LB_Motor.setSpeed(0);
  LF_Motor.setSpeed(0);
  RB_Motor.setSpeed(0);
  RF_Motor.setSpeed(0);
  delay(100);
}//end stop  
//------------------------------
void gunup(){
  pulseTilt=pulseTilt+2;    
  pulseTilt=constrain(pulseTilt, 310, 360);   
  myServo.setPWM(servoTilt, 0, pulseTilt);
}//end gunup  
//------------------------------
void gundown(){
  pulseTilt=pulseTilt-2;    
  pulseTilt=constrain(pulseTilt, 310, 360);   
  myServo.setPWM(servoTilt, 0, pulseTilt);
}//end gundown  
//------------------------------
void gunleft(){
  pulsePan=pulsePan+2;    
  pulsePan=constrain(pulsePan, 260, 480);   
  myServo.setPWM(servoPan, 0, pulsePan);
}//end gunleft  
//------------------------------
void gunright(){
  pulsePan=pulsePan-2;    
  pulsePan=constrain(pulsePan, 260, 480);   
  myServo.setPWM(servoPan, 0, pulsePan);
}//end gunright  
//------------------------------
void laser(){
  Serial.println("laser");
  digitalWrite(Laser, HIGH); 
  delay(1000); 
  digitalWrite(Laser, LOW); 
}//end laser  
//------------------------------
void fire(){
  if (bulletState==false) Serial.print("load state");
  else if (bulletState==true) Serial.print("fire state");
  if (bulletState==false){
    if (bullet==0) pulseFire=150;
    else if (bullet==1) pulseFire=250;
    else if (bullet==2) pulseFire=350;
    else if (bullet==3) pulseFire=460;     
    else if (bullet==4) pulseFire=580;
    if (bullet==4) bulletState=true;
    bullet=bullet+1;
  }
  else{
    bullet=bullet-1;
    if (bullet==4) pulseFire=460;
    else if (bullet==3) pulseFire=350;
    else if (bullet==2) pulseFire=250;
    else if (bullet==1) pulseFire=150;     
    else if (bullet==0) pulseFire=0;
    if (bullet==1) bulletState=false;
  }
  myServo.setPWM(servoFire, 0, pulseFire);
//  if (bulletState==false) Serial.print("load state");
//  else if (bulletState==true) Serial.print("fire state");
  Serial.print("   ");
  Serial.print(bullet-1);
  Serial.print("   ");
  Serial.println(pulseFire);  
}//end fire  
