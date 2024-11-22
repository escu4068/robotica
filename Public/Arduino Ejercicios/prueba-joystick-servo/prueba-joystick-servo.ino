// Como ejercicio puedes probar a conectar otro servo y controlarlo con el ángulo del eje y del joystick con Arduino
// Prueba Joystick con Arduino

// Incluyo Libreria Servo.h
#include <Servo.h>

// Después se declaran las constantes necesarias. 
//En este caso se emplean 4 constantes para definir los pines de las tres señales del joystick y el pin del servo.

#define PIN_VRx A0
#define PIN_VRy A1
#define PIN_SW 2
#define PIN_SERVO 6

// Se declara una variable tipo Servo para controlar el motor. 
// También se declaran variables para almacenar las lecturas analógicas del joystick y los ángulos correspondientes.

Servo motor;
int x, y;
int x_ang, y_ang;


// En la función setup() en primer lugar  se inicializa el puerto Serial a 9600 baudios para enviar información al monitor serie. 
// Luego se configura el pin del pulsador como entrada con resistencia de pullup. 
// Por último, se especifica el pin al que se ha conectado el servomotor y se pone en la posición de 0 grados.
// Es importante configurar el pin del pulsador como entrada con pullup porque el módulo no tiene resistencia de pullup.

void setup() {
  // inicializar monitor serie a 9600 baudios
  Serial.begin(9600);
  
  // configurar el pin del pulsador como entrada con pullup
  pinMode( PIN_SW, INPUT_PULLUP );

  // inicializar el servo para trabajar con el pin 6
  motor.attach(PIN_SERVO);

  // colocar el servo en la posición de 0 grados
  motor.write(0);
  
}

// En la función loop() inicialmente se obtiene los valores analógicos del joystick.

void loop() {
  // leer posición del joystick con Arduino
  x = analogRead(PIN_VRx);
  y = analogRead(PIN_VRy);

  // sirve para mapear los valores a grados
  x_ang = map( x, 0, 1023, 0, 180 );
  y_ang = map( y, 0, 1023, 0, 180 );

// Los valores de ángulos obtenidos y el estado del pulsador son enviados al monitor serie para verificar que todo esté funcionando correctamente.

  // Imprimir datos al monitor serie
  Serial.print( "X_ang:" );
  Serial.print(x_ang);
  Serial.print("  ");

  Serial.print( "Y_ang:" );
  Serial.print(y_ang);
  Serial.print( " SW:");
  Serial.print( digitalRead(PIN_SW) );
  Serial.println();

  // actualizar ángulo del motor
  motor.write( x_ang );

  // esperar 250 ms
  delay(250);
}
