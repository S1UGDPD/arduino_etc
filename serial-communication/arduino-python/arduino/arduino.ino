void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potRead = analogRead(A0);
  Serial.println(potRead);

  delay(50);
}
