#define PIN_LED D0 // untuk led
#define PIN_LDR A0 //oytput dari ldr

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
 int a = analogRead(A0);

 Serial.println(a);
if (a > 50) {
digitalWrite(PIN_LED, HIGH);
}
else {
digitalWrite(PIN_LED, LOW);
}
 
 delay(2000);
}
