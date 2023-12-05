#include <Adafruit_LiquidCrystal.h>

float temp;
const int lm36_pin = A0;
float vout;
float voltage;
Adafruit_LiquidCrystal lcd_1(0);
const int buzz = 5;
void setup()
{
    // put your setup code here, to run once:
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(lm36_pin, INPUT);
    pinMode(buzz, OUTPUT);
    Serial.begin(9600);
    Serial.println("\n-------------------------");
    Serial.println("\nProcessing");
    delay(1000);
    Serial.println("-------------------------");
    lcd_1.begin(16, 2);
    lcd_1.setBacklight(1);
    lcd_1.setCursor(0, 0);
    lcd_1.print("Temperature and");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Light Indicator");
    delay(2000);
    lcd_1.clear();
}

void loop()
{
    voltage = analogRead(lm36_pin);  // Temerature Read
    vout = (voltage * (3.3 / 1024)); // Covert adc value to Equivalent Voltage
    temp = (vout - 0.5) * 100;
    if (temp >= 60 && temp > 50)
    {
        Serial.print("Temperature in Celcius = ");
        Serial.println(temp);
        lcd_1.setCursor(0, 0);
        lcd_1.println("Temp = ");
        lcd_1.setCursor(7, 0);
        lcd_1.print(temp);
        lcd_1.setCursor(0, 1);
        lcd_1.print("Very Hot");
        digitalWrite(13, HIGH);
        // delay(2000);
        // digitalWrite(13, LOW);
        // delay(100);
        tone(buzz, 3000);
        // delay(2000);
        // noTone(buzz);
        // delay(2000);
        lcd_1.clear();
    }
    else if (temp <= 50 && temp > 30)
    {
        Serial.print("Temperature in Celcius = ");
        Serial.println(temp);
        lcd_1.setCursor(0, 0);
        lcd_1.println("Temp =");
        lcd_1.setCursor(6, 0);
        lcd_1.print(temp);
        lcd_1.setCursor(0, 1);
        lcd_1.print("Hot");
        digitalWrite(12, HIGH);
        delay(2000);
        digitalWrite(12, LOW);
        delay(2000);
        lcd_1.clear();
    }
    else if (temp <= 30 && temp >= 25)
    {
        Serial.print("Temperature in Celcius = ");
        Serial.println(temp);
        lcd_1.setCursor(0, 0);
        lcd_1.println("Temp =");
        lcd_1.setCursor(6, 0);
        lcd_1.print(temp);
        lcd_1.setCursor(0, 1);
        lcd_1.print("Room Temeperature");
        digitalWrite(11, HIGH);
        delay(2000);
        digitalWrite(11, LOW);
        delay(2000);
        lcd_1.clear();
    }
    else if (temp < 25 && temp > 15)
    {
        Serial.print("Temperature in Celcius = ");
        Serial.println(temp);
        lcd_1.setCursor(0, 0);
        lcd_1.println("Temp =");
        lcd_1.setCursor(6, 0);
        lcd_1.print(temp);
        lcd_1.setCursor(0, 1);
        lcd_1.print("Low Cold");
        digitalWrite(10, HIGH);
        delay(2000);
        digitalWrite(10, LOW);
        delay(2000);
        lcd_1.clear();
    }
    else if (temp <= 15 && temp >=0)
    {
        Serial.print("Temperature in Celcius = ");
        Serial.println(temp);
        lcd_1.setCursor(0, 0);
        lcd_1.println("Temp =");
        lcd_1.setCursor(6, 0);
        lcd_1.print(temp);
        lcd_1.setCursor(0, 1);
        lcd_1.print("Cold");
        digitalWrite(9, HIGH);
        delay(2000);
        digitalWrite(9, LOW);
        delay(2000);
        lcd_1.clear();
    }
    else if (temp < 0)
    {
        Serial.print("Temperature in Celcius = ");
        Serial.println(temp);
        lcd_1.setCursor(0, 0);
        lcd_1.println("Temp =");
        lcd_1.setCursor(6, 0);
        lcd_1.print(temp);
        lcd_1.setCursor(0, 1);
        lcd_1.print("Freezing");
        digitalWrite(8, HIGH);
        delay(2000);
        digitalWrite(8, LOW);
        delay(2000);
        lcd_1.clear();
    }
}
