#include <TinyGPS++.h>
#include <dht.h>
#include <SoftwareSerial.h>  
#define dht_apin A1 
#define DHTTYPE DHT11   // DHT 11
#define pump 10// pump
#define soil 11
int mq=A5; 
int fire=8;
SoftwareSerial mySerial(4, 3);/* (Rx, Tx) */
TinyGPSPlus gps;      
volatile float minutes, seconds;
volatile int degree, secs, mins;
String lati,lon;
dht DHT;
String data1="";
String l, t;
  double lat_val, lng_val;
void setup() {
  Serial.begin(9600); /* Define baud rate for serial communication */
  mySerial.begin(9600); /* Define baud rate for software serial communication */
  pinMode(mq,INPUT);
  pinMode(pump, OUTPUT);
  pinMode(soil, INPUT);
  pinMode(fire, INPUT);
  pinMode(A2, INPUT);// for x
  pinMode(A3, INPUT);// for y
  pinMode(A4, INPUT);// for z
  //Serial.println("plant monitoring system: ");
}
void loop() {

  int soil_s=digitalRead(soil);
  int f=digitalRead(fire);
  int m=analogRead(mq);
  int x=analogRead(A2);
  int y=analogRead(A3);
  int z=analogRead(A4);
//  Serial.println(x);
//  Serial.println(y);
//  Serial.println(z);

  String adxl=String(x)+","+String(y)+","+String(z);
//  Serial.print("soil :");
//  Serial.println(soil_s);
//  Serial.print("MQ2: ");
//  Serial.println(m);
//  Serial.print("vibration sensor : ");
 //Serial.println(f);
  DHT.read11(dht_apin);
  int h=DHT.humidity;
  int tt=DHT.temperature;
//    Serial.print("Current humidity = ");
//    Serial.print(DHT.humidity);
//    Serial.print("%  ");
//    Serial.print("temperature = ");
//Serial.print(t); 
//    Serial.println("C  ");
    
        smartDelay(1000); /* Generate precise delay of 1ms */
        unsigned long start;
      
        bool loc_valid;
        lat_val = gps.location.lat(); /* Get latitude data */
        loc_valid = gps.location.isValid(); /* Check if valid location data is available */
        lng_val = gps.location.lng(); /* Get longtitude data */
        lat_val=12.915506;
        lng_val=77.60157;
        l="12.915506";
        t="77.60157";
//       Serial.println(l);
//       Serial.println(t);

//          Serial.print("Latitude: ");
//          Serial.println(lat_val, 6);
//          Serial.print("Longitude: ");
//          Serial.println(lng_val, 6);
//          delay(1000);

   data1=String(m)+"#"+String(adxl)+"#"+String(lat_val,6)+"#"+String(lng_val,6)+"#"+String(f)+"#"+String(h)+"#"+String(tt)+"#"+String(soil_s);
   Serial.println(data1);
   delay(4000);
if(soil_s==0)
{ //SendMessage();
  digitalWrite(pump,LOW);
  //Serial.println("water sprey is off");
}
if(soil_s==1)
{
  SendMessage();
  digitalWrite(pump,HIGH);
  //Serial.println("water sprey is on");
}


if(f==1)
{
  SendMessagef();
 // Serial.println("fire is off");
  
}
if(f==0)
{
  //ndMessagef();
 // Serial.println("fire is on");
  
}  

if(m>300)
{
  SendMessagemq();
 // Serial.println("plant is vibrating");
} 
   
delay(1000);       
}



static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (Serial.available())  /* Encode data read from GPS while data is available on serial port */
      gps.encode(Serial.read());
    /* Encode basically is used to parse the string received by the GPS and to store it in a buffer so that information can be extracted from it */
  } while (millis() - start < ms);
}





 void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"9980400837\"\r"); // Replace x with mobile number
  delay(1000);
  String m="no_water http://maps.google.com/maps?daddr="+String(lat_val)+","+String(lng_val);// l="12.915506"; t="77.60157";
  //no_water http://maps.google.com/maps?daddr=12.915506,77.60157;

  mySerial.println(m);
  //Serial.println("from arduino");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
 void SendMessagef()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"dddd\"\r"); // Replace x with mobile number
  delay(1000);
  String m="fire_detect http://maps.google.com/maps?daddr="+String(lat_val)+","+String(lng_val);

  mySerial.println(m);
  //Serial.println("from arduino");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}


void SendMessagemaxt()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"sssss\"\r"); // Replace x with mobile number
  delay(1000);
  String m="max_tem http://maps.google.com/maps?daddr="+String(lat_val)+","+String(lng_val);

   mySerial.println(m);
  //Serial.println("from arduino");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
void SendMessagemq()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"dddddd\"\r"); // Replace x with mobile number
  delay(1000);
  String m="polution http://maps.google.com/maps?daddr="+String(lat_val)+","+String(lng_val);

   mySerial.println(m);
  //Serial.println("from arduino");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
