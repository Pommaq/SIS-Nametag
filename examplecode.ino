#include <LiquidCrystal.h>
#include <avr/power.h>
#include <avr/sleep.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(10, 2, 5, 10, 11, 12);
String test[] = {"Hello", "hEllo", "heLlo", "helLo", "hellO"};
int counter = 0;
void setup() {
  // set up the LCD's number of columns and rows:
  digitalWrite(4, LOW);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  clock_prescale_set(clock_div_8);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  
  lcd.print(test[counter]);
  counter = (counter + 1) % 5;
  delay(100);
}


