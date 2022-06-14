
[![Arduino CI](https://github.com/RobTillaart/UUID/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/UUID/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/UUID/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/UUID/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/UUID/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/UUID/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/UUID.svg?maxAge=3600)](https://github.com/RobTillaart/UUID/releases)


# UUID

Arduino library for generating UUID strings.


## Description

This experimental library provides a UUID generator.

The basis for the UUID is a Marsaglia pseudo random number generator.
This must be seeded with two random numbers to get real usable UUID's.

In such this is for experimental use only.

Tested on Arduino UNO only.

// e.g. 20D24650-D900-E34F-DE49-8964AB3EB46D
// version uuid?
// layout  rfc4122


## Interface


## UUID class

Use **\#include "UUID.h"**

- **UUID()** Constructor, initializes internals.
- **void seed(uint32_t s1, uint32_t s2 = 0)** reseeds the internal 
pseudo random number generator.
Mandatory to set s1 while s2 is optional.
- **void generate()** generates new random numbers for a new UUID.
- **char \* toCharArray()** returns a pointer to a char buffer 
representing the last generated UUID.


### Printable 

The UUID class implements the printable interface.
This allows one to print the UUID object directly.
To do so it uses the **toCharArray()** internally.

```cpp
UUID uuid;

Serial.println(uuid);
```

Note: there is a knwon compile warning on AVR on this. 


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

### General

- improve documentation
  - external random input needed
  - GUID, UUID, versions (links)
  - background 
  - RFC layout
- test other platforms
- investigate entropy harvesting
  - freeRAM, micros, timers, RAM, USB-ID, ...

### Functions

- add **setSeparator(char)** and **getSeparator()** ?
  - one char
- add **setUpperCase()** and **setLowerCase()**, **isUpperCase()**
  - one bool flag 
- add flag for generate to call **toCharArray()** (so it is not dirty)

### Examples

- ESP32 UUID server 
  - using timing of the calls as entropy !
- RTC for entropy

### Fixes / optimizations

- improve performance of **toCharArray()**
- reduce footprint
  - can the buffer be reduced?
  - smaller random generator?
- Fix compile warning - printTo().


