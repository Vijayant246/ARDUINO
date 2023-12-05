const int buzz = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzz, OUTPUT);
  Serial.println("\n-------------------------");
  Serial.println("\nProcessing");
  delay(1000);
  Serial.println("-------------------------");
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(buzz, 3000);
}
