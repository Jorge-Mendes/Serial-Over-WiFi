/*
 * ESP8266 NodeMCU AJAX Demo
 * Updates and Gets data from webpage without page refresh
 * https://circuits4you.com
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <FS.h>

#include <ESP8266mDNS.h>

// Our HTML webpage contents
#include "index.h"

// On board LED
#define LED 2

// Define enable pin
#define ENABLE D1

// Save the characters that arrive through the serial port
String lastReceivedString = "";
String allReceivedString = "";
char receivedChar;

// Defining a static IP address: local & gateway
// Default IP in AP mode is 192.168.4.1
IPAddress apIP(42, 42, 42, 42);  

// SSID and Password for the Access Point
const char *ssid = "ESPserial";
const char *password = "0123456789";

// Server on port 80
ESP8266WebServer server(80); 

//Define WiFi event handlers
WiFiEventHandler stationConnectedHandler;
WiFiEventHandler stationDisconnectedHandler;

int num_devices_connected = 0;
 
// ===================================================================
// This routine is executed when you open the IP of the AP in browser
// ===================================================================
void handleRoot() {
  // ESP12E crash when using PROGMEM: https://www.esp8266.com/viewtopic.php?f=15&t=11780
  
  // On Windows it works like this:
  //String s = MAIN_page;               // Read HTML contents
  //server.send(200, "text/html", s);   // Send web page

  // On Linux works like this:
  PGM_P s = MAIN_page;                  // Read HTML contents
  server.send_P(200, "text/html", s);   // Send web page

  // If we want to save the HTML page in the SPIFFS we need to do this
  //File file = SPIFFS.open("/index.html", "r");
  //server.streamFile(file, "text/html");
  //file.close();

  //handleGetCommands();
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
      //allReceivedString = allReceivedString + "\n" + lastReceivedString;   // nao pode ser assim porque da a ideia que a resposta tinha um \n, quando na realidade nao tinha
      allReceivedString = allReceivedString + lastReceivedString;
    }
    //Serial.print("<< ");
    //Serial.print(lastReceivedString);
  }
  lastReceivedString = "";
  server.send(200, "text/plane", allReceivedString);

  allReceivedString = "";
  
}



void handleAddCommands() {

  String texto = server.arg("texto");         // Refer: xhttp.open("GET", "ajax_inputs" + strText, true);

  File file = SPIFFS.open("/commands.txt", "a");
  if (!file) {
    //Serial.println("file open failed");
  } else {
    texto = texto + "\n";
    file.print(texto);
  }
  file.close();
}






void handleRemoveCommands() {
  // RECEBER TODOS OS CAMANDOS EXCEPTO O SELECIONADO E ESCREVER DE NOVO NO FICHEIRO

    String removerTexto = server.arg("textoRemove");         // Refer: xhttp.open("GET", "ajax_inputs" + strText, true);
  
    File file_r = SPIFFS.open("/commands.txt", "r");
    
  String allCommands = "";
  String line = "";
  while(file_r.available()) {
    //Lets read line by line from the file_r
    line = file_r.readStringUntil('\n');
    
    if (allCommands.length() == 0) {
      // https://gist.github.com/divayprakash/f6b61a5675a25d08c9dd6f68335d9ead because http://forum.arduino.cc/index.php?topic=53773.0 (#4)
      //line.trim();
      //removerTexto.trim();
      if (!line.equals(removerTexto)) {
        
allCommands = allCommands + line;
      }
    }
    else {
      // https://gist.github.com/divayprakash/f6b61a5675a25d08c9dd6f68335d9ead because http://forum.arduino.cc/index.php?topic=53773.0 (#4)
      //line.trim();
      //removerTexto.trim();
      if (!line.equals(removerTexto)) {
        allCommands = allCommands + "\n" + line;
      }
    }
  }
  file_r.close();



  //Serial.println(allCommands);
  


    File file_w = SPIFFS.open("/commands.txt", "w");
  if (!file_w) {
    //Serial.println("file open failed");
  } else {
    file_w.print(allCommands + "\n");
  }
  file_w.close();



  
  
}




void handleGetCommands() {
  // Get our predefined commands list from SPIFFS
  File file = SPIFFS.open("/commands.txt", "r");
  //size_t size = file.size();    // Returns the number of characteres
  //Serial.println(size);

  // Vector where the list of commands will be saved
  //std::vector<String> cmd_arr;

  //int cmd_arr_size = 0;
  String allCommands = "";
  String line = "";

  while(file.available()) {
    //Lets read line by line from the file
    line = file.readStringUntil('\n');
    //cmd_arr.push_back(line);
    //Serial.println(cmd_arr[cmd_arr_size]);
    //cmd_arr_size++;
    if (allCommands.length() == 0) {
      allCommands = allCommands + line;
    }
    else {
      allCommands = allCommands + ";" + line;
    }
  }
  //Serial.print("Foram carregados ");
  //Serial.print(cmd_arr_size);
  //Serial.println(" comandos");
  file.close();
  //Serial.println(allCommands);

  //server.send(200, "text/plane", cmd_arr[0]);
  server.send(200, "text/plane", allCommands);

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
  //Serial.print(">> ");
  digitalWrite(ENABLE,HIGH);
  delayMicroseconds(50);      // pauses for 50 microseconds https://www.arduino.cc/reference/en/language/functions/time/delaymicroseconds/
  Serial.print(texto);                      // This line is responsible for sending the message to the serial port
  Serial.flush();             // Espera a transmissão de dados seriais enviados terminar https://www.arduino.cc/reference/pt/language/functions/communication/serial/flush/
  delayMicroseconds(50);      // pauses for 50 microseconds https://www.arduino.cc/reference/en/language/functions/time/delaymicroseconds/
  digitalWrite(ENABLE,LOW);
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





void handleSendBaudrate() {
  String texto = server.arg("baudrate");         // Refer: xhttp.open("GET", "ajax_inputs" + strText, true);
  //Serial.print(">> ");
  //Serial.print(texto);                      // This line is responsible for sending the message to the serial port
  // https://forum.arduino.cc/index.php?topic=382040.0

  //Serial.println(texto);

  changeBaudRate(texto);

  File file = SPIFFS.open("/baudrate.txt", "w");
  if (!file) {
    //Serial.println("file open failed");
  } else {
    file.print(texto);
  }
  file.close();


  //handleGetBaudRate();
  
}



void handleGetBaudRate() {




  // Get our predefined commands list from SPIFFS
  File file = SPIFFS.open("/baudrate.txt", "r");
  //size_t size = file.size();    // Returns the number of characteres
  //Serial.println(size);

  // Vector where the list of commands will be saved
  //std::vector<String> cmd_arr;

  //int cmd_arr_size = 0;
  String allCommands = "";
  String line = "";

  while(file.available()) {
    //Lets read line by line from the file
    line = file.readStringUntil('\n');
    //cmd_arr.push_back(line);
    //Serial.println(cmd_arr[cmd_arr_size]);
    //cmd_arr_size++;
    if (allCommands.length() == 0) {
      allCommands = allCommands + line;
      //Serial.println(allCommands);
    }
    else {
      allCommands = allCommands + ";" + line;
    }
  }
  //Serial.print("Foram carregados ");
  //Serial.print(cmd_arr_size);
  //Serial.println(" comandos");
  file.close();
  //Serial.println(allCommands);

  // CASO O FICHEIRO ESTEJA VAZIO
  if (allCommands.length() < 4) {
    allCommands = "57600";
  }

  changeBaudRate(allCommands);

  //server.send(200, "text/plane", cmd_arr[0]);
  server.send(200, "text/plane", allCommands);




  
}



void changeBaudRate(String texto) {
    //Serial.print(texto.toInt());
  int baud_rate = texto.toInt();
    
  Serial.flush();
  //delay(2);
  delay(20);
  Serial.end();
  //delay(500);
  delay(100);

  //Start the serial port and wait for it to initialize
  Serial.begin(baud_rate);
  //delay(1000);
  delay(100);
}



// ===================================================================
// Setup routine
// ===================================================================
void setup(void){
  delay(1000);
  
  // Onboard LED port set to OUTPUT
  pinMode(LED,OUTPUT);
  digitalWrite(LED,HIGH);

  // ENABLE port set to OUTPUT
  pinMode(ENABLE,OUTPUT);
  digitalWrite(ENABLE,LOW);
  
  Serial.begin(57600);

  // Start SPIFFS
  // https://www.instructables.com/id/Using-ESP8266-SPIFFS/
  // https://tttapa.github.io/ESP8266/Chap11%20-%20SPIFFS.html
  // https://www.youtube.com/watch?v=pfJROpQg-Is
  // https://www.esp8266.com/viewtopic.php?f=33&t=11862
  // https://github.com/squix78/esp8266-projects/blob/master/arduino-ide/filesystem-example/filesystem-example.ino
  SPIFFS.begin();
  
  //Serial.println("\nConfiguring access point...");

  // Set-up the custom IP address
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));   // Subnet FF FF FF 00
  WiFi.softAP(ssid, password);
  
  // IP address assigned to your ESP8266
  IPAddress myIP = WiFi.softAPIP();
  //Serial.print("AP IP address: ");
  //Serial.println(myIP);


  // Start mDNS
  // https://techtutorialsx.com/2016/11/20/esp8266-webserver-resolving-an-address-with-mdns/
  // https://tttapa.github.io/ESP8266/Chap08%20-%20mDNS.html
  MDNS.begin("espserial");

  
 
  server.on("/", handleRoot);         // Which routine to handle at root location. This is display page
  server.on("/setLED", handleLed);
  server.on("/readADC", handleReceive);
  server.on("/ajax_inputs", handleSend);
  server.on("/clear_text", handleClear);
  server.on("/getCommands", handleGetCommands);
  server.on("/addCommands", handleAddCommands);
  server.on("/removeCommands", handleRemoveCommands);
  server.on("/sendBaudrate", handleSendBaudrate);
  server.on("/getBaudRate", handleGetBaudRate);
  
  // Start server
  server.begin();
  //Serial.println("HTTP server started!");

  stationConnectedHandler = WiFi.onSoftAPModeStationConnected(&onStationConnected);
  stationDisconnectedHandler = WiFi.onSoftAPModeStationDisconnected(&onStationDisconnected);
  // Source: https://github.com/esp8266/Arduino/issues/3279
}

// ===================================================================
// Loop routine
// ===================================================================
void loop(void) {
  // Handle client requests
  server.handleClient();
}

void onStationConnected(const WiFiEventSoftAPModeStationConnected& evt) {
  //Serial.println("Conectou-se um cliente!");
  num_devices_connected = num_devices_connected + 1;
  if (num_devices_connected >= 1) {
    digitalWrite(LED,LOW);
  }
}

void onStationDisconnected(const WiFiEventSoftAPModeStationDisconnected& evt) {
  //Serial.println("Desconectou-se um cliente!");
  num_devices_connected = num_devices_connected - 1;
  if (num_devices_connected == 0) {
    digitalWrite(LED,HIGH);
  }
}

// Source: https://circuits4you.com/2016/12/16/esp8266-web-server-html/
