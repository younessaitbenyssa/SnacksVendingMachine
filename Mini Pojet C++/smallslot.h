#include "Slot.h"
#ifndef SMALLSLOT
#define SMALLSLOT
class smallSlot : public Slot
{
    moteur motor1;
public:
    smallSlot(int ,string, int, int, int);
    void drop();
};
#endif // SMALLSLOT
