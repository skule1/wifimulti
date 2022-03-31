Here are three versions of Arduino sketches, handling multiple WiFI connections with the ESP microcontrollers. Both versions of the ESP controllers can be uses, the ESP32 and ESP8266 versions.

Also, here are a presentation of two eays to connect two ESP-controllers by WiFi connection, one device is the client and the other is the server.

In the first case the client make a request to the server, which is responding by establishing the connection. Then the data between the client and server are excanged and the connection is terminated immedately.

In the second case the connection is established permanently until the client is closing it by a 'stop' command. The server is then able to update the client at any time withing the connected time session. Other clients are locked out from the server while the first connection session is active.
