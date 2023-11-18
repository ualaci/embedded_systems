#include <Wire.h>

// C++ code
//
void setup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Wire.begin();
}

void loop()
{
  Wire.requestFrom(8,1);
  while(Wire.available()) {
	char data_rcvd = Wire.read();
    if (data_rcvd == '1') digitalWrite(13, HIGH);
    if (data_rcvd == '0') digitalWrite(13, LOW);
  }
  Wire.beginTransmission(8);
  if (digitalRead(2) == HIGH) Wire.write('0');
  else Wire.write('1');
  Wire.endTransmission();
}