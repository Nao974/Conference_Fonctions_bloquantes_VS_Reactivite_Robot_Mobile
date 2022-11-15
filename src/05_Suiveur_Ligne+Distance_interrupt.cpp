#include <arduino.h>

#include <MotorShield.h>
#include<HC_SR04.h>

// Carte Moteurs
MotorShield motorLeft, motorRight;
const uint8_t SPEED = 150;

// Suiveurs Ligne
const uint8_t PIN_LINE_LEFT = 5;
const uint8_t PIN_LINE_RIGHT = 4;

// Distance par UltraSon
const uint8_t TRIG = 7;
const uint8_t ECHO = 2; // Interruption PCINT0
const float US2CM = .017300; // 24°C

uint32_t duration;
float    distance;

sr04  distanceSensor(TRIG,ECHO);


void setup() {
// Setup moteurs
	motorLeft.init(12, 9, 3);
	motorRight.init(13, 8, 11);

// Setup Suiveurs Ligne
	pinMode(PIN_LINE_LEFT, INPUT);
	pinMode(PIN_LINE_RIGHT, INPUT);

	Serial.begin(9600);
}


void loop() {
// Lecture Distance par UltraSon
    if (finished) {
    // calcule de la durée de ECHO à l'état haut
        duration  = end_us - start_us;

    // Conversion    
        distance = US2CM * duration;

    // Déclenchement d'une nouvelle mesure
        distanceSensor.start();
        finished= false;
    }

	Serial.print("Distance= ");Serial.println(distance);
	if (distance > 20) {
	// Lecture Suiveurs Ligne
		uint8_t lineLeft = digitalRead(PIN_LINE_LEFT);
		uint8_t lineRight = digitalRead(PIN_LINE_RIGHT);

	// Action en fonction de la position du robot sur la ligne
		if (lineLeft && lineRight) {
			motorLeft.speed(SPEED);
			motorRight.speed(SPEED);
		}
		else if (lineLeft && !lineRight) {
			motorLeft.speed(50);
			motorRight.speed(SPEED);
		}
		else if ( !lineLeft && lineRight) {
			motorLeft.speed(SPEED);
			motorRight.speed(50);
		}
		else {
			motorLeft.speed(50);
			motorRight.speed(SPEED);
		}
	}

	// Si obstacle <20 cm alors Stop du robot
	else {
		motorLeft.stop();
		motorRight.stop();
	}
 
}