// DHT11 library


    #include "DHT.h"

    #define DHTPIN D7
    #define DHTTYPE DHT11
    DHT dht(DHTPIN, DHTTYPE);
// DHT11 variables

void ReadSensors() {
  Temperature = round(dht.readTemperature() * 10) / 10.0;
  Humidity = round(dht.readHumidity() * 10) / 10.0;
  HeatIndex = round(dht.computeHeatIndex(Temperature, Humidity, false) * 10) / 10.0;

  Light = analogRead(LDRPIN);

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
    Serial.println(Light);

   
  }
}
