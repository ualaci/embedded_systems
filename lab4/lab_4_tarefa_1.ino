// C++ code
//
void setup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available()) {
	char data_rcvd = Serial.read();
    if (data_rcvd == '1') digitalWrite(13, HIGH);
    if (data_rcvd == '0') digitalWrite(13, LOW);
  }
  if (digitalRead(2) == HIGH) Serial.write('0');
  else Serial.write('1');
}