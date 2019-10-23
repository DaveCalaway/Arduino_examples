// PARSE STRING BY TOKEN, comma separated text

void setup() {
  // buffer with data
  char someDataFeed[] = "sgklfjgflgwaasdcKevinONE,2,THREE,4,5.1203";

  // keyword to looks for in the buffer
  char keyword[] = "Kevin";

  char *pointerToFoundData = strstr(someDataFeed, keyword);// go find keyword
  if (pointerToFoundData != NULL) { //found it
    int positionInString = pointerToFoundData - someDataFeed;
    Serial.print("Keyword Starts at ");
    Serial.println(positionInString);

    // now strip out keyword and junk
    char goodData[50];
    strncpy(goodData, &someDataFeed[positionInString + strlen(keyword)], sizeof(goodData));
    Serial.println(goodData);
    Serial.println(" ");


    // PARSE **  PARSE **  PARSE **  PARSE **  PARSE **  PARSE **  PARSE **
    const char delimiter[] = ",";
    char parsedStrings[5][20]; // array with 5 locations and 20 character for location
    char *token =  strtok(goodData, delimiter);
    strncpy(parsedStrings[0], token, sizeof(parsedStrings[0]));//first one
    for (int i = 1; i < 5; i++) {
      token =  strtok(NULL, delimiter);
      strncpy(parsedStrings[i], token, sizeof(parsedStrings[i]));
    }

    for (int i = 0; i < 5; i++)
      Serial.println(parsedStrings[i]);//  should have the 5 data strings parsed out

  } else {
    Serial.println("NO KEYWORD");
  }
}


void loop() {

}
