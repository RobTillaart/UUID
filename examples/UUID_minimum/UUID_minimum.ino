//
//    FILE: UUID_minimum.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo - will generate same UUID's  (no external entropy)
//     URL: https://github.com/RobTillaart/UUID


#include "Arduino.h"
#include "UUID.h"

UUID uuid;


void setup()
{
  Serial.begin(115200);
  while (!Serial);

  Serial.println();
  Serial.println(__FILE__);
  Serial.print("UUID_LIB_VERSION: ");
  Serial.println(UUID_LIB_VERSION);
  Serial.println();
}


void loop()
{
  uuid.generate();
  Serial.print("UUID: ");
  Serial.println(uuid);
  delay(100);
}


//  -- END OF FILE --
