#include "smallslot.h"

smallSlot::smallSlot( int prix,string prdname, int slotid, int moteur1id, int moteur2id)
    : Slot(slotid, prdname, prix, moteur1id, moteur2id), motor1(moteur1id) {
}

void smallSlot::drop(){
    motor1.trigger();
    cout <<"\n"<<getProductName() << " delivered from the location " << getId();
}
