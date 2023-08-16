#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); //atau 0x3F

#define triggerPin D4
#define echoPin D3


void setup() {
   lcd.init();
   pinMode(triggerPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(BUILTIN_LED, OUTPUT);
}
void loop() {
   lcd.clear();
   lcd.backlight();
   lcd.home();
   long duration, jarak;
   digitalWrite(triggerPin, LOW);
   delayMicroseconds(2);
   digitalWrite(triggerPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(triggerPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   jarak = (duration/2) / 29.1;
   lcd.setCursor(0,0);
   lcd.print("Jarak : ");
   lcd.print(jarak);
   lcd.print(" cm");
   delay(1000);
}
