const int trigPin = 9;
const int echoPin = 10;

const int greenPin = 2;
const int yellowPin = 4;
const int redPin = 7;

const int buzzerPin = 12;

long duration;
float distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);

  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.0343 / 2;

  if (distance < 10) {

    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);

    tone(buzzerPin, 1000);
    delay(100);

    noTone(buzzerPin);
    delay(100);
  }

  else if (distance < 30) {

    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);

    tone(buzzerPin, 1000);
    delay(200);

    noTone(buzzerPin);
    delay(300);
  }

  else {

    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);

    noTone(buzzerPin);

    delay(500);
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
