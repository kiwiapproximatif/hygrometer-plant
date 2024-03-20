const int HYGRO_ANALOG = A0;
const int BAUD_RATE = 9600;
const int SWITCH_DELAY = 1000;

const int RED_LED_PIN = 7;
const int YELLOW_LED_PIN = 9;
const int GREEN_LED_PIN = 10;

void serialPrintAnalog(int value) {
  int sensorValue = analogRead(value);
  Serial.println(sensorValue);
}

void switchLedOnLowHumidityMultipleLevel() {
  int hygroValue = analogRead(HYGRO_ANALOG);

  if (hygroValue < 50) {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
  } else if (hygroValue >= 50 && hygroValue < 100) {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
  } else {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
  }

  delay(SWITCH_DELAY);
}

void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  Serial.begin(BAUD_RATE); 
}

void loop() {
  serialPrintAnalog(HYGRO_ANALOG);
  switchLedOnLowHumidityMultipleLevel();
}