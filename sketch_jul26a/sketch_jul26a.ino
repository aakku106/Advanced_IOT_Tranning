#include <Servo.h>

// Pin definitions
const int trigPin = 2;
const int echoPin = 3;
const int servoPin = 6;
const int buzzerPin = 9;

// Variables for distance measurement
long duration;
int distance;
Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  // Sweep servo from 15 to 165 degrees
  for (int i = 15; i <= 165; i++) {
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    handleBuzzer(distance);
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }

  // Sweep servo from 165 to 15 degrees
  for (int i = 165; i >= 15; i--) {
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    handleBuzzer(distance);
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

void handleBuzzer(int distance) {
  if (distance > 31) {
    digitalWrite(buzzerPin, LOW);
  } else if (distance <= 30 && distance > 20) {
    beepBuzzer(150);
  } else if (distance <= 15 && distance > 10) {
    beepBuzzer(70);
  } else if (distance <= 15) {
    beepBuzzer(10);
  }
}

void beepBuzzer(int delayTime) {
  for (int j = 0; j < 6; j++) {
    digitalWrite(buzzerPin, HIGH);
    delay(delayTime);
    digitalWrite(buzzerPin, LOW);
    delay(delayTime);
  }
}
