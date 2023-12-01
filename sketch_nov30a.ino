// Libraries needed for IR Sensor, Wet Sensor, and Metal Detecting Sensor
#include <IRremote.h> // IR Sensor library - example, replace with your specific library
#include <LiquidCrystal.h> // Library for 16x2 LCD

// Pins Configuration
const int irSensorPin = 2; // Pin for IR Sensor
const int wetSensorPin = 3; // Pin for Wet Sensor
const int metalSensorPin = 4; // Pin for Metal Detecting Sensor
const int buzzerPin = 5; // Pin for Buzzer
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 10, d7 = 9; // Pins for LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Variables
int irSensorValue;
int wetSensorValue;
int metalSensorValue;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Initialize LCD
  lcd.begin(16, 2);
  
  // Set sensor pins
  pinMode(irSensorPin, INPUT);
  pinMode(wetSensorPin, INPUT);
  pinMode(metalSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read sensor values
  irSensorValue = digitalRead(irSensorPin);
  wetSensorValue = digitalRead(wetSensorPin);
  metalSensorValue = digitalRead(metalSensorPin);

  // Display sensor values on Serial Monitor
  Serial.print("IR Sensor: ");
  Serial.println(irSensorValue);
  Serial.print("Wet Sensor: ");
  Serial.println(wetSensorValue);
  Serial.print("Metal Sensor: ");
  Serial.println(metalSensorValue);
  
  // Display sensor values on LCD
  lcd.setCursor(0, 0);
  lcd.print("IR:");
  lcd.print(irSensorValue);
  lcd.setCursor(0, 1);
  lcd.print("Wet:");
  lcd.print(wetSensorValue);
  lcd.setCursor(8, 0);
  lcd.print("Metal:");
  lcd.print(metalSensorValue);

  // Check for specific conditions and trigger actions
  if (irSensorValue == HIGH) {
    // Perform actions for IR Sensor detecting something
    // Add your logic here
  }

  if (wetSensorValue == HIGH) {
    // Perform actions for Wet Sensor detecting moisture
    // Add your logic here
  }

  if (metalSensorValue == HIGH) {
    // Perform actions for Metal Detecting Sensor detecting metal
    digitalWrite(buzzerPin, HIGH); // Turn on buzzer
    delay(1000); // Buzzer on for 1 second
    digitalWrite(buzzerPin, LOW); // Turn off buzzer
    // Add your logic here
  }

  delay(500); // Adjust delay as needed
}

