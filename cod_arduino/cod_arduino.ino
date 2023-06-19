// analógico -> um valor quanto mais maior
// digital -> valor 0 ou 1

#include <Adafruit_BMP280.h>
#include <MQUnifiedsensor.h>
#include <SPI.h>
#include <SD.h>
Adafruit_BMP280 sensor_bmp;

const int chipSelect = 10; // Pino de chip select do cartão SD
const int temp_pres = A4;
const int mq3AnalogPin = A3;
const int mq7AnalogPin = A1;
const int mq8AnalogPin = A2;
const int mq135AnalogPin = A0;
const int buzzerPin = 5;
// const int mq3DigitalPin = 5;
// const int mq7DigitalPin = 3;
// const int mq8DigitalPin = 4;
const int mq135DigitalPin = 2;

float ler_temp;
float ler_pres;
float mq3AnalogValue;
float mq7AnalogValue;
float mq8AnalogValue;
float mq135AnalogValue;
// float mq3DigitalValue;
// float mq7DigitalValue;
// float mq8DigitalValue;
float mq135DigitalValue;

void setup() {
  Serial.begin(9600);

  // Inicializa o cartão SD
  if (!SD.begin(chipSelect)) {
    Serial.println("Falha ao inicializar o cartão SD!");
    return;
  }

  Serial.println("Cartão SD inicializado com sucesso!");

  // Cria um arquivo para escrita
  File dataFile = SD.open("dados_monitoramento.txt", FILE_WRITE);

  if (dataFile) {
    Serial.println("Arquivo aberto com sucesso!");

    // Lê os dados do Arduino e grava no arquivo
    for (int i = 0; i < 10; i++) {
      int sensorData = analogRead(A0);
      dataFile.println(sensorData);
      delay(60000);
    }

    // Fecha o arquivo
    dataFile.close();
    Serial.println("Dados gravados com sucesso!");
  } else {
    Serial.println("Erro ao abrir o arquivo!");
  }
  // pinMode(mq3DigitalPin, INPUT);
  // pinMode(mq7DigitalPin, INPUT);
  // pinMode(mq8DigitalPin, INPUT);
  pinMode(mq135DigitalPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  sensor_bmp.begin();
  sensor_bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                         Adafruit_BMP280::SAMPLING_X2,
                        Adafruit_BMP280::SAMPLING_X16,
                        Adafruit_BMP280::FILTER_X16,
                        Adafruit_BMP280::STANDBY_MS_500);
}

void loop() {
  digitalWrite(buzzerPin, HIGH);
  ler_temp = sensor_bmp.readTemperature();
  ler_pres = sensor_bmp.readPressure();
  mq3AnalogValue = analogRead(mq3AnalogPin);
  mq7AnalogValue = analogRead(mq7AnalogPin);  
  mq8AnalogValue = analogRead(mq8AnalogPin);
  mq135AnalogValue = analogRead(mq135AnalogPin);
  // mq3DigitalValue = digitalRead(mq3DigitalPin);
  // mq7DigitalValue = digitalRead(mq7DigitalPin);
  // mq8DigitalValue = digitalRead(mq8DigitalPin);
  mq135DigitalValue = digitalRead(mq135DigitalPin);

Serial.print("MQ-3 Analog: ");
Serial.println(mq3AnalogValue);
// Serial.print("MQ-3 Digital: ");
// Serial.println(mq3DigitalValue);
delay(60000);

Serial.print("MQ-7 Analog: ");
Serial.println(mq7AnalogValue);
// Serial.print("MQ-7 Digital: ");
// Serial.println(mq7DigitalValue);
delay(60000);

Serial.print("MQ-8 Analog: ");
Serial.println(mq8AnalogValue);
// Serial.print("MQ-8 Digital: ");
// Serial.println(mq8DigitalValue);
delay(60000);

Serial.print("MQ-135 Analog: ");
Serial.println(mq135AnalogValue);
Serial.print("MQ-135 Digital: ");
Serial.println(mq135DigitalValue);
delay(60000);

Serial.print("Temperatura(°C): ");
Serial.println(ler_temp);
delay(60000);

Serial.print("Pressao (Pa)= ");
Serial.println(ler_pres);
delay(60000);

// if (mq3DigitalPin == 0 || mq7DigitalPin == 0 || mq8DigitalPin == 0 || mq135DigitalValue == 0) 
//  { digitalWrite(buzzerPin, HIGH);}
// else
//  { digitalWrite(buzzerPin, LOW); }
// delay(1000);
}


