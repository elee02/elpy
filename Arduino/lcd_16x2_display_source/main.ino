#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  String text = "This is a long text that will scroll on the first row of the LCD.";
  for (int positionCounter = 0; positionCounter < text.length(); positionCounter++) {
    lcd.setCursor(0, 0); // Set cursor to the start of the first row
    for (int i = 0; i < 16; i++) {
      // Print 16 characters of the text string at a time
      lcd.print(text[positionCounter + i]);
    }
    delay(500); // Delay for readability
    lcd.clear(); // Clear the LCD
  }
  lcd.setCursor(0, 1); // Set cursor to the start of the second row
  lcd.print("This is the second row."); // Print a static message on the second row
}