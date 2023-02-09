
#define sensorInterrupt     0       // 0 = digital pin 2 as interrupt
#define sensorPin           2       // flow meter sensor pin
#define calibrationFactor   5.5;    // the hall-effect flow sensor outputs approximately 5.5 pulses per second per litre/minute of flow.

volatile byte pulseCount = 0;       // variable to store pulse count from the hall-effect sensor
byte pulse1Sec = 0;                 // *variable to store pulse count

float flowRate_min = 0;             // flow in L/min
float flowRate_sec = 0;             // flow in L/sec
float vol_litres = 0;               // vol in L
float flowRate_mLsec = 0;           // flow in mL/sec

unsigned long prevTimeSensor = 0;   // variable to store previous millis time of sensor

void setup() {
  Serial.begin(115200);             // initialize serial with serial monitor

  pinMode(sensorPin, INPUT);        // set pinmode for sensor pin as input
  digitalWrite(sensorPin, HIGH);    // set sensor pin as input pull up

  attachInterrupt(sensorInterrupt, flowCounter, FALLING);   // set sensorInterrupt as interrupt, run flowCounter() when state is FALLING (High to Low)
}


void loop() {
  if ((millis() - prevTimeSensor) > 1000) {
    
    pulse1Sec = pulseCount;
    pulseCount = 0;
    
    flowRate_min = ( ( 1000.0 / (millis() - prevTimeSensor) ) * pulse1Sec) / calibrationFactor;    // pulseCount = 5.5 Q; Q = L/min

    prevTimeSensor = millis();

    flowRate_mLsec = flowRate_min * 1000 / 60;    // flow in mL/sec    
//    flowRate_sec = flowRate_min / 60;             // flow in L/sec
//    vol_litres += flowRate_sec;                   // vol in L

    Serial.print("Flow rate: ");
    Serial.print(flowRate_mLsec);
    Serial.println(" mL/sec");
    
    Serial.print("Volume: ");
    Serial.print(vol_litres);
    Serial.println("L");
  }
}


void flowCounter() {
  pulseCount++;         // pulse count increment
}
