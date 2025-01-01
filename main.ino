#include <DS3231.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT11.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  
DHT11 dht11(3);
DS3231 myRTC;

bool century = false;
bool h12Flag;
bool pmFlag;

void setup() {
  
  lcd.init();  
  lcd.backlight();                   
  
  
  lcd.setCursor(0, 0);
  lcd.print("Kirikkale");
  lcd.setCursor(0, 1);
  lcd.print("Universitesi");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Fizik");
  lcd.setCursor(0, 1);
  lcd.print("Laboratuvari");
  delay(1000);
  lcd.clear();
  
  
  Wire.begin();
  Serial.begin(57600);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Aktif");
  lcd.setCursor(0, 1);
  lcd.print("Sensor:");
  lcd.print("5");

  int temperature = 0;
  int humidity = 0;

  lcd.setCursor(12, 1);
  lcd.print(myRTC.getHour(h12Flag, pmFlag), DEC);
  lcd.print(':');
  lcd.print(myRTC.getMinute(), DEC);

  int result = dht11.readTemperatureHumidity(temperature, humidity);

  if (result == 0) {
    
    lcd.setCursor(9, 0);

    lcd.print(temperature);
    lcd.print("C");

    lcd.setCursor(12, 0);
    lcd.print("/");

    lcd.setCursor(13, 0);
    lcd.print(humidity);
    lcd.print("%");
  }

  delay(1000); 
}
