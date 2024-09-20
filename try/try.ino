#define gate 12
#define ir A3
#define PIR A4
void setup() {
  // put your setup code here, to run once:
  pinMode(ir, INPUT);
  pinMode(PIR, INPUT);
  pinMode(gate, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(ir);
  Serial.print(x);
}

int p = 1, t = 2, r = 3;
int si = (p * t * r) / 100;