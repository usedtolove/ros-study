const int IA = 6;
const int IB = 5;

void setup() {
  // put your setup code here, to run once:
 pinMode(IA, OUTPUT);
 pinMode(IB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(IA, HIGH);
  digitalWrite(IB, LOW);
}
