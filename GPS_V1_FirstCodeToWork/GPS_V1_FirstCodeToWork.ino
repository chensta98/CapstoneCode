#include <SparkFun_u-blox_GNSS_Arduino_Library.h>
#include <u-blox_config_keys.h>
#include <u-blox_structs.h>

#include <Wire.h> // I2C to GPS

#define I2C_SDA 21
#define I2C_SCL 20

SFE_UBLOX_GNSS myGNSS;

void setup() {
delay(2000);
Serial.begin(115200);
Serial.println("SparkFun u-blox Example");

Wire.begin(I2C_SDA, I2C_SCL);

myGNSS.begin();
if (myGNSS.begin() == false) 
  {
    Serial.println(F("u-blox GNSS module not detected at default I2C address. Please check wiring. Freezing."));
  }
Serial.println("I2C Default Setup Passed");
//  //This will pipe all NMEA sentences to the serial port so we can see them
myGNSS.setNMEAOutputPort(Serial);
}



void loop() 
{
  myGNSS.checkUblox();
  delay(250);

  //TODO: Pull out all serial lines starting w/ $GNGLL

  //TODO: Store serial line in Txt format

  //TODO: Send Txt File via Wifi

}

