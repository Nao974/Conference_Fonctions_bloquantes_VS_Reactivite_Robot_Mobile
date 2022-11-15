#include <Arduino.h>
#include<HC_SR04.h>

const uint8_t TRIG = 7;
const uint8_t ECHO = 2; // Interruption PCINT0
const float US2CM = .017300; // 24°C

uint32_t duration;
float    distance;

sr04  distanceSensor(TRIG,ECHO);

void setup() {

    Serial.begin(9600);   

}

void loop() {

    if (finished) {
    // calcule de la durée de ECHO à l'état haut
        duration  = end_us - start_us;

    // Conversion    
        distance = US2CM * duration;

    // Affichage
        Serial.print("duration: "); Serial.print(duration); Serial.print(" µs, ");
        Serial.print("distance: "); Serial.print(distance); Serial.println(" cm");

    // Déclenchement d'une nouvelle mesure
        distanceSensor.start();
        finished= false;
    }

}