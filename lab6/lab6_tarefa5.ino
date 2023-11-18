
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //pinos que serão utilizados no display

const int tempAlvo = A0;
const int tempAmb = A1;

void setup(){
  lcd.begin(16,2); //define numero de linhas e colunas no display
}

void scrollLeft (int passos){ //rolagem para a esquerda
  for (int posicao = 0; posicao < passos; posicao++){
    lcd.scrollDisplayLeft();
    delay (300);
  }
}

void scrollRight (int passos){
  for (int posicao = 0; posicao < passos; posicao++){
    lcd.scrollDisplayRight();
    delay(300);
  }
}

void loop (){
  const double temp1 = analogRead(tempAlvo);
  const double temp2 = analogRead(tempAmb);
  
  lcd.clear(); //Limpa a tela
  lcd.setCursor(0,0); //Posiciona o cursor na coluna 3, linha 0;
  lcd.print("Temp. Alvo: ");//texto que vai para o lcd
  const int a = (50*temp1)/1023;
  lcd.print(a);
  lcd.print(" c");
  
  lcd.setCursor(0, 1);
  lcd.print("Temp. Amb.: ");
  const int b = (50*temp2)/1023;
  lcd.print(b);
  lcd.print(" c");
  delay(3000);

  scrollLeft(3);
  scrollRight(6);
}
