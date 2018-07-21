#include <Arduino.h>

#include <ESP8266WiFi.h>

int reedPin = D2;
int reedState = 0;
int reedLast = -1;

unsigned int gasPulses = 0;
unsigned int gasThis = 0;
unsigned int gasPrev = 0;
unsigned int gasLast = 0;

const char* ssid = "DEMO AP";
const char* password = "DEMO_PASS";

String strFull = "";


void flashLed (int i) {
  digitalWrite(BUILTIN_LED, 1);
  delay(i);
  digitalWrite(BUILTIN_LED, 0);
}


void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    delay(100);
    Serial.println("Preparing the gas Monitor project...");

    
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

    pinMode(BUILTIN_LED, OUTPUT);

    pinMode(reedPin, INPUT);
}
void loop() {

    reedState = digitalRead(reedPin);

    if (reedState != reedLast && reedLast != -1) {
        if (reedState == 1 && reedLast != -1) {
            gasPulses = gasPulses + 1;
            flashLed(200);
            Serial.println("pulse");

        } 
    }
    reedLast = reedState;

    strFull = gasPulses;
    strFull += "\t";
    strFull += gasPrev;
    strFull += "\t";
    Serial.println(strFull);
    gasPrev = gasPulses;
}