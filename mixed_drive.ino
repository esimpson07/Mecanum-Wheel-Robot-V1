#include <Servo.h>

int tolerance = 10;

int maxspeed = 255;
int minspeed = 100;
int absoluteminspeed = 70;
long currentTime = 0;
long pastTime = 0;
int pastTimeLong = 0;
int delayTime = 4000;
int driveTime = 2000;
int i = 0;

int motor1_ena = 2;
int motor1_enb = 3;
int motor1_in1 = 24;
int motor1_in2 = 25;
int motor1_in3 = 22;
int motor1_in4 = 23;

int motor2_ena = 4;
int motor2_enb = 5;
int motor2_in1 = 28;
int motor2_in2 = 29;
int motor2_in3 = 26;
int motor2_in4 = 27;

int mFL = 0;
int mFR = 0;
int mBL = 0;
int mBR = 0;

int mFLtarget = 90;
int mFRtarget = 90;
int mBLtarget = 90;
int mBRtarget = 90;

int ogmFLtarget = 90;
int ogmFRtarget = 90;
int ogmBLtarget = 90;
int ogmBRtarget = 90;

bool serFlag = 0;
int leftSpeed = 0;
int rightSpeed = 0;
int midSpeed = 120;
int newPastTime = 0;
int xfc = 0;

void newStrRead(){
  
}

void mFLdrive(){
  if (mFL > 0){
    digitalWrite( motor1_in1, HIGH);
    digitalWrite( motor1_in2, LOW);
    analogWrite( motor1_ena, abs(mFL));
  } else if (mFL < 0){
    digitalWrite( motor1_in1, LOW);
    digitalWrite( motor1_in2, HIGH);
    analogWrite( motor1_ena, abs(mFL));
  } else if (mFL == 0){
    digitalWrite( motor1_in1, LOW);
    digitalWrite( motor1_in2, LOW);
  }
}

void mFRdrive(){
  if (mFR > 0){
    digitalWrite( motor1_in3, LOW);
    digitalWrite( motor1_in4, HIGH);
    analogWrite( motor1_enb, abs(mFR));
  } else if (mFR < 0){
    digitalWrite( motor1_in3, HIGH);
    digitalWrite( motor1_in4, LOW);
    analogWrite( motor1_enb, abs(mFR));
  } else if (mFR == 0){
    digitalWrite( motor1_in3, LOW);
    digitalWrite( motor1_in4, LOW);
  }
}

void mBLdrive(){
  if (mBL > 0){
    digitalWrite( motor2_in3, HIGH);
    digitalWrite( motor2_in4, LOW);
    analogWrite( motor2_enb, abs(mBL));
  } else if (mBL < 0){
    digitalWrite( motor2_in3, LOW);
    digitalWrite( motor2_in4, HIGH);
    analogWrite( motor2_enb, abs(mBL));
  } else if (mBL == 0){
    digitalWrite( motor2_in3, LOW);
    digitalWrite( motor2_in4, LOW);
  }
}

void mBRdrive(){
  if (mBR > 0){
    digitalWrite( motor2_in1, LOW);
    digitalWrite( motor2_in2, HIGH);
    analogWrite( motor2_ena, abs(mBR));
  } else if (mBR < 0){
    digitalWrite( motor2_in1, HIGH);
    digitalWrite( motor2_in2, LOW);
    analogWrite( motor2_ena, abs(mBR));
  } else if (mBR == 0){
    digitalWrite( motor2_in1, LOW);
    digitalWrite( motor2_in2, LOW);
  }
}

void const_loop(){
  currentTime = millis();#include <Servo.h>
#define blockSeparator "|"
#define dataSeparator "="
#define outputA1 10
#define outputB1 33
#define outputA2 11
#define outputB2 32
#define outputA3 12
#define outputB3 31
#define outputA4 13
#define outputB4 30

//s1=180|s2=180|s3=180|s4=180
//s1=90|s2=90|s3=90|s4=90
//s1=0|s2=0|s3=0|s4=0
//MFL=255|MFR=255|MBL=255|MBR=255
//MFL=-255|MFR=-255|MBL=-255|MBR=-255
//MFL=0|MFR=0|MBL=0|MBR=0
//MFL=255|MFR=255|MBL=255|MBR=255|EFL=400|EFR=400|EBL=400|EBR=400
//MFL=100|MFR=100|MBL=100|MBR=100|EFL=400|EFR=400|EBL=400|EBR=400

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

String str;
String sub;
String cmd;
String value;

int s1pos = 90;
int s2pos = 90;
int s3pos = 90;
int s4pos = 90;

int counter1 = 0; 
int aState1;
int aLastState1;  
int counter2 = 0; 
int aState2;
int aLastState2; 
int counter3 = 0; 
int aState3;
int aLastState3;  
int counter4 = 0; 
int aState4;
int aLastState4; 
int stateFlag = false;

int ogcounter1 = 0;
int ogcounter2 = 0;
int ogcounter3 = 0;
int ogcounter4 = 0;

int eFLtarget = 90;
int eFRtarget = 90;
int eBLtarget = 90;
int eBRtarget = 90;

int tolerance = 10;

int maxspeed = 255;
int minspeed = 100;
int absoluteminspeed = 70;
long currentTime = 0;
long pastTime = 0;
int pastTimeLong = 0;
int delayTime = 2000;
int driveTime = 2000;
int i = 0;

int motor1_ena = 2;
int motor1_enb = 3;
int motor1_in1 = 24;
int motor1_in2 = 25;
int motor1_in3 = 22;
int motor1_in4 = 23;

int motor2_ena = 4;
int motor2_enb = 5;
int motor2_in1 = 28;
int motor2_in2 = 29;
int motor2_in3 = 26;
int motor2_in4 = 27;

int mFL = 0;
int mFR = 0;
int mBL = 0;
int mBR = 0;

int mFLtarget = 90;
int mFRtarget = 90;
int mBLtarget = 90;
int mBRtarget = 90;

int ogmFLtarget = 90;
int ogmFRtarget = 90;
int ogmBLtarget = 90;
int ogmBRtarget = 90;

bool serFlag = 0;
int leftSpeed = 0;
int rightSpeed = 0;
int midSpeed = 120;
int newPastTime = 0;
int xfc = 0;

void split_behavior(String subset) {
  int subIndex = str.indexOf(dataSeparator);

  if (subIndex >= 0) {
    cmd = subset.substring(0, subIndex);
    cmd.toUpperCase();
    value = subset.substring(subIndex + 1, subset.length());

    if (cmd == "XFC"){
      xfc = value.toInt();
      serFlag = true;
    } else if (cmd == "S1") {
      s1pos = value.toInt();
    } else if (cmd =="S2") {
      s2pos = value.toInt();
    } else if (cmd =="S3") {
      s3pos = value.toInt();
    } else if (cmd =="S4") {
      s4pos = value.toInt();
    } else if (cmd =="MFL") {
      mFLtarget = value.toInt();
      ogmFLtarget = mFLtarget;
    } else if (cmd =="MFR") {
      mFRtarget = value.toInt();
      ogmFRtarget = mFRtarget;
    } else if (cmd =="MBL") {
      mBLtarget = value.toInt();
      ogmBLtarget = mBLtarget;
    } else if (cmd =="MBR") {
      mBRtarget = value.toInt();
      ogmBRtarget = mBRtarget;
    } else if (cmd =="EFL") {
      eFLtarget = value.toInt();
    } else if (cmd =="EFR") {
      eFRtarget = value.toInt();
    } else if (cmd =="EBL") {
      eBLtarget = value.toInt();
    } else if (cmd =="EBR") {
      eBRtarget = value.toInt();
    }
  }
}

void string_in() {
  if (Serial.available() > 0) {
    str = Serial.readString();    
    
    int index = 0;
    int next = str.indexOf(blockSeparator, index);
    
    while (next >= 0) {
      sub = str.substring(index, next);
      split_behavior(sub);

      index = next + 1;
      next = str.indexOf(blockSeparator, index);
    }

    sub = str.substring(index, str.length());
    split_behavior(sub);
  }
}

void newStr(){
  if (Serial.available() > 0) {
    str = Serial.readString();
    xfc = str.toInt();
    serFlag = true;
    Serial.println(xfc);
  } else (){
    str = "";
  }
}

void mFLdrive(){
  if (mFL > 0){
    digitalWrite( motor1_in1, HIGH);
    digitalWrite( motor1_in2, LOW);
    analogWrite( motor1_ena, abs(mFL));
  } else if (mFL < 0){
    digitalWrite( motor1_in1, LOW);
    digitalWrite( motor1_in2, HIGH);
    analogWrite( motor1_ena, abs(mFL));
  } else if (mFL == 0){
    digitalWrite( motor1_in1, LOW);
    digitalWrite( motor1_in2, LOW);
  }
}

void mFRdrive(){
  if (mFR > 0){
    digitalWrite( motor1_in3, LOW);
    digitalWrite( motor1_in4, HIGH);
    analogWrite( motor1_enb, abs(mFR));
  } else if (mFR < 0){
    digitalWrite( motor1_in3, HIGH);
    digitalWrite( motor1_in4, LOW);
    analogWrite( motor1_enb, abs(mFR));
  } else if (mFR == 0){
    digitalWrite( motor1_in3, LOW);
    digitalWrite( motor1_in4, LOW);
  }
}

void mBLdrive(){
  if (mBL > 0){
    digitalWrite( motor2_in3, HIGH);
    digitalWrite( motor2_in4, LOW);
    analogWrite( motor2_enb, abs(mBL));
  } else if (mBL < 0){
    digitalWrite( motor2_in3, LOW);
    digitalWrite( motor2_in4, HIGH);
    analogWrite( motor2_enb, abs(mBL));
  } else if (mBL == 0){
    digitalWrite( motor2_in3, LOW);
    digitalWrite( motor2_in4, LOW);
  }
}

void mBRdrive(){
  if (mBR > 0){
    digitalWrite( motor2_in1, LOW);
    digitalWrite( motor2_in2, HIGH);
    analogWrite( motor2_ena, abs(mBR));
  } else if (mBR < 0){
    digitalWrite( motor2_in1, HIGH);
    digitalWrite( motor2_in2, LOW);
    analogWrite( motor2_ena, abs(mBR));
  } else if (mBR == 0){
    digitalWrite( motor2_in1, LOW);
    digitalWrite( motor2_in2, LOW);
  }
}

void const_loop(){
  currentTime = millis();
  newStr();
}

void cvDrive(){
  while (true){
    const_loop();
    if (serFlag == true){
      leftSpeed = midSpeed + (0.4 * xfc);
      rightSpeed = midSpeed - (0.4 * xfc);
      mFL = leftSpeed;
      mFR = rightSpeed;
      mBL = leftSpeed;
      mBR = rightSpeed;
      mFLdrive();
      mFRdrive();
      mBLdrive();
      mBRdrive();
      newPastTime = currentTime;
      serFlag = false;
    }
    if (newPastTime < currentTime - delayTime) {
      mFL = 0;
      mFR = 0;
      mBL = 0;
      mBR = 0;
      mFLdrive();
      mFRdrive();
      mBLdrive();
      mBRdrive();
    }
  } 
}

void setup() {  
  pinMode( motor1_ena, OUTPUT);
  pinMode( motor1_enb, OUTPUT);
  pinMode( motor1_in1, OUTPUT);
  pinMode( motor1_in2, OUTPUT);
  pinMode( motor1_in3, OUTPUT);
  pinMode( motor1_in4, OUTPUT);
  pinMode( motor2_ena, OUTPUT);
  pinMode( motor2_enb, OUTPUT);
  pinMode( motor2_in1, OUTPUT);
  pinMode( motor2_in2, OUTPUT);
  pinMode( motor2_in3, OUTPUT);
  pinMode( motor2_in4, OUTPUT);
  Serial.begin(1000000);
  aLastState1 = digitalRead(outputA1);   
  aLastState2 = digitalRead(outputA2);   
  aLastState3 = digitalRead(outputA3);   
  aLastState4 = digitalRead(outputA4);
}

void loop(){
  const_loop();
  cvDrive();
}
