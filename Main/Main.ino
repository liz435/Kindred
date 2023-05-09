#include<Servo.h>
#include<Ramp.h>
#include<math.h>
#include <Arduino.h>

Servo left1;
Servo left2;
Servo leftTip;
Servo right1;
Servo right2;
Servo rightTip;
int duration = 500;
unsigned long timer  = 0;
unsigned long previous = 0;

int lastX;
int lastY;

class Dance {
  private:
 
  public:
    float xyPos[2];
    int angles[3];
    float radian1;
    float radian2;
    float radian3;

    int offsetLeft1 = - 50;
    int offsetLeft2 = 50;
    int offsentTip;

    void init(){
      left1.writeMicroseconds(1500 + offsetLeft1);
      left2.writeMicroseconds(1500 + offsetLeft2);
      leftTip.writeMicroseconds(1500);
      right1.writeMicroseconds(1500 );
      right2.writeMicroseconds(1500  );
      rightTip.writeMicroseconds(1500);
    }

    void calcPoint(){
      float xPos ;
      float yPos ;
      int leng = 10;
      xPos = cos(radian1)*10 + cos(radian1+radian2)*10 + cos(radian1+radian2+radian3)*5;
      yPos = sin(radian1)*10 + sin(radian1+radian2)*10 + sin(radian1+radian2+radian3)*5;
      Serial.print(xPos);
      Serial.print(',');
      Serial.println(yPos);
    }

    void receive(int x, int y, int z) {
      angles[0] = abs(x);
      angles[1] = abs(y);
      angles[2] = abs(z);

      radian1 = angles[0]*PI/180;
      radian2 = angles[1]*PI/180;
      radian3 = angles[2]*PI/180;
    }

};

class Interpolation {  
public:
    rampInt myRamp;
    int interpolationFlag = 0;
    int savedValue;    

    int go(int input, int duration) {

      if (input != savedValue) {   // check for new data
          interpolationFlag = 0;
      }
      savedValue = input;          // bookmark the old value  
    
      if (interpolationFlag == 0) {                                        // only do it once until the flag is reset
          myRamp.go(input, duration, LINEAR, ONCEFORWARD);              // start interpolation (value to go to, duration)
          interpolationFlag = 1;
      }
    
      int output = myRamp.update();               
      return output;
    }
}; 

Interpolation interpX;
Interpolation interpZ;

class DanceWithIt{
  private:
  public:
  DanceWithIt(){

  }

  void guess(){
    
  }
};
    Dance DanceNow;
void setup() {
  Serial.begin(9600);
  left1.attach(9);
  left2.attach(2);
  leftTip.attach(4);
  right1.attach(7);
  right2.attach(10);
  rightTip.attach(12);
  DanceNow.init();
}

void loop() {
  timer = millis();
    // int* array = DanceNow.convert();
    int rX = random(0,90);
    int rY = random(0,90);
    int rZ;

    int IX;
    int IY;

    left1.write(90);
    // left1.write(rX);
    // left2.write(90+rY);

  
    // lastX = abs(lastX - rX);
    // lastY = abs(lastY - rY);

    // duration = 1000;

    // while(millis() - timer <=duration){
    // IX = interpX.go(rX, duration);
    // IY = interpZ.go(rY, duration);
    // left1.write(IX);
    // left2.write(90+IY);
    // // Serial.print(500);
    // // Serial.print(',');
    // // Serial.print(IX);
    // // Serial.print(',');
    // // Serial.println(IY);
    // lastX = rX;
    // lastY = rY;
    // }

}