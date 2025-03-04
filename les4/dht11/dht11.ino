#include "DHT.h"
#include <ArduinoJson.h>

#define DHTPIN D7
#define DHTTYPE DHT11
#define LDRPIN A0

DHT dht(DHTPIN, DHTTYPE);

float Temperature, Humidity, HeatIndex;
int LDRValue;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LDRPIN, INPUT);
}

void loop() {
  ReadSensors();
  delay(6000);
}

void ReadSensors() {
  Temperature = round(dht.readTemperature() * 10) / 10.0;
  Humidity = round(dht.readHumidity() * 10) / 10.0;
  HeatIndex = round(dht.computeHeatIndex(Temperature, Humidity, false) * 10) / 10.0;

  LDRValue = analogRead(LDRPIN);

  if (isnan(Temperature) || isnan(Humidity) || isnan(HeatIndex)) {
    Serial.println("DHT11 sensor error");
  } else {
    Serial.print("Temp: ");
    Serial.print(Temperature);
    Serial.println("°C");

    Serial.print("Humidity: ");
    Serial.print(Humidity);
    Serial.println("%");

    Serial.print("HeatIndex: ");
    Serial.print(HeatIndex);
    Serial.println("°C");

    Serial.print("LDR Value: ");
    Serial.println(LDRValue);

    DynamicJsonDocument doc(1024);
    doc["Temperature"] = Temperature;
    doc["Humidity"] = Humidity;
    doc["HeatIndex"] = HeatIndex;
    doc["LDRValue"] = LDRValue;

    String output;
    serializeJson(doc, output);
    Serial.println(output);

    if (LDRValue < 300) {
      Serial.println("It's dark, turning on lights!");
    } else {
      Serial.println("It's bright, lights off.");
    }
  }
}

