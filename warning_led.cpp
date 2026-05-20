int pot = 34;
int led = 18;

void setup() {

  pinMode(led, OUTPUT);

  Serial.begin(115200);
}

void loop() {

  int deger = analogRead(pot);

  Serial.println(deger);

  if(deger > 3000) {

    digitalWrite(led, HIGH);

  } else {

    digitalWrite(led, LOW);
  }

  delay(100);
}