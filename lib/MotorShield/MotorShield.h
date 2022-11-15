#include <arduino.h>


class MotorShield {

    private:
        uint8_t _pinDIR;
        uint8_t _pinCMD;
        uint8_t _pinBRAKE;

    public:
        void init(uint8_t pinDIR, uint8_t pinBRAKE, uint8_t pinCMD);
        void speed(int16_t speed);
        void stop();
};
         