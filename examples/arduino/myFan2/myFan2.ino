#define IA 6
#define IB 5
#define Pot A0
#define LED 3

int valBuffer = 0;
int val = 0;

void setup() {
  // put your setup code here, to run once:
 pinMode(IA, OUTPUT);
 pinMode(IB, OUTPUT);
 pinMode(LED, OUTPUT);

 digitalWrite(IB, LOW);
}

void loop() {
  valBuffer = analogRead(Pot);
  val = map(valBuffer, 0, 1023, 0, 255);
  analogWrite(IA, val);
  analogWrite(LED,(255-val));
  delay(100);
}
