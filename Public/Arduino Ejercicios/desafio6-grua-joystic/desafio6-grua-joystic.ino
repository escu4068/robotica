// Desafio # 6 Grua con Joystic

# include <servo.h>
//Definicion de los objetos servo

Servo miservo1;
Servo miservo2;

// Posicion inicial de los Servos

int eje_xPos = 90;
int eje_yPos = 90;


//declaracion de Entradas Analogicas del Joystic

int valor_Jx = A0;
int valor_Jy = A1;
int valor;
// int  = 2; //No utilizaremos el pulsador del Joystic


void setup() {

miservo1.attach(2);
miservo2.attach(4);
miservo1.write(90);
miservo2.write(90);

// pinMode(sw_valor, INPUT_PULLUP); //No utilizaremos el pulsador del Joystic

}

void loop() {
// Ciclo para el Servo1
  if (analogRead(A0)<200 && xPos<180){
    xPos++;
    servo1.write(xPos);
  }
  if (analogRead(A0)>700 && xPos>0){
    xPos--;
    servo1.write(xPos);
  }
  // Ciclo para el Servo2

  if (analogRead(A1)<200 && eje_yPos<180){
    eje_yPos++;
    servo2.write(eje_yPos);
  }
  if (analogRead(A1)>700 && eje_yPos>0){
    eje_yPos--;
    servo2.write(eje_yPos);
  }
  delay(15);
}

}
