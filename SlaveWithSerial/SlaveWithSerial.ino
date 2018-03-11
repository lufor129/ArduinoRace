#include<Servo.h>
#include<SoftwareSerial.h>

#define rxpin 2
#define txpin 3

Servo servo1;

SoftwareSerial mySerial=SoftwareSerial(rxpin,txpin);

void setup(){
  pinMode(rxpin,INPUT);
  pinMode(txpin,OUTPUT); 
  for(int i=8;i<13;i++){
    pinMode(i,OUTPUT);
  }
  servo1.attach(4);
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop(){
  char val;
  if(mySerial.available()){
  val=computerinput();
  Serial.write(val);
  }

  if(val=='a'){
    turn();
  }
  else
  back();
}



/*底下函數庫  */
char computerinput(){
  while(mySerial.available())
  return mySerial.read();
}

void bright(){
  for(int i=8;i<13;i++)
  digitalWrite(i,HIGH);
  delay(2000);
}

void extinguish(){
  for(int i=8;i<13;i++)
  digitalWrite(i,LOW);
}

void turn(){
  extinguish();
  delay(2000);
  for(int angle=0;angle<=15;angle+=3){
  servo1.write(angle);
  bright();
  extinguish();
  delay(2000);
  }
  back();
}

void back(){
  extinguish();
  servo1.write(0);
}
