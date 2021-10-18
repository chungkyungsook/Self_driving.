#include <Servo.h>
Servo servo;
Servo throttle;

int motor = 7; // 서보모터 핀
int angle = 90; // 서보모터 초기 각도 값aa

int pos = 0;
int pin = 6;

void setup() {
  servo.attach(motor); // 서보모터 연결
  throttle.attach(pin);
  Serial.begin(9600); // 시리얼 모니터 시작

  Serial.println("모터 & 서보 모터 작동하기"); // 

   // ESC 작동을 위한 작업
   for (pos = 90; pos <= 100; pos += 1) { 
      throttle.write(pos);             
      delay(150);                       
   }
}

void loop() {
  if(Serial.available()){ // 시리얼모티너가 사용가능할때
    char input = Serial.read(); // 문자 입력받기

    // a,d : 차량 각도 증가, 감소
    // w,s : 차량 속도 증가, 감소
    if(input=='a'){
      Serial.print("+10");
      // 현 각도에 +10
      for(int i=0; i<10; i++){ 
        angle=angle+1;
        if(angle>=150) // 각도가 150이상이면 값 고정
          angle = 150;

        servo.write(angle);
        delay(10);
      }
      Serial.print("현 각도:");
      Serial.println(angle); 
    }
    else if(input=='d'){
      Serial.print("-10");
      // 현 각도에 -10
      for(int i=0;i<10;i++){
        angle = angle -1;
        if(angle<=35) // 각도가 35이하면 값 고정
          angle=35;
        servo.write(angle);
        delay(10);
      }
      Serial.print("현 각도:");
      Serial.println(angle);
     }
     else if(input=='w'){
        pos += 1;  // 현재 속도 1씩 증가
        Serial.print("현재 속도: ");
        Serial.println(pos); 
        throttle.write(pos);
        delay(100);

      }
      else if(input=='s'){
        pos -= 1;  // 현재 속도 1씩 감소
        Serial.print("현재 속도 : ");
        Serial.println(pos); 
        throttle.write(pos);
        delay(100);
      }

  }
}
