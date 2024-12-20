// Incluímos la libreria externa para poder utilizarla
#include <LiquidCrystal.h> // Entre los símbolos <> buscará en la carpeta de librerías configurada


// Lo primero is inicializar la librería indicando los pins de la interfaz
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Definimos las constantes
#define COLS 16 // Columnas del LCD
#define ROWS 2 // Filas del LCD
#define VELOCIDAD 300 // Velocidad para mover el texto
#define ARRAYTXT 5 // Número de textos a escribir

//Variables globales
float tempC; // Variable para almacenar el valor obtenido del sensor (0 a 1023)
int pinLM35 = 0; // Variable del pin de entrada del sensor (A0)
int indice; //Posicion del array de textos

void setup() {
  // Configuramos las filas y las columnas del LCD en este caso 16 columnas y 2 filas (Depende del hardware de cada uno)
  lcd.begin(COLS, ROWS);
  Serial.begin(9600);
}

void loop() {
  
  String textos[ARRAYTXT] = {"Mucho Calor", "Calor", "Confort", "Frio", "Mucho Frio"};
   
  //Obtenemos datos del sensor
  // Con analogRead leemos el sensor, recuerda que es un valor de 0 a 1023
  tempC = analogRead(pinLM35);
  
  // Calculamos la temperatura con la fórmula
  tempC = (5.0 * tempC * 100.0)/1024.0; 

  //Mostramos texto en LCD
  // Lo primero es borrar toda la pantallas
  lcd.clear();

  // Escribimos un mensaje en el LCD, por defecto empieza en la fila 0 y columna 0
  lcd.print("Temp. "+String(tempC)+"C");

  //Instrucciones para determinar el rango de temperatura
  if (tempC > 30){
     indice = 0;
  }else{
    if (tempC > 24){
        indice = 1;
      }else{
        if (tempC > 18){
            indice = 2;
          } else{
            if (tempC > 10){
                indice = 3;
              } else{
                  indice = 4;
                }
            }
        }
    }

  //Escribimos en la fila de abajo
  lcd.setCursor(0,1);
      
  // Escribimos mensaje
  lcd.print(textos[indice]);
    
  // Esperamos un tiempo para repetir el loop
  delay(1000);
}
