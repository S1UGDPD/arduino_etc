#define IN1             8    // blue
#define IN2             9    // pink
#define IN3             10   // yellow
#define IN4             11   // orange

int step_case = 0;
int mSpeed = 1;

// case 0 variables:
int err;
int potVal;
int prevPotVal;
int stepDeg;
uint8_t potPin = A0;

// debounce variables:
int btnPin[2] = {2, 3};     // 2 = main button; 3 = reverse button
bool state[2] = {0, 0};
bool buttonState[2];
bool lastButtonState[2] = {1, 1};
unsigned long lastDebounceTime[2] = {0, 0};
unsigned long debounceDelay[2] = {50, 50};

void setup()
{
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(btnPin[0], INPUT_PULLUP);
  pinMode(btnPin[1], INPUT_PULLUP);
}

void loop()
{
  btnRead(0);
  if (buttonState[0] == 1) step_case++;

  switch (step_case) {
    case 0:
      potVal = map(analogRead(potPin), 0, 1023, 0, 360);
      err = abs(prevPotVal - potVal);
      if (err <= 180) rotCW();
      else if (err > 180) rotCCW();

      case_check();

    case 1:
      mode_2();
      case_check();

    case 2:

      case_check();

    default:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
  }
}


void case_check()
{
  btnRead(0);
  if (buttonState[0] == 1) step_case++;
}

void btnRead(int index)
{
  int reading = digitalRead(btnPin[index]);

  if (reading != lastButtonState[index]) {
    lastDebounceTime[index] = millis();
  }
  if ((millis() - lastDebounceTime[index]) > debounceDelay[index]) {
    if (reading != buttonState[index]) {
      buttonState[index] = reading;
      if (buttonState[index] == 0) {
        state[index] = !state[index];
      }
    }
  }
  lastButtonState[index] = reading;
}

void mode_2()
{
  btnRead(1);
  if (state == 0) rotCW();
  else rotCCW();
}

void rotCCW()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(mSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay (mSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(mSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(mSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(mSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay (mSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(mSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(mSpeed);
}

void rotCW()
{
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, LOW);
  delay(mSpeed);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, LOW);
  delay (mSpeed);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, LOW);
  delay(mSpeed);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
  delay(mSpeed);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
  delay(mSpeed);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, HIGH);
  delay (mSpeed);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
  delay(mSpeed);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
  delay(mSpeed);
}
