/*
 * 3-Sensor Line Follower for Arduino Uno + L298P R3 Shield
 * Sensors output HIGH (1) = Black line
 * Sensors output LOW (0)  = White surface
 */

// --- Pin Definitions ---

// IR Sensor Pins
const int leftIR = 6;
const int midIR  = 2;
const int rightIR = 3;

// L298P Motor Shield Pins
const int motorA_dir = 12;  // Left motor direction
const int motorA_pwm = 10;  // Left motor speed (PWM)
const int motorB_dir = 13;  // Right motor direction
const int motorB_pwm = 11;  // Right motor speed (PWM)

// --- Speed Settings ---
int baseSpeed = 150;  // Adjust for your robot (0–255)
int turnSpeed = 120;

void setup() {
  // IR sensor pins
  pinMode(leftIR, INPUT);
  pinMode(midIR, INPUT);
  pinMode(rightIR, INPUT);

  // Motor pins
  pinMode(motorA_dir, OUTPUT);
  pinMode(motorA_pwm, OUTPUT);
  pinMode(motorB_dir, OUTPUT);
  pinMode(motorB_pwm, OUTPUT);

  stopMotors();

  Serial.begin(9600);
}

void loop() {
  int leftVal  = digitalRead(leftIR);
  int midVal   = digitalRead(midIR);
  int rightVal = digitalRead(rightIR);

  // Debugging (optional)
  // Serial.print(leftVal); Serial.print(" ");
  // Serial.print(midVal); Serial.print(" ");
  // Serial.println(rightVal);

  // --- Line Following Logic ---
  if (leftVal == 0 && midVal == 1 && rightVal == 0) {
    // Center sensor on line → Go forward
    goForward();
  }
  else if (leftVal == 1 && midVal == 0 && rightVal == 0) {
    // Left sensor on line → Turn left
    turnLeft();
  }
  else if (leftVal == 1 && midVal == 1 && rightVal == 0) {
    // Left + Middle → Sharper left
    turnLeft();
  }
  else if (leftVal == 0 && midVal == 0 && rightVal == 1) {
    // Right sensor on line → Turn right
    turnRight();
  }
  else if (leftVal == 0 && midVal == 1 && rightVal == 1) {
    // Middle + Right → Sharper right
    turnRight();
  }
  else if (leftVal == 0 && midVal == 0 && rightVal == 0) {
    // No line detected → Stop
    stopMotors();
  }
  else if (leftVal == 1 && midVal == 1 && rightVal == 1) {
    // All sensors on line → Stop (or junction)
    stopMotors();
  }
  else {
    stopMotors();
  }
}

// --- Motor Control Functions ---

void goForward() {
  digitalWrite(motorA_dir, HIGH);
  digitalWrite(motorB_dir, HIGH);
  analogWrite(motorA_pwm, baseSpeed);
  analogWrite(motorB_pwm, baseSpeed);
}

void turnLeft() {
  digitalWrite(motorA_dir, LOW);   // Left motor reverse (or slow)
  digitalWrite(motorB_dir, HIGH);  // Right motor forward
  analogWrite(motorA_pwm, turnSpeed / 2);
  analogWrite(motorB_pwm, baseSpeed);
}

void turnRight() {
  digitalWrite(motorA_dir, HIGH);  // Left motor forward
  digitalWrite(motorB_dir, LOW);   // Right motor reverse (or slow)
  analogWrite(motorA_pwm, baseSpeed);
  analogWrite(motorB_pwm, turnSpeed / 2);
}

void stopMotors() {
  analogWrite(motorA_pwm, 0);
  analogWrite(motorB_pwm, 0);
}
