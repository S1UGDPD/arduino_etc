# define mode               "Full"      // "Full" or "Half"
# define motorSpeed         1000
# define calibration_factor 1.9

# define IN1 8      // blue
# define IN2 9      // pink
# define IN3 10     // yellow
# define IN4 11     // orange

int step_per_degree ;

void step_degree(int degree, String step_direction = "CW");
void step_run(int _case);
void step_loop(String step_direction = "CW"); 

void setup()
{
  Serial.begin(115200);

  if (mode == "Full") step_per_degree = 6;        // step per rev = 2048, step per degree = 2048/360 = 6
  else if (mode == "Half") step_per_degree = 11;  // step per rev = 4096, step per degree = 4096/360 = 11

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

//  step_degree(360);
}

void loop()
{
  step_loop("CW");
}

void step_loop(String step_direction = "CW") {
  if (step_direction == "CW") {
    for (int i = 1; i <= 8; i++) {
      step_run(i);
    }
  }
  else if (step_direction == "CCW") {
    for (int i = 8; i >= 1; i--) {
      step_run(i);
    }
  }
}

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
