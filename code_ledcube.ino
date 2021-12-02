#define FALSE 0
#define TRUE 1

// Define pins
const int latchPin = 3;
const int clockPin = 4;
const int dataPin = 2;
const int transistor1Pin = 5;
const int transistor2Pin = 8;
const int transistor3Pin = 7;
const int transistor4Pin = 9;

typedef struct {
  byte first;
  byte second;
} Registers;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(transistor1Pin, OUTPUT);
  pinMode(transistor2Pin, OUTPUT);
  pinMode(transistor3Pin, OUTPUT);
  pinMode(transistor4Pin, OUTPUT);

  // Initialize random number generator
  randomSeed(analogRead(0));
}


void loop() {
  // Circumference loop
  Registers pattern0[12] = {{15, 0}, {142, 0}, {140, 8}, {136, 136}, {128, 200}, {0, 232}, {0, 240}, {0, 113}, {16, 49}, {17, 17}, {19, 1}, {23, 0}};
  showPatternOnAllLevels(pattern0, 12);

  // Left to right
  Registers pattern1[6] = {{15, 0}, {240, 0}, {0, 15}, {0, 240}, {0, 15}, {240, 0}};
  showPatternOnAllLevels(pattern1, 6);

  // Front to back
  Registers pattern2[6] = {{136, 136}, {68, 68}, {34, 34}, {17, 17}, {34, 34}, {68, 68}};
  showPatternOnAllLevels(pattern2, 6);

  // Top to bottom
  for (int i = 0; i < 2; i++) {
    showLeds({255, 255}, TRUE, FALSE, FALSE, FALSE);
    showLeds({255, 255}, FALSE, TRUE, FALSE, FALSE);
    showLeds({255, 255}, FALSE, FALSE, TRUE, FALSE);
    showLeds({255, 255}, FALSE, FALSE, FALSE, TRUE);
    showLeds({255, 255}, FALSE, FALSE, TRUE, FALSE);
    showLeds({255, 255}, FALSE, TRUE, FALSE, FALSE);
  }

  // Rain
  Registers pattern4[20];
  for (int i = 0; i < 20; i++) {
    pattern4[i] = {(byte) (random() % 256), (byte) (random() % 256)};

    unsigned int startTime = millis();
    do {
      digitalWrite(latchPin, LOW);
      showLeds(pattern4[i], 1);
      if (i >= 1) {
        showLeds(pattern4[i - 1], 2);
        if (i >= 2) {
          showLeds(pattern4[i - 2], 3);
          if (i >= 3) {
            showLeds(pattern4[i - 3], 4);
          }
        }
      }
    } while (millis() - startTime < 400);
  }
}

void showPatternOnAllLevels(Registers *pattern, int size) {
  for (int i = 0; i < 2; i++) {
    for (int num = 0; num < size; num++) {
      showLeds(pattern[num], TRUE, TRUE, TRUE, TRUE);
    }
  }
}

void showLeds(Registers pattern, int level1, int level2, int level3, int level4) {
  unsigned int startTime = millis();
  do {
    digitalWrite(latchPin, LOW);
    if (level1) {
      showLeds(pattern, 1);
    }
    if (level2) {
      showLeds(pattern, 2);
    }
    if (level3) {
      showLeds(pattern, 3);
    }
    if (level4) {
      showLeds(pattern, 4);
    }
  } while (millis() - startTime < 400);
}

void showLeds(Registers pattern, int level) {
  digitalWrite(latchPin, LOW);
  digitalWrite(transistor1Pin, level == 1 ? HIGH : LOW);
  digitalWrite(transistor2Pin, level == 2 ? HIGH : LOW);
  digitalWrite(transistor3Pin, level == 3 ? HIGH : LOW);
  digitalWrite(transistor4Pin, level == 4 ? HIGH : LOW);

  shiftOut(dataPin, clockPin, MSBFIRST, pattern.second);
  shiftOut(dataPin, clockPin, MSBFIRST, pattern.first);
  digitalWrite(latchPin, HIGH);
  delay(5);
}
