#include "ExEEPROM.h"

ExEEPROM eeprom;

void setup() {

  Serial.begin(9600);
  eeprom.begin(0x57);

  
  eeprom.update(0, 1);
  eeprom.update(1, 2);
  eeprom.update(2, 3);
  eeprom.update(3, 4);
  eeprom.update(4, 5);// Recommended using update rather than write
  //eeprom.write(0, 15);
}

void loop() {

  Serial.println(eeprom.read(0));
  Serial.println(eeprom.read(1));
  Serial.println(eeprom.read(2));
  Serial.println(eeprom.read(3));
  Serial.println(eeprom.read(4));
}
