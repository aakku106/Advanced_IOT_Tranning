void setup() {
  // put your setup code here, to run once:
  pinMode(A3, INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(A3);
  Serial.println(x);
  if (x <= 100) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }
}
