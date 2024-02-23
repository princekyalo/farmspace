#include <DHT.h> // Include the DHT library

#define DHT11_PIN 2 // Define the Arduino pin connected to DHT-11

DHT dht11(DHT11_PIN, DHT11); // Create a DHT-11 object
void setup() {
  Serial.begin(9600);
  dht11.begin();
}

void loop() {
   
  // Read the analog value from the rain sensor
  int rainValue = analogRead(A0);

  // Digital output (rain detected or not)
  if (rainValue < 10) {
    Serial.println("Rain detected!");
  } else {
    Serial.println("No rain.");
  }

  // Analog output (rain level)
  Serial.print("Analog reading: ");
  Serial.println(rainValue);
  // Read the input on analog pin A0 (value between 0 and 1023)
  int tempValue = analogRead(A0);
  Serial.print("Analog reading: ");
  Serial.print(tempValue); // The raw analog reading

  // Determine light levels qualitatively
  if (tempValue < 10) {
    Serial.println(" - Dark");
  } else if (tempValue < 200) {
    Serial.println(" - Dim");
  } else if (tempValue < 500) {
    Serial.println(" - Light");
  } else if (tempValue < 800) {
    Serial.println(" - Bright");
  } else {
    Serial.println(" - Very bright");
  }
  float humidity = dht11.readHumidity();
  float temperatureC = dht11.readTemperature();

  // Print the values to the serial monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  delay(1000); // Wait for a second
}
