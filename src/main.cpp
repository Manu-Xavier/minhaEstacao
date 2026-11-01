#include <Arduino.h>
#include <DHT.h>

static const int DHTPIN = 5;
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup(){
  Serial.begin(115200);
  Serial.println(F("Testando o DHT22!"));

  dht.begin();
}

void loop(){
  delay(5000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(h) || isnan(t)){
    Serial.println("Falha na leitura do DHT");
    return;
  }

  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Umidade: ");
  Serial.print(h);

  Serial.print("%  Temperatura: ");
  Serial.print(t);
  Serial.print("°C Sensacao termica: ");

  Serial.print(hic);
  Serial.println("°C ");
}