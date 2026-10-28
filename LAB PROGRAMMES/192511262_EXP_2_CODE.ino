
//  NAME:N.Supriya
//ROLL NO:192511262
//CLASS:ECE
//ECA1407-Embedded Systems Slot A
int NS_RED = 2;
int NS_YELLOW = 3;
int NS_GREEN = 4;

int EW_RED = 5;
int EW_YELLOW = 6;
int EW_GREEN = 7;

void setup() {
  pinMode(NS_RED, OUTPUT);
  pinMode(NS_YELLOW, OUTPUT);
  pinMode(NS_GREEN, OUTPUT);

  pinMode(EW_RED, OUTPUT);
  pinMode(EW_YELLOW, OUTPUT);
  pinMode(EW_GREEN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // State 1: North-South GREEN, East-West RED
  digitalWrite(NS_RED, LOW);
  digitalWrite(NS_YELLOW, LOW);
  digitalWrite(NS_GREEN, HIGH);

  digitalWrite(EW_RED, HIGH);
  digitalWrite(EW_YELLOW, LOW);
  digitalWrite(EW_GREEN, LOW);

  Serial.println("STATE 1: NS GREEN - EW RED");
  delay(5000);

  // State 2: North-South YELLOW, East-West RED
  digitalWrite(NS_GREEN, LOW);
  digitalWrite(NS_YELLOW, HIGH);

  Serial.println("STATE 2: NS YELLOW - EW RED");
  delay(2000);

  // State 3: North-South RED, East-West GREEN
  digitalWrite(NS_YELLOW, LOW);
  digitalWrite(NS_RED, HIGH);

  digitalWrite(EW_RED, LOW);
  digitalWrite(EW_GREEN, HIGH);

  Serial.println("STATE 3: NS RED - EW GREEN");
  delay(5000);

  // State 4: North-South RED, East-West YELLOW
  digitalWrite(EW_GREEN, LOW);
  digitalWrite(EW_YELLOW, HIGH);

  Serial.println("STATE 4: NS RED - EW YELLOW");
  delay(2000);
}
