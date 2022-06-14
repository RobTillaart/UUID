//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2022-06-14
// PURPOSE: unit tests for the UUID library
//          https://github.com/RobTillaart/UUID
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// https://github.com/Arduino-CI/arduino_ci/blob/master/cpp/unittest/Assertion.h#L33-L42
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)
// assertNotNull(actual)

#include <ArduinoUnitTests.h>


#include "Arduino.h"
#include "UUID.h"


unittest_setup()
{
  fprintf(stderr, "UUID_LIB_VERSION: %s\n", (char *) UUID_LIB_VERSION);
}

unittest_teardown()
{
}


unittest(test_constants)
{
  assertEqual(0, 0);
}


unittest(test_generate)
{
  UUID uuid;
  assertEqual(0, uuid.count());
  assertEqual(1, uuid.generate());
  assertEqual(1, uuid.count());
}



unittest_main()

// --------
