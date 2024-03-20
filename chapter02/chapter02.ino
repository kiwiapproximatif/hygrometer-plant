const int LED_PIN = 11;
const int LED_BLINK_DELAY = 1000;

void changeValueLedWithDelay(int value, int d) {
  digitalWrite(LED_PIN, value);
  delay(d);
}

void blinkLed(int d) {
  changeValueLedWithDelay(HIGH, d);
  changeValueLedWithDelay(LOW, d);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  blinkLed(LED_BLINK_DELAY);
}