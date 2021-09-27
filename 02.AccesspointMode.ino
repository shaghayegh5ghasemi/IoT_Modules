#include <ESP8266WiFi.h>

IPAddress local_IP(192,168,4,31);
IPAddress gateway(192,168,4,1);
IPAddress subnet(255,255,255,0);

void setup()
{
  Serial.begin(9000);
  Serial.println();
  Serial.setDebugOutput(false);
  WiFi.softAP("HW2_IOT","9629041_9639035");
  WiFi.mode(WIFI_AP);
  Serial.println("Current ip:");
  Serial.println(WiFi.softAPIP());
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "IP CHANGED!" : "Failed!");
  Serial.println("Current ip:");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // put your main code here, to run repeatedly:
}
