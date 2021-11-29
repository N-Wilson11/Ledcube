



//Initialiseer pinnen
const int latchPin = 3;
const int clockPin = 4;
const int dataPin = 2;
const int transistor1 = 5; 
const int transistor3 = 7;
const int transistor2 = 8; 
const int transistor4 = 9; 


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PATRONEN
/*
//Knipperen
const byte pattern0[] = {B11111111, B00000000};

// Om en om
const byte pattern1[] = {B10101010, B01010101};


// Allebei de kanten op
const byte pattern2[] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000,B01000000,B00100000,B00010000,B00001000,B00000100,B00000010};


//Twee tegelijk
const byte pattern3[] = {B00000011,B00000110,B00001100,B00011000,B00110000,B01100000,B11000000, B01100000, B00110000, B00011000, B00001100, B00000110};



//1001 patroon
const byte pattern4[] = {B10000001, B01000010, B00100100, B00011000, B00100100, B01000010};
*/
const int pattern1[] = {0b11111111};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(transistor1, OUTPUT);
  pinMode(transistor2, OUTPUT);
  pinMode(transistor3, OUTPUT);
  pinMode(transistor4, OUTPUT);
  //digitalWrite(transistor1, HIGH);
  //digitalWrite(transistor2, HIGH);
  //digitalWrite(transistor3, HIGH);
 // digitalWrite(transistor4, HIGH);
}


void loop() {

/*for (int i = 0; i < 2; i++) {
    for (int num = 0; num < sizeof(pattern1); num++) {
      showLeds(pattern1[num]);
      delay(300);
    }
  }*/
  patroon1();

}


void patroon1(){
for(int i = 0; i < 4; i++){

 digitalWrite(transistor4, HIGH);
 delay(150);
 digitalWrite(transistor4, LOW);
 

 digitalWrite(transistor3, HIGH);
 delay(150);
 digitalWrite(transistor3, LOW);
 

 digitalWrite(transistor2, HIGH);
 delay(150);
 digitalWrite(transistor2, LOW);
 

digitalWrite(transistor1, HIGH);
 delay(150);
digitalWrite(transistor1, LOW);




 digitalWrite(transistor2, HIGH);
 delay(150);
 digitalWrite(transistor2, LOW);
 

 digitalWrite(transistor3, HIGH);
 delay(150);
 digitalWrite(transistor3, LOW);
 

 
 
 
 }
}



//Void functie om de leds aan te sturen
void showLeds(byte value) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, value);
  digitalWrite(latchPin, HIGH);
}
