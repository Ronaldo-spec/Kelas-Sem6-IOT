#define BLYNK_TEMPLATE_ID "TMPLYuKgeoSI"
#define BLYNK_DEVICE_NAME "AKU"
#define BLYNK_AUTH_TOKEN "SUVDPZxWnCFbSOBFKriSbLCooJyV07c5"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
#define data D3     
#define DHTTYPE DHT11 

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Rumah 🏠 🐈";
char pass[] = "12346789";

const int analogPinA0 = A0;

BlynkTimer timer;
int sensorData;
int output;
float suhu, lembab;
DHT dht(data, DHTTYPE);

void sendSensor()
{

  sensorData = analogRead(A0); //reading the sensor on A0

  if ( isnan(sensorData) ){
    Serial.println("Failed to read from Hygrometer Soil Moisture sensor!");
    return;
  } else {
    Serial.println(sensorData);
    // When the plant is watered well the sensor will read a value 380~400, I will keep the 400 
    // value but if you want you can change it below. 
  
    sensorData = constrain(sensorData,239,595);  //Keep the ranges!
    output = map(sensorData,239,595,100,0);  //Map value : 400 will be 100 and 1023 will be 0
     Serial.println(output);

    Blynk.virtualWrite(V2, output);
      if (output > 90){
       Blynk.logEvent("tanah_sangat");
      } else if(output > 80){
       Blynk.logEvent("tanah_cukup");
      } else if(output > 70){
       Blynk.logEvent("tanah_layak");
      } else if(output > 30){
       Blynk.logEvent("tanah_tidaklayak");
      } else if (output > 10){
       Blynk.logEvent("tanah_buruk");
      }
  }

}

void getSuhu()
{

  sensorData = data; //reading the sensor on A0

  if ( isnan(sensorData) ){
    Serial.println("Failed to read from DHT sensor!");
    return;
  } else {
    suhu = dht.readTemperature();
    lembab = dht.readHumidity();
    // When the plant is watered well the sensor will read a value 380~400, I will keep the 400 
    // value but if you want you can change it below. 
  
    // sensorData = constrain(sensorData,239,595);  //Keep the ranges!
    // output = map(sensorData,239,595,100,0);  //Map value : 400 will be 100 and 1023 will be 0

    Blynk.virtualWrite(V0, suhu);
    Blynk.virtualWrite(V1, lembab);
    
    if (suhu > 24 && suhu < 30){
       Blynk.logEvent("suhu_sangat_baik");
      }
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(1000L, getSuhu);
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
  }
