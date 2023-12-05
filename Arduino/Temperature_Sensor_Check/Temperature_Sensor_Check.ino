/*  LM35 Analog Temperature Sensor Test

  Reads the output of LM35 connected to pin A0 and reports that temperature in degrees
  Celcius and Farenheit out to the Serial Monitor Window
*/

const int LM35_PIN = A0;    // Define analog pin the LM35 is connected to
int temp_C, temp_F;         // Define a couple of variables to hold the temperatures
//===============================================================================
//  Initialization
//===============================================================================
void setup() {
  Serial.begin(9600);       // Initialize Serial Monitor window comm speed
}

//===============================================================================
//  Main
//===============================================================================
void loop() {
  temp_C = Get_Temp(LM35_PIN);    // Get the temp in C
  temp_F = C_To_F(temp_C);         // Convert the temp from C to degrees F
  // Printout the results
  Serial.print(temp_C); Serial.println(" Degrees C");
  Serial.print(temp_F); Serial.println(" Degrees F");
  Serial.println("");
  delay(1000);                    // Pause 1 sec then repeat
}

//===============================================================================
//  Get_Temp - subroutine to read the temperature from the LM35
//===============================================================================
int Get_Temp(int pin) {
  int raw_temp = analogRead(pin);
  float voltage = raw_temp * 500 / 1023; // Calculate temp based on raw reading
  return voltage;
}

//===============================================================================
//  C_To_F - subroutine to convert temp from Celcius to Fahrenheit
//===============================================================================
int C_To_F(int temp) {
  return (temp * 9 / 5) + 32;  // Basic formula for converting degrees C to F
}
