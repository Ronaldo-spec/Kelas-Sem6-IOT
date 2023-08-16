#define LedMerah D0 
#define LedHijau D1 
#define LedBiru D2 

void setup() {
Serial.begin(9600);
pinMode(LedMerah, OUTPUT);
pinMode(LedHijau, OUTPUT);
pinMode(LedBiru, OUTPUT); // atur pin digital sebagai output.
}
void RunningLED() {
digitalWrite(LedMerah, HIGH);
digitalWrite(LedHijau, LOW);
digitalWrite(LedBiru, LOW);
Serial.println("LED Merah nyala");
delay(1000);
digitalWrite(LedMerah, LOW);
digitalWrite(LedHijau, HIGH);
digitalWrite(LedBiru, LOW);
Serial.println("LED Hijau nyala");
delay(1000);
digitalWrite(LedMerah, LOW);
digitalWrite(LedHijau, LOW);
digitalWrite(LedBiru, HIGH);
Serial.println("LED Biru nyala");
delay(1000);
Serial.println();
}
void loop() {
RunningLED();
}
