#define CLOCKWISE_CMD     3 //botão de comando para giro no sentido horário
#define ANTICLOCKWISE_CMD 4 //botao de comando para giro no sentido anti-horário
#define MOTOR_PIN1        5 //Pino2 do L293D
#define MOTOR_PIN2        6 //Pino 7 do L293D
#define ENABLE            7 //Pino 1 do L293D

void setup(){
  pinMode(CLOCKWISE_CMD, INPUT);
  pinMode(ANTICLOCKWISE_CMD, INPUT);
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
  pinMode(ENABLE, OUTPUT);
  digitalWrite(ENABLE, HIGH); //coloca nível alto em ENABLE para girar o motor
}

void loop(){
  if(digitalRead(CLOCKWISE_CMD) == HIGH){//checa o estado do botão
    //estabelece um sentido de giro para o motor
    digitalWrite(MOTOR_PIN1, LOW);
    digitalWrite(MOTOR_PIN2, HIGH);
  }
  else{
    //estabelece estado de repouso do motor (motor destravado)
    digitalWrite(MOTOR_PIN1, LOW);
    digitalWrite(MOTOR_PIN2, LOW);
  }
   if(digitalRead(ANTICLOCKWISE_CMD) == HIGH){//checa o estado do botão
    //estabelece um sentido de giro para o motor
    digitalWrite(MOTOR_PIN1, HIGH);
    digitalWrite(MOTOR_PIN2, LOW);
  }
  else{
    //estabelece estado de repouso do motor (motor destravado)
    digitalWrite(MOTOR_PIN1, LOW);
    digitalWrite(MOTOR_PIN2, LOW);
  }
}