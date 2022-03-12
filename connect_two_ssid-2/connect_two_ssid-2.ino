

#ifdef ESP32
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

#include "wifiaccred.h"
// accreditals for the wifi networks.

void setup() {
  Serial.begin(115200);

  Serial.println("\nWL_CONNECTED: " + String(WL_CONNECTED));//assigned when connected to a WiFi network;
  Serial.println("WL_NO_SHIELD: " + String(WL_NO_SHIELD));//assigned when no WiFi shield is present;
  Serial.println("WL_IDLE_STATUS: " + String(WL_IDLE_STATUS));//it is a temporary status assigned when WiFi.begin() is called and remains active until the number of attempts expires (resulting in WL_CONNECT_FAILED) or a connection is established (resulting in WL_CONNECTED);
  Serial.println("WL_NO_SSID_AVAIL: " + String(WL_NO_SSID_AVAIL));//assigned when no SSID are available;
  Serial.println("WL_SCAN_COMPLETED: " + String(WL_SCAN_COMPLETED));//assigned when the scan networks is completed;
  Serial.println("WL_CONNECT_FAILED: " + String(WL_CONNECT_FAILED));//assigned when the connection fails for all the attempts;
  Serial.println("WL_CONNECTION_LOST: " + String(WL_CONNECTION_LOST));//assigned when the connection is lost;
  Serial.println("WL_DISCONNECTED: " + String(WL_DISCONNECTED));//assigned when disconnected from a network;

  Serial.println("\nConnect: " + String(WiFi.status()));

  WiFi.begin(ssid1, password);
  Serial.println("\nStart connection");

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
