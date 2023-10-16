#include <DHT.h>

#define DHTPIN 10    // Номер пина, к которому подключен датчик
#define DHTTYPE DHT11   // Тип датчика (DHT11 или DHT22)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C ");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  delay(10000);
}
