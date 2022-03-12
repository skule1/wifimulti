

#ifdef ESP32
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

#include "wifiaccred.h"
// accreditals for the wifi networks.

void setup() {
  Serial.begin(115200);
  Serial.println("\nStart connection");
  WiFi.begin(ssid1, password);


  int i = 5;
  while ((WiFi.status() != WL_CONNECTED) && (i-- >1)) {
    Serial.print(".");
    delay(1000);
  }
  
  Serial.println("\nConnect: " + String(WiFi.status()));
  if (i =1) {
    WiFi.disconnect(true);
    WiFi.begin(ssid, password);

    i = 5;
    while ((WiFi.status() != WL_CONNECTED) && (i-- > 0)) {
      Serial.print(".");
      delay(1000);
    }
  }
  Serial.println("\nConnect: " + String(WiFi.status()));


  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());



}

void loop() {
  // put your main code here, to run repeatedly:

}
