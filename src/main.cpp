#include <Adafruit_CCS811.h>  // Air Quality Sensor
#include <Arduino.h>
#include <HTTPClient.h>
#include <Servo.h>
#include <SevSeg.h>  // Seven Segment Display
#include <WiFiNINA.h>
#include "secrets.hpp"

/***********************/
/* EDITABLE PARAMETERS */
/***********************/
int aqSensorMode = 2;  // 0: Iddle, 1: Every 1s, 2: Every 10s, 3: Every 60s

/******************************************/
/* DO NOT CHANGE ANYTHING BELOW THIS LINE */
/******************************************/
Adafruit_CCS811 aqSensor;
Servo servo;
float temp;

/* CONNECT TO THE INTERNET */
void initWiFi() {
    Serial.print("Connecting WiFi");

    WiFi.begin(SECRET_WIFI_SSID, SECRET_WIFI_PWD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("connected!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

/* INITIALIZE AIR QUALITY SENSOR */
void initAirQualitySensor() {
    Serial.println("Initializing Air Quality Sensor...");

    aqSensor.setDriveMode(aqSensorMode);

    if (!aqSensor.begin()) {
        Serial.println(
            "Failed to start Air Quality sensor! Please check the wiring.");

        while (1) delay(1000);
    }

    while (!aqSensor.available()) delay(1000);

    temp = aqSensor.calculateTemperature();
    aqSensor.setTempOffset(temp - 25.0);
}

/* INITIALIZE SERVO */
void initServo() {
    Serial.println("Initializing Servo...");

    servo.attach(9);
}

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
        } else {
            Serial.println("ERROR!");
        }
    }
    delay(1000);
}
