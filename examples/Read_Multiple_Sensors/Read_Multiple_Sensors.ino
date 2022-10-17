/**
 * This is a simple demo code that reads the Temperature and Humidity of the "SHTC3 RS485 Modbus RTU".
 * With default sensor configuration parameters: Baudrate 4800 bit/s ; Address 0x01.
 *
 * There are 2 ways to use it:
 * 1. Use the Struct variable "dataSHTC3"
 * 2. Read each value type separately
 */

#include "SHTC3Modbus.h"

/* ------------------------------------------------------------------------- */

#define RX_SHT 11
#define TX_SHT 12

/* Using with SoftwareSerial, default (RX=11) and (TX=12) */
SHTC3 demo(RX_SHT, TX_SHT);

/* Using with HardwareSerial, default (RX=0) and (TX=1) */
// SHTC3 demo(0x01);

/* ------------------------------------------------------------------------- */

void setup()
{
  /* ----------------------- Test with SoftwareSerial ---------------------- */
  Serial.begin(115200);
  Serial.println(F("Start reading SHTC3 Modbus (HSHOP)"));

  demo.begin(4800);

  /* ----------------------- Test with HardwareSerial ---------------------- */
  // Serial.begin(4800);
  // Serial.println(F("Start reading SHTC3 Modbus (HSHOP)"));

  // demo.begin(4800);
}

void loop()
{
  /* --------------------------------- [01] -------------------------------- */
  dataSHTC3 data = demo.getData(0x02);

  Serial.print(data.temperatureC);
  Serial.print(F("°C\t"));
  Serial.print(data.temperatureF);
  Serial.print(F("°F\t"));
  Serial.print(data.humidity);
  Serial.print(F("%\t\t\t"));
  delay(10);
  data = demo.getData(0x01);

  Serial.print(data.temperatureC);
  Serial.print(F("°C\t"));
  Serial.print(data.temperatureF);
  Serial.print(F("°F\t"));
  Serial.print(data.humidity);
  Serial.println(F("%"));

  delay(1000);
}