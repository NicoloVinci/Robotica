#include <Servo.h>

// ===== SERVO =====
#define SERVO_PIN 9
Servo servoKit;
int posServo=0;

void setup() {
  Serial.begin(9600);
  Serial.println("setup...");
// Setup Servo
  servoKit.attach(SERVO_PIN);
  servoKit.write(0); // Posizione iniziale
  
}

void loop() {
  // Movimento servo per rilascio
    Serial.print("inizio...");
    Serial.println(posServo);
    giro();
  //  servoKit.write(180);  // Apre meccanismo
  //  delay(1500);
  //  servoKit.write(0);   // Chiude meccanismo
  //  delay(500);

    delay(5000);
}

void giro() {
  Serial.print("giro...");
  Serial.println(posServo);
  if (posServo == 0) {
    servoKit.write(180);  // Apre meccanismo
    delay(1500);
    posServo=180;
  } else 
  {
    servoKit.write(0);  // Apre meccanismo
    delay(500);
    posServo=0;
  }


}