#ifndef CASTORS_H
#define CASTORS_H

#include "HERMENEXExternal.h"
#include "patri.h"
#include "boost.h"
#include "tip.h"
#include "pid.h"
#include "ptc.h"
#include "pwm.h"

class CastorS {
public:
    void begin();
    void update();
    void encoder(int delta);

    TipConfig* getActiveTip();
};

extern CastorS castorS;

#endif
