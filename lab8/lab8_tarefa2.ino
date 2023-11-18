#define DC_MOTOR 10
#define ON_OFF 6

void setup(){
  pinMode (DC_MOTOR, OUTPUT);
  pinMode(ON_OFF, INPUT_PULLUP);
}

void loop(){
  if(digitalRead(ON_OFF) == LOW){
    analogWrite(DC_MOTOR, 255);//5v no motor
  }
  else{
    analogWrite(DC_MOTOR, 0);
  }
}