void setup() {
  Serial.begin(115200);
  }

void loop() {
  char *strBuf = (char*)malloc(8*sizeof(char));
  if (strBuf == NULL){Serial.println("malloc failed");}
  
  else {
    Serial.println("malloc succeeded");
    strcpy(strBuf, "testing");
  }

  Serial.println("Attempting to read from buffer");
  Serial.println(strBuf);
  
  delay (5000);
  free(strBuf);  
}
