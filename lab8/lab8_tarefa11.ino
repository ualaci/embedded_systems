#include <Servo.h>
#define CLOCKWISE 3
#define ANTICLOCKWISE 2

int posicao = 0;
Servo servo;

void setup(){
  Serial.begin(9600);
  servo.attach(7);
  pinMode(CLOCKWISE, INPUT);
  pinMode(ANTICLOCKWISE, INPUT);
  Serial.println(posicao);
}

void loop(){
  if(digitalRead(CLOCKWISE) == HIGH && posicao <= 180){
    posicao++;
    Serial.println("CLOCKWISE");
  }
  if(digitalRead(ANTICLOCKWISE) == HIGH && posicao >= 0){
    posicao--;
    Serial.println("ANTICLOCKWISE");
  }
  servo.write(posicao);
  Serial.println(posicao);
  delay(10);
}