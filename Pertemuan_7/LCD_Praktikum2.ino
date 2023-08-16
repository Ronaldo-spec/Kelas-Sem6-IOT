#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
lcd.init();
lcd.backlight();
lcd.home();
}

void scrollText(int row, String message, int delayTime, int lcdColumns)
{
for (int i = 0; i < lcdColumns; i++)
{
message = " " + message;
}
message = message + " ";
for (int pos = 0; pos < message.length(); pos++)
{
lcd.setCursor(0, row);
lcd.print(message.substring(pos, pos + lcdColumns));
delay(delayTime);
}
}

void loop() {
  lcd.home();
lcd.print("Kelompok 5 TI3B");
scrollText(1, "Kelas IoT.", 250, 16);
}
