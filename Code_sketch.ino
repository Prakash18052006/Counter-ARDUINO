#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int x = 0;
int input = A0;
int state = 0;

LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init(); // initialize the lcd

  // Print a message to the LCD.
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Turn counter");
  lcd.setCursor(0, 1);
  lcd.print(x);
  lcd.print("  =turn  ");
}
void loop()
{
  int counter = digitalRead(A0);
  if (state == 0)
  {
    switch (counter) {

      case 1 : state = 1; lcd.setCursor (0, 1); x = x + 1; lcd.print(x); break;
      case 0 : state = 0; break;

    }
  }

  if (counter == LOW) {
    state = 0;
  }
}
