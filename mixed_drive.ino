int maxspeed = 255;
int minspeed = 100;
int absoluteminspeed = 70;
long currentTime = 0;
long pastTime = 0;
int pastTimeLong = 0;
int delayTime = 1500;
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

String str = "";
long newCurrentTime = 0;
long newPastTime = 0;
bool serFlag = 0;
int leftSpeed = 0;
int rightSpeed = 0;
int midSpeed = 120;
int xfc = 0;
int timeTimes = 0;

void newStr(){
  if (Serial.available() > 0) {
    str = Serial.readString();
    xfc = str.toInt();
    newPastTime = currentTime;
    serFlag = true;
  } else {
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
  newCurrentTime = millis();
  newStr();
}

void cvDrive(){
  while (true){
    const_loop();
    if (serFlag == true){
      leftSpeed = midSpeed + (0.4 * xfc);
      rightSpeed = midSpeed - (0.4 * xfc);
      if (leftSpeed < 0){
        leftSpeed = 0;
      } else if (rightSpeed < 0){
        rightSpeed = 0;
      }
      mFL = leftSpeed;
      mFR = rightSpeed;
      mBL = leftSpeed;
      mBR = rightSpeed;
      mFLdrive();
      mFRdrive();
      mBLdrive();
      mBRdrive();
      newPastTime = newCurrentTime;
      serFlag = false;
    }
    if (newPastTime < (newCurrentTime - delayTime)) {
      mFL = 0;
      mFR = 0;
      mBL = 0;
      mBR = 0;
      mFLdrive();
      mFRdrive();
      mBLdrive();
      mBRdrive();
      newPastTime = newCurrentTime;
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
  Serial.begin(115200);
}

void loop(){
  const_loop();
  cvDrive();
}
