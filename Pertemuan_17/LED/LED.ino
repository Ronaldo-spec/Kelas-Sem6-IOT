#define BLYNK_TEMPLATE_ID "TMPLNkvBK1qX"
#define BLYNK_DEVICE_NAME "LED2"
#define BLYNK_AUTH_TOKEN "Fh60fxpsnGM5Iw9JDpuCsbtvsbKRMpt5"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define LED1 D3
#define LED2 D4

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Adolf Hitler";
char pass[] = "asdfgh123";

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(LED1,OUTPUT);
}

void setup2(){
  pinMode(LED2,OUTPUT);
}

void loop(){
  Blynk.run();
}
