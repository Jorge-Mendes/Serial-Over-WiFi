/*
 * ESP8266 NodeMCU AJAX Demo
 * Updates and Gets data from webpage without page refresh
 * https://circuits4you.com
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// Our HTML webpage contents
#include "index.h"

// On board LED
#define LED 2

// Save the characters that arrive through the serial port
String lastReceivedString = "";
String allReceivedString = "";
char receivedChar;

// Defining a static IP address: local & gateway
// Default IP in AP mode is 192.168.4.1
IPAddress apIP(42, 42, 42, 42);  

// SSID and Password for the Access Point
const char *ssid = "ESPJORGE";
const char *password = "123456789";

// Server on port 80
ESP8266WebServer server(80); 
 
// ===================================================================
// This routine is executed when you open the IP of the AP in browser
// ===================================================================
void handleRoot() {
  // On Windows it works like this:
  //String s = MAIN_page;               // Read HTML contents
  //server.send(200, "text/html", s);   // Send web page

  // On Linux works like this:
  PGM_P s = MAIN_page;                  // Read HTML contents
  server.send_P(200, "text/html", s);   // Send web page
}

// ===================================================================
// This routine is responsible for reading what was received on the
// serial port and put this in the received messages box of the web
// page
// This function will be called every 100 milliseconds because in
// javascript there is no action to call the function so it is called
// with the function setInterval(function()) in the index.h
// ===================================================================
void handleReceive() {
  while (Serial.available()) {
    receivedChar = (char)Serial.read();
    lastReceivedString += receivedChar;
  }
  if (lastReceivedString.length() > 0) {
    if (allReceivedString.length() == 0) {
      allReceivedString = allReceivedString + lastReceivedString;
    }
    else {
      allReceivedString = allReceivedString + "\n" + lastReceivedString;
    }
    Serial.print("<< ");
    Serial.println(lastReceivedString);
  }
  lastReceivedString = "";
  server.send(200, "text/plane", allReceivedString); 
}

// ===================================================================
// This routine is responsible for controlling the ESP8266 LED
// ===================================================================
void handleLed() {
  String ledState = "OFF";
  String t_state = server.arg("LEDstate");    // Refer: xhttp.open("GET", "setLED?LEDstate="+led, true);
  if(t_state == "1") {
    digitalWrite(LED,LOW);                    // Set LED ON
    ledState = "ON";                          // Feedback parameter
  }
  else
  {
    digitalWrite(LED,HIGH);                   // Set LED OFF
    ledState = "OFF";                         // Feedback parameter
  }
  server.send(200, "text/plane", ledState);   // Send feedback parameter to the web page
}

// ===================================================================
// This routine is responsible for sending to the serial port what
// was inserted in the sent messages box of the web page
// ===================================================================
void handleSend() {
  String texto = server.arg("texto");         // Refer: xhttp.open("GET", "ajax_inputs" + strText, true);
  Serial.print(">> ");
  Serial.println(texto);                      // This line is responsible for sending the message to the serial port
}

// ===================================================================
// This routine is responsible for clearing all the received messages
// and clear the received messages box of the web page
// ===================================================================
void handleClear() {
  //String texto = server.arg("texto2");        // Refer: xhttp.open("GET", "clear_text" + clrText, true);
  //texto="";
  allReceivedString = "";
  server.send(200, "text/plane", allReceivedString);
}

// ===================================================================
// Setup routine
// ===================================================================
void setup(void){
  delay(1000);
  
  // Onboard LED port set to OUTPUT
  pinMode(LED,OUTPUT);
  digitalWrite(LED,HIGH);
  
  Serial.begin(9600);
  
  Serial.println("\nConfiguring access point...");

  // Set-up the custom IP address
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));   // Subnet FF FF FF 00
  WiFi.softAP(ssid, password);
  
  // IP address assigned to your ESP8266
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
  server.on("/", handleRoot);         // Which routine to handle at root location. This is display page
  server.on("/setLED", handleLed);
  server.on("/readADC", handleReceive);
  server.on("/ajax_inputs", handleSend);
  server.on("/clear_text", handleClear);
  
  // Start server
  server.begin();
  Serial.println("HTTP server started!");
}

// ===================================================================
// Loop routine
// ===================================================================
void loop(void) {
  // Handle client requests
  server.handleClient();
}

// Source: https://circuits4you.com/2016/12/16/esp8266-web-server-html/
