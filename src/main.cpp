#include "main.hpp"

int aqSensorMode = 2;  // 0: Iddle, 1: Every 1s, 2: Every 10s, 3: Every 60s
Adafruit_CCS811 aqSensor;
Servo servo;
float temp;

/* EXECUTED ONCE AT THE START */
void setup() {
    Serial.begin(9600);
    initAirQualitySensor();
    initServo();
    initWiFi();
}

/* MAIN LOOP */
void loop() {
    if (aqSensor.available()) {
        temp = aqSensor.calculateTemperature();

        if (!aqSensor.readData()) {
            Serial.print("CO2: ");
            Serial.println(aqSensor.geteCO2());

            Serial.print("TVOC: ");
            Serial.println(aqSensor.getTVOC());

            Serial.print("Temp:");
            Serial.println(temp);

            Serial.print("Wifi strength: ");
            Serial.println(WiFi.RSSI());
        } else {
            Serial.println("ERROR!");
        }
    }
    delay(1000);
}
