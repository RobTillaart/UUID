
[![Arduino CI](https://github.com/RobTillaart/UUID/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/UUID/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/UUID/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/UUID/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/UUID/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/UUID/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/UUID.svg?maxAge=3600)](https://github.com/RobTillaart/UUID/releases)


# UUID

Arduino library for generating UUID strings.


## Description

This **experimental** library provides a UUID generator.
A UUID is an Universally Unique IDentifier of 128 bits.
These are typically written in the following format, defined in RFC 4122.

```
    0ac82d02-002b-4ccb-b96c-1c7839cbc4c0
                  ^    ^
```

The length is 32 HEX digits + four hyphens = 36 characters.
Note that the HEX digits are lower case.

The 0.1.1 version of the lib tries to follow the RFC4122, 
for version 4 and variant 1.
In the format above the version 4 is indicated by the first arrow and must be 4.
The variant 1 is at the position of the second arrow. 
This nibble must be 8,9, a or b.

The basis for the UUID class is a Marsaglia pseudo random number generator.
This PRNG must be seeded with two real random uint32_t to get real random UUID's.

Often one sees also the term GUID = Globally Unique Identifier.

Tested on Arduino UNO only.

- https://en.wikipedia.org/wiki/Universally_unique_identifier
- https://en.wikipedia.org/wiki/GUID


## Interface


## UUID class

Use **\#include "UUID.h"**

The UUID class has only a few methods.

- **UUID()** Constructor, initializes internals an generates a default UUID.
- **void seed(uint32_t s1, uint32_t s2 = 0)** reseeds the internal 
pseudo random number generator.
It is mandatory to set s1 while s2 is optional.
The combination {0, 0} is not allowed and overruled in software.
- **void generate(bool rnd)** generates a new UUID.
  - if rnd == true, all UUID bits are random. (== fastest mode).
  - if rnd == false, the UUID (tries to) conform to version 4 variant 1.
  see above.
- **char \* toCharArray()** returns a pointer to a char buffer 
representing the last generated UUID. 
Multiple subsequent calls to **toCharArray()** gives the same UUID 
until **generate()** is called.


### Printable 

The UUID class implements the printable interface.
This allows one to print the UUID object directly over Serial and any other
stream implementing the Print interface. Think Ethernet or SD card. 

```cpp
UUID uuid;

Serial.println(uuid);

// gives same output as

Serial.println(uuid.toCharArray());
```


## Performance

Not tested ESP32 (and many other platforms) yet.
Performance measured with **UUID_test.ino** shows the following times,
Note that 0.1.1 has 2x better performance on AVR.


| Version |  Function    |  UNO 16 MHz  |  ESP32 240 MHz  |
|:-------:|:-------------|:------------:|:---------------:|
| 0.1.0   | seed         |       4 us   |                 |
| 0.1.0   | generate     |     412 us   |                 |
| 0.1.0   | toCharArray  |       4 us   |                 |
| 0.1.1   | seed         |       4 us   |                 |
| 0.1.1   | generate(T)  |     196 us   |                 | 
| 0.1.1   | generate(F)  |     240 us   |                 | 
| 0.1.1   | toCharArray  |       4 us   |                 |


UUID's per second

| Version |  UNO 16 MHz  |  ESP32 240 MHz  | notes  |
|:-------:|:------------:|:---------------:|:------:|
| 0.1.0   |    2000++    |                 |
| 0.1.1   |    5000++    |                 | use generate(true);
| 0.1.1   |    4000++    |                 | use generate(false);

Note that this max is not realistic e.g. for a server where also
other tasks need to be done (listening, transfer etc).


## Operation

See examples.


## Future

### General

- improve documentation
  - external random input needed
  - GUID, UUID, versions (links)
  - background
- test other platforms
- investigate entropy harvesting
  - freeRAM, micros, timers, RAM, USB-ID, ...

### Functions

- add **setSeparator(char)** and **getSeparator()** ?
  - one char
- add **setUpperCase()** and **setLowerCase()**, **isUpperCase()**
  - one bool flag
- binary output in a byte array ?
- follow the RFC4122 in terms of the content.
  - should be version 4 (random)  variant 1

### Examples

- ESP32 UUID server 
  - using timing of the calls as entropy !
- RTC for entropy

### Fixes / optimizations

- reduce footprint
  - can the buffer be reduced?
  - smaller random generator?

### Won't

- support for { and }


