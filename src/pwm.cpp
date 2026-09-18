#include <Arduino.h>
#include "pwm.h"
#include "HERMENEXExternal.h"
#include "HERMENEXExternal.h"

void initPWM() {
    ledcAttach(hermenexConfig.pwmPin, hermenexConfig.pwmFreq, hermenexConfig.pwmRes);
    heaterOff();
}

void heaterOff() {
    ledcWrite(hermenexConfig.pwmPin, 0);
}

void heaterOn() {
    // SLEEP is a hard heater-off state for CastorS.
    if (sleeping) {
        ledcWrite(hermenexConfig.pwmPin, 0);
        return;
    }

    ledcWrite(hermenexConfig.pwmPin, pwmOut);
}

void setPWM(int pwm) {

    if (pwm < 0)
        pwm = 0;

    // Never allow PID/UI code to re-enable the heater during SLEEP.
    if (sleeping) {
        pwmOut = 0;
        ledcWrite(hermenexConfig.pwmPin, 0);
        return;
    }

    pwmOut = pwm;
    ledcWrite(hermenexConfig.pwmPin, pwmOut);
}

void startTempRead() {
    heaterOff();
    delayMicroseconds(200);
}

void endTempRead() {
    heaterOn();
}