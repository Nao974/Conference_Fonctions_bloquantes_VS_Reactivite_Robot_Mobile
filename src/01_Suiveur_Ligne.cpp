#include <arduino.h>
#include <MotorShield.h>

// Carte Moteurs
MotorShield motorLeft, motorRight;
const uint8_t SPEED = 150;

// Suiveurs Ligne
const uint8_t PIN_LINE_LEFT = 5;
const uint8_t PIN_LINE_RIGHT = 4;



void setup() {
// Setup moteurs
	motorLeft.init(12, 9, 3);
	motorRight.init(13, 8, 11);

// Setup Suiveurs Ligne
	pinMode(PIN_LINE_LEFT, INPUT);
	pinMode(PIN_LINE_RIGHT, INPUT);
}


void loop() {
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