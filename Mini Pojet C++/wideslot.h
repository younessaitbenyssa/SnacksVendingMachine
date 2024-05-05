#include "Slot.h"
#ifndef WIDESLOT
#define WIDESLOT
class wideslot : public Slot
{
    moteur motor1;
    moteur motor2;
public:
    wideslot(int, string, int, int, int);
    void drop();
};
#endif // WIDESLOT
