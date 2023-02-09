/*
 * Kode demo untuk stepper, mengatur kecepatan rotasi (delay) berdasar nilai analogRead
 */

//# define IN1 8    // blue
//# define IN2 9    // pink
//# define IN3 10   // yellow
//# define IN4 11   // orange

# define IN1 23    // blue
# define IN2 25    // pink
# define IN3 27   // yellow
# define IN4 29   // orange

int rawSpeed, mSpeed;

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  rawSpeed = analogRead(A0);
  mSpeed = map(rawSpeed, 0, 1023, 650, 5000);

  Serial.print(rawSpeed); Serial.print("\t"); Serial.println(mSpeed);
  
  rotCW();
}

void rotCCW () {
  // 1
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delayMicroseconds(mSpeed);
  // 2
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delayMicroseconds (mSpeed);
  // 3
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delayMicroseconds(mSpeed);
  // 4
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delayMicroseconds(mSpeed);
  // 5
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delayMicroseconds(mSpeed);
  // 6
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delayMicroseconds (mSpeed);
  // 7
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delayMicroseconds(mSpeed);
  // 8
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delayMicroseconds(mSpeed);
}

void rotCW() {
  // 1
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, LOW);
  delayMicroseconds(mSpeed);
  // 2
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, LOW);
  delayMicroseconds (mSpeed);
  // 3
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, LOW);
  delayMicroseconds(mSpeed);
  // 4
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
  delayMicroseconds(mSpeed);
  // 5
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
  delayMicroseconds(mSpeed);
  // 6
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, HIGH);
  delayMicroseconds (mSpeed);
  // 7
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
  delayMicroseconds(mSpeed);
  // 8
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
  delayMicroseconds(mSpeed);
}
