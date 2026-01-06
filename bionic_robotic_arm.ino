#include <Servo.h>

// === Servos ===
Servo servoBaseX;   // MG996R on D3  (Joystick X)
Servo servoBaseY;   // MG996R on D5  (Joystick Y)
Servo finger1;  // MG90S  on D6  (Button A + B)
Servo finger2;  // MG90S  on D8  (Button C + D)

// === Button pins ===
const int btnA = 7; // close fast
const int btnB = 6; // open fast
const int btnC = 5; // close slowly
const int btnD = 4; // open slowly

// === Joystick pins ===
#define JOY_X A2
#define JOY_Y A3

// Servo angles
int angleBaseX = 90;    // MG996R on D3
int angleBaseY = 65;    // MG996R on D5
float fingerPos1 = 90;
float fingerPos2 = 90;   // MG90S on D8 (0–90°)

// --- Parameters ---
const int deadzone = 30;         // joystick deadzone
const float smoothing = 0.12;    // 0-1, smaller = smoother
const float fingerSmoothing = 0.15;

// --- Finger targets ---
float targetFinger1 = 90;
float targetFinger2 = 90;

void setup() {
  Serial.begin(9600);

  servoBaseX.attach(8);
  servoBaseY.attach(9);
  finger1.attach(10);
  finger2.attach(11);

   // Initialize servo positions
  servoBaseX.write(angleBaseX);
  servoBaseY.write(angleBaseY);
  finger1.write(fingerPos1);
  finger2.write(fingerPos2);

  // Button inputs
  pinMode(btnA, INPUT_PULLUP);
  pinMode(btnB, INPUT_PULLUP);
  pinMode(btnC, INPUT_PULLUP);
  pinMode(btnD, INPUT_PULLUP);

  Serial.println("Robotic Arm Control System Ready...");
}
float smoothMove(float current, float target, float factor) {
  return current + (target - current) * factor;
}
void updateFingers() {
  if (digitalRead(btnA) == LOW) {
    targetFinger1 = 0;  targetFinger2 = 0;
  }
  else if (digitalRead(btnB) == LOW) {
    targetFinger1 = 180;  targetFinger2 = -180;
  }
  else if (digitalRead(btnC) == LOW) {
    targetFinger1 = -180;   targetFinger2 = 180;
  }
  else if (digitalRead(btnD) == LOW) {
    targetFinger1 = 180;  targetFinger2 = 180;
  }
  else {
  }
}
void loop() {

  // -------------------------------------
  // 1) PRINT INPUT STATUS CONSTANTLY
  // -------------------------------------
  updateFingers();
  fingerPos1 = smoothMove(fingerPos1, targetFinger1, fingerSmoothing);
  fingerPos2 = smoothMove(fingerPos2, targetFinger2, fingerSmoothing);

  finger1.write((int)fingerPos1);
  finger2.write((int)fingerPos2);

  delay(6); // faster loop = smoother movement
  int joyX = analogRead(JOY_X);
  int joyY = analogRead(JOY_Y);

  Serial.print(" | Joystick X=");
  Serial.print(joyX);
  Serial.print(" Y=");
  Serial.println(joyY);

  // -------------------------------------
  // 2) JOYSTICK → MG996R SERVOS
  // -------------------------------------

  // Joystick X → Servo on D3
  int offsetX = joyX - 512;  // center offset
  int speedX = map(abs(offsetX), 0, 512, 0, 7); // speed scaling

  if (offsetX > 60) angleBaseX += speedX;
  if (offsetX < -60) angleBaseX -= speedX;

  angleBaseX = constrain(angleBaseX, 0, 180);
  servoBaseX.write(angleBaseX);

  // Joystick Y → Servo on D5
  int offsetY = joyY - 512;
  int speedY = map(abs(offsetY), 0, 512, 0, 7);

  if (offsetY > 60) angleBaseY += speedY;
  if (offsetY < -60) angleBaseY -= speedY;

  angleBaseY = constrain(angleBaseY, 0, 180);
  servoBaseY.write(angleBaseY);

  // -------------------------------------
  // 3) BUTTON CONTROL FOR MG90S (D6 & D8)
  // -------------------------------------

  // MG90S Joint 1 on D6
  // === MG90S Joint 1 (Finger / String Pull) ===
}