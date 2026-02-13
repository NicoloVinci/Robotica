//Motore sinistro
const int IN1_L = 8;
const int IN2_L = 9;
const int PWM_L = 6;

//Motore destro
const int IN1_R = 10;
const int IN2_R = 11;
const int PWM_R = 7;

//Encoder?
/*
const int ENC_L_A = 2;
const int ENC_L_B = 4;
const int ENC_R_A = 3;
const int ENC_R_B = 5;
*/

const int MOTOR_PWM = 220;

void setup() {
    pinMode(IN1_L, OUTPUT);
    pinMode(IN2_L, OUTPUT);
    pinMode(PWM_L, OUTPUT);

    pinMode(IN1_R, OUTPUT);
    pinMode(IN2_R, OUTPUT);
    pinMode(PWM_R, OUTPUT);

    Serial.begin(115200);
    delay(1000);
    Serial.println("Test motori start");
}

void loop() {
    driveForwardRaw();
    delay(1000); // 1 s avanti

    stopMotors();
    delay(2000); // 2 s fermo
}

void driveForwardRaw() {
  // avanti per entrambi, correggi se uno va al contrario
  digitalWrite(IN1_L, HIGH);
  digitalWrite(IN2_L, LOW);
  analogWrite(PWM_L, MOTOR_PWM);

  digitalWrite(IN1_R, HIGH);
  digitalWrite(IN2_R, LOW);
  analogWrite(PWM_R, MOTOR_PWM);
}

void stopMotors() {
  analogWrite(PWM_L, 0);
  analogWrite(PWM_R, 0);
}