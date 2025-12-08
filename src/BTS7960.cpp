#include "BTS7960.h"

BTS7960::BTS7960(uint8_t rpwm, uint8_t lpwm, uint8_t en) {
  _rpwm = rpwm;
  _lpwm = lpwm;
  _en   = en;
}

void BTS7960::begin() {
  pinMode(_rpwm, OUTPUT);
  pinMode(_lpwm, OUTPUT);
  pinMode(_en, OUTPUT);
}
void BTS7960::mover(uint8_t dir, uint8_t speed, unsigned long ms) { //parametros
  
 digitalWrite(_en, HIGH); // habilitar driver

 
  if (dir == HORARIO) {
    analogWrite(_rpwm, speed);
    analogWrite(_lpwm, 0);
    
  } else if (dir == ANTIHORARIO) {
    analogWrite(_rpwm, 0);
    analogWrite(_lpwm, speed);
  } 

   delay(ms);// Esta relacionado con (unsigned long ms) en la linea 14 en el método mover
   
   
}

void BTS7960::stop() { //Detiene el motor
  analogWrite(_rpwm, 0);
  analogWrite(_lpwm, 0);
  digitalWrite(_en, 0); // 0 ó LOW para deshabilitar
}
