#ifndef MAIN_HPP
#define MAIN_HPP

#include <Adafruit_CCS811.h>  // Air Quality Sensor
#include <Arduino.h>
#include <HTTPClient.h>
#include <Servo.h>
#include <SevSeg.h>  // Seven Segment Display
#include <WiFiNINA.h>

extern int aqSensorMode;
extern Adafruit_CCS811 aqSensor;
extern Servo servo;
extern float temp;

void initWiFi();
void initAirQualitySensor();
void initServo();

#endif
