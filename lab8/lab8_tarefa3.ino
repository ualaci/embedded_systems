#include <EEPROM.h>

#define pinMotor 5 // PWM
int pinPot = A0; // Potenciômetro

int pinBotao = 7;
int velocidade = 0;

boolean botaoRetencao(); //Declaração da função que lê o estado do botão, ligado/desligado.

void setup() {
    Serial.begin(9600);
  
    pinMode(pinBotao, INPUT_PULLUP);
    pinMode(pinMotor, OUTPUT);
    pinMode(pinPot, INPUT);
    

}

void loop() {

    botaoRetencao(pinBotao);
    
    if(botaoRetencao(pinBotao)) { 
      
    velocidade = analogRead(pinPot);
    analogWrite(pinMotor, velocidade/4);
    
    } else {
      analogWrite(pinMotor, 0);
    }
    Serial.println(velocidade/4);
}

boolean botaoRetencao(int pinBotao) { //Verifica se o botão foi acionado **Botão com retenção e resistor de PullUp interno do Arduino**
    #define delayBounce 50
    static unsigned long tempoDeBounce = 0;
    boolean estadoBotao;
    static boolean estadoAntBotao = true;
    static boolean estado = false;

    estadoBotao = digitalRead(pinBotao);

    if( (!estadoBotao && estadoAntBotao) && ( millis() - tempoDeBounce) > delayBounce ) {
       estado = !estado; 
       tempoDeBounce = millis();
    }
    estadoAntBotao = estadoBotao;
    
    return estado;
}