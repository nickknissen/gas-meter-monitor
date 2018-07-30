#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "config.h"

int reedPin = CONFIG_REED_PIN;

unsigned int pulseCount = 0;
unsigned int priorPulseCount = 0;
const char* ssid = CONFIG_WIFI_SSID;
const char* password = CONFIG_WIFI_PASS;

void flashLed (int i) {
  digitalWrite(LED_BUILTIN, 1);
  delay(i);
  digitalWrite(LED_BUILTIN, 0);
}


void onPulse() {
    pulseCount++;
}

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    delay(100);

    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
  
    Serial.println("");
    Serial.println("WiFi connected");  
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());     
    pinMode(reedPin, INPUT_PULLUP);
    attachInterrupt(reedPin, onPulse, CHANGE);
}
void loop() {
    if (pulseCount != priorPulseCount) {
        Serial.println(pulseCount);
        priorPulseCount = pulseCount;
    }
}