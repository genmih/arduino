#include <WiFi.h>
#include <UniversalTelegramBot.h>

// Укажите ваш SSID и пароль Wi-Fi
const char* ssid = "Ваш_SSID";
const char* password = "Ваш_пароль";

// Укажите токен вашего бота
const char* token = "Ваш_токен";

WiFiClient gen;
UniversalTelegramBot bot(token, gen);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    
    while (numNewMessages) {
      Serial.println("New message received");
      
      for (int i = 0; i < numNewMessages; i++) {
        String chat_id = String(bot.messages[i].chat_id);
        String text = bot.messages[i].text;
        
        // Обработка полученного сообщения
        // Здесь вы можете добавить свою логику обработки сообщений
        
        // Пример отправки ответного сообщения
        bot.sendMessage(chat_id, "Привет, я Arduino!");
      }
      
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
  }
  
  delay(1000);
}
