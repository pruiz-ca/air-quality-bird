#include "main.hpp"
#include "secrets.hpp"

/****************************************/
/*  FUNCTIONS TO INITIALIZE COMPONENTS  */
/****************************************/

/* Connect To The Internet */
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

/* Initialize Air Quality Sensor */
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

/* Initialize Servo */
void initServo() {
    Serial.println("Initializing Servo...");

    servo.attach(9);
}
