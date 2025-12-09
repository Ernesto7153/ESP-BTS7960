#ifndef EncoderMotor_h
#define EncoderMotor_h

#include <Arduino.h>

class EncoderMotor {
  private:
    int pinA;
    int pinB;
    int pulsesPerRev;
    volatile long pulseCount;
    int direction;
    unsigned long lastTime;
    float rpm;

    static EncoderMotor* instance; // para ISR estática
    static void IRAM_ATTR isrHandler();

  public:
    EncoderMotor(int a, int b, int ppr);

    void begin();
    void update();

    float getRPM();
    int getDirection();
    long getCount();
};

#endif
