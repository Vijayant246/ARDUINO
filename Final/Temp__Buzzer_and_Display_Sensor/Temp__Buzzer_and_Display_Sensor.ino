//#include <Wire.h>
#include <LiquidCrystal_I2C.h>
const int ledR = 12;
const int ledB = 11;
const int ledY = 10;
const int lm35_pin = A0;
const int buzz = 5;
float temp;
float voltage;
LiquidCrystal_I2C lcd_1(0x27, 20, 4);
void setup()
{
    Serial.begin(9600);
    // put your setup code here, to run once:
    pinMode(ledR, OUTPUT);
    pinMode(ledB, OUTPUT);
    pinMode(ledY, OUTPUT);
    pinMode(lm35_pin,INPUT);
    pinMode(buzz, OUTPUT);
    Serial.println("-------------------------");
    Serial.println("Processing");
    delay(1000);
    Serial.println("-------------------------");
    lcd_1.begin(20, 4);
    lcd_1.setBacklight(1);
    lcd_1.setCursor(0, 0);
    lcd_1.print("    TEMPERATURE");
    lcd_1.setCursor(0, 1);
    lcd_1.print("        AND");
    lcd_1.setCursor(0, 2);
    lcd_1.print("       LIGHT");
    lcd_1.setCursor(0, 3);
    lcd_1.print("     INDICATOR");
    delay(5000);
    lcd_1.clear();
}

void loop()
{
    voltage = analogRead(lm35_pin); //Temerature Read
    temp = voltage * 330 /1024; // Covert adc value to Equivalent Voltage
    if (temp >= 60 && temp > 50)
    {
        Serial.print("Temperature in Celcius = ");
        Serial.println(temp);
        digitalWrite(ledR, HIGH);
        delay(2000);
        digitalWrite(ledR, LOW);
        delay(2000);
        lcd_1.begin(20, 4);
        lcd_1.setCursor(0, 0);
        lcd_1.println("TEMPERATUER = ");
        lcd_1.setCursor(14, 0);
        lcd_1.print(temp);
        lcd_1.setCursor(0, 1);
        lcd_1.print("VERY HOT");
        lcd_1.clear();
        tone(buzz,2000); //Time in millisecand
    }
    
    else if (temp <= 30 && temp >= 25)
    {
        Serial.print("Temperature in Celcius = ");
        Serial.println(temp);
        lcd_1.begin(20, 4);
        lcd_1.setCursor(0, 0);
        lcd_1.println("TEMPERATUER = ");
        lcd_1.setCursor(14, 0);
        lcd_1.print(temp);
        lcd_1.setCursor(0, 1);
        lcd_1.print("ROOM TEMPERATURE");
        digitalWrite(ledB, HIGH);
        delay(2000);
        digitalWrite(ledB, LOW);
        delay(2000);
        lcd_1.clear();
    }
    
    else if (temp < 20)
    {
        Serial.print("Temperature in Celcius = ");
        Serial.println(temp);
        lcd_1.begin(20, 4);
        lcd_1.setCursor(0, 0);
        lcd_1.println("TEMPERATUER = ");
        lcd_1.setCursor(14, 0);
        lcd_1.print(temp);
        lcd_1.setCursor(0, 1);
        lcd_1.print("COLD");
        digitalWrite(ledY, HIGH);
        delay(2000);
        digitalWrite(ledY, LOW);
        delay(2000);
        lcd_1.clear();
    }
}
