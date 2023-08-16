#include <ESP8266WiFi.h>
#include <DHT.h>
#define LED D4
#define PIN_LDR A0

DHT dht(D3, DHT11);
const char *ssid = "Adolf Hitler";
const char *password = "asdfgh123";
const uint16_t port = 80;
const char *host = "192.168.43.214";
float t = 0, h = 0;
int a = 0;
unsigned long DHT_millis = 0;
int lampu = HIGH;
WiFiClient client;
void setWifi()
{
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(250);
    Serial.printf("Connecting to %s \n", ssid);
  }
  Serial.printf("Connected to %s \n", ssid);
}
void setSocket()
{
  while (!client.connect(host, port))
  {
    delay(250);
    Serial.printf("Connection to %s failed \n", host);
  }
  Serial.printf("Connection to %s success \n", host);
}
void setup()
{
  dht.begin();
  delay(2000);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("INOVASI IOT");
  setWifi();
  setSocket();
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
}
void loop()
{
  String response;
  if (!client.connected())
    setSocket();
  unsigned long DHT_current = millis();
  if (DHT_current - DHT_millis >= 1000)
  {
    DHT_millis = DHT_current;
    t = dht.readTemperature();
    h = dht.readHumidity();
    a = analogRead(A0);
  }
  if (isnan(t) || isnan(h))
  {
    Serial.println("DHT Failed!");
    return;
  }
  if (client.available() > 0)
  {
    response = client.readStringUntil('\n');
    Serial.print("[Response:]");
    Serial.println(response);
  }
  if (response.equalsIgnoreCase("on") )
  {
    lampu = LOW;
    delay(500);
    lampu = HIGH;
    Serial.println("Lampu: ON");
    client.println("Lampu: ON");
    digitalWrite(LED, lampu);
  }
  else if (response.equalsIgnoreCase("off") )
  {
    lampu = HIGH;
    delay(500);
    lampu = LOW;
    Serial.println("Lampu: OFF");
    client.println("Lampu: OFF");
    digitalWrite(LED, lampu);
  }
  else if (response.equalsIgnoreCase("status") )
  {
    Serial.println("[Sending Status]");
    client.print(String("") + "====== Status ======" +
                  " || LDR: " + a + " || Temp: " + t + " || Humidity: " + h  +
                 " || Lampu : " + (lampu ? "ON" : "OFF"));
  }
}
