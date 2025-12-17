#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <DHT.h>
#include <DHT_U.h>

// DHT11 setup
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// OLED setup (for SH1106 1.3" I2C)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
#define I2C_ADDRESS 0x3C

// Buzzer setup - ACTIVE BUZZER
#define BUZZER_PIN 3  // Buzzer connected to Digital Pin 3 (D3)

// Temperature threshold
#define TEMP_THRESHOLD 32.0  

// Buzzer control variables
unsigned long previousMillis = 0; // Store the last time the buzzer was updated
const long interval = 1000;        // Interval for buzzer on/off (1 second)
bool buzzerState = false;          // Buzzer state

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 + SH1106 OLED Test - Active Buzzer"));

  // Initialize DHT11
  dht.begin();

  // Initialize SH1106 OLED
  if (!display.begin(0x3C, true)) { // I2C addr 0x3C
    Serial.println(F("SH1106 allocation failed"));
    for (;;);
  }

  // Initialize buzzer pin
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW); // Ensure buzzer is off initially

  // Test buzzer on startup (short beep)
  Serial.println(F("Testing active buzzer..."));
  digitalWrite(BUZZER_PIN, HIGH);
  delay(100);
  digitalWrite(BUZZER_PIN, LOW);
  delay(100);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);
  display.println(F("DHT11 + OLED PRELIM"));
  display.println(F(" "));
  display.println(F("FUNDAMENTALS OF MIXED SIGNALS AND SENSOR"));
  display.println(F(" "));
  display.println(F("SAKAMOTO, KENJI D."));
  display.display();
  delay(5000);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT11!"));
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(F("Sensor Error"));
    display.display();
    
    // Turn off buzzer in case of error
    digitalWrite(BUZZER_PIN, LOW);
    
    delay(1000);
    return;
  }

  // Control ACTIVE buzzer based on temperature
  if (t >= TEMP_THRESHOLD) {
    unsigned long currentMillis = millis();
    
    // Check if it's time to toggle the buzzer state
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis; // Save the last time the buzzer was updated
      buzzerState = !buzzerState; // Toggle the buzzer state
      digitalWrite(BUZZER_PIN, buzzerState ? HIGH : LOW); // Set buzzer state
    }
    
    Serial.println(F("WARNING: High temperature! Buzzer ON"));
  } else {
    // Turn off buzzer if temperature is normal
    digitalWrite(BUZZER_PIN, LOW);
    buzzerState = false; // Reset buzzer state
  }

  // Print to Serial Monitor
  Serial.print(F("Temperature: "));
  Serial.print(t, 2);
  Serial.print(F("°C Humidity: "));
  Serial.print(h, 2);
  Serial.println(F("%"));
  Serial.print(F("Buzzer state: "));
  Serial.println(t >= TEMP_THRESHOLD ? "ON" : "OFF");
  Serial.print(F("Threshold: "));
  Serial.print(TEMP_THRESHOLD, 2);
  Serial.println(F("°C"));

  // Show on OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F(" READINGS: "));

  display.setTextSize(2); // Set text size to 2 for temperature
  display.setCursor(0, 16);
  display.print(F("Temp:"));
  display.print(t, 1);
  display.println(F("C"));
  
  // Show WARNING message if temperature is high
  if (t >= TEMP_THRESHOLD) {
    display.setTextSize(1);
    display.setCursor(70, 16);
    display.println(F("!"));
    display.setCursor(0, 55);
    display.println(F(" HOT TEMP!"));
  }

  display.setTextSize(2); // Set text size to 2 for humidity
  display.setCursor(0, 40);
  display.print(F("Humi:"));
  display.print(h, 1);
  display.println(F("%"));

  display.display();

  delay(200); // Short delay to avoid overly fast loop iterations
}