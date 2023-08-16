#include <SimpleDHT.h>
#include <LiquidCrystal_I2C.h>
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#define pinDHT 7
#define panas D3
#define dingin D5
#define normal D4

byte temperature = 0;
byte humidity = 0;
byte data[40] = {0};

String suhu;
String date;

const char *ssid     = "Pew";
const char *password = "qwe12345";

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "asia.pool.ntp.org");

SimpleDHT11 dht11(D0);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void kelembabansuhu()
{
  dht11.read(&temperature, &humidity, data);
  for (int i = 0; i < 40; i++) {
    if (i > 0 && ((i + 1) % 4) == 0) {
    }
  }
  suhu = String(temperature)+"*C | "+String(temperature*1.8+32)+"*F";
  Serial.print("Suhu 1: ");
  Serial.println(suhu);
  delay(3000);
  if((int)temperature > 31){
    digitalWrite(panas, HIGH);
    digitalWrite(normal, LOW);
    digitalWrite(dingin, LOW);
    delay(1000);
    digitalWrite(panas, LOW);
    digitalWrite(normal, LOW);
    digitalWrite(dingin, LOW);
    delay(1000);
  }else if((int)temperature >= 29 && (int)temperature < 31){
    digitalWrite(panas, LOW);
    digitalWrite(normal, HIGH);
    digitalWrite(dingin, LOW);
    delay(1000);
    digitalWrite(panas, LOW);
    digitalWrite(normal, LOW);
    digitalWrite(dingin, LOW);
    delay(1000);
  }else if((int)temperature < 29){
    digitalWrite(panas, LOW);
    digitalWrite(normal, LOW);
    digitalWrite(dingin, HIGH);
    delay(1000);
    digitalWrite(panas, LOW);
    digitalWrite(normal, LOW);
    digitalWrite(dingin, LOW);
    delay(1000);
  }
}
void waktu(){
  timeClient.update();
  time_t epochTime = timeClient.getEpochTime();
  struct tm *ptm = gmtime ((time_t *)&epochTime);
  int hari = ptm->tm_mday;
  int bulan = ptm->tm_mon+1;
  int tahun = ptm->tm_year+1900;
  date = String(hari) + "-" + String(bulan) + "-" + String(tahun)+" "+String(timeClient.getHours())+":"+String(timeClient.getMinutes());
}

void setup()
{
  Serial.begin(115200);
  //setup wfi untuk waktu
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  timeClient.begin();
  timeClient.setTimeOffset(25200);
  lcd.init();
  lcd.backlight();
  lcd.home();
  pinMode(panas, OUTPUT);
  pinMode(normal, OUTPUT);
  pinMode(dingin, OUTPUT);
}

void loop()
{
  kelembabansuhu();
  waktu();
  lcd.home();
  lcd.print(suhu);
  lcd.setCursor(0,1);
  lcd.print(date);
}
