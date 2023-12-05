float a, b, add, sub, divide, multiply, power;
void setup()
{
  Serial.begin(9600);
  Serial.println("Value of A = ");
    while(Serial.available() == 0){
      }
    a=Serial.parseFloat();
    Serial.println(a);
    delay(5000);
    Serial.println("Value of B = ");
    while(Serial.available() == 0){
      }
    b=Serial.parseFloat();
//    delay(5000);
    Serial.print(b);
    add = a + b;
    Serial.print("\nAddition: ");
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
    power = pow(a,b);
    Serial.print("Power: ");
    Serial.println(power);

}
void loop()
{
  
}
