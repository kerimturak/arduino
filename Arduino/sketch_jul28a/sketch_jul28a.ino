/*
  ESP32 Web Server - STA Mode
  modified on 25 MAy 2019
  by Mohammadreza Akbari @ Electropeak
  https://electropeak.com/learn
*/

#include <WiFi.h>
#include <WebServer.h>

// SSID & Password
 char* ssid = "KRMTRK";  // Enter your SSID here
 char* password = "Krmtrk1997";  //Enter your Password here

WebServer server("80");  // Object of WebServer(HTTP port, 80 is defult)

void setup() {
  Serial.begin(115200);
  Serial.println("Try Connecting to ");
  Serial.println(ssid);

  // Connect to your wi-fi modem
  WiFi.begin(ssid, password);

  // Check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected successfully");
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());  //Show ESP32 IP on serial


  server.begin();
  Serial.println("HTTP server started");
  delay(100); 
}

void loop() {

}

// HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>My First Web Server with ESP32 - Station Mode &#128522;</h1>\
</body>\
</html>";

// Handle root url (/)
