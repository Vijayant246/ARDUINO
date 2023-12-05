#include <LiquidCrystal.h>

float temp;
const int lm36_pin = A0;
float vout;
float voltage;

void setup()
{
    // put your setup code here, to run once:
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(lm36_pin,INPUT);
    Serial.begin(9600);
    Serial.println("\n-------------------------");
    Serial.println("\nProcessing");
    delay(1000);
    Serial.println("-------------------------");
    lcd.begin(16, 2);
    lcd.setBacklight(1);
    lcd.setCursor(0, 0);
    lcd.print("Temperature and");
    lcd.setCursor(0, 1);
    lcd.print("Light Indicator");
    delay(2000);
    lcd.clear();
}

void loop()
{
    voltage = analogRead(lm36_pin); //Temerature Read
    vout = (voltage * (3.3 /1024)); // Covert adc value to Equivalent Voltage
    temp = (vout - 0.5) * 100;
    if (temp >= 60 && temp > 50)
    {
        Serial.print("Temperature in Celcius = ");
        Serial.println(temp);
        lcd.setCursor(0, 0);
        lcd.println("Temp = ");
        lcd.setCursor(7, 0);
        lcd.print(temp);
        lcd.setCursor(0, 1);
        lcd.print("Very Hot");
        digitalWrite(13, HIGH);
        delay(2000);
        digitalWrite(13, LOW);
        delay(2000);
        lcd.clear();
    }
    else if (temp <= 50 && temp > 30)
    {
        Serial.print("Temperature in Celcius = ");
        Serial.println(temp);
        lcd.setCursor(0, 0);
        lcd.println("Temp =");
        lcd.setCursor(6, 0);
        lcd.print(temp);
        lcd.setCursor(0, 1);
        lcd.print("Hot");
        digitalWrite(12, HIGH);
        delay(2000);
        digitalWrite(12, LOW);
        delay(2000);
        lcd.clear();
    }
    else if (temp <= 30 && temp >= 25)
    {
        Serial.print("Temperature in Celcius = ");
        Serial.println(temp);
        lcd.setCursor(0, 0);
        lcd.println("Temp =");
        lcd.setCursor(6, 0);
        lcd.print(temp);
        lcd.setCursor(0, 1);
        lcd.print("Room Temeperature");
        digitalWrite(11, HIGH);
        delay(2000);
        digitalWrite(11, LOW);
        delay(2000);
        lcd.clear();
    }
    else if (temp < 25 && temp > 15)
    {
        Serial.print("Temperature in Celcius = ");
        Serial.println(temp);
        lcd.setCursor(0, 0);
        lcd.println("Temp =");
        lcd.setCursor(6, 0);
        lcd.print(temp);
        lcd.setCursor(0, 1);
        lcd.print("Low Cold");
        digitalWrite(10, HIGH);
        delay(2000);
        digitalWrite(10, LOW);
        delay(2000);
        lcd.clear();
    }
    else if (temp < 15)
    {
        Serial.print("Temperature in Celcius = ");
        Serial.println(temp);
        lcd.setCursor(0, 0);
        lcd.println("Temp =");
        lcd.setCursor(6, 0);
        lcd.print(temp);
        lcd.setCursor(0, 1);
        lcd.print("Cold");
        digitalWrite(9, HIGH);
        delay(2000);
        digitalWrite(9, LOW);
        delay(2000);
        lcd.clear();
    }
}
