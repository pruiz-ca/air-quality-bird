#include "main.hpp"
#include "secrets.hpp"

/****************************************/
/*  FUNCTIONS TO INITIALIZE COMPONENTS  */
/****************************************/

/* Connect To The Internet */
void initWiFi() {
    Serial.println("\n*****");
    Serial.println("Connecting WiFi");

    WiFi.begin(SECRET_WIFI_SSID, SECRET_WIFI_PWD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Wifi connected!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println("*****\n");
}

/* Initialize Air Quality Sensor */
void initAirQualitySensor(Adafruit_CCS811& ccs) {
    Serial.println("\n*****");
    Serial.println("Initializing Air Quality Sensor...");

    if (!ccs.begin()) {
        Serial.println(
            "Failed to start Air Quality sensor! Please check the wiring.");
        while (1) delay(1000);
    }

    while (!ccs.available()) {
        Serial.println("Waiting for sensor to be ready...");
        delay(1000);
    }

    double temp = ccs.calculateTemperature();
    ccs.setTempOffset(temp - 25.0);

    Serial.println("Air Quality Sensor initialized!");
    Serial.println("*****\n");
}

/* Initialize Servo */
void initServo(Servo& servo) {
    Serial.println("\n*****");
    Serial.println("Initializing Servo...");

    servo.attach(9);
    Serial.println("Servo initialized!");
    Serial.println("*****\n");
}
