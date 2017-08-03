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
   static int which = 0;
   uint8_t buff[8];
   if (Serial4.available()) Serial.write(Serial4.read());
#ifdef BOOTLOADER
   if (Serial.available()) Serial4.write(Serial.read());
#else
   if ((lastCount + 4000) < millis())
   {
      Serial.println();
      lastCount = millis();
      digitalWrite(BLE_CS, LOW);
      delayMicroseconds(10);
      //Due to unending stupidity in the ESP32 design one must send SPI traffic
      //with at least 8 bytes and then in multiples of 4 bytes or data could be lost.
      //Yeah, that's stupid.
      if (which == 0)
      {
          buff[0] = SPI.transfer(0xA5);
          buff[1] = SPI.transfer(0x40);
          buff[2] = SPI.transfer(0x01);
          buff[3] = SPI.transfer(0x32);
          buff[4] = SPI.transfer(0);
          buff[5] = SPI.transfer(0);
          buff[6] = SPI.transfer(0);
          buff[7] = SPI.transfer(0);
      }
      if (which == 1)
      {
          buff[0] = SPI.transfer(0xA5);
          buff[1] = SPI.transfer(0x40);
          buff[2] = SPI.transfer(0x09);
          buff[3] = SPI.transfer(0x33);
          buff[4] = SPI.transfer(00);
          buff[5] = SPI.transfer(0);
          buff[6] = SPI.transfer(0);
          buff[7] = SPI.transfer(0);
      }
      if (which == 2)
      {
          buff[0] = SPI.transfer(0xA5);
          buff[1] = SPI.transfer(0xC0);
          buff[2] = SPI.transfer(0x06);
          buff[3] = SPI.transfer(0x31);
          buff[4] = SPI.transfer(1);
          buff[5] = SPI.transfer(2);
          buff[6] = SPI.transfer(4);
          buff[7] = SPI.transfer(8);
      }
      if (which == 3)
      {
          buff[0] = SPI.transfer(0xA5);
          buff[1] = SPI.transfer(0xC0);
          buff[2] = SPI.transfer(0x3E);
          buff[3] = SPI.transfer(0x35);
          buff[4] = SPI.transfer(1);
          buff[5] = SPI.transfer(2);
          buff[6] = SPI.transfer(4);
          buff[7] = SPI.transfer(8);
      }      
      if (which == 4)
      {
          buff[0] = SPI.transfer(0xBE);
          buff[1] = SPI.transfer(0x40);
          buff[2] = SPI.transfer(1);
          buff[3] = SPI.transfer(40);
          buff[4] = SPI.transfer(0);
          buff[5] = SPI.transfer(0);
          buff[6] = SPI.transfer(0);
          buff[7] = SPI.transfer(0);
      }
      if (which == 5)
      {
          buff[0] = SPI.transfer(0xA5);
          buff[1] = SPI.transfer(0x4D);
          buff[2] = SPI.transfer(1);
          buff[3] = SPI.transfer(40);
          buff[4] = SPI.transfer(0);
          buff[5] = SPI.transfer(0);
          buff[6] = SPI.transfer(0);
          buff[7] = SPI.transfer(0);
      }      

      Serial.print("Reply from previous msg: ");
      for (int j = 0; j < 8; j++) 
      {
        Serial.print(buff[j], HEX);
        Serial.print(" ");
      }
      Serial.println();
      
      
      digitalWrite(BLE_CS, HIGH);      
      which = (which + 1) % 6;
   }   
#endif
   
}
