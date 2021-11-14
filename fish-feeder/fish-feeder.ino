#define delay_time 5

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DS3231.h>
#include <Servo.h>

DS3231 rtc(SDA, SCL);
Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

Time t;
int Li = 16;
int Lii = 0;
int Ri = -1;
int Rii = -1;

// ------------------------------------------------------------------- //

void setup() {
  Serial.begin(115200);

  rtc.begin();
  lcd.begin();
  servo.attach(3);
  servo.write(0);

  //  rtc.setDOW(SATURDAY);     // Set Day-of-Week to SUNDAY
  //  rtc.setTime(15, 52, 0);     // Set the time to 12:00:00 (24hr format)
  //  rtc.setDate(13, 11, 2021);   // Set the date to January 1st, 2014

  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Auto Feeding");
  lcd.setCursor(0, 1);
  lcd.print("Machine");
  delay(2000);
  lcd.clear();
}


void loop() {
  _timeDisplay();

  lcd.setCursor(0, 1);
  lcd.print(Scroll_LCD_Right("Automatic Feeding Machine"));

  if (t.sec >= 0 && t.sec <= 1) {
    _feed();
  }

  delay (1000);
}


// ------------------------------------------------------------------- //

void _feed() {
  lcd.clear();

  lcd.setCursor(1, 0);
  lcd.print("S E L A M A T");
  lcd.setCursor(3, 1);
  lcd.print("M A K A N");

  for (int i = 0; i <= 90; i++) {
    servo.write(i);
    delay(delay_time);
  }
  for (int j = 90; j >= 0; j--) {
    servo.write(j);
    delay(delay_time);
  }
  lcd.clear();
}


void _timeDisplay() {
  t = rtc.getTime();

  if (t.hour < 10) {
    lcd.setCursor(0, 0);
    lcd.print("0");
    lcd.setCursor(1, 0);
    lcd.print(t.hour, DEC);
  } else {
    lcd.setCursor(0, 0);
    lcd.print(t.hour, DEC);
  }

  lcd.setCursor(2, 0);
  lcd.print(":");

  if (t.min < 10) {
    lcd.setCursor(3, 0);
    lcd.print("0");
    lcd.setCursor(4, 0);
    lcd.print(t.min, DEC);
  } else {
    lcd.setCursor(3, 0);
    lcd.print(t.min, DEC);
  }

  lcd.setCursor(5, 0);
  lcd.print(":");

  if (t.sec < 10) {
    lcd.setCursor(6, 0);
    lcd.print("0");
    lcd.setCursor(7, 0);
    lcd.print(t.sec, DEC);
  } else {
    lcd.setCursor(6, 0);
    lcd.print(t.sec, DEC);
  }

  lcd.setCursor(8, 0); lcd.println("  ");

  lcd.setCursor(10, 0); lcd.print(rtc.getTemp());
  lcd.setCursor(14, 0); lcd.print((char)223);
  lcd.setCursor(15, 0); lcd.print("C");
}


String Scroll_LCD_Left(String StrDisplay) {
  String result;
  String StrProcess = "                " + StrDisplay + "                ";
  result = StrProcess.substring(Li, Lii);
  Li++;
  Lii++;
  if (Li > StrProcess.length()) {
    Li = 16;
    Lii = 0;
  }
  return result;
}


String Scroll_LCD_Right(String StrDisplay) {
  String result;
  String StrProcess = "                " + StrDisplay + "                ";
  if (Rii < 1) {
    Ri  = StrProcess.length();
    Rii = Ri - 16;
  }
  result = StrProcess.substring(Rii, Ri);
  Ri--;
  Rii--;
  return result;
}


void Clear_Scroll_LCD_Left() {
  Li = 16;
  Lii = 0;
}


void Clear_Scroll_LCD_Right() {
  Ri = -1;
  Rii = -1;
}
