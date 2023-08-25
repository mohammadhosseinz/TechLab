/**
   Arduino Electronic keypad
   Copyright (C) 2023, TechLab.
*/

#include <LiquidCrystal.h>
#include <Keypad.h>


/* Display */
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

/* Keypad setup */
const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;
byte rowPins[KEYPAD_ROWS] = {5, 4, 3, 2};
byte colPins[KEYPAD_COLS] = {A3, A2, A1, A0};
char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS);

void showStartupMessage() {
  lcd.setCursor(4, 0);
  lcd.print("Welcome!");
  delay(1000);
  lcd.clear();

  lcd.setCursor(4, 0);
  String message = "Techlab";
  for (byte i = 0; i < message.length(); i++) {
    lcd.print(message[i]);
    delay(100);
  }
  delay(500);
}

String inputSecretCode() {
  lcd.setCursor(3, 1);
  lcd.print("[_______]");
  lcd.setCursor(4, 1);
  String result = "";
  while (result.length() <= 7) {
    char key = keypad.getKey();
    
    if (key >= '0' && key <= '9') {
      lcd.print(key);
      result += key;
    }
  }
  return result;
}


void setup() {
  lcd.begin(16, 2);
  showStartupMessage();
}

void loop() {
 inputSecretCode();
}
