#include <Servo.h>
#include <Arduino.h>

// Initialize servo objects for each servo
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

void setup() {
  // Attach the servos to their respective pins

  servo1.attach(0,1100,5100); //right bot
  servo2.attach(2); //right mid
  servo3.attach(4); // right top
  servo4.attach(7); //left bot
  servo5.attach(10); //left mid
  servo6.attach(12); // left top
}

void loop() {
  // Move each servo to a different position
  servo1.write(85);
  servo2.write(0);
  servo3.write(45);
  servo4.write(180);
  servo5.write(180);
  servo6.write(105);
  // for(int i = 0; i<90; i++){
  //   servo3.write(i);
  //     delay(20);
  // }

  // 85 0 45 180 180 105
  // 

  // Wait for a second before moving the servos again

}
