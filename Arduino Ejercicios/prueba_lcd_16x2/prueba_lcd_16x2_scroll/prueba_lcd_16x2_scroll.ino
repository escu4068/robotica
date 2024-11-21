#include <LiquidCrystal.h>

//Crear el objeto LCD con los números correspondientes (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  // Inicializar el LCD con el número de  columnas y filas del LCD
  lcd.begin(16, 2);
  // Escribimos el Mensaje en el LCD en una posición  central.
  lcd.setCursor(10, 0);
  lcd.print("www.atilioanastasi.edu.ar");
  lcd.setCursor(5, 1);
  lcd.print("Anastasi, Virtual 4068  ");
}

void loop() {
  //desplazamos una posición a la izquierda
  lcd.scrollDisplayLeft(); 
  delay(250);
}
