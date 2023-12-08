#include <LiquidCrystal.h>
#include <string.h>

const int rs{12}, e{11}, d4{5}, d5{4}, d6{3}, d7{2};
LiquidCrystal lcd{rs, e, d4, d5, d6, d7};
const int numCols{16}, numRows{2};

String msg = "Hello Arduino Uno!";
size_t msg_size{msg.length()+1};
size_t cms{1}; //current_massage_size
size_t overflow{msg_size-16};
size_t o16{0};
char row1[numCols], row2[numCols];

void setup() {
  lcd.begin(numCols, numRows);
}

void loop() {
  lcd.setCursor(16,0);
  while (true) {
    if (cms < numCols && o16 < overflow) {
      for (int i = 0; i < cms; i++) {
    	row1[16-cms+i] = msg[i];
      }
      cms++;
    } else if (cms == numCols && o16 < overflow) {
      for (int i = 0; i < numCols; i++) {
        row1[i] = msg[o16 + i];
      }
      o16++;
    } else break;
      
    pCharArray(row1, lcd);
  }
  delay(1000);
  lcd.clear();
}

void pCharArray(char* txt, LiquidCrystal& display) {
  for (int i = 0; i < 16; i++) {
    display.print(txt[i]);
  }
}