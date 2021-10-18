#include<Servo.h> // Servo 라이브러리  추가
Servo servo;      // Servo 클래스로 servo객체 생성
int   value = 0;  // 각도를 조절할 변수 value

void setup() {
  servo.attach(7);    // 멤버함수인 attach : 핀 설정
  Serial.begin(9600); // 시리얼 모티너 사용
}

void loop() {
  if(Serial.available())    // 시리얼 모니터에 데이터가 입력되면
  {
    char in_data;            // 입력된 데이터를 담을 변수 in_data
    in_data = Serial.read(); // 시리얼모티너로 입력된 데이터 in_data로 저장
    if(in_data=='1')
    {
      value +=10;           // 각도를 10도 증가
      if(value == 180)      // 각도가 180도가 되면
        value=0;
    }
    else                    // 그외의 데이터가 입력되면
      value=0;              // 각도를 0으로 초기화

    servo.write(value); // value값의 각도로 회전
  }
}
