#include <Servo.h>

const int trigg = 6;
const int echo = 7;

Servo pluma;

// LEDs
const int ledRojo = 8;
const int ledVerde = 9;

long duracion;
int distancia;

void setup() {
  pinMode(trigg, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  pluma.attach(3);   // Servo en pin 3
  pluma.write(0);    // Posición inicial (cerrado)

  digitalWrite(ledRojo, HIGH);  // Empieza cerrado → LED rojo encendido
  digitalWrite(ledVerde, LOW);

  Serial.begin(9600);
}

void loop() {
  // Pulso ultrasónico
  digitalWrite(trigg, LOW);
  delayMicroseconds(2);
  digitalWrite(trigg, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigg, LOW);

  duracion = pulseIn(echo, HIGH);
  distancia = duracion * 0.01715;

  Serial.print("Distancia : ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia <= 30) {
    // Abrir pluma
    pluma.write(90);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledRojo, LOW);

    delay(3000); // Espera 3 segundos con la pluma abierta

    // Cerrar pluma automáticamente
    pluma.write(0);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledRojo, HIGH);
  }
}

