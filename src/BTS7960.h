#ifndef BTS7960_H
#define BTS7960_H

#include <Arduino.h>

// Definiciones de dirección
#define HORARIO     0
#define ANTIHORARIO 1
#define STOP       2  

class BTS7960 {
  public:
    BTS7960(uint8_t rpwm, uint8_t lpwm, uint8_t en);

    void begin();   // Inicializa pines
    void mover(uint8_t dir, uint8_t speed, unsigned long ms); // Movimiento por tiempo
    void stop();    // Detener motor

  private:
    uint8_t _rpwm;
    uint8_t _lpwm;
    uint8_t _en;
};

#endif

