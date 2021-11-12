// Define Connections to 74HC595 
const int latchPin = 4;// ST_CP pin 12
const int clockPin = 3; // SH_CP pin 11
const int dataPin = 2; // DS pin 14 
int pattern[16];
///////////////////////////////////////////////
void setup()
{
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);    

  //Heen en terug
//  pattern[0] = B10000000;
//  pattern[1] = B01000000;
//  pattern[2] = B00100000;
//  pattern[3] = B00010000;
//  pattern[4] = B00001000;
//  pattern[5] = B00000100;
//  pattern[6] = B00000010;
//  pattern[7] = B00000001;

  pattern[0] = B10000000;
  pattern[1] = B01000000;
  pattern[2] = B00100000;
  pattern[3] = B00010000;
  pattern[4] = B00100000;
  pattern[5] = B01000000;
  pattern[6] = B10000000;
  pattern[7] = B00000001;


 pattern[8]  = B00000001;
  pattern[9]  = B00000010;
  pattern[10] = B00000100;
  pattern[11] = B00001000;
  pattern[12] = B00010000;
  pattern[13] = B00100000;
  pattern[14] = B01000000;
  pattern[15] = B10000000;


  // LED om en om aan
//  pattern[0] = B10101010;
 // pattern[1] = B01010101;
 // pattern[2] = B10101010;
 // pattern[3] = B01010101;
 // pattern[4] = B10101010;
//  pattern[5] = B01010101;
//  pattern[6] = B10101010;
//  pattern[7] = B01010101;

 // pattern[0] = B00000001;
 // pattern[1] = B00000010;
//  pattern[2] = B00000100;
//  pattern[3] = B00001000;
 // pattern[4] = B00010000;
 // pattern[6] = B01000000;
 // pattern[7] = B10000000;

}
////////////////////////////////////////////////
void loop() 
{  
 for(int num = 0; num < 8; num++)
  {
    shiftLED(pattern[num]);
    delay(500); 
  }
}
//////////////////////////////////////////////
void shiftLED(byte LED)
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, MSBFIRST, LED);
   digitalWrite(latchPin, HIGH);
}
//////////////////////////////////////////////
