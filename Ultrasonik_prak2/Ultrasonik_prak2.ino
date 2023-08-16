#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2)

#define triggerPin D6
#define echoPin D5

//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(9600); // Starts the serial communication
  pinMode(triggerPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
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
  // Clears the trigPin
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
   lcd.home();
lcd.print("Polinema");
scrollText(1, "Kelas IoT.", 250, 16);
  
  delay(1000);
}
