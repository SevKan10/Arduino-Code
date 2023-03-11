#include <DHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int DHTPIN = 2;
const int DHTTYPE = DHT11;
DHT dht(DHTPIN, DHTTYPE);


void setup() 
{
  Serial.begin(9600);
  lcd.init();   
  lcd.backlight();
  dht.begin();  
}
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) or  isnan(h)) 
  { 
    lcd.setCursor(0,0);
    lcd.print("no");
    lcd.setCursor(8,0);
    lcd.print("no");
  } 
  else {
    lcd.setCursor(0,0);
    lcd.print(round(t));
    Serial.print(t); Serial.println(" do C");
    lcd.print(" *C");
    lcd.setCursor(8,0);
    lcd.print(round(h));
    Serial.print(h); Serial.println(" %"); delay(500);
    lcd.print(" %");    
  }
}