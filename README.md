# GattServer_GEVCU


A GATT Server running on ESP32 for use with GEVCU (or other boards)


This sketch is so far a test for setting up a BLE GATT Server on the ESP32 chip. At the moment it can register
all of the needed characteristics and display them to the end user. That's part 1 of two necessary pieces.

Part 2 will be getting the code to also act as a SPI slave to connected devices and allow them to send/receive
updates to information needed by GEVCU. 

So, this is quite specific to GEVCU but could be used as a baseline for other GATT servers that you might want
to build on the ESP32 chip.
