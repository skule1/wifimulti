#ifdef ESP32
#include <WiFi.h>
#include <WiFiMulti.h>
WiFiMulti WiFiMulti;
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
ESP8266WiFiMulti WiFiMulti;
#endif

const uint32_t connectTimeoutMs = 5000;

#include "wificred.h"
// creditals for the wifi networks.

void setup() {
  Serial.begin(115200);
  WiFiMulti.addAP(ssid1, password);
  WiFiMulti.addAP(ssid1, password);
  WiFiMulti.addAP(ssid1, password);
  WiFiMulti.addAP(ssid, password);


  if (WiFiMulti.run(connectTimeoutMs) == WL_CONNECTED) {
    Serial.print("WiFi connected: ");
    Serial.print(WiFi.SSID());
    Serial.print(" ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("WiFi not connected!");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.println(rssi);
  if (rssi > -65) Serial.println(" Very Good");
  else   if ((rssi < -64) && (rssi > -75)) Serial.println(" Good");
  else   if ((rssi < -74) && (rssi < -85)) Serial.println(" Low");
  else   if (rssi < -84) Serial.println(" Very low");

}

void loop() {
  // put your main code here, to run repeatedly:

}
