#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int mq135_aqi_sensor = A0;
const int green_led = 8;
const int red_led = 10;
const int buzzer = 11;
int aqi_ppm = 0;

void setup() {
  pinMode(mq135_aqi_sensor, INPUT);
  pinMode(green_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(green_led, LOW);
  digitalWrite(red_led, LOW);
  digitalWrite(buzzer, LOW);

  Serial.begin(9600);
  lcd.begin(16, 2);

  Serial.println("AQI Alert System");
  lcd.setCursor(0, 0);
  lcd.print("AQI Alert System");
  delay(500);
}

void loop() {
  float humi = dht.readHumidity();
  float tempc = dht.readTemperature();
  
  Serial.print("Humidity: ");
  Serial.print(humi);
  Serial.print("% Temperature: ");
  Serial.print(tempc);
  Serial.println("°C");

  aqi_ppm = analogRead(mq135_aqi_sensor);

  Serial.print("Air Quality: ");
  Serial.println(aqi_ppm);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Air Quality: ");
  lcd.print(aqi_ppm);

  if ((aqi_ppm >= 0) && (aqi_ppm <= 50)) {
    lcd.setCursor(0, 1);
    lcd.print("AQI Good");
    Serial.println("AQI Good");
    digitalWrite(green_led, HIGH);
    digitalWrite(red_led, LOW);
    digitalWrite(buzzer, LOW);
  } else if ((aqi_ppm >= 51) && (aqi_ppm <= 100)) {
    lcd.setCursor(0, 1);
    lcd.print("AQI Moderate");
    Serial.println("AQI Moderate");

    for (int i = 0; i < 5; i++) {
      digitalWrite(green_led, HIGH);
      delay(100);
      digitalWrite(green_led, LOW);
      delay(100);
    }

    digitalWrite(red_led, LOW);
    digitalWrite(buzzer, LOW);
  } else if ((aqi_ppm >= 101) && (aqi_ppm <= 200)) {
    lcd.setCursor(0, 1);
    lcd.print("AQI Unhealthy");
    Serial.println("AQI Unhealthy");
    digitalWrite(green_led, HIGH);
    digitalWrite(red_led, LOW);
    digitalWrite(buzzer, HIGH);
  } else if ((aqi_ppm >= 201) && (aqi_ppm <= 300)) {
    lcd.setCursor(0, 1);
    lcd.print("AQI V. Unhealthy");
    Serial.println("AQI V. Unhealthy");
    Serial.println("Temperature: 23 degrees");
    Serial.println("Humidity:82%");
    digitalWrite(green_led, LOW);
    digitalWrite(red_led, HIGH);
    digitalWrite(buzzer, HIGH);
  } else if (aqi_ppm >= 301) {
    lcd.setCursor(0, 1);
    lcd.print("AQI Hazardous");
    Serial.println("AQI Hazardous");
    digitalWrite(green_led, LOW);
    digitalWrite(red_led, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  delay(1000);
}
