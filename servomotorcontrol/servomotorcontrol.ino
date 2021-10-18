#include <Servo.h>
Servo servo;

int motor = 7; // 서보모터 핀
int angle = 90; // 서보모터 초기 각도 값
void setup() {
  servo.attach(motor); // 서보모터 연결
  Serial.begin(9600); // 시리얼 모니터 시작

  Serial.println("entter the u or d"); // u or d키 입력하기
  Serial.println("u=angle+15"); 

  Serial.println("d=angle-15\n");
}

void loop() {
  if(Serial.available()){ // 시리얼모티너가 사용가능할때
    char input = Serial.read(); // 문자 입력받기

    if(input=='u'){
      Serial.print("+15");
      for(int i=0; i<15; i++){ // 현 각도에 +15
        angle=angle+1;
        if(angle>=150)
          angle = 90;

        servo.write(angle);
        delay(10);
      }
      Serial.print("\t\t");
      Serial.print(angle);    // 현각도 출력
    }
    else if(input=='d'){
      Serial.print("\t-15\t");
      for(int i=0;i<15;i++){
        angle = angle -1;
        if(angle<=35)
          angle=90;
        servo.write(angle);
        delay(10);
      }
      Serial.println(angle);
    }
    else{
      Serial.println("wrong character!!");
    }
  }
}
