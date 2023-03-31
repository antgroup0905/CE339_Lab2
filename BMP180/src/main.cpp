#include <Wire.h>
#include <BMP180.h>
#include <arduino.h>
#include <Servo.h>
#define seaLevelPressure_hPa 1013.25

// Define BMP180 sensor object
BMP180 bmp;

// Define servo object
Servo servo;

// Define temperature threshold A
const float A = 30.0, B = 31.0, C = 32.0;
  
void setup() {
  Serial.begin(9600);
  bmp.init();

  // Initialize servo
  servo.attach(9);  // Assuming the signal wire is connected to digital pin 9
  // Set servo to 0 degree angle
  servo.write(0);
  delay(1000);
}
  
void loop() {
  unsigned int ut = bmp.bmp180ReadUT();
  //unsigned long up = bmp.bmp180ReadUP();
  float temperature = bmp.bmp180GetTemperature(ut);
  //long pressure = bmp.bmp180GetPressure(up);
  //float altitude = bmp.calcAltitude(pressure);
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");
  /*Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" Pa");
  Serial.print("Altitude: ");
  Serial.print(altitude);
  Serial.println(" m");*/

// Set servo to 0 degree angle
    servo.write(0);
    delay(5000);
  // Check if temperature is below threshold A
  if (temperature < A) {
    // spin 30 degree and return to 0 every 2 secs for 10 sec
    for (int i = 0; i < 10; i+=2) {
      Serial.print(i+1);
      Serial.println(" sec");
      servo.write(30);  // 30 degree angle
      delay(1000);  // delay for 1sec
      Serial.print(i+2);
      Serial.println(" sec");
      servo.write(0); //Reset servo to 0 degree angle
      delay(1000);  // delay for 1sec
    }

    // Set servo to 0 degree angle
    servo.write(0);
  }
  else if (temperature > A && temperature <= B) {
    // spin 60 degree and return to 0 every 2 secs for 30 sec
    for (int i = 0; i < 30; i+=2) {
      Serial.print(i+1);
      Serial.println(" sec");
      servo.write(60);  // 60 degree angle
      delay(1000);  // delay for 1sec
      Serial.print(i+2);
      Serial.println(" sec");
      servo.write(0); //Reset servo to 0 degree angle
      delay(1000);  // delay for 1sec
    }

    // Set servo to 0 degree angle
    servo.write(0);
  }
  else if (temperature > B && temperature <= C) {
    // spin 120 degree and return to 0 every 2 secs for 45 sec
    for (int i = 0; i < 45; i+=2) {
      Serial.print(i+1);
      Serial.println(" sec");
      servo.write(120);  // 120 degree angle
      delay(1000);  // delay for 1sec
      Serial.print(i+2);
      Serial.println(" sec");
      servo.write(0); //Reset servo to 0 degree angle
      delay(1000);  // delay for 1sec
    }

    // Set servo to 0 degree angle
    servo.write(0);
  }
  else if (temperature > C) {
    // spin 180 degree and return to 0 every 2 secs for 60 sec
    for (int i = 0; i < 60; i+=2) {
      Serial.print(i+1);
      Serial.println(" sec");
      servo.write(180);  // 180 degree angle
      delay(1000);  // delay for 1sec
      Serial.print(i+2);
      Serial.println(" sec");
      servo.write(0); //Reset servo to 0 degree angle
      delay(1000);  // delay for 1sec
    }
  }

  delay(10000);
}
