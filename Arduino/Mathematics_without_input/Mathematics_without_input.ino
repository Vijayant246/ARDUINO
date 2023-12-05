int a = 5;
int b = 6;
float add, sub, divide, multiply, reminder, power;
void setup() {
  Serial.begin(9600);
  add = a + b;
  Serial.print("Addition: ");
  Serial.println(add);
  sub = a - b;
  Serial.print("Subtraction: ");
  Serial.println(sub);
  divide = a / b;
  Serial.print("Divivde: ");
  Serial.println(divide);
  multiply = a * b;
  Serial.print("Multiply: ");
  Serial.println(multiply);
  reminder = a % b;
  Serial.print("Reminder: ");
  Serial.println(reminder);
  power = pow(a,b);
  Serial.print("Power: ");
  Serial.println(power);
}
void loop() {
  // put your main code here, to run repeatedly:

}
