#include <SPI.h>
// Slave
// C++ code

volatile boolean flag;
volatile char data_rcvd;

void setup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  pinMode(MISO, OUTPUT);
  SPI.attachInterrupt();
  SPCR |= _BV(SPE);
  flag = false;
  
  digitalWrite(13, LOW);
}

ISR (SPI_STC_vect) 
{
  data_rcvd = SPDR;
  flag = true;
}

void loop()
{
  if (flag) {
    if (data_rcvd == '1') {
      digitalWrite(13, HIGH);
    }
    if (data_rcvd == '0') {
      digitalWrite(13, LOW);
    }
    flag = false;
  }
  
  if (digitalRead(2) == HIGH){
    SPDR = '0';
  }
  else {
    SPDR = '1';
  }
}

