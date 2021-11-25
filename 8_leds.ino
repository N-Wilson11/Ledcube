const int latchPin = 3;
const int clockPin = 4;
const int dataPin = 2;

// Om en om
const byte pattern0[2] = {B10101010, B01010101};

// Heen en terug
byte pattern1[14];

// Heen en terug dubbel;
byte pattern2[12];

// Allebei de kanten op
const byte pattern3[6] = {B10000001, B01000010, B00100100, B00011000, B00100100, B01000010};

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  pattern1[7] = 1;
  byte value = 2;
  for (int i = 1; i < 8; ++i) {
    pattern1[7 - i] = value;
    if (i < 7) {
      pattern1[7 + i] = value;
    }
    value *= 2;
  }

  pattern2[6] = 3;
  value = 6;
  for (int i = 1; i < 7; ++i) {
    pattern2[6 - i] = value;
    if (i < 6) {
      pattern2[6 + i] = value;
    }
    value *= 2;
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    for (int num = 0; num < sizeof(pattern0)/sizeof(pattern0[0]); num++) {
      showLeds(pattern0[num]);
      delay(300);
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int num = 0; num < sizeof(pattern1)/sizeof(pattern1[0]); num++) {
      showLeds(pattern1[num]);
      delay(300);
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int num = 0; num < sizeof(pattern2)/sizeof(pattern2[0]); num++) {
      showLeds(pattern2[num]);
      delay(300);
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int num = 0; num < sizeof(pattern3)/sizeof(pattern3[0]); num++) {
      showLeds(pattern3[num]);
      delay(300);
    }
  }
}

void showLeds(byte value) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, value);
  digitalWrite(latchPin, HIGH);
}
