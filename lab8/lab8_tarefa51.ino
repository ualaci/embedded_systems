#include <Stepper.h>
#define SPEED_ADJ A0

const int stepsPerRevolution = 400;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
int stepCount = 0;

void setup(){
}

void loop(){
  int ajuste_velocidade = analogRead(SPEED_ADJ);
  int velocidade_Motor = map(ajuste_velocidade, 0, 1023, 0, 200);
  if(velocidade_Motor > 0){
    myStepper.setSpeed(velocidade_Motor);
    myStepper.step(1);
    delay(2000);// esse atraso  varia conforme o tempo de resposta do motor
  }
}