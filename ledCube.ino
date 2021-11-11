int latchPin = 4; 
int clockPin = 3;
int dataPin = 2;




void setup() {
   pinMode(latchPin, OUTPUT);
   pinMode(clockPin, OUTPUT);
   pinMode(dataPin, OUTPUT);
   Serial.begin(9600);
}

void loop() {
for ( int i = 0; i < 8; i++){

  digitalWrite(latchPin, LOW);
  
  digitalWrite(dataPin, HIGH);
   digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, LOW);
   digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, HIGH);
  digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, LOW);
  
  shiftOut(dataPin, clockPin, MSBFIRST, i);
  digitalWrite(latchPin, HIGH);
  delay(500);

  

  /*digitalWrite(latchPin, LOW);
  
  digitalWrite(dataPin, HIGH);
  // digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, LOW);
   //digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, HIGH);
   //digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, LOW);
   //digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, HIGH);
  // digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, LOW);
  // digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, HIGH);
   //digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, LOW);
   digitalWrite(clockPin, HIGH);

  
  
  
  digitalWrite(latchPin, HIGH);
  delay(500);
  
*/
  /*digitalWrite(latchPin, LOW);
  
  digitalWrite(dataPin, LOW);
   //digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, HIGH);
   //digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, LOW);
   //digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, HIGH);
   //digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, LOW);
  // digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, HIGH);
   //digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, LOW);
   //digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, HIGH);
  // digitalWrite(clockPin, HIGH);
  
  digitalWrite(clockPin, HIGH);
  
 
  delay(500);
*/
  

}
  

}
