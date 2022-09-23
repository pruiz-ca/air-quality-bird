#ifndef MAIN_HPP
#define MAIN_HPP

#include <Adafruit_CCS811.h>  // Air Quality Sensor
#include <Arduino.h>
#include <HTTPClient.h>
#include <Servo.h>
#include <SevSeg.h>  // Seven Segment Display
#include <WiFiNINA.h>

void initAirQualitySensor(Adafruit_CCS811& ccs);
void initServo(Servo& servo);
void initWiFi();

#endif
