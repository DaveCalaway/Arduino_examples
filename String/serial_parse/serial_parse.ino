// READ FROM SERIAL AND PARSE OUT

// Globals variables
char rawData[100] = "";
char keyword[] = "Mydata=";
char parsedStrings[4][20];
bool dataOK = 0;


// --- PARSE KEY ----
byte parse_key(int dataPosition) {
  const char delimiter[] = ",";
  int dataCount = 0;

  char *token =  strtok(&rawData[dataPosition], delimiter);//look for first piece of data after keyword until comma
  if (token != NULL && strlen(token) < sizeof(parsedStrings[0])) {
    strncpy(parsedStrings[0], token, sizeof(parsedStrings[0]));
    dataCount++;
  } else {
    Serial.println("token to big");
    strcpy(parsedStrings[0], NULL);
  }

  for (int i = 1; i < 4; i++) {
    token =  strtok(NULL, delimiter);
    if (token != NULL && strlen(token) < sizeof(parsedStrings[i])) {
      strncpy(parsedStrings[i], token, sizeof(parsedStrings[i]));
      dataCount++;
    } else {
      Serial.println("token to big");
      strcpy(parsedStrings[i], NULL);
    }
  }

  Serial.print("Found ");
  Serial.print(dataCount);
  Serial.println(" strings:");
  for (int i = 0; i < 4; i++)
    Serial.println(parsedStrings[i]);

  return dataCount;
}

// --- CONVERT VARIABLES ---
void convertVariable(char *theText, int *theInt, long *theLong, float *theFloat) {
  strncpy(theText, parsedStrings[0], sizeof(theText));
  *theInt = atoi(parsedStrings[1]);
  *theLong = atol(parsedStrings[2]);
  *theFloat = atof(parsedStrings[3]);
}


// --- SETUP ---
void setup() {
  Serial.println("Send me data like this: Mydata=text,int,long,float");
}


// --- LOOP ---
void loop() {
  if (Serial.available() > 0) { // new data in in the Serial buffer
    /* read the single character from the Serial buffer
      - Parameters:
      stream : an instance of a class that inherits from Stream.
      character : the character to search for (char)
      buffer: the buffer to store the bytes in (char[] or byte[])
      length : the number of bytes to read (int)

      Remember to set "newline" in the Serial terminal, or the \n doesn't arrive!
    */
    size_t byteCount = Serial.readBytesUntil('\n', rawData, sizeof(rawData) - 1); // numbers of character -1
    // -1 because we need to add the null character
    rawData[byteCount] = NULL;// put an end character on the data
    Serial.print("Raw Data = ");
    Serial.println(rawData);
    dataOK = 1;
  }

  if (dataOK == 1 ) { // have i received something?
    dataOK = 0;

    char *keywordPointer = strstr(rawData, keyword); //now find keyword and parse
    if (keywordPointer != NULL) {
      int dataPosition = (keywordPointer - rawData) + strlen(keyword); //should be position after Mydata=

      byte dataCount = parse_key(dataPosition); // do the parse

      // convert to variables that we can actually use
      char theText[20];
      int theInt = 0;
      long theLong = 0;
      float theFloat = 0.0;

      if (dataCount == 4) {
        convertVariable(theText, &theInt, &theLong, &theFloat);
        Serial.print("The Text = ");
        Serial.println(theText);
        Serial.print("The Int = ");
        Serial.println(theInt);
        Serial.print("The Long = ");
        Serial.println(theLong);
        Serial.print("The Float = ");
        Serial.println(theFloat);
      } else {
        Serial.println("data no good");
      }
    } else Serial.println("sorry no keyword");
  }
}
