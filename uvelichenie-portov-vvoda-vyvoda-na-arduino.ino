#include <PCF8574.h>               // Подключение библиотеки PCF8574
PCF8574 pcf8574(0x20);            // Создаем объект и указываем адрес устройства 0x20

void setup(){
  Serial.begin(115200);
  pcf8574.pinMode(P0, INPUT);       // Устанавливаем выход P0, как вход
  pcf8574.pinMode(P1, INPUT);       // Устанавливаем выход P1, как вход
  pcf8574.pinMode(P2, INPUT);       // Устанавливаем выход P2, как вход
  pcf8574.pinMode(P3, INPUT);       // Устанавливаем выход P3, как вход
  pcf8574.pinMode(P4, OUTPUT);      // Устанавливаем выход P4, как выход
  pcf8574.pinMode(P5, OUTPUT);      // Устанавливаем выход P5, как выход
  pcf8574.pinMode(P6, OUTPUT);      // Устанавливаем выход P6, как выход
  pcf8574.pinMode(P7, OUTPUT);      // Устанавливаем выход P7, как выход

// Проверка инициализация библиотеки pcf8574
  Serial.print("Init pcf8574...");
  if (pcf8574.begin()){
    Serial.println("OK");}
  else{
    Serial.println("ERROR");}
  delay(50);                                        // Необходимо время для инициализации 
}

void loop()
{
  uint8_t val0 = pcf8574.digitalRead(P0);            // Чтение состоянии вывода PO
  uint8_t val1 = pcf8574.digitalRead(P1);            // Чтение состоянии вывода P1 
  uint8_t val2 = pcf8574.digitalRead(P2);            // Чтение состоянии вывода P2
  uint8_t val3 = pcf8574.digitalRead(P3);            // Чтение состоянии вывода P3  

  if (val0 == HIGH) pcf8574.digitalWrite(P4, HIGH);  // Если кнопка не нажата, светодиод не горит 
  else              pcf8574.digitalWrite(P4, LOW);   // Если кнопка нажата, светодиод горит
  delay(5);                                         // Пауза 
  
  if (val1 == HIGH) pcf8574.digitalWrite(P5, HIGH);  // Если кнопка не нажата, светодиод не горит
  else              pcf8574.digitalWrite(P5, LOW);   // Если кнопка нажата, светодиод горит
  delay(5);                                         // Пауза 

  if (val2 == HIGH) pcf8574.digitalWrite(P6, HIGH);  // Если кнопка не нажата, светодиод не горит
  else              pcf8574.digitalWrite(P6, LOW);   // When Button is Released
  delay(5);                                         // Пауза 

  if (val3 == HIGH) pcf8574.digitalWrite(P7, HIGH);  // Если кнопка не нажата, светодиод не горит
  else              pcf8574.digitalWrite(P7, LOW);   // Если кнопка нажата, светодиод горит
  delay(5);                                         // Пауза 
}
