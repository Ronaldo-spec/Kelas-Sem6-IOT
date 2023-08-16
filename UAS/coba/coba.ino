#define BLYNK_TEMPLATE_ID "TMPLYuKgeoSI"
#define BLYNK_DEVICE_NAME "AKU"
#define BLYNK_AUTH_TOKEN "SUVDPZxWnCFbSOBFKriSbLCooJyV07c5"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


#define DHTPIN D3     
#define DHTTYPE DHT11

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Rumah 🏠 🐈";
char pass[] = "12346789";

//------------ TANAH ----------------
#define moisture A0
int sensorTanah = analogRead(A0);
int tanah;

//------------ DHT11 ----------------
#include "DHT.h"
#define DHTPIN D3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
float suhu;
float hmd;


//------------ FUZZY ----------------
#include <Fuzzy.h>
Fuzzy *fuzzy = new Fuzzy();

// INPUT  tanah
FuzzySet *gersang = new FuzzySet(0, 20, 40, 60);
FuzzySet *optimal = new FuzzySet(50, 60, 70, 80);
FuzzySet *becek = new FuzzySet(70, 80, 90, 100 );

// INPUT suhu
FuzzySet *dingin = new FuzzySet(0, 0, 20, 25);
FuzzySet *hangat = new FuzzySet(20, 25, 25, 30);
FuzzySet *panas = new FuzzySet(25, 30, 60, 60);

// INPUT humidity
FuzzySet *kering = new FuzzySet(0, 0, 60, 70);
FuzzySet *normal = new FuzzySet(60, 70, 70, 80);
FuzzySet *basah = new FuzzySet(70, 80, 100, 100 );
//------------------------------------------------------ 
// OUTPUT SUHU
FuzzySet *q = new FuzzySet(0, 8, 16, 24);
FuzzySet *w = new FuzzySet(23, 25, 27, 29);
FuzzySet *e = new FuzzySet(30, 40, 50, 60);

// OUTPUT tanah
FuzzySet *a = new FuzzySet(0, 10, 20, 40);
FuzzySet *s = new FuzzySet(40, 60, 60, 80);
FuzzySet *d = new FuzzySet(70, 80, 90, 100);


//---------- TAB LAIN --------------
#include "fuzzy_set.h" 
#include "fuzzy_rule.h" 





void setup()
{
  
  Serial.begin(9600);
  //randomSeed(analogRead(0));

  //------------ TANAH ----------------
  
  //------------ DHT11 ----------------
  dht.begin();
  //------------ PANGGIL FUNGSI  ----------------
  fuzzySet();
  fuzzyRule();  
}

void loop()
{
  suhu = dht.readTemperature();
  hmd = dht.readHumidity();
  sensorTanah = constrain(sensorData,239,595);
  tanah = map(sensorTanah,239,595,100,0);

  //-------------------
  Serial.print("Tanah :");
  Serial.print(tanah); Serial.println(" %");
  Serial.print("Suhu :");
  Serial.print(suhu); Serial.println(" C");
  Serial.print("Humidity :");
  Serial.print(hmd); Serial.println(" %");

  fuzzy->setInput(1,tanah);
  fuzzy->setInput(2,suhu);
  fuzzy->setInput(3,hmd);
  
}
  
