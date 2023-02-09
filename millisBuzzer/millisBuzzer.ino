#define buzzer              11
#define input               8

unsigned long prevTimeBuzzer = 0;   // variable to store previous millis time of buzzer
unsigned long currentTime = 0;      // variable to store current millis time

bool alarm = false;                 // variable to store alarm condition
bool buzzerState = false;           // variable to store buzzer state
int count;                          // variable to store count of buzzer


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(buzzer, OUTPUT);
  pinMode(input, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(input) == LOW) {
    alarm = !alarm;
  }
  Serial.println(alarm);
  buzzerTest();
  delay(300);
}

void buzzerTest() {
  currentTime = millis();
  if (((currentTime - prevTimeBuzzer) > 750) && (count <= 15)) {
    if (count == 15) {
      alarm = false;
      count = 0;
      digitalWrite(buzzer, LOW);
    }

    if (alarm == true) {
      buzzerState = !buzzerState;
      if (buzzerState) {
        digitalWrite(buzzer, HIGH);
      } else {
        digitalWrite(buzzer, LOW);
      }
      count++;
    }
    prevTimeBuzzer = millis();
  }
}
