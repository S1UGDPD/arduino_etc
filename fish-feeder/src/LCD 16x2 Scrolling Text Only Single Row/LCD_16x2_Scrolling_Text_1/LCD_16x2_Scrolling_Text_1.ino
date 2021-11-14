//----------------------------------
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);           // select the pins used on the LCD panel
//----------------------------------
int Li          = 16;
int Lii         = 0; 
int Ri          = -1;
int Rii         = -1;
//----------------------------------
void setup(){
  lcd.begin(16, 2);                           // start the LCD library
}
//---------------------------------- 

void loop(){
  lcd.setCursor(0,0);             
  lcd.print("    Uteh Str    ");  
  lcd.setCursor(0, 1);
  lcd.print(Scroll_LCD_Right("Arduino LCD 16x2 Scrolling Text Only single row"));
  delay(350);
}

//----------------------------------
String Scroll_LCD_Left(String StrDisplay){
  String result;
  String StrProcess = "                " + StrDisplay + "                ";
  result = StrProcess.substring(Li,Lii);
  Li++;
  Lii++;
  if (Li>StrProcess.length()){
    Li=16;
    Lii=0;
  }
  return result;
}

void Clear_Scroll_LCD_Left(){
  Li=16;
  Lii=0;
}
//----------------------------------
String Scroll_LCD_Right(String StrDisplay){
  String result;
  String StrProcess = "                " + StrDisplay + "                ";
  if (Rii<1){
    Ri  = StrProcess.length();
    Rii = Ri-16;
  }
  result = StrProcess.substring(Rii,Ri);
  Ri--;
  Rii--;
  return result;
}

void Clear_Scroll_LCD_Right(){
  Ri=-1;
  Rii=-1;
}
