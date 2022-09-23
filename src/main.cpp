#include "main.hpp"

Adafruit_CCS811 ccs;
Servo servo;
double temp;

/* EXECUTED ONCE AT THE START */
void setup() {
    Serial.begin(9600);
    delay(10000);

    // initWiFi();
    initServo(servo);
    initAirQualitySensor(ccs);
    Serial.println("All started!");
}

/* MAIN LOOP */
void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    if (ccs.available()) {
        digitalWrite(LED_BUILTIN, HIGH);
        temp = ccs.calculateTemperature();

        if (ccs.readData() != false && ccs.readData() == 0) {
            int co2 = ccs.geteCO2();
            int tvoc = ccs.getTVOC();

            Serial.println("\n*****");

            Serial.print("CO2: ");
            Serial.println(co2);

            Serial.print("TVOC: ");
            Serial.println(tvoc);

            Serial.print("Temp:");
            Serial.println(temp);

            Serial.print("Wifi strength: ");
            Serial.println(WiFi.RSSI());

            Serial.println("*****\n");

            if (co2 > 1000) {
                servo.write(10);
            } else {
                servo.write(160);
            }
        } else {
            Serial.println("ERROR!");
        }
    }
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}
