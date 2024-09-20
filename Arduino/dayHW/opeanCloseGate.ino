#define gate 12
#define ir A3
void setup() {
  // put your setup code here, to run once:
  pinMode(ir, INPUT);
  pinMode(gate, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(ir);
  Serial.print(x);
}
