#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "HW2_IOT";
const char* password = "9629041_9639035";

IPAddress local_ip(192,168,4,31);
IPAddress gateway(192,168,4,1);
IPAddress subnet(255,255,255,0);
ESP8266WebServer server(80);
int LED = 16;


void setup() {
  Serial.begin(9000);
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  pinMode(LED,OUTPUT);
  server.on("/", handle_OnConnect);
  server.on("/ledon", handle_ledon);
  server.on("/ledoff", handle_ledoff);
  server.on("/ldr", handle_ldr);
  server.onNotFound(handle_NotFound);
  
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
}

void handle_OnConnect() {
  server.send(200, "text/html", SendHTML(0)); 
}

void handle_ledon() {
  digitalWrite(LED,HIGH);
  server.send(200, "text/html", SendHTML(0)); 
}

void handle_ledoff() {
  digitalWrite(LED,LOW);
  server.send(200, "text/html", SendHTML(0)); 
}

void handle_ldr() {
  int sensorvalue=analogRead(A0);
  int value = map(sensorvalue, 0,1023, 0,100);
  server.send(200, "text/html", SendHTML(value)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(int n){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>LED Control</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #1abc9c;}\n";
  ptr +=".button-on:active {background-color: #16a085;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>HW2 IOT Hassan Kazemi Tehrani-Shaghayegh Ghasemi</h1>\n";
  ptr +="<h3>Using Access Point(AP) Mode</h3>\n";

  ptr +="<p>Show LDR figure</p><a class=\"button button-on\" href=\"/ldr\">Show</a>\n";
  ptr +="<p>Turn on LED</p><a class=\"button button-on\" href=\"/ledon\">ON</a>\n";
  ptr +="<p>Turn off LED</p><a class=\"button button-off\" href=\"/ledoff\">OFF</a>\n";
  if(n!=0){
    ptr +="<p>Value is :</p><a class=\"button button-on\">"+String(n)+"</a>\n";
  }


  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
