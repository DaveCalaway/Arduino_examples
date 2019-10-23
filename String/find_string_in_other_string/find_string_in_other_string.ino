// FIND STRING IN ANOTHER STRING, like a keyword, then save data after that

void setup() {
  // buffer with data
  char someDataFeed[] = "sgfjfghkfkKevin12345";

  // keyword to looks for in the buffer
  char keyword[] = "Kevin";

  char *pointerToFoundData = strstr(someDataFeed, keyword);//go find keyword
  if (pointerToFoundData != NULL) { //found it
    int positionInString = pointerToFoundData - someDataFeed;
    Serial.print("Keyword Starts at ");
    Serial.println(positionInString);

    //now strip out keyword and junk
    char goodData[20];
    strncpy(goodData, &someDataFeed[positionInString + strlen(keyword)], sizeof(goodData));
    Serial.println(goodData);
  } else {
    Serial.println("NO KEYWORD");
  }
}

void loop() {

}
