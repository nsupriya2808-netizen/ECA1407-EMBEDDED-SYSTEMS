
//  NAME:N.Supriya
//ROLL NO:192511262
//CLASS:ECE
//ECA1407-Embedded Systems Slot A

#define GAS_SENSOR A0
#define PIR_SENSOR 2
#define TRIG_PIN 7
#define ECHO_PIN 6

#define LED_PIN 13
#define BUZZER_PIN 12

int gasLevel;
int motion;
long duration;
float distance;

void setup() {
  Serial.begin(9600);

  pinMode(GAS_SENSOR, INPUT);
  pinMode(PIR_SENSOR, INPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(TRIG_PIN, LOW);

  Serial.println("SMART HOME SAFETY SYSTEM");
  Serial.println("------------------------------");
}

void loop() {
  // Read gas sensor
  gasLevel = analogRead(A0);;

  // Read PIR motion sensor
  motion = digitalRead(PIR_SENSOR);

  // Measure ultrasonic distance
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000UL);

  if (duration == 0) {
    distance = -1;
  } else {
    distance = duration * 0.0343 / 2.0;
  }

  // Print sensor values
  Serial.print("Gas Level: ");
  Serial.println(gasLevel);

  Serial.print("Motion: ");
  Serial.println(motion == HIGH ?
                 "DETECTED" : "NOT DETECTED");

  Serial.print("Distance: ");

  if (distance < 0) {
    Serial.println("NO ECHO");
  } else {
    Serial.print(distance, 1);
    Serial.println(" cm");
  }

  // Safety decision
  bool gasAlert = (gasLevel >= 600);
  bool occupancy = (motion == HIGH) ||
                   (distance >= 0 && distance <= 25);

  if (gasAlert) {
    Serial.println("GAS ALERT!");
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);
  }
  else if (occupancy) {
    Serial.println("OCCUPANCY DETECTED");
    digitalWrite(LED_PIN, HIGH);
    noTone(BUZZER_PIN);
  }
  else {
    Serial.println("SYSTEM SAFE");
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
  }

  Serial.println("------------------------------");
  delay(1000);
}
