#define BLYNK_TEMPLATE_ID "TMPLdQ6ebD9-"
#define BLYNK_DEVICE_NAME "DHT11"
#define BLYNK_AUTH_TOKEN "euA0GeXZVnihShDDiARVCTW-RIgjY5dO"


#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>  

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Adolf Hitler";
char pass[] = "asdfgh123";

#include <DHT.h>
#define DHTPIN 0
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(0, h);  //V5 is for Humidity
  Blynk.virtualWrite(2, t);  //V6 is for Temperature
}

void setup()
{
  Serial.begin(9600); // See the connection status in Serial Monitor
  Blynk.begin(auth, ssid, pass);

  dht.begin();

}

void loop()
{
  Blynk.run(); // Initiates Blynk
}
