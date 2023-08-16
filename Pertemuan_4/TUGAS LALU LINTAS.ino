#define LedMerah1 16 //D0 pin led merah
#define LedHijau1 5 //D1 pin led hijau
#define LedBiru1 4 //D2 pin led biru
#define LedMerah2 0 //D3 pin led merah
#define LedHijau2 2 //D4 pin led hijau
#define LedBiru2 14 //D5 pin led biru 
#define LedMerah3 12 //D6 pin led merah
#define LedHijau3 13 //D7 pin led hijau
#define LedBiru3 15 //D8 pin led biru
void setup() {
Serial.begin(9600);
pinMode(LedMerah1, OUTPUT);
pinMode(LedHijau1, OUTPUT);
pinMode(LedBiru1, OUTPUT); // atur pin digital sebagai output.
pinMode(LedMerah2, OUTPUT);
pinMode(LedHijau2, OUTPUT);
pinMode(LedBiru2, OUTPUT); // atur pin digital sebagai output.
pinMode(LedMerah3, OUTPUT);
pinMode(LedHijau3, OUTPUT);
pinMode(LedBiru3, OUTPUT); // atur pin digital sebagai output.
}
void RunningLED() {
//kondisi 1
digitalWrite(LedMerah1, HIGH);
digitalWrite(LedMerah2, HIGH);
digitalWrite(LedMerah3, LOW);
digitalWrite(LedBiru1, LOW);
digitalWrite(LedBiru2, LOW);
digitalWrite(LedBiru3, LOW);
digitalWrite(LedHijau1, LOW);
digitalWrite(LedHijau2, LOW);
digitalWrite(LedHijau3, HIGH);
Serial.println("kondisi satu");
delay(5000);
//kondisi biru
digitalWrite(LedMerah1, HIGH);
digitalWrite(LedMerah2, HIGH);
digitalWrite(LedMerah3, LOW);
digitalWrite(LedBiru1, HIGH);
digitalWrite(LedBiru2, LOW);
digitalWrite(LedBiru3, LOW);
digitalWrite(LedHijau1, LOW);
digitalWrite(LedHijau2, LOW);
digitalWrite(LedHijau3, LOW);
Serial.println("kondisi biru1");
delay(500);
//kondisi 2
digitalWrite(LedMerah1, LOW);
digitalWrite(LedMerah2, HIGH);
digitalWrite(LedMerah3, HIGH);
digitalWrite(LedBiru1, LOW);
digitalWrite(LedBiru2, LOW);
digitalWrite(LedBiru3, LOW);
digitalWrite(LedHijau1, HIGH);
digitalWrite(LedHijau2, LOW);
digitalWrite(LedHijau3, LOW);
Serial.println("kondisi dua");
delay(5000);
//kondisi biru
digitalWrite(LedMerah1, LOW);
digitalWrite(LedMerah2, HIGH);
digitalWrite(LedMerah3, HIGH);
digitalWrite(LedBiru1, LOW);
digitalWrite(LedBiru2, HIGH);
digitalWrite(LedBiru3, LOW);
digitalWrite(LedHijau1, LOW);
digitalWrite(LedHijau2, LOW);
digitalWrite(LedHijau3, LOW);
delay(500);
//kondisi 3
digitalWrite(LedMerah1, HIGH);
digitalWrite(LedMerah2, LOW);
digitalWrite(LedMerah3, HIGH);
digitalWrite(LedBiru1, LOW);
digitalWrite(LedBiru2, LOW);
digitalWrite(LedBiru3, LOW);
digitalWrite(LedHijau1, LOW);
digitalWrite(LedHijau2, HIGH);
digitalWrite(LedHijau3, LOW);
Serial.println("kondisi tiga");
delay(5000);
//kondisi biru
digitalWrite(LedMerah1, HIGH);
digitalWrite(LedMerah2, LOW);
digitalWrite(LedMerah3, HIGH);
digitalWrite(LedBiru1, LOW);
digitalWrite(LedBiru2, LOW);
digitalWrite(LedBiru3, HIGH);
digitalWrite(LedHijau1, LOW);
digitalWrite(LedHijau2, LOW);
digitalWrite(LedHijau3, LOW);
delay(500);
Serial.println();
}
void loop() {
RunningLED();
}
