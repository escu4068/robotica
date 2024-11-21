#include «Wire.h»
#include «LiquidCrystal_I2C.h»

#define sensor A0
LiquidCrystal_I2C lcd(0x27, 16, 2); 
int valor = 0;



void setup()
{
    lcd.init();
    lcd.backlight();
}


void loop()
{
    int valor = map(analogRead(sensor), 0, 1023, 100, 0);
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Humedad: ");
    lcd.setCursor(5,1);
    lcd.print(valor);
    lcd.setCursor(8,1);
    lcd.print("%");
    lcd.print(" ");
    delay(200);
}
