#include <LiquidCrystal.h>
#define RS 4 // Correct
#define RW 3 // Correct
#define E 2 // Correct
// Data pins
#define D0 8 // Correct
#define D1 7 // Correct
#define D2 6 // Correct
#define D3 9 // Correct
#define D4 5 // Correct
#define D5 10 // Correct
#define D6 11 // Correct
#define D7 12 // Correct

// DOCUMENTATION:
// https://arduinoliquidcrystal.readthedocs.io/en/latest/liquidcrystal.html

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(RS, RW, E, D0, D1, D2, D3, D4, D5, D6, D7);
int allpins[] = {RS, RW, E, D0, D1, D2, D3, D4, D5, D6, D7};
char *test[] = {"SISHACKTOBERFEST", "CAKE", "IS", "A", "LIE"};
char buf[2][8];
int counter = 0;


void setup() {
  for (int i = 0; i < 11; i++){
      pinMode(allpins[i], OUTPUT);
  }
  // set up the LCD's number of columns and rows:
  lcd.blink();
  lcd.begin(8, 2); // Sets number of letters, columns
}

void loop() {
  // set the cursor to column 0, line 0
  // (note: line 0 is the first row, since counting begins with 0):
  lcd.clear(); // Clears display and resets cursor to (0,0)
  //lcd.setCursor(0, 0);
  // Print shit
  clear(buf[0], 8);
  clear(buf[1], 8);
  strncpy(buf[0], test[counter], 8);
  lcd.print(buf[0]);
  if (strlen(test[counter]) > 8) {
      lcd.setCursor(0,1);
      int l = strlen(test[counter+8]);
      strncpy(buf[1], test[counter+8], l);
      lcd.print(buf[1]);
  }
  counter = (counter + 1) % 5;
  delay(100);
}

void clear(char *buf, int len) {
  for (int i = 0; i < len; i++) {
    buf[i] = 0;
  }
}
