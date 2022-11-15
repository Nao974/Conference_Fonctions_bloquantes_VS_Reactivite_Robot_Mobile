#include <MotorShield.h>

void MotorShield::init(uint8_t pinDIR, uint8_t pinBRAKE, uint8_t pinCMD) {
    pinMode(_pinDIR=pinDIR, OUTPUT);
    pinMode(_pinCMD=pinCMD, OUTPUT);
    pinMode(_pinBRAKE=pinBRAKE, OUTPUT);

    digitalWrite(_pinDIR, HIGH);
    stop();
}

void MotorShield::speed(int16_t value) {
    if ( value < 0) {
        digitalWrite(_pinDIR, LOW);
        value = - value;
    }
    else
        digitalWrite(_pinDIR, HIGH);

    digitalWrite(_pinBRAKE, LOW);
    analogWrite(_pinCMD, value);

}

void MotorShield::stop() {
    digitalWrite(_pinBRAKE, HIGH);
}
