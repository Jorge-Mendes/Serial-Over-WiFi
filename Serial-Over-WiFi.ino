/*
 * ESP8266 NodeMCU AJAX Demo
 * Updates and Gets data from webpage without page refresh
 * https://circuits4you.com
 */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
#include "index.h" //Our HTML webpage contents with javascripts
 
#define LED 2  //On board LED


String inputString = ""; // Para guardar os caracteres que chegam pela porta série.
char inChar;


IPAddress    apIP(42, 42, 42, 43);  // Defining a static IP address: local & gateway
                                    // Default IP in AP mode is 192.168.4.1

const char *ssid = "ESPNUNO";
const char *password = "123456789";


 
ESP8266WebServer server(80); //Server on port 80
 
//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}


// Esta função vai ser chamada de 2 em 2 segundos porque 
// no javascript não existe uma acção para chamar a função
// então ela é chamada com a função setInterval(function()). 
void handleADC() { 

  while (Serial.available()) {        
    inChar = (char)Serial.read();
    inputString += inChar;      
  }

  // inputString += "<br>"; // Nem pensar
   
  server.send(200, "text/plane", inputString); 

  //inputString = ""; // Não é uma boa ideia. Aparece texto mas com o refresh de 2 s o texto tem que ser rápido.
}
 
void handleLED() {
 String ledState = "OFF";
 String t_state = server.arg("LEDstate"); //Refer  xhttp.open("GET", "setLED?LEDstate="+led, true);
 //Serial.println(t_state);
 if(t_state == "1")
 {
  digitalWrite(LED,LOW); //LED ON
  ledState = "ON"; //Feedback parameter
 }
 else
 {
  digitalWrite(LED,HIGH); //LED OFF
  ledState = "OFF"; //Feedback parameter  
 }
 
 server.send(200, "text/plane", ledState); //Send web page
}


void handleTexto() {   
  String texto = server.arg("texto"); //Refer  xhttp.open("GET", "ajax_inputs" + strText, true);
  Serial.println(texto);
 
}

void handleClearTexto() {   
  String texto = server.arg("texto2"); //Refer  xhttp.open("GET", "ajax_inputs" + strText, true);
  texto="";
  inputString = "";
  server.send(200, "text/plane", texto);
}


//==============================================================
//                  SETUP
//==============================================================
void setup(void){
  delay(1000);
  //Onboard LED port Direction output
  pinMode(LED,OUTPUT);

  Serial.begin(9600);
  Serial.println();
  Serial.println("Configuring access point...");

  //set-up the custom IP address
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));   // subnet FF FF FF 00 
  
  WiFi.softAP(ssid, password);
  // Só para saber que lhe foi atribuido um IP
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/setLED", handleLED);
  server.on("/readADC", handleADC);
  server.on("/ajax_inputs", handleTexto);
  server.on("/clear_text", handleClearTexto);
 
  server.begin();                  //Start server
  Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  server.handleClient();          //Handle client requests
}
