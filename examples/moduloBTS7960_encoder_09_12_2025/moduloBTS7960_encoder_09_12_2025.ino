#include <EncoderMotor.h>
#include <BTS7960.h>
#define ENCODER_A 27
#define ENCODER_B 26
#define PWM_L 2
#define PWM_R 15
#define EN 4

const int gearRatio = 10;
const int pulsesPerRev = 7 * gearRatio;

EncoderMotor Encoder(ENCODER_A, ENCODER_B, pulsesPerRev);
BTS7960 motor(PWM_R, PWM_L, EN);
void setup() {
  Serial.begin(115200);
  motor.begin();

  motor.mover(1,255,4000);
  Encoder.begin();

  motor.mover(1,100,4000);
  Encoder.begin();

  motor.mover(1,0,4000);
  Encoder.begin();

  motor.mover(1,50,4000);
  Encoder.begin();

  motor.mover(0,155,4000);
  Encoder.begin();



/*
  // Configuración PWM con API moderna
  ledcAttach(PWM_L, 15000, 8); // pin, frecuencia, resolución
  ledcAttach(PWM_R, 15000, 8);
  pinMode(EN, OUTPUT);
  
  delay(3000);
 digitalWrite(EN, HIGH);
  ledcWrite(PWM_L, 35); //35 ES LA DEL VELOCIDAD DEL MOTOR, PWM_L ES Arrancar motor horario
  ledcWrite(PWM_R, 0);
  delay(786); //para menos vuelta del motor
  digitalWrite(EN, 0);
  delay(2000);

 digitalWrite(EN, HIGH);
  ledcWrite(PWM_L, 0); //VELOCIDAD DEL MOTOR
  ledcWrite(PWM_R, 35);
  delay(786);
  digitalWrite(EN, 0);
  delay(2000);

  digitalWrite(EN, HIGH);
  ledcWrite(PWM_L, 35); //VELOCIDAD DEL MOTOR
  ledcWrite(PWM_R, 0);
  delay(786);
  digitalWrite(EN, 0);
  delay(2000);

  digitalWrite(EN, HIGH);
  ledcWrite(PWM_L, 35); //VELOCIDAD DEL MOTOR
  ledcWrite(PWM_R, 0);
  delay(786);
  digitalWrite(EN, 0);
  delay(2000);

*/
}

void loop() {
  Encoder.update();

  Serial.print("Velocidad eje de salida: ");
  Serial.print(Encoder.getRPM());
  Serial.print(" RPM, Dirección: ");
  if (Encoder.getDirection() == 1) Serial.println("Horario (CW)");
  else if (Encoder.getDirection() == -1) Serial.println("Antihorario (CCW)");
  else Serial.println("Indefinido");

  Serial.print("Pulsos contados: ");
  Serial.println(Encoder.getCount());
  delay(500);
}
