#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <LiquidCrystal_I2C.h>
#include <math.h>

// Initialize ADXL345 sensor
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

// Initialize LCD display (I2C Address: 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Initialize GSM module on Serial2
#define SIM800_RX 16
#define SIM800_TX 17

// Define buzzer and LED pins
#define BUZZER_PIN 15
#define LED_PIN 2

// Set vibration threshold
float threshold = 1.5; // Adjust based on sensitivity required

void setup() {
    Serial.begin(115200);

    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);

    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("System Initializing");

    if (!accel.begin()) {
        Serial.println("ADXL345 not found!");
        lcd.setCursor(0, 1);
        lcd.print("Sensor Error!");
        while (1);
    }

    accel.setRange(ADXL345_RANGE_16_G);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("System Ready");
    delay(1000);
}

void loop() {
    sensors_event_t event;
    accel.getEvent(&event);

    float totalAcc = sqrt(pow(event.acceleration.x, 2) +
                          pow(event.acceleration.y, 2) +
                          pow(event.acceleration.z, 2));

    if (totalAcc > threshold) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Earthquake Alert!");
        digitalWrite(BUZZER_PIN, HIGH);
        digitalWrite(LED_PIN, HIGH);

        sendSMS("Earthquake Detected! Take action immediately.");
    } else {
        digitalWrite(BUZZER_PIN, LOW);
        digitalWrite(LED_PIN, LOW);
        lcd.setCursor(0, 1);
        lcd.print("Monitoring...");
    }

    delay(500);
}

void sendSMS(String message) {
    delay(1000);
    
    delay(1000);
    
    delay(1000);
    Serial2.write(26);
    delay(5000);
}
