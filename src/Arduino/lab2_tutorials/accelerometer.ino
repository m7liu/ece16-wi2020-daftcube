#define ACCEL_Z_PIN A0

#if ACCELEROMETER
void setup() {
  // put your setup code here, to run once:
  pinMode(ACCEL_Z_PIN, INPUT);  
  Serial.begin(9600);
}

void loop() {
  int readValue = analogRead(ACCEL_Z_PIN);
  Serial.println(readValue);
  delay(100);
}
#endif
