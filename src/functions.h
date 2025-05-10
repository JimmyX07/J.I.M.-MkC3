#include <customization.h>
#include <ESP32Servo.h>
#include <OneButton.h>

Servo servo1;
Servo servo2;

const int dt = 1500;
bool stato = false;          // Toggle del movimento
bool overrideLED = false;    // Override dei LED tramite doppio click

void animazioneLED();
void handleClick();
void handleDoubleClick();
void eyesOn();
void eyesOff();
OneButton button(BUTTON_PIN, true, true);

void startUp() {
  Serial.begin(115200);
  delay(2000);
  pinMode(RIGHT_EYE, OUTPUT);
  pinMode(LEFT_EYE, OUTPUT);
  servo1.attach(SERVO1_PIN, PWM_LOW, PWM_HIGH);
  servo2.attach(SERVO2_PIN, PWM_LOW, PWM_HIGH);
  servo1.write(90);
  servo2.write(90);
  delay(200);
  servo1.write(SERVO1_CLOSE_POS);
  servo2.write(SERVO2_CLOSE_POS);
  delay(1000);
  servo1.detach();
  servo2.detach();
  #ifdef EYES_EFFECT
  animazioneLED();
  #endif
  #ifndef EYES_EFFECT
  eyesOn();
  #endif

  button.attachClick(handleClick);
  button.attachDoubleClick(handleDoubleClick);

  Serial.println("Sistema pronto.");
}

void handleClick() {
  stato = !stato;

  if (stato) {
    eyesOff();
    servo1.attach(SERVO1_PIN, PWM_LOW, PWM_HIGH);
    servo2.attach(SERVO2_PIN, PWM_LOW, PWM_HIGH);
    servo1.write(SERVO1_OPEN_POS);
    servo2.write(SERVO2_OPEN_POS);
    delay(dt);
    servo1.detach();
    servo2.detach();
  } else {
    overrideLED = false;
    servo1.attach(SERVO1_PIN, PWM_LOW, PWM_HIGH);
    servo2.attach(SERVO2_PIN, PWM_LOW, PWM_HIGH);
    servo1.write(SERVO1_CLOSE_POS);
    servo2.write(SERVO2_CLOSE_POS);
    delay(750);
    eyesOn();
    delay(750);
    servo1.detach();
    servo2.detach();
  }
}

void handleDoubleClick() {
  if (stato) {
    Serial.println("Doppio click ignorato: occhi chiusi.");
    return;
  }

  overrideLED = !overrideLED;

  if (overrideLED) {
    digitalWrite(RIGHT_EYE, LOW);
    digitalWrite(LEFT_EYE, LOW);
    Serial.println("Override LED: OFF");
  } else {
    digitalWrite(RIGHT_EYE, HIGH);
    digitalWrite(LEFT_EYE, HIGH);
    Serial.println("Override LED: ON");
  }
}

void animazioneLED() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(RIGHT_EYE, HIGH);
    digitalWrite(LEFT_EYE, HIGH);
    delay(80);
    digitalWrite(RIGHT_EYE, LOW);
    digitalWrite(LEFT_EYE, LOW);
    delay(80);
  }
  delay(300);
  digitalWrite(RIGHT_EYE, HIGH);
  digitalWrite(LEFT_EYE, HIGH);
}

void eyesOn() {
  digitalWrite(RIGHT_EYE, HIGH);
  digitalWrite(LEFT_EYE, HIGH);
}
void eyesOff() {
  digitalWrite(RIGHT_EYE, LOW);
  digitalWrite(LEFT_EYE, LOW);
}