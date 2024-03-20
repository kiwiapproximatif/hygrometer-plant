const int LED_PIN = 11;
const int LED_BLINK_DELAY = 1000;
const int HYGRO_ANALOG = A0;
const int BAUD_RATE = 9600;


void serialPrintAnalog(int value) {
  int sensorValue = analogRead(value);
  Serial.println(sensorValue);
}

void switchLedOnLowHumidity() {
  int hygroValue = analogRead(HYGRO_ANALOG);

  if (hygroValue < 100) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}


void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(BAUD_RATE); 
}

void loop() {
  serialPrintAnalog(HYGRO_ANALOG);
  switchLedOnLowHumidity();
}