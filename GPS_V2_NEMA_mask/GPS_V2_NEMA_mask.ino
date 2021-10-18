#include <SparkFun_u-blox_GNSS_Arduino_Library.h>
#include <u-blox_config_keys.h>
#include <u-blox_structs.h>

#include <Wire.h> // I2C to GPS

#define I2C_SDA 21
#define I2C_SCL 20

#define Data_Buf_Size 512
SFE_UBLOX_GNSS myGNSS;

void setup() {
delay(2000);
Serial.begin(115200);
Serial.println("SparkFun u-blox Example");

//Serial.println("setting up data buffer")
//char *myData = (char*)malloc(Data_buf*sizeof(char));



Wire.begin(I2C_SDA, I2C_SCL);
myGNSS.setFileBufferSize(Data_Buf_Size); //must be called before .begin() 

myGNSS.begin();
if (myGNSS.begin() == false) 
  {
    Serial.println(F("u-blox GNSS module not detected at default I2C address. Please check wiring. Freezing."));
  }
Serial.println("I2C Default Setup Passed");
//  //This will pipe all NMEA sentences to the serial port so we can see them
//myGNSS.setNMEAOutputPort(Serial);

myGNSS.setI2COutput(COM_TYPE_UBX | COM_TYPE_NMEA); //Set the I2C port to output both UBX and NMEA messages

myGNSS.setNavigationFrequency(1); //Produce only 1 navigation solution per second

myGNSS.setAutoPVT(true, false); //Enables automatic NAV PVT messages: no callback; no implicit update
myGNSS.logNAVPVT(); //Enables NAV PVT data logging

myGNSS.enableNMEAMessage(UBX_NMEA_GGA, COM_PORT_I2C, 1); //Enables logging of posFix messages

myGNSS.setNMEALoggingMask(SFE_UBLOX_FILTER_NMEA_ALL);

}



void loop() 
{
  myGNSS.checkUblox();

  while (myGNSS.fileBufferAvailable() >= Data_Buf_Size) {
    uint8_t myBuffer[Data_Buf_Size];
    myGNSS.extractFileBufferData((uint8_t *)&myBuffer, Data_Buf_Size);

    Serial.println((char*)myBuffer);

    myGNSS.checkUblox();
  }

  
  //free(myData);
  //TODO: Pull out all serial lines starting w/ $GNGLL

  //TODO: Store serial line in Txt format

  //TODO: Send Txt File via Wifi

}

