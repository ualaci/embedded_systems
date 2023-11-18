#define A 11
#define B 10
#define C 7
#define D 8
#define E 9
#define F 12
#define G 13
#define H 14 //não vamos usar era o ponto

#define I 3
#define J 2
#define K 6
#define L 0
#define M 1
#define N 4
#define O 5
#define P 14 //não vamos usar era o ponto

void setup (void){
  pinMode (A, OUTPUT);
  pinMode (B, OUTPUT);
  pinMode (C, OUTPUT);
  pinMode (D, OUTPUT);
  pinMode (E, OUTPUT);
  pinMode (F, OUTPUT);
  pinMode (G, OUTPUT);
  
  pinMode (I, OUTPUT);
  pinMode (J, OUTPUT);
  pinMode (K, OUTPUT);
  pinMode (L, OUTPUT);
  pinMode (M, OUTPUT);
  pinMode (N, OUTPUT);
  pinMode (O, OUTPUT);
  
  
}
//loop principal
void loop (void){
  for (int bcd=0; bcd<=9; bcd++){
    byte _7seg = bcdTo7seg (bcd);
    updateDisplay (_7seg);
    
  	for (int bcd2=0; bcd2<=9; bcd2++){
      byte _7seg2 = bcdTo7seg (bcd2);
      updateDisplay2 (_7seg2);
      delay (1000);
    }
    delay (1000);
    
  }
}
//Conversor bcd para 7 segmentos
byte bcdTo7seg (int bcd){
  switch (bcd){ //hgfedcba
    case 0: return 0b00111111;
    case 1: return 0b00000110;
    case 2: return 0b01011011;
    case 3: return 0b01001111;
    case 4: return 0b01100110;
    case 5: return 0b01101101;
    case 6: return 0b01111100;
    case 7: return 0b00000111;
    case 8: return 0b01111111;
    case 9: return 0b01100111;
  }
}
//Atualização de display
void updateDisplay (byte _7seg){
  digitalWrite (A, bitRead(_7seg, 0));
  digitalWrite (B, bitRead(_7seg, 1));
  digitalWrite (C, bitRead(_7seg, 2));
  digitalWrite (D, bitRead(_7seg, 3));
  digitalWrite (E, bitRead(_7seg, 4));
  digitalWrite (F, bitRead(_7seg, 5));
  digitalWrite (G, bitRead(_7seg, 6));
  digitalWrite (H, bitRead(_7seg, 7));
}

void updateDisplay2 (byte _7seg){
  digitalWrite (I, bitRead(_7seg, 0));
  digitalWrite (J, bitRead(_7seg, 1));
  digitalWrite (K, bitRead(_7seg, 2));
  digitalWrite (L, bitRead(_7seg, 3));
  digitalWrite (M, bitRead(_7seg, 4));
  digitalWrite (N, bitRead(_7seg, 5));
  digitalWrite (O, bitRead(_7seg, 6));
  digitalWrite (P, bitRead(_7seg, 7));
}
