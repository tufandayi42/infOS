#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "infLib.h"

void wait(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds * 1000));
}

#endif