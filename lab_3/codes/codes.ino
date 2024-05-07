#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DFRobot_RGBLCD1602.h>

LiquidCrystal_I2C lcD(0x3F, 20, 4); 

DFRobot_RGBLCD1602 lcd(0x60 ,16,2);

void setup() {
  Wire.begin();

   Serial.begin(9600);
  while (!Serial); 
  Serial.println("\nI2C Scanner");

  lcd.init();
    lcd.print("Hello World!");

    lcD.init(); 
    lcD.print("Hello World!");
   delay(500);

   lcd.clear();
   lcD.clear();

  lcd.print("I love arduino");
  lcd.setCursor(0, 1);
  lcd.print(":)");
  }

void loop() {
int nDevices = 0;
  Serial.println("Scanning...");

  for (byte address = 1; address < 127; ++address) {
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println("  !");
      ++nDevices;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  } else {
    Serial.println("done\n");
  }
  lcD.setCursor(0, 3);
  lcD.print("Devices: ");
  lcD.print(nDevices);

  delay(500);
}
