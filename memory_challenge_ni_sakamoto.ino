// Simon Says Color Memory Game for ESP32
// Pins from user's setup
#define GREEN_LED   23
#define BLUE_LED    22
#define RED_LED     19
#define YELLOW_LED  18
#define BUZZER      12

#define GREEN_BTN   26
#define BLUE_BTN    27
#define RED_BTN     14
#define YELLOW_BTN  13

// Game variables
int sequence[100];       // store up to 100 steps
int level = 0;           // current level
int userIndex = 0;       // player input index
bool gameOver = false;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  pinMode(GREEN_BTN, INPUT_PULLUP);
  pinMode(BLUE_BTN, INPUT_PULLUP);
  pinMode(RED_BTN, INPUT_PULLUP);
  pinMode(YELLOW_BTN, INPUT_PULLUP);

  randomSeed(analogRead(0)); // randomize

  Serial.begin(115200);
  startGame();
}

void loop() {
  if (gameOver) {
    playLoseTone();
    delay(2000);
    startGame();
  } else {
    // Show sequence
    showSequence();
    // Wait for player input
    getUserInput();
    // If correct, next round
    if (!gameOver) {
      level++;
      delay(1000);
    }
  }
}

void startGame() {
  level = 1;
  gameOver = false;
  for (int i = 0; i < 100; i++) {
    sequence[i] = random(4); // 0=green,1=blue,2=red,3=yellow
  }
}

void showSequence() {
  Serial.print("Level: "); Serial.println(level);
  for (int i = 0; i < level; i++) {
    lightUp(sequence[i]);
    delay(400);
    allOff();
    delay(200);
  }
  userIndex = 0;
}

void getUserInput() {
  while (userIndex < level) {
    int btn = readButton();
    if (btn != -1) {
      lightUp(btn);
      delay(300);
      allOff();

      if (btn == sequence[userIndex]) {
        userIndex++;
      } else {
        gameOver = true;
        return;
      }
    }
  }
}

int readButton() {
  if (digitalRead(GREEN_BTN) == LOW) return 0;
  if (digitalRead(BLUE_BTN) == LOW) return 1;
  if (digitalRead(RED_BTN) == LOW) return 2;
  if (digitalRead(YELLOW_BTN) == LOW) return 3;
  return -1;
}

void lightUp(int color) {
  switch (color) {
    case 0: digitalWrite(GREEN_LED, HIGH); tone(BUZZER, 261); break; // C note
    case 1: digitalWrite(BLUE_LED, HIGH);  tone(BUZZER, 329); break; // E note
    case 2: digitalWrite(RED_LED, HIGH);   tone(BUZZER, 392); break; // G note
    case 3: digitalWrite(YELLOW_LED, HIGH);tone(BUZZER, 523); break; // C high
  }
}

void allOff() {
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  noTone(BUZZER);
}

void playLoseTone() {
  for (int i = 0; i < 3; i++) {
    tone(BUZZER, 200);
    delay(200);
    noTone(BUZZER);
    delay(200);
  }
}
