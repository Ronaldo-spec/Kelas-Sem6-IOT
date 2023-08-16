#define PIN_LDR A0 //oytput dari ldr
#include "DHT.h"
#define GPI04 5     
#define DHTTYPE DHT11   // DHT 11
#define Ledbiru D2
#define Ledhijau D3
#define Ledmerah D4
const int sensor_pin = A0;
DHT dht(D3, DHT11);

void setup() {
  Serial.begin(115200);
  Serial.println("DHTxx test!");
  dht.begin();
  pinMode(Ledmerah, OUTPUT);
  pinMode(Ledbiru, OUTPUT);
  pinMode(Ledhijau, OUTPUT);
}

void loop() {
 int a = analogRead(A0);
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  float m;

  m = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );

  Serial.print("Soil Moisture(in Percentage) = ");
  Serial.print(m);
  Serial.println("%");

 
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Celcius : ");
  Serial.print(t);
  Serial.print("Cahaya : ");
  Serial.print(a);
  

  
 if (t < 30 && m <500) {
    digitalWrite(Ledbiru, HIGH);
    digitalWrite(Ledhijau, LOW);
    digitalWrite(Ledmerah, LOW); 
    Serial.println("suhu dingin atau kelembapan turun ");
  }

    if ( t >= 30 && m >= 500 || t <32 && m <600) {
    digitalWrite(Ledbiru, LOW); 
    digitalWrite(Ledhijau, HIGH);
    digitalWrite(Ledmerah, LOW); 
    Serial.println("suhu sedang dan tanah sedang ");
  }

    if (t >= 32 && m >=600) {
    digitalWrite(Ledhijau, LOW);
    digitalWrite(Ledmerah, HIGH);
    digitalWrite(Ledbiru, LOW); 
    Serial.println("suhu hangat atau kelembapan naik, cahaya terang ,dan tanah basah ");
  }
 delay(2000);
}
