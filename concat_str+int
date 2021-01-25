/*
 * Concatenate file name with name + number + extension
 */

void setup() {
  Serial.begin(9600);
  char fullName[12];
  unsigned int fileNum = 1111;
  const char *fileName = "log";  // no array size, it will be AUTO terminated with \0
  const char *ext = ".csv";      // no array size, it will be AUTO terminated with \0
  char num[5]; // defined array size, NO auto teminated with \0

  //The terminating null character in destination is overwritten by the first character of source, 
  //and a null-character is included at the end of the new string formed by the concatenation of both in destination.
  strcpy(fullName, fileName);
  itoa(fileNum, num, 10); // output in base 10 + auto terminated with \0
  strcat(fullName, num);
  strcat(fullName, ext);
  
  Serial.println(fullName);

}

void loop() {
  // put your main code here, to run repeatedly:

}
