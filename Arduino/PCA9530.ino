// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// PCA9530
// This code is designed to work with the PCA9530_I2CPWM I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/products

#include<Wire.h>

// PCA9530 I2C address is 0x60(96)
#define Addr 0x60

void setup()
{
  // Initialise I2C communication as MASTER
  Wire.begin();
  // Initialise serial communication, set baud rate = 9600
  Serial.begin(9600);
  delay(300);
}

void loop()
{
  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select frequency prescaler 0 register
  Wire.write(0x01);
  // Period of blink = 0.5 sec
  Wire.write(0x4B);
  // Stop I2C Transmission
  Wire.endTransmission();

  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select pulse width modulation 0 register
  Wire.write(0x02);
  // Duty cycle = 50
  Wire.write(0x80);
  // Stop I2C Transmission
  Wire.endTransmission();

  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select LED selector register
  Wire.write(0x05);
  // Output set to Blinking at PWM0
  Wire.write(0xFA);
  // Stop I2C Transmission
  Wire.endTransmission();
  delay(300);
}

