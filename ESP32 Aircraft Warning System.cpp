#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int pot = 34;
int led = 18;
int buzzer = 5;

Adafruit_SSD1306 ekran(128, 64, &Wire, -1);

void setup() {

  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(115200);

  Wire.begin(21, 22);

  ekran.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  ekran.clearDisplay();
  ekran.setTextColor(WHITE);
}

void loop() {

  int deger = analogRead(pot);

  Serial.println(deger);

  ekran.clearDisplay();

  ekran.setTextSize(1);

  ekran.setCursor(0, 10);
  ekran.print("TEMP: ");
  ekran.println(deger);

  if(deger > 3000) {

    digitalWrite(led, HIGH);

    tone(buzzer, 1000);

    ekran.setCursor(0, 40);
    ekran.println("WARNING!");

  } else {

    digitalWrite(led, LOW);

    noTone(buzzer);

    ekran.setCursor(0, 40);
    ekran.println("NORMAL");
  }

  ekran.display();

  delay(100);
}