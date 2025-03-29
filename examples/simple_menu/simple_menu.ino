#include <LiquidCrystal.h>

// Initialize the LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Button threshold values
#define BTN_RIGHT 0
#define BTN_UP 100
#define BTN_DOWN 250
#define BTN_LEFT 450
#define BTN_SELECT 650
#define BTN_NONE 1023

int menuIndex = 0;
int submenuIndex = 0;
bool inSubmenu = false;

const char* mainMenu[] = {"Start", "Settings", "About"};
const int mainMenuSize = sizeof(mainMenu) / sizeof(mainMenu[0]);

const char* settingsMenu[] = {"Volume", "Brightness", "Back"};
const int settingsMenuSize = sizeof(settingsMenu) / sizeof(settingsMenu[0]);

int readButton() {
    int adc_key_in = analogRead(0);
    if (adc_key_in < 50)   return BTN_RIGHT;
    if (adc_key_in < 150)  return BTN_UP;
    if (adc_key_in < 350)  return BTN_DOWN;
    if (adc_key_in < 550)  return BTN_LEFT;
    if (adc_key_in < 750)  return BTN_SELECT;
    return BTN_NONE;
}

void displayMenu() {
    lcd.clear();
    lcd.setCursor(0, 0);
    if (inSubmenu) {
        lcd.print(settingsMenu[submenuIndex]);
    } else {
        lcd.print(mainMenu[menuIndex]);
    }
    lcd.setCursor(0, 1);
    lcd.print("< Up  Sel  Dwn >");
}

void setup() {
    lcd.begin(16, 2);
    displayMenu();
}

void loop() {
    int button = readButton();
    if (button != BTN_NONE) {
        delay(200);
        switch (button) {
            case BTN_UP:
                if (inSubmenu) {
                    submenuIndex = (submenuIndex - 1 + settingsMenuSize) % settingsMenuSize;
                } else {
                    menuIndex = (menuIndex - 1 + mainMenuSize) % mainMenuSize;
                }
                break;
            case BTN_DOWN:
                if (inSubmenu) {
                    submenuIndex = (submenuIndex + 1) % settingsMenuSize;
                } else {
                    menuIndex = (menuIndex + 1) % mainMenuSize;
                }
                break;
            case BTN_SELECT:
                if (!inSubmenu && menuIndex == 1) { // "Settings" selected
                    inSubmenu = true;
                    submenuIndex = 0;
                } else if (inSubmenu && submenuIndex == settingsMenuSize - 1) { // "Back" selected
                    inSubmenu = false;
                }
                break;
        }
        displayMenu();
    }
}
