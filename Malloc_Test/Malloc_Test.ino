void setup() {
  Serial.begin(115200);
}

void loop() {
  byte *ptr = (byte*)malloc(8);
  if (ptr == NULL){Serial.println("malloc failed");}
  else {
    Serial.println("malloc succeeded");
    free(ptr);  
  }
  delay (5000);
}
