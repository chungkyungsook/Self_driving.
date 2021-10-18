#include <Servo.h>
 
Servo motor;
 
void setup() {
 
  motor.attach(7);                              
  motor.write(70); //ESC 대기 신호  
  delay(2500); //ESC의 준비 시간
 
}
 
void loop() {
 
  motor.write(100); //A
 
}
