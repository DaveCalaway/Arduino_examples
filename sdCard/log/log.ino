/*
 * Create a new file, increment name, every reboot or if the file size is greater than maxSDsize
 */

#include <SD.h>

#define maxSDsize 200 // bytes
#define csPin 10

char fullName[12];
unsigned int fileNum = 0;


//** ------------ **
void checkSD() {
    if (!SD.begin(csPin)) {
        Serial.println("SD initialization fail.");
        while (true)
            ;
    }
}

//** ------------ **
void save_data(char *buffer) {
  bool wrote = 0;

  while (!wrote) {
    File dataFile = SD.open(fullName, FILE_WRITE); // create or append file

    if (dataFile.size() < maxSDsize) {  // size ok, write in the same file
      Serial.print("size: ");
      Serial.println(dataFile.size());
      dataFile.write(buffer);
      dataFile.write("\n");
      wrote = 1;
      Serial.println("File written.");
    } else {  // file name ++
      Serial.println("Creating new file.");
      fileNum++;
      const char *fileName = "log";  // no array size, it will be AUTO teminated with \0
      const char *ext = ".csv";      // no array size, it will be AUTO teminated with \0
      char num[5];                   // defined array size, NO auto teminated with \0

      fullName[0] = 0;             // nulls out the first charater - effectively making an empty string
      strcpy(fullName, fileName);  // output auto terminater with \0
      itoa(fileNum, num, 10);      // output in base10 + auto terminated with \0
      strcat(fullName, num);
      strcat(fullName, ext);
    }
    dataFile.close();
  }
}

//** ------------ **
void fileName() {
  const char *fileName = "log";  // no array size, it will be AUTO teminated with \0
  const char *ext = ".csv";      // no array size, it will be AUTO teminated with \0
  char num[5];                   // defined array size, NO auto teminated with \0
  bool notFind = 1;

  while (notFind) {
    strcpy(fullName, fileName);  // output auto terminater with \0
    itoa(fileNum, num, 10);      // output in base10 + auto terminated with \0
    strcat(fullName, num);
    strcat(fullName, ext);
    //Serial.println(fullName);

    if (SD.exists(fullName))
      fileNum++;
    else
      notFind = 0;
  }
  Serial.print("last file name: ");
  Serial.println(fullName);
}



void setup() {
  Serial.begin(9600);
  Serial.println("\n");
  
  checkSD();
  fileName();
}

void loop() {
    char text[] = "chiappe";
    
    save_data(text);
    delay(1000);
}
