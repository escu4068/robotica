#include <Servo.h> 
 
Servo myservo;  //creamos un objeto servo 
 
void setup() { 
  myservo.attach(3);  // asignamos el pin 3 al servo.
   Serial.begin(9600);
} 
 
void loop() { 
  int adc = analogRead(A0);  // realizamos la lectura del potenciometro
  int angulo = map(adc, 0, 1023, 0, 180);  // escalamos la lectura a un valor entre 0 y 180
  myservo.write(angulo);  // enviamos el valor escalado al servo
  Serial.print("ángulo:  ");
  Serial.println(angulo);
  delay(10);            
}
