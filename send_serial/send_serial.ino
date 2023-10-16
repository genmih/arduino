#include <TimeLib.h> // Подключаем библиотеку TimeLib для работы со временем

void setup() {
  // Инициализация последовательного порта с битовой скоростью 9600
  Serial.begin(9600);
}

void loop() {
// long epochTime = Serial.parseInt(); // Получаем текущее время в формате Unix timestamp
  /*
  int year = year(epochTime);           // Получаем год
  int month = month(epochTime);         // Получаем месяц
  int day = day(epochTime);             // Получаем день
  int hour = hour(epochTime);           // Получаем часы
  int minute = minute(epochTime);       // Получаем минуты
  int second = second(epochTime);       // Получаем секунды
  */
  // Отправка сообщения в последовательный порт
  Serial.println("Hello, world!");
  //Serial.println(epochTime);
  // Задержка в 10 секунд
  delay(10000);
}