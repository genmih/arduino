import serial
import time
import requests

# Параметры соединения с Arduino
ser = serial.Serial('COM3', 9600, timeout=1)

# Токен и ID чата Telegram
TOKEN = 'your_token'
CHAT_ID = 'your_chat_id'

# URL для отправки сообщений через Telegram API
URL = 'https://api.telegram.org/bot{}/sendMessage'.format(TOKEN)

# Основной цикл программы
while True:
    # Считываем данные с порта Serial
    data = ser.readline().decode().strip()
    
    # Если данные не пустые, отправляем их в Telegram
    if data:
        message = 'Получено сообщение: {}'.format(data)
        params = {'chat_id': CHAT_ID, 'text': message}
        requests.post(URL, data=params)
        
    # Ждем 1 секунду перед следующей итерацией цикла
    time.sleep(1)
