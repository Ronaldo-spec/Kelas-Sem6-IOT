#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); //atau 0x3F

#define triggerPin D6
#define echoPin D5
#define Ledmerah D3
#define Ledbiru D0
#define Ledhijau D4


void setup() {
   lcd.init();
   pinMode(triggerPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(BUILTIN_LED, OUTPUT);
  pinMode(Ledmerah, OUTPUT);
  pinMode(Ledbiru, OUTPUT);
  pinMode(Ledhijau, OUTPUT);
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
   
   if (jarak <= 1 ) {
   digitalWrite(Ledmerah, LOW);
   digitalWrite(Ledbiru, LOW);
   digitalWrite(Ledhijau, HIGH); 
  }
     if (jarak > 1 && jarak <= 2  ) {
   digitalWrite(Ledmerah, HIGH);
   digitalWrite(Ledbiru, LOW);
   digitalWrite(Ledhijau, LOW); 
  }

     if (jarak > 2 && jarak <= 3 ) {
   digitalWrite(Ledmerah, LOW);
   digitalWrite(Ledbiru, HIGH);
   digitalWrite(Ledhijau, LOW); 
  }

     if (jarak > 3) {
   digitalWrite(Ledmerah, HIGH);
   digitalWrite(Ledbiru, HIGH);
   digitalWrite(Ledhijau, HIGH); 
   delay(1000);
   digitalWrite(Ledmerah, LOW);
   digitalWrite(Ledbiru, LOW);
   digitalWrite(Ledhijau, LOW); 
   delay(1000);
  }
  
   delay(500);
}
