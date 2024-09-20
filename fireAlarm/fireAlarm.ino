void setup() {
  // put your setup code here, to run once:
  pinMode(A3, INPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int y = analogRead(A3);
  if (y >= 50) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }
}
