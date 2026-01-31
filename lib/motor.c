#include "motor.h"
#include <Arduino.h>

void initMotor() {
    pinMode(MOTOR_PIN, OUTPUT);
}

void turnMotorOn() {
    digitalWrite(MOTOR_PIN, HIGH);
}

void turnMotorOff() {
    ditialWrite(MOTOR_PIN, LOW);
}