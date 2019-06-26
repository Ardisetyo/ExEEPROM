#include <Arduino.h>
#include <Wire.h>

#include "ExEEPROM.h"

#define DEVICEADDRESS deviceAddress

ExEEPROM::ExEEPROM() {

}

void ExEEPROM::begin(uint8_t address)
{
  deviceAddress = address;
  Wire.begin();
}

void ExEEPROM::write(unsigned int address, uint8_t data) {

  Wire.beginTransmission((uint8_t)DEVICEADDRESS);
  Wire.write(address >> 8);
  Wire.write(address & 0xFF);
  Wire.write(data);
  Wire.endTransmission();
  delay(10);
}

byte ExEEPROM::read(unsigned int address) {

  Wire.beginTransmission((uint8_t)DEVICEADDRESS);
  Wire.write(address >> 8);
  Wire.write(address & 0xFF);
  Wire.endTransmission();

  Wire.requestFrom((uint8_t)DEVICEADDRESS, (byte)1);
  byte data = 0;

  if (Wire.available()) {
    data = Wire.read();
  }
  return data;
}

bool ExEEPROM::update(unsigned int address, uint8_t data) {

  if (data != read(address)) {
    write(address, data);
    return 1;
  } else return 0;
}
