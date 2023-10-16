int buzzerPin = 9; // Пин для подключения пищалки
int dotDelay = 250; // Задержка для точки
int dashDelay = 500; // Задержка для тире
int wordDelay = 1000; // Задержка между словами

void setup() {
  pinMode(buzzerPin, OUTPUT); // Устанавливаем пин пищалки на выход
}

void loop() {
  tone(buzzerPin, 1000, dashDelay);
  String message = "kaliningrad"; // Текст, который нужно преобразовать в звуковой код Морзе
  for (int i = 0; i < message.length(); i++) {
    char c = toupper(message[i]);
    if (c == ' ') { // Если символ - пробел, то делаем задержку между словами
      delay(wordDelay);
    } 
    else {
      String morseCode = getMorseCode(c); // Получаем код Морзе для символа
      for (int j = 0; j < morseCode.length(); j++) {
        if (morseCode[j] == '.') { // Если символ - точка, то проигрываем короткий звук
          tone(buzzerPin, 1000, dotDelay);
        } 
        else if (morseCode[j] == '-') { // Если символ - тире, то проигрываем длинный звук
          tone(buzzerPin, 1000, dashDelay);
        }
        noTone(buzzerPin); // Останавливаем звук
        delay(dotDelay); // Между символами делаем небольшую задержку
      }
    }
  }
}

String getMorseCode(char c) { // Функция для получения кода Морзе для символа
  switch (c) {
    case 'A':
      return ".-";
    case 'B':
      return "-...";
    case 'C':
      return "-.-.";
    case 'D':
      return "-..";
    case 'E':
      return ".";
    case 'F':
      return "..-.";
    case 'G':
      return "--.";
    case 'H':
      return "....";
    case 'I':
      return "..";
    case 'J':
      return ".---";
    case 'K':
      return "-.-";
    case 'L':
      return ".-..";
    case 'M':
      return "--";
    case 'N':
      return "-.";
    case 'O':
      return "---";
    case 'P':
      return ".--.";
    case 'Q':
      return "--.-";
    case 'R':
      return ".-.";
    case 'S':
      return "...";
    case 'T':
      return "-";
    case 'U':
      return "..-";
    case 'V':
      return "...-";
    case 'W':
      return ".--";
    case 'X':
      return "-..-";
    case 'Y':
      return "-.--";
    case 'Z':
      return "--..";
    default:
      return "";
  }
}