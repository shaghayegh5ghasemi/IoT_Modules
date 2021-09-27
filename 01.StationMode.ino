#include <ESP8266WiFi.h>


void setup()
{
  Serial.begin(9000);
  Serial.println();
  Serial.setDebugOutput(false);
  WiFi.mode(WIFI_STA);
  int numberofssid = WiFi.scanNetworks();
  Serial.println("list of SSIDs");
  for(int i=0;i<numberofssid;i++){
    Serial.println(WiFi.SSID(i));
  }
  WiFi.begin("iPhone", "shayshay4");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
}
