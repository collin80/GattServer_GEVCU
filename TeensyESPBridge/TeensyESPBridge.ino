//If this is defined then we set pins to force the ESP32 into bootloader mode
//otherwise the board won't accept new firmware
//#define BOOTLOADER  

#include <SPI.h>

#define BLE_RST 7   //read on start up to get into bootloader mode
#define BLE_DFU 8   //used as IRQ for ESP32 but bootloader mode on start up
#define BLE_IRQ 9   //but ESP32 board has this attached to Enable pin
#define BLE_CS  10  //slave select pin for ESP32

void setup() {
#ifdef BOOTLOADER
   pinMode(BLE_RST, OUTPUT);
   pinMode(BLE_DFU, OUTPUT);
   pinMode(BLE_IRQ, OUTPUT);
   
   digitalWrite(BLE_RST, LOW);
   digitalWrite(BLE_DFU, LOW);
   digitalWrite(BLE_IRQ, HIGH);
#else
   pinMode(BLE_IRQ, OUTPUT);
   pinMode(BLE_DFU, INPUT);
   pinMode(BLE_RST, OUTPUT);
   digitalWrite(BLE_RST, LOW);
   delay(5000); //give user 5 seconds to fire up a serial console
   digitalWrite(BLE_RST, HIGH); //then set enable pin to high so ESP32 board boots
   //digitalWrite(BLE_DFU, HIGH);
   digitalWrite(BLE_IRQ, HIGH);
   pinMode(BLE_CS, OUTPUT);
   digitalWrite(BLE_CS, HIGH); //HIGH = off
   SPI.begin();
#endif

   Serial.begin(115200);
   Serial4.begin(115200);

}

void loop() {
   static uint32_t lastCount;
   if (Serial4.available()) Serial.write(Serial4.read());
#ifdef BOOTLOADER
   if (Serial.available()) Serial4.write(Serial.read());
#else
   if ((lastCount + 100) < millis())
   {
      lastCount = millis();
      if (digitalRead(BLE_DFU))
      {
          digitalWrite(BLE_CS, LOW);
          delayMicroseconds(10);
          for (int i = 0; i < 128; i++) {
              Serial.write(SPI.transfer('0' + i % 10));
          }
          digitalWrite(BLE_CS, HIGH);
          Serial.println("got SPI");
      }
      else Serial.println("Ain't no SPI");
   }   
#endif
   
}
