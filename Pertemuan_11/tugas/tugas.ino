#include <Arduino.h>
#include <ESP8266WiFi.h>
#define LED D4

const char *ssid = "Adolf Hitler";
const char *password = "asdfgh123";
const uint16_t port = 80;
const char *host = "192.168.43.214";

WiFiClient client;

void connect_wifi()
{
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
  delay(250);
}

void connect_server()
{
  while (!client.connect(host, port))
  {
    Serial.printf("\n[Connecting to %s ... ", host);
    delay(1000);
    return;
  }
  Serial.println("connected]");
  delay(1000);
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Contoh penggunaan socket client");
  connect_wifi();
  connect_server();
  pinMode(LED,OUTPUT);
}

void loop()
{
  if (client.connected())
  {
    Serial.print("[Response:]");
    String line = client.readStringUntil('\n');
    Serial.println(line);
    if (line.equalsIgnoreCase("on"))
    {
      pinMode(LED, HIGH);
      delay(500);
      pinMode(LED, LOW);
    } else if (line.equalsIgnoreCase("off"))
    { 
      pinMode(LED, LOW);
      delay(500);
      pinMode(LED, HIGH);
    }
  }else{
    connect_server();
  }
  delay(250);
}
