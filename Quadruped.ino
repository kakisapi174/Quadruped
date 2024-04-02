#include <Servo.h>

Servo servo1;  
Servo servoA;
Servo servo2;
Servo servoB;
Servo servo3;
Servo servoC;
Servo servo4;
Servo servoD;

void setup() {

  Serial.begin (9600);

  servo1.attach(3); 
  servoA.attach(2);
  servo2.attach(9);
  servoB.attach(8);
  servo3.attach(5);
  servoC.attach(4);
  servo4.attach(7);
  servoD.attach(6);
}

void Idle () {
  //IDLE, posisi berdiri doang
  servo1.write(90);
  servo2.write(0);
  servo3.write(0);
  servo4.write(90);

  servoA.write(40);
  servoB.write(40);
  servoC.write(40);
  servoD.write(40);
}

void Down(){
  //turun
  servo1.write(45);
  servo2.write(45);
  servo3.write(45);
  servo4.write(45);

  servoA.write(40);
  servoB.write(40);
  servoC.write(40);
  servoD.write(40);
}

void Emote(){
  //"emote
  servo1.write(15);
  servo2.write(80);
  servo3.write(80);
  servo4.write(10);

  servoA.write(0);
  servoB.write(80);
  servoC.write(80);
  servoD.write(0);
}

void forward(unsigned int step){  //jalan maju
  while (step-- > 0){
  servo3.write(30);
  servo2.write(30);
  delay(200);
  servoC.write(0);
  servoB.write(80);
  servoD.write(40);
  servoA.write(40);
  delay(200);
  servo3.write(0);
  servo2.write(0);
  Idle();
  
  servo4.write(60);
  servo1.write(60);
  delay(200);
  servoC.write(40);
  servoB.write(40);
  servoD.write(80);
  servoA.write(0);
  delay(200);
  servo4.write(90);
  servo1.write(90);
  Idle();
  }
}

void backward(unsigned int step){
  while (step-- > 0){
  servo3.write(30);
  servo2.write(30);
  delay(200);
  servoC.write(80);
  servoB.write(0);
  servoD.write(40);
  servoA.write(40);
  delay(200);
  servo3.write(0);
  servo2.write(0);
  Idle();
  
  servo4.write(60);
  servo1.write(60);
  delay(200);
  servoC.write(40);
  servoB.write(40);
  servoD.write(0);
  servoA.write(80);
  delay(200);
  servo4.write(90);
  servo1.write(90);
  Idle();
  }  
}

void right(unsigned int step){
  while (step-- > 0){
  servo3.write(30);
  servo2.write(30);
  delay(200);
  servoC.write(0);
  servoB.write(0);
  servoD.write(40);
  servoA.write(40);
  delay(200);
  servo3.write(0);
  servo2.write(0);
  Idle();
  
  servo4.write(60);
  servo1.write(60);
  delay(200);
  servoC.write(40);
  servoB.write(40);
  servoD.write(0);
  servoA.write(0);
  delay(200);
  servo4.write(90);
  servo1.write(90);
  Idle();
  }  
}

void left(unsigned int step){
  while (step-- > 0){
  servo3.write(30);
  servo2.write(30);
  delay(200);
  servoC.write(80);
  servoB.write(80);
  servoD.write(40);
  servoA.write(40);
  delay(200);
  servo3.write(0);
  servo2.write(0);
  Idle();
  
  servo4.write(60);
  servo1.write(60);
  delay(200);
  servoC.write(40);
  servoB.write(40);
  servoD.write(80);
  servoA.write(80);
  delay(200);
  servo4.write(90);
  servo1.write(90);
  Idle();
  } 
}

void loop() {
  if (Serial.available()){
    char Direction = Serial.read();
    Serial.print(Direction);
    if (Direction == 'F'){
        forward(5);
        delay(2000);
    }
    else if (Direction == 'B'){
      backward(5);
      delay(2000);
    }
    else if (Direction == 'L'){
      left(5);
      delay(2000);
    }
    else if (Direction == 'R'){
      right(5);
      delay(2000);
    }
    else if (Direction == 'D'){
      Down();
      delay(2000);
    }
    else if (Direction == 'E'){
      Emote();
      delay(2000);
    }
    else if (Direction == 'I'){
        Idle();
        delay(3000);
    }
  }
}
