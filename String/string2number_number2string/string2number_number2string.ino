// CONVERT STRINGS TO NUMBERS AND FROM NUMBERS TO STRINGS

// Global variables
char goodData[50]; // now strip out keyword and junk
char parsedStrings[5][20]; // array with 5 locations and 20 character for location


// --- FIND KEY ---
void find_key(char someDataFeed[], char keyword[]) {
  char *pointerToFoundData = strstr(someDataFeed, keyword); // go find keyword

  if (pointerToFoundData != NULL) { //found it
    int positionInString = pointerToFoundData - someDataFeed;
    Serial.print("Keyword Starts at ");
    Serial.println(positionInString);

    strncpy(goodData, &someDataFeed[positionInString + strlen(keyword)], sizeof(goodData));
    Serial.println(goodData);
    Serial.println(" ");
  }
  else {
    Serial.println("NO KEYWORD");
  }
}

// --- PARSE ---
void parse_data() {
  const char delimiter[] = ",";

  char *token =  strtok(goodData, delimiter);
  strncpy(parsedStrings[0], token, sizeof(parsedStrings[0]));//first one
  for (int i = 1; i < 5; i++) {
    token =  strtok(NULL, delimiter);
    strncpy(parsedStrings[i], token, sizeof(parsedStrings[i]));

  }
}

// --- SETUP ---
void setup() {
  // keyword to looks for in the buffer
  char someDataFeed[] = "sgklfjgflgwaasdcKevin-56,1000000,4.57687,text,more text";

  // buffer with data
  char keyword[] = "Kevin";

  find_key(someDataFeed, keyword);
  parse_data();

  for (int i = 0; i < 5; i++)
    Serial.println(parsedStrings[i]);//  should have the 5 data strings parsed out

  // CONVERT CONVERT ** CONVERT CONVERT ** CONVERT CONVERT ** CONVERT CONVERT **
  // data should be an int, long, float, text, text
  int firstInteger = atoi(parsedStrings[0]);
  Serial.println(firstInteger);

  long secondLong = atol(parsedStrings[1]);
  Serial.println(secondLong);

  float thirdFloat = atof(parsedStrings[2]);
  Serial.println(thirdFloat);

  //now to convert everything back into a string
  char newString[100];
  char floatValue[5];
  dtostrf(thirdFloat, 1, 2, floatValue);//convert float to str
  sprintf(newString, "%s%i,%li,%s,%s,%s", keyword, firstInteger, secondLong, floatValue, parsedStrings[3], parsedStrings[4]);
  Serial.println(newString);
}

// --- LOOP ---
void loop() {
  // put your main code here, to run repeatedly:

}
