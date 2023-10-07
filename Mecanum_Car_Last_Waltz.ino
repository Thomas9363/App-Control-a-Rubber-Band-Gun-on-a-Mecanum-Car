// The last waltz
//MEGA motor pin
int enPin = 8;
int dirPin1 = 5;
int stepPin1 = 2;
int dirPin2 = 6;
int stepPin2 = 3;
int dirPin3 = 7;
int stepPin3 = 4;
int dirPin4 = 13;
int stepPin4 = 12;
int t=600;
int t00=t/4,t0=t/2,t1=1*t,t2=2*t,t3=3*t;
int t4=4*t,t5=5*t,t6=6*t, t7=7*t, t8=8*t;
int tp=50;
int b00=4048;
int c0=3821,cf0=3607,d0=3405,df0=3213,e0=3033,f0=2863;
int ff0=2701,g0=2551,gf0=2407,a0=2272,af0=2145,b0=2024;
int c=1910,cf=1803,d= 1702,df=1606,e=1516,f=1431;
int ff=1350,g= 1275,gf=1203,a=1136,af=1072,b=1012;
int c1=955,cf1=901,d1=851,df1=803,e1=758,f1=715;
int ff1=675,g1= 637,gf1=601,a1=568,af1=536, b1=506;
int c2=477,cf2=450,d2=425,df2=401,e2=379,f2=357;
int ff2=337,g2= 318,gf2=300,a2=284,af2=268, b2=253;


int coun;
bool dir=0;
int del;
int tempo=200;

void setup() {
  Serial.begin (9600);
  pinMode(enPin, OUTPUT); // set all the motor control pins to outputs
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin3, OUTPUT);
  pinMode(stepPin3, OUTPUT);
  pinMode(dirPin4, OUTPUT);
  pinMode(stepPin4, OUTPUT);
}//end setup

void loop() {
//line1
pa(tp*3);
note(e,t0);
note(ff,t0+t1);
note(e,t0);
note(ff,t0+t1);
note(e,t0);

note(ff,t3);
note(d1,t1);
note(b,t1);
note(ff,t1);

note(e,t6+t4);

//note(e,t4);
pa(tp);  

//line2
pa(tp);
note(b0,t0);
note(d,t0+t1);
note(b,t0);
note(d,t0+t1);
note(b,t0);

note(b,t3);
note(a,t1);
note(ff,t1);
note(e,t1);

note(ff,t6+t4);

//note(ff,t4);
pa(tp);
note(e,t1);

note(ff,t0+t1);
note(e,t0);
note(ff,t0+t1);
note(e,t0);
note(ff,t0+t1);
note(e,t0); 

//line3
note(ff,t3);
note(d1,t1);
note(b,t1);
note(ff,t1);

note(e,t6+t4);

//note(e,t4);
pa(tp);

pa(tp);
note(b,t0);
note(d,t0+t1);
note(b,t0);
note(d,t0+t1);
note(b,t0);

note(b,t2);
note(a,t2);
note(cf,t2);

note(d,t6);

note(a,t2);
note(b,t2);
note(cf,t2);

//line4
note(d1,t6);

note(cf1,t4);
note(a,t2);

note(b,t6);

note(b,t6);

note(cf1,t2);
note(cf1,t3);
note(cf1,t1);

note(cf1,t2);
note(b,t3);
note(a,t1);

note(gf,t1);
note(b,t1);
note(a,t4);

note(a,t6); 

//line5
note(ff1,t6);

note(e1,t4);
note(d1,t2);

note(e1,t4);
note(d1,t2);

note(e,t4);
pa(tp);
note(g,t1);

note(b,t6);
// note(b,t3);
// note(b,t1);

note(a,t4);
pa(tp);
note(cf,t5);

note(d,t2);

pa(tp); 

//line6
note(cf,t2);
note(d,t4);

pa(tp);
pa(tp);
note(c1,t1);
note(d1,t1);

note(e1,t4);
note(d1,t2);

note(b,t4);
note(cf1,t1);
note(d1,t1);

note(e1,t4);
note(d1,t2);

note(af,t1);
note(cf1,t1);
note(b,t1);

note(a,t4);
note(a,t1);
note(a,t1); 

//line7
note(b,t2);
note(cf1,t2);
note(d1,t2);

note(ff1,t6);

note(e1,t6);

note(ff,t0+t1);
note(e,t0);
note(ff,t0+t1);
note(e,t0);
note(ff,t2);

note(d1,t2);
note(b,t2);
note(ff,t2);

note(e,t6+t6);

note(d,t0+t1);
note(b,t0);
note(d,t0+t1);
note(b,t0);
note(d,t2); 

//line8
note(b,t2);
note(a,t2);
note(cf,t2);

note(d,t6);

note(a,t2);
note(b,t2);
note(cf1,t2);  

//line9
note(cf,t2);
note(d,t4);

pa(2*tp);

note(ff,t0+t1);
note(e,t0);
note(ff,t0+t1);
note(e,t0);
note(ff,t2);

note(d1,t2);
note(b,t2);
note(ff,t2);

note(e,t6);

}//end loop
void note(int num,long dur) {
/*  dir=!dir;
  digitalWrite(dirPin1,dir);
  digitalWrite(dirPin2,dir);
  digitalWrite(dirPin3,dir);
  digitalWrite(dirPin4,dir);*/
  digitalWrite(dirPin1,random(0, 2));
  digitalWrite(dirPin2,random(0, 2));
  digitalWrite(dirPin3,random(0, 2));
  digitalWrite(dirPin4,random(0, 2));
  coun=floor((dur*tempo)/num);
//  int randNumber = random(0, 2);
//  Serial.println (randNumber);
  for(int x = 0; x < coun; x++) {
    digitalWrite(stepPin1,HIGH);
    digitalWrite(stepPin2,HIGH);
    digitalWrite(stepPin3,HIGH);
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(num);
    digitalWrite(stepPin1,LOW);
    digitalWrite(stepPin2,LOW);
    digitalWrite(stepPin3,LOW);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(num);
  }
}

void pa(int durp){
  int ker=floor(durp/100)*tempo;
  delay(ker);
  }
