/*
  Current Sensitivity
          0.185 for ACS712ELCTR-05B-T
          0.100 for ACS712ELCTR-20A-T
          0.066 for ACS712ELCTR-30A-T
  sensitivity array is holding the sensitivy of the  ACS712
  current sensors. Do not change. All values are from page 5  of data sheet
*/

#define Current_sensor A1
#define Current_sensitivity 0.066

int rawI;
float rawV, i;

void setup() {
  Serial.begin(9600);
  pinMode(Current_sensor, INPUT);

}

void loop() {
  rawI = analogRead(Current_sensor);
  //  rawV = 5.0 * 0.00097751710 * rawI;
  rawV = 5.0 * 0.000996954 * rawI;
  i = (rawV+30)*0.08333333333;
  

  Serial.print(rawI); Serial.print("\t"); Serial.print(rawV, 3); Serial.print("\t");
  Serial.print(i, 3); Serial.println(" mA");
  delay(100);
}
