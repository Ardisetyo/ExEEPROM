#ifndef ZEeprom_h
#define ZEeprom_h

#include <Arduino.h>
#include <Wire.h>

class ExEEPROM {

  public:
    ExEEPROM();
    void begin(uint8_t address);
    void write(unsigned int address, uint8_t data);
    byte read(unsigned int address);
    bool update(unsigned int adrress, uint8_t data);

  private:
    unsigned int deviceAddress;
};

#endif
