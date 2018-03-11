#include<Servo.h>
#include<SoftwareSerial.h>

#define rxpin 2
#define txpin 3
const byte redlight=A3;
Servo servo1;
int red;

SoftwareSerial mySerial=SoftwareSerial(rxpin,txpin);

void setup(){
  pinMode(rxpin,INPUT);
  pinMode(txpin,OUTPUT); 
  pinMode(redlight,INPUT);
  for(int i=8;i<13;i++){
    pinMode(i,OUTPUT);
  }
  
  mySerial.begin(9600);
  Serial.begin(9600);
  servo1.attach(4);
}

void loop(){
  red=digitalRead(redlight);
  if(serialread()=='a'||red==HIGH){
    mySerial.write('a');
    turn();
  } 
  else 
  back();
}



/*底下函數庫  */
char serialread(){
  if(Serial.available()){
  delay(5);
  while(Serial.available())
  return Serial.read();
  }
  else
  return NULL;
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
  for(int angle=15;angle>=0;angle-=3){
  servo1.write(angle);
  bright();
  extinguish();
  delay(2000);
  }
  back();
}

void back(){
  extinguish();
  servo1.write(15);
}
