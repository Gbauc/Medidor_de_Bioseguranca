const int mq135AnalogPin = A0;
const int mq135DigitalPin = 7;
const int buzzerPin = 8;
// geovana estude querida, obrigada


void setup() {
 pinMode(mq135DigitalPin, INPUT);
 pinMode(buzzerPin, OUTPUT);
 Serial.begin(9600);
}

void loop() {
 int mq135AnalogValue = analogRead(mq135AnalogPin);
 int mq135DigitalValue = digitalRead(mq135DigitalPin);


Serial.print("MQ-135 Analog: ");
Serial.print(mq135AnalogValue);

Serial.print("  MQ-135 Digital: ");
Serial.println(mq135DigitalValue);

if (mq135DigitalValue == 0) 
 { digitalWrite(buzzerPin, HIGH);}
else
 { digitalWrite(buzzerPin, LOW); }
delay(1000);
}