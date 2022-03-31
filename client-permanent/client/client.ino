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

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFiMulti.addAP(ssid1, password);
  WiFiMulti.addAP(ssid1, password);
  WiFiMulti.addAP(ssid1, password);
  WiFiMulti.addAP(ssid, password);


  if (WiFiMulti.run(connectTimeoutMs) == WL_CONNECTED) {
    Serial.print("WiFi connected: ");
    Serial.println(WiFi.SSID());
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.print(rssi);
    if (rssi > -65) Serial.println(" - Very Good");
    else if ((rssi < -64) && (rssi > -75)) Serial.println(" - Good");
    else if ((rssi < -74) && (rssi < -85)) Serial.println(" - Low");
    else if (rssi < -84) Serial.println(" - Very low");
  } else {
    Serial.println("WiFi not connected!");
  }
  Serial.println("");

  if (!client.connect("192.168.10.137", 50)) {
    Serial.println("Connection failed.");
    Serial.println("Waiting 5 seconds before retrying...");
    delay(5000);
    return;
  }
  else
    Serial.println("Connected server");


}

void loop() {
  if (Serial.available() > 0) {           // if there's bytes to read from the client,
    String c1 = Serial.readStringUntil('\r');           // read a byte, then

    if (!client.connected()) {
      if (!client.connect("192.168.10.137", 50)) {
        Serial.println("Connection failed.");
        Serial.println("Waiting 5 seconds before retrying...");
        delay(5000);
        return;
      }
      else
        Serial.println("Connected server");
    }
    //   client.println("test");
    client.print(c1);
    if (c1 == "stop") {
//      client.disconnect(void);
      client.stop();
          ESP.restart();
    }
  }

  if (client.available()) {             // if there's bytes to read from the client,
    String c = client.readStringUntil('\r');           // read a byte, then
    Serial.println(c);
  };


}
