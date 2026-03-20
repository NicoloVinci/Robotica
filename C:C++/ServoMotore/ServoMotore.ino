#include <Servo.h>

// ===== SERVO =====
#define SERVO_PIN 9
Servo servoKit;
int posServo = 0;

void servoCommand(int sum) {
  if (sum == 1) {
    if (posServo == 0) {
      servoKit.write(180);
      posServo = 180;
    } else {
      servoKit.write(0);
      posServo = 0;
    }
  } else if (sum == 2) {
    if (posServo == 0) {
      servoKit.write(180);
      delay(1000);
      servoKit.write(0);
      posServo = 0;
    } else {
      servoKit.write(0);
      delay(1000);
      servoKit.write(180);
      posServo = 180;
    }
  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial) { }
  servoKit.attach(SERVO_PIN);
  servoKit.write(0);
  Serial.println("Inserisci numero (1 o altro) e premi Invio:");
}

void loop() {
  if (Serial.available() > 0) {
    int n = Serial.parseInt();
    while (Serial.available() > 0) {
      Serial.read();
    }
    Serial.print("Comando ricevuto: ");
    Serial.println(n);
    servoCommand(n);
    Serial.println("Inserisci un altro numero e premi Invio:");
  }
}