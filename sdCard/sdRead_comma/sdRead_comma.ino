/*
  SD card file comma

  This example shows how to read a file from the SD card using the
  SD library and feed the String. 
  --> SD file example : 1,2,3,4,5,6 ( plus the '\r' = CR (Carriage Return)  )
  The String class separate every datas between the commas and save the 
  result in a array.

  The circuit:
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

  created  22 December 2010
  by Limor Fried
  modified 9 Apr 2012
  by Tom Igoe
  modified 14 July 2017
  Davide Gariselli
  
  This example code is in the public domain.
*/

#include <SPI.h>
#include <SD.h>

const int chipSelect = 4;
byte fileN = 0;
byte i = 0;
// array dimenion
int base[6] = {5, 4, 3, 2, 1, 0};

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("1.txt");
  Serial.println("1.txt");

  // if the file is available, write to it:
  if (dataFile) {
    while (dataFile.available()) {
      //Serial.write(dataFile.read());
      // https://goo.gl/4jooTB
      String myString = dataFile.readStringUntil('\r');
      // https://goo.gl/wRM9CW
      Serial.print("File on the SD: ");
      Serial.println(myString);

      // First comma
      int commaIndex = myString.indexOf(',');
      String Value = myString.substring(0, commaIndex);
      base[i] = Value.toInt();
      Serial.print("What i read: ");
      Serial.println(base[i]);

      byte a = 1;
      int OLDcommaIndex = commaIndex + 1;
      while ( a == 1 ) {
        i = i + 1;
        int NextcommaIndex = myString.indexOf(',', OLDcommaIndex);
        Serial.print("Next comma: ");
        Serial.println(NextcommaIndex);
        Value = myString.substring(OLDcommaIndex, NextcommaIndex);
        Serial.print("What i read: ");
        Serial.println(Value);
        base[i] = Value.toInt();
        OLDcommaIndex = NextcommaIndex + 1;
        
        if ( NextcommaIndex == -1 )  a = 0;
      }
    }
    dataFile.close();
    // Print array extracted
    for ( byte y = 0; y <= i; y++) {
      Serial.println(base[y]);
    }
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}

void loop() {
}

