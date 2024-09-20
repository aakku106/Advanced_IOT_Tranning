void setup() {
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  int x = analogRead(3);
  if (x < 50) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }
}
