#include "CastorS.h"

CastorS castorS;

void CastorS::begin() {
    initPWM();
    initPTC();
}

void CastorS::update() {
    updateBoost();
    updatePID();
}

void CastorS::encoder(int delta) {
    if (delta == 0) return;
    targetTemp += delta * 5;
    targetTemp = constrain(targetTemp, hermenexConfig.tempMin, maxTemp);
}

TipConfig* CastorS::getActiveTip() {
    return activeTip;
}
