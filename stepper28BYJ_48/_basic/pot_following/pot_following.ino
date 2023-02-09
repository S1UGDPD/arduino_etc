# define mode               "Full"      // "Full" or "Half"
# define motorSpeed         1000
# define calibration_factor 1.9

# define IN1 8      // blue
# define IN2 9      // pink
# define IN3 10     // yellow
# define IN4 11     // orange

void step_degree(int degree, String step_direction = "CW");
void step_run(int _case);

int step_per_degree;
int rawADC = 0;
struct mapADC {
  int val = 0;
  int val_1 = 0;
};
int err = 0;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = //

void setup()
{
  Serial.begin(115200);

  if (mode == "Full") step_per_degree = 6;        // step per rev = 2048, step per degree = 2048/360 = 6
  else if (mode == "Half") step_per_degree = 11;  // step per rev = 4096, step per degree = 4096/360 = 11

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop()
{
  rawADC = analogRead(A0);
  mapADC.val = map(rawADC, 0, 1024, 0, 360);

  if (mapADC.val != mapADC.val_1) {
    err = abs(mapADC.val - mapADC.val_1);
    
    step_degree(mapADC);
  }
  

  Serial.print(rawADC); Serial.print("\t"); Serial.println(mapADC);
  mapADC.val_1 = mapADC.val;
}


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = //

void step_degree(int degree, String step_direction = "CW") {
  int motor_step = step_per_degree * degree * calibration_factor;
  if (step_direction == "CW") {
    for (int i = 1; i <= motor_step; i++) {
      step_run(i);
    }
  }
  else if (step_direction == "CCW") {
    for (int i = motor_step; i >= 1; i--) {
      step_run(i);
    }
  }
}

void step_run(int _case) {
  if (_case > 8) {
    _case %= 8;
  }
  switch (_case) {
    case 1:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delayMicroseconds(motorSpeed);
      break;
    case 2:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delayMicroseconds(motorSpeed);
      break;
    case 3:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delayMicroseconds(motorSpeed);
      break;
    case 4:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delayMicroseconds(motorSpeed);
      break;
    case 5:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delayMicroseconds(motorSpeed);
      break;
    case 6:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      delayMicroseconds(motorSpeed);
      break;
    case 7:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delayMicroseconds(motorSpeed);
      break;
    case 8:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delayMicroseconds(motorSpeed);
      break;
    default:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
  }
}
