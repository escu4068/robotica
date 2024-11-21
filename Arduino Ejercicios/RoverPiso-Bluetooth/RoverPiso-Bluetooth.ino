#include <SoftwareSerial.h>
#include <Servo.h>

// CONEXIONES PARA EL BLUETOOTH.

int bluetoothTx = 2;
int bluetoothRx = 3;
int ledpin = 13;
int buzzerpin = 8;
int ledpinrojo = 4;
int ledpinverde = 9;
int buzzerdelay=100;
char dato;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

int mi1=6;
int mi2=7;

int md1=10;
int md2=11;


void setup ()
{
bluetooth.begin(9600);
pinMode(mi1,OUTPUT);
pinMode(mi2,OUTPUT);
pinMode(md1,OUTPUT);
pinMode(md2,OUTPUT);
pinMode(ledpin,OUTPUT);
pinMode(ledpinrojo,OUTPUT);
pinMode(ledpinverde,OUTPUT);
pinMode(buzzerpin,OUTPUT);
digitalWrite( mi1, LOW);
digitalWrite( mi2, LOW );
digitalWrite( md1, LOW );
digitalWrite( md2, LOW);
digitalWrite(ledpin,LOW);
digitalWrite(ledpinrojo,LOW);
digitalWrite(buzzerpin,LOW);
}

void loop()
{

dato = bluetooth.read();
delay(100);

if(dato == 'S')
{ 
digitalWrite(ledpinverde,LOW);
digitalWrite(ledpinrojo,LOW);
digitalWrite( mi1, LOW);
digitalWrite( mi2, LOW);
digitalWrite( md1, LOW),
digitalWrite( md2, LOW);

}

if( dato == 'F')
{
// ESTOS HARAN QUE VAYA PARA ADELANTE EL CARRITO.

digitalWrite(ledpinrojo,LOW);
digitalWrite(ledpinverde,HIGH);

digitalWrite(buzzerpin,LOW);

digitalWrite(mi1,HIGH);
digitalWrite(mi2,LOW);

digitalWrite(md1,HIGH);
digitalWrite(md2,LOW);

}
if(dato == 'B')
{

// ESTOS HARA RETROCEDER EL ROVER.


digitalWrite(buzzerpin,LOW);
digitalWrite(ledpin,LOW);
digitalWrite(ledpinverde,LOW);
digitalWrite(ledpinrojo,HIGH);
digitalWrite(mi1,LOW);
digitalWrite(mi2,HIGH);
digitalWrite(md1,LOW);
digitalWrite(md2,HIGH);
digitalWrite(buzzerpin,HIGH);
delay(100);
digitalWrite(buzzerpin,LOW);
}
if( dato == 'L')
{
// ESTOS HARAN QUE VAYA PARA DERECHA.

digitalWrite(buzzerpin,LOW);
digitalWrite(mi1,HIGH);
digitalWrite(mi2,LOW);
digitalWrite(md1,LOW);
digitalWrite(md2,LOW);

}

if( dato == 'R')
{
// ESTOS HARAN QUE VAYA PARA IQUIERDA.

digitalWrite(buzzerpin,LOW);
digitalWrite(mi1,LOW);
digitalWrite(mi2,LOW);
digitalWrite(md1,HIGH);
digitalWrite(md2,LOW);

}
if( dato == 'W')
{
// ESTOS HARAN QUE VAYA PARA IQUIERDA.

digitalWrite(ledpin,HIGH);

}
if( dato == 'w')
{
// ESTOS HARAN QUE VAYA PARA IQUIERDA.

digitalWrite(ledpin,LOW);

}


}
