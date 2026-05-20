void setup() {

  Serial.begin(115200);
}

void loop() {

  int deger = analogRead(34);

  Serial.println(deger);

  delay(200);
}