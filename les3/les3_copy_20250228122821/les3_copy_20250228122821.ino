
#include <ArduinoJson.h>

JsonDocument doc;
char jsonOut[128];

void setup() {
  pinMode(D3, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);

}


void loop() {

CreateJson();


  int ldr_value = analogRead(A0);

  delay(500);

  if (ldr_value < 500){
    digitalWrite(D3, HIGH);
    delay(100);
    digitalWrite(D3, LOW);
    delay(100);
    digitalWrite(D6, HIGH);
    delay(100);
    digitalWrite(D6, LOW);
    delay(100);
    digitalWrite(D5, HIGH);
    delay(100);
    digitalWrite(D5, LOW);
    delay(100);


  }
}

  void CreateJson(){
    doc ["key"] = "value";
    doc ["key2"] = "value";

    serializeJson(doc, jsonOut);
    serializeJson(doc, Serial);
  }


