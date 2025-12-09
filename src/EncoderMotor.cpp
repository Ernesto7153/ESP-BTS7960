#include "EncoderMotor.h"

EncoderMotor* EncoderMotor::instance = nullptr;

void IRAM_ATTR EncoderMotor::isrHandler() {
  int stateA = digitalRead(instance->pinA);
  int stateB = digitalRead(instance->pinB);

  if (stateA == stateB) {
    instance->direction = -1; // antihorario
    instance->pulseCount--;
  } else {
    instance->direction = 1;  // horario
    instance->pulseCount++;
  }
}

EncoderMotor::EncoderMotor(int a, int b, int ppr) {
  pinA = a;
  pinB = b;
  pulsesPerRev = ppr;
  pulseCount = 0;
  direction = 0;
  lastTime = 0;
  rpm = 0;
  instance = this;
}

void EncoderMotor::begin() {
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinA), isrHandler, RISING);
}

void EncoderMotor::update() {
  unsigned long now = millis();
  if (now - lastTime >= 1000) { // cada segundo
    noInterrupts();
    long count = pulseCount;
    pulseCount = 0;
    interrupts();

    rpm = (abs(count) * 60.0) / pulsesPerRev;
    lastTime = now;
  }
}

float EncoderMotor::getRPM() {
  return rpm;
}

int EncoderMotor::getDirection() {
  return direction;
}

long EncoderMotor::getCount() {
  return pulseCount*2;                  //return pulseCount*2;
}
