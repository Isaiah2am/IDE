#include "DHT.h"
#define DHTPIN D7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

 void ReadSensors() {


  Temperature = round(dht.readTemperature() * 10) / 10.0;
  Humidity = round(dht.readHumidity() * 10) / 10.0;
  HeatIndex = round(dht.computeHeatIndex(Temperature, Humidity, false) * 10) / 10.0;
  Light = analogRead(A0);
Serial.println(Temperature);

  if (Light < 500){
    digitalWrite(D3, HIGH);
  } else  {
    digitalWrite(D3, LOW);
  }

  }

