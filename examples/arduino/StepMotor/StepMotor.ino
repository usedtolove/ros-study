#define A1 2
#define B1 3
#define C1 4
#define D1 5

const int delayTime = 10;

void setup() {
  pinMode(A1, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(D1, OUTPUT);
}

void loop() {
//  clockwise();
  anticlockwise();
}

void clockwise() {
  phaseA();
  delay(delayTime);
  phaseB();
  delay(delayTime);
  phaseC();
  delay(delayTime);
  phaseD();
  delay(delayTime);
}

void anticlockwise() {
  phaseD();
  delay(delayTime);
  phaseC();
  delay(delayTime);
  phaseB();
  delay(delayTime);
  phaseA();
  delay(delayTime);
}

void  phaseA() {
  digitalWrite(A1, HIGH);
  digitalWrite(B1, LOW);
  digitalWrite(C1, LOW);
  digitalWrite(D1, LOW);
}

void  phaseB() {
  digitalWrite(A1, LOW);
  digitalWrite(B1, HIGH);
  digitalWrite(C1, LOW);
  digitalWrite(D1, LOW);
}

void  phaseC() {
  digitalWrite(A1, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(C1, HIGH);
  digitalWrite(D1, LOW);
}

void  phaseD() {
  digitalWrite(A1, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(C1, LOW);
  digitalWrite(D1, HIGH);
}
