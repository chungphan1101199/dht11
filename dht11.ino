#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11
int LDR = A0;
int value;
#define dht_dpin 4
DHT dht(dht_dpin, DHTTYPE); 
void setup(void)
{ 
  dht.begin();
  pinMode(0,OUTPUT);
  Serial.begin(115200);
  Serial.println("Humidity and temperature\n\n");
//  delay(700);
}
void loop() {
    float h = dht.readHumidity();
    float t = dht.readTemperature(); 
    value = analogRead(LDR);        
    Serial.print("Humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("Temperature = ");
    Serial.print(t); 
    Serial.println("*C  ");
    Serial.print("Value sensor light = ");
    Serial.println(value);
    delay(1000);
}
