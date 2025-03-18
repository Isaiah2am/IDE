
#define MAX_UNSIGNED_LONG 4294967295
#define DHT11ReadDelay 5000

    #include "DHT.h"
    #include <ArduinoJson.h>

    #define DHTPIN D7
    #define DHTTYPE DHT11
    #define LDRPIN A0
// GLOBAL VARIABLES
// json
char jsonOut[128];
// dht11
float Temperature = -1;
float Humidity = -1;
float HeatIndex = -1;
// light sensor
int Light = -1;
    DHT dht(DHTPIN, DHTTYPE);

    
void setup() 
{
  Serial.begin(115200);
      dht.begin();
      pinMode(LDRPIN, INPUT);
  
  SetupWifi();
  CheckWifi();
}

void loop() {
  static unsigned long previousTime = 0;
  unsigned long currentTime = millis();

  // this is separated so the LDR can work constinously
  if(currentTime - previousTime >= DHT11ReadDelay || currentTime >= MAX_UNSIGNED_LONG - DHT11ReadDelay) {
    // Clear monitor
    Serial.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    Serial.println("Reading sensors\n");
    
    ReadSensors();

    Serial.println("Creating JSON\n");

    CreateJSON();
    
    Serial.println("Sending POST\n");

    SendPOST();

    previousTime = millis();
  }

  CheckWifi();



//#include "DHT.h"
//#include <ArduinoJson.h>

//#define DHTPIN D7
//#define DHTTYPE DHT11
//#define LDRPIN A0

//DHT dht(DHTPIN, DHTTYPE);


//char jsonOut[128];

//float Temperature, Humidity, HeatIndex;
//int LDRValue;




//void setup() {
//  Serial.begin(9600);
//  dht.begin();
//  pinMode(LDRPIN, INPUT);
//}
//
//void loop() {
//  ReadSensors();
//  delay(6000);
//}

