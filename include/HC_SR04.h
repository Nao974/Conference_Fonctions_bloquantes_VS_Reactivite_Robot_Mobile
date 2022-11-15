#include <arduino.h>

// variables modified in the ISR therefore in volatile
volatile uint32_t end_us=0;
volatile uint32_t start_us=0;
volatile uint8_t finished=true;

// ISR for pin 2 state change detection
void HC04Isr() {
    if ( PIND & B00000100 ) // ECHO signal high on pin 2 (from port D) ?
        start_us=micros();  //    => start of acquisition
    else {
        end_us=micros();    // ELSE ECHO signal end
        finished=true;      //    => acquisition completed
    }   
}

// Structure for managing HC-SR04 sensors
struct sr04 {
    uint8_t pin_trigger;
    uint8_t pin_echo;

    // pin initialization and attach interrupt
    sr04(uint8_t trigger, uint8_t echo) {
        pinMode(pin_trigger=trigger, OUTPUT);
        pinMode(pin_echo=echo, INPUT);

        attachInterrupt(digitalPinToInterrupt(pin_echo), HC04Isr, CHANGE);
    }

    //Start of a measurement by going to the high state of the Trigger pin for 10µs
    void start() {
        digitalWrite(pin_trigger, LOW);
        delayMicroseconds(2);
        digitalWrite(pin_trigger, HIGH);
        delayMicroseconds(10);
        digitalWrite(pin_trigger, LOW);
    }
};

