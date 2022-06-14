
[![Arduino CI](https://github.com/RobTillaart/UUID/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/UUID/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/UUID/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/UUID/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/UUID/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/UUID/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/UUID.svg?maxAge=3600)](https://github.com/RobTillaart/UUID/releases)


# UUID

Arduino Library for generating UUID strings.


## Description

This experimental library provides a UUID generator.

The basis for the UUID is a pseudo random number generator.
This must be seeded with two random numbers to get real usable UUID's.

In such this is for experimental sue only.

Tested on Arduino UNO only.

// e.g. 20D24650-D900-E34F-DE49-8964AB3EB46D


## Interface


## UUID class

Use **\#include "UUID.h"**

- **UUID()** Constructor, initializes internals.
- **void seed(uint32_t s1, uint32_t s2 = 0)** resets the internals.
mandatory setting start values for s1 and optional for s2.
- **void generate()** generates new random numbers for UUID
- **char \* toCharArray()** returns a pointer to internal char buffer.


### Printable 

The UUID class implements the printable interface.
This allows one to print the UUID object directly.
This uses the **toCharArray()** internally.

```cpp
UUID uuid;

Serial.println(uuid);
```

#### Performance

Not tested ESP32 (and many other platforms) yet.
First numbers measured with **UUID_test.ino** shows the following timing.

| Version |  Function         |  UNO 16 MHz  |  ESP32 240 MHz  |
|:-------:|:------------------|:------------:|:---------------:|
| 0.1.0   | seed              |       4 us   |                 |
| 0.1.0   | generate          |      44 us   |                 |
| 0.1.0   | toCharArray dirty |     352 us   |                 |
| 0.1.0   | toCharArray clean |       4 us   |                 |

The performance of **char \* toCharArray()** depends on the dirty flag
which is set if a new UUID is generated.

Note an UNO can generate 2000++ UUID's per second.


## Operation

See examples.

Note: compile warning ...


## Future

- update documentation
  - external random input needed
- investigate entropy harvesting
  - freeRAM, micros, timers, RAM, USB-ID, ...
- test other platforms
- improve performance of **toCharArray()**
- add **setSeparator(char)** ? + getter?
- Fix compile warning - printTo().
- add example ESP32 UUID server 
  - using timing of the calls as entropy !
- add example
  - RTC for entropy
- add flag for generate to call **toCharArray()** (so it is not dirty)




