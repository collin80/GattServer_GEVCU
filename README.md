# GattServer_GEVCU


A GATT Server running on ESP32 for use with GEVCU (or maybe other boards if you're crafty)

This sketch is so far a test for setting up a BLE GATT Server on the ESP32 chip. At the moment it can register
all of the needed characteristics and display them to the end user. That's part 1 of two necessary pieces.

Part 2 (in progress!) will be getting the code to also act as a SPI slave to connected devices and allow them to send/receive
updates to information needed by GEVCU. 

So, this is quite specific to GEVCU but could be used as a baseline for other GATT servers that you might want
to build on the ESP32 chip.

There is now a test sketch that runs on Teensy boards that can be used to validate proper operation of the ESP32. It uses a Teensy adapter board not available to the public yet (yeah, I'm like that). So, good luck. But, you could make your own interface board by bread boarding an ESP32 and hooking it up a Teensy with teensy little wires. 

To compile the ESP32 sketch you need a very recent version of the esp-idf project. Download that lil devil along with the ESP32 compiler and you too can play with wireless boards.
