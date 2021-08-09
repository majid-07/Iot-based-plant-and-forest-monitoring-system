#include <ESP8266WiFi.h>
#define NAME "guest" // wifi name
#define PASS "ansprotech@07" // wifi password    
String data1="", id="";
const char* host = "192.168.0.130";
WiFiClient client;
 String dd="";
void setup() {
  Serial.begin(9600);
  while (!Serial) continue;
  WiFi.mode(WIFI_STA);
  WiFi.begin(NAME, PASS);
  Serial.print("Connecting");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP ahddress: ");
  Serial.println(WiFi.localIP());
}
 
void loop() {
Serial.println("Waiting for data");
  if(Serial.available())
 {
  
  while(Serial.available())
  {
   delay(3);
   char data = Serial.read();
   data1 += data; 
  }
 }
 if(data1!=0)
 {
  
  Serial.println(data1);
if (client.connect(host, 7000))
  {
    Serial.print("Connected to: ");
    Serial.println(host);
    Serial.println("sending");
   // Serial.println(data1);
    client.println(data1); 
    delay(2000);
    data1="";
    client.stop();
  }
  }
  client.stop();
  delay(1000);
 }
