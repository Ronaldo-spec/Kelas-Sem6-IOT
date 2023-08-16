#define BLYNK_TEMPLATE_ID "TMPLq5v-SHDU"
#define BLYNK_DEVICE_NAME "CobaLEDDhimas"
#define BLYNK_AUTH_TOKEN "itGkFZGjXsKfPnsOhLCG_hbwdo0p9kgf"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Fuzzy.h>
#include <SimpleDHT.h>

#define kdrAir A0
#define sensorFlame D0
#define pinDHTGabah D2
#define pinDHTApi D1

SimpleDHT11 dht11(pinDHTGabah);
SimpleDHT22 dht22(pinDHTApi);

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Pew";
char pass[] = "qwe12345";

float nyalaApi, suhuKmp, suhuGbh, kadarAir;

byte suhugbh = 0;
byte hmdtgbh = 0;
byte suhukmp = 0;
byte hmdtkmp = 0;

Fuzzy *fuzzy = new Fuzzy();

// suhu kompor
FuzzySet *kecil = new FuzzySet(30, 35, 38, 43);
FuzzySet *sedang = new FuzzySet(40, 45, 50, 55);
FuzzySet *besar = new FuzzySet(50, 60, 65, 70);

// suhu gabah
FuzzySet *kurang = new FuzzySet(25, 30, 35, 40);
FuzzySet *optimal = new FuzzySet(35, 40, 40, 48);
FuzzySet *panas = new FuzzySet(45, 50, 55, 60);

// Kadar air
FuzzySet *rendah = new FuzzySet(10, 13, 16, 17);
FuzzySet *medium = new FuzzySet(16, 20, 22, 23);
FuzzySet *tinggi = new FuzzySet(22, 24, 27, 33);

// Output
FuzzySet *apiKecil = new FuzzySet(1, 1, 1, 2);
FuzzySet *apiNormal = new FuzzySet(1, 2, 2, 2);
FuzzySet *apiBesar = new FuzzySet(2, 3, 3, 4);

FuzzySet *kadarGiling = new FuzzySet(1, 1, 1, 1);
FuzzySet *kadarSimpan = new FuzzySet(2, 2, 2, 2);
FuzzySet *kadarPanen = new FuzzySet(3, 3, 3, 3);

#include "fuzzy_rule.h"
#include "fuzzy_rule2.h"

float getADC(int aDCpin, int avgCount = 10) {
  float aDCAvg = 0;
  for (int i = 0; i < avgCount; i++) {
    aDCAvg = aDCAvg + analogRead(aDCpin);
    delay(1);
  }
  aDCAvg = aDCAvg / avgCount;
  return aDCAvg;
}

void getSuhuGabah(){
  dht11.read(&suhugbh, &hmdtgbh, NULL);
  suhuGbh = suhugbh;
  Blynk.virtualWrite(V0, int(suhuGbh));
}
void getSuhuKompor(){
  dht22.read(&suhukmp, &hmdtkmp, NULL);
  suhuKmp = suhukmp;
  Blynk.virtualWrite(V1, int(suhuKmp));
}
void getApiNyala(){
  nyalaApi = digitalRead(sensorFlame);
  
  if(nyalaApi==0){
    Blynk.virtualWrite(V2, "Api Mati");
  }else if(nyalaApi==1){
    Blynk.virtualWrite(V2, "Api Nyala");
  }
}
void getKadarAir(){
  float nilaiSensor = getADC(kdrAir);
  nilaiSensor = roundf(nilaiSensor * 1000) / 1000;
  kadarAir = map(nilaiSensor, 0.0, 1023.0, 100.0, 0.0) + 13;
  Blynk.virtualWrite(V4, int(kadarAir));
}
void getData(){
  getSuhuGabah();
  getSuhuKompor();
  getApiNyala();
  getKadarAir();
}

void setup() {
  // Set the Serial output
  Serial.begin(9600);
  Serial.println("Monitoring oven gabah");
  Blynk.begin(auth, ssid, pass);
  pinMode(kdrAir, INPUT);
  pinMode(sensorFlame, INPUT);
  rule();
  rule2();
}

void loop() {
//  nyalaApi = random(0,2);
//  suhuKmp = random(30, 66);
//  suhuGbh = random(32, 55);
//  kadarAir = random(16, 25);

  getData();
  Serial.println("Data dari sensor: ");
  Serial.print("\tNyala: ");
  Serial.print(nyalaApi);
  Serial.print("\tSuhuKmp: ");
  Serial.print(suhuKmp);
  Serial.print("\tsuhuGbh: ");
  Serial.print(suhuGbh);
  Serial.print("\tkadarAir: ");
  Serial.println(kadarAir);
  
  fuzzy->setInput(1, suhuKmp);
  fuzzy->setInput(2, suhuGbh);
  fuzzy->setInput(3, kadarAir);

  fuzzy->fuzzify();

  float output1 = fuzzy->defuzzify(1);
  float output2 = fuzzy->defuzzify(2);
  Serial.println("Data fuzzy: ");
  Serial.print("\tapiKecil-> ");
  Serial.print(apiKecil->getPertinence());
  Serial.print(", apiNormal-> ");
  Serial.print(apiNormal->getPertinence());
  Serial.print(", apiBesar-> ");
  Serial.println(apiBesar->getPertinence());
  Serial.print("\tkadarGiling-> ");
  Serial.print(kadarGiling->getPertinence());
  Serial.print(", kadarSimpan-> ");
  Serial.print(kadarSimpan->getPertinence());
  Serial.print(", kadarPanen-> ");
  Serial.println(kadarPanen->getPertinence());

  Serial.println("Output fuzzy: ");
  Serial.print("\tKeadaan Suhu: ");
  Serial.print(output1);
  Serial.print("  |  Kadar Air: ");
  Serial.print(output2);
  Serial.print("\n\n");
  if(output2<1.5){
    Blynk.virtualWrite(V3, "Kadar Giling");
  }else if(output2>1.5 && output1<3){
    Blynk.virtualWrite(V3, "Kadar Simpan");
  }else if(output2>2.5){
    Blynk.virtualWrite(V3, "Kadar Panen");
  }else{
    Blynk.virtualWrite(V3, "Kadar Panen");
  }
  if(output1<1.5){
    Blynk.virtualWrite(V5, "Api Kecil");
    Serial.println("Kecil");
  }else if(output1>1.5 && output1<2.5){
    Blynk.virtualWrite(V5, "Api Normal");
    Serial.println("Normal");
  }else if(output1>2.5){
    Blynk.virtualWrite(V5, "Api Besar");
    Serial.println("Besar");
  }
  delay(2000);
}
