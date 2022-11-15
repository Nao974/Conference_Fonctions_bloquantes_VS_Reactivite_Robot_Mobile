#include <Arduino.h>

const uint8_t TRIG = 7;
const uint8_t ECHO = 2;
const float US2CM = .017300; // 24°C

uint32_t duration;
float    distance;

void setup() {

    Serial.begin(9600);

    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

}

void loop() {

// Déclenchement
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

// Lecture de la distance
    duration = pulseIn(ECHO, HIGH);

// Conversion    
    distance = US2CM * duration;

// Affichage
    Serial.print("duration: "); Serial.print(duration); Serial.print(" µs, ");
    Serial.print("distance: "); Serial.print(distance); Serial.println(" cm");

    delay(1000);

}