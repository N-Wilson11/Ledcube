
//Initialiseer pinnen
const int latchPin = 3;
const int clockPin = 4;
const int dataPin = 2;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PATRONEN

//Knipperen
const byte pattern0[] = {B11111111, B00000000};

// Om en om
const byte pattern1[] = {B10101010, B01010101};


// Allebei de kanten op
const byte pattern2[] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000,B01000000,B00100000,B00010000,B00001000,B00000100,B00000010};


//Twee tegelijk
const byte pattern3[] = {B00000110,B00001100,B00011000,B00110000,B01100000,B11000000,B11000000, B01100000, B00110000, B00011000, B00001100, B00000110};



//1001 patroon
const byte pattern4[] = {B10000001, B01000010, B00100100, B00011000, B00100100, B01000010};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}


void loop() {

for (int i = 0; i < 2; i++) {
    for (int num = 0; num < sizeof(pattern1); num++) {
      showLeds(pattern1[num]);
      delay(300);
    }
  }
  //Loop voor tweede patroon
  for (int i = 0; i < 2; i++) {
    for (int num = 0; num < sizeof(pattern2); num++) {
      showLeds(pattern2[num]);
      delay(300);
    }
  }

  //Loop voor derde patroon
  for (int i = 0; i < 3; i++) {
    for (int num = 0; num < sizeof(pattern3); num++) {
      showLeds(pattern3[num]);
      delay(300);
    }
  }

//Loop voor vierde patroon
  for (int i = 0; i < 2; i++) {
    for (int num = 0; num < sizeof(pattern4); num++) {
      showLeds(pattern4[num]);
      delay(300);
    }
  }

}


//Void functie om de leds aan te sturen
void showLeds(byte value) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, value);
  digitalWrite(latchPin, HIGH);
}
