#include <Adafruit_BMP280.h>
#include <MQUnifiedsensor.h>
// #include <SPI.h>
// #include <SdFat.h>
Adafruit_BMP280 sensor_bmp;

// const int chipSelect = 10; // Pino de chip select do cartão SD
const int temp_pres = A4;
const int mq3AnalogPin = A3;
const int mq7AnalogPin = A1;
const int mq8AnalogPin = A2;
const int mq135AnalogPin = A0;
const int buzzerPin = 5;
const int mq135DigitalPin = 2;

float ler_temp;
float ler_pres;
float mq3AnalogValue;
float mq7AnalogValue;
float mq8AnalogValue;
float mq135AnalogValue;
float mq135DigitalValue;

// SdFat SD;
// File dataFile;

void setup() {
  Serial.begin(9600);

  // if (!SD.begin(chipSelect, SPI_HALF_SPEED)) {
  //   Serial.println("Falha ao inicializar o cartão SD!");
  //   return;
  // }

  // Serial.println("Cartão SD inicializado com sucesso!");

  pinMode(mq135DigitalPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  sensor_bmp.begin();
  sensor_bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                         Adafruit_BMP280::SAMPLING_X2,
                         Adafruit_BMP280::SAMPLING_X16,
                         Adafruit_BMP280::FILTER_X16,
                         Adafruit_BMP280::STANDBY_MS_500);

  // // Abre o arquivo para escrita no início do programa
  // dataFile = SD.open("dados_monitoramento.txt", FILE_WRITE);
  // if (dataFile) {
  //   Serial.println("Arquivo aberto com sucesso!");
  //   dataFile.close(); // Fecha o arquivo imediatamente após a abertura
  // } else {
  //   // Se o arquivo não existir, cria o arquivo
  //   dataFile = SD.open("dados_monitoramento.txt", FILE_WRITE | O_CREAT);
  //   if (dataFile) {
  //     Serial.println("Arquivo criado com sucesso!");
  //     dataFile.close(); // Fecha o arquivo imediatamente após a criação
  //   } else {
  //     Serial.println("Erro ao criar o arquivo!");
  //   }
  // }
}

void loop() {
  digitalWrite(buzzerPin, HIGH);
  ler_temp = sensor_bmp.readTemperature();
  ler_pres = sensor_bmp.readPressure();
  mq3AnalogValue = analogRead(mq3AnalogPin);
  mq7AnalogValue = analogRead(mq7AnalogPin);
  mq8AnalogValue = analogRead(mq8AnalogPin);
  mq135AnalogValue = analogRead(mq135AnalogPin);
  mq135DigitalValue = digitalRead(mq135DigitalPin);

  Serial.print("MQ-3 Analog: ");
  Serial.println(mq3AnalogValue);
  // saveData("MQ-3 Analog", mq3AnalogValue);
  
  Serial.print("MQ-7 Analog: ");
  Serial.println(mq7AnalogValue);
  // saveData("MQ-7 Analog", mq7AnalogValue);

  Serial.print("MQ-8 Analog: ");
  Serial.println(mq8AnalogValue);
  // saveData("MQ-8 Analog", mq8AnalogValue);

  Serial.print("MQ-135 Analog: ");
  Serial.println(mq135AnalogValue);
  // saveData("MQ-135 Analog", mq135AnalogValue);

  Serial.print("MQ-135 Digital: ");
  Serial.println(mq135DigitalValue);
  // saveData("MQ-135 Digital", mq135DigitalValue);

  Serial.print("Temperatura(°C): ");
  Serial.println(ler_temp);
  // saveData("Temperatura(°C)", ler_temp);

  Serial.print("Pressao (Pa)= ");
  Serial.println(ler_pres);
  // saveData("Pressao (Pa)", ler_pres);

  delay(5000);
}

// void saveData(const char* dataLabel, float dataValue) {
//   // Abre o arquivo para escrita no início de cada salvamento
//   dataFile = SD.open("dados_monitoramento.txt", FILE_WRITE);
//   if (dataFile) {
//     dataFile.print(dataLabel);
//     dataFile.print(": ");
//     dataFile.println(dataValue);
//     dataFile.close();
//     Serial.println("Dados gravados com sucesso!");
//   } else {
//     Serial.println("Erro ao abrir o arquivo!");
//   }
// }
