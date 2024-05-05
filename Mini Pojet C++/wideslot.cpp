#include "wideslot.h"

wideslot::wideslot(int prix,string prdname, int slotid, int moteur1id, int moteur2id)
    : Slot(slotid, prdname, prix, moteur1id, moteur2id), motor1(moteur1id), motor2(moteur2id) {
}
void wideslot::drop(){
    motor1.trigger();
    motor2.trigger();
    cout <<"\n"<<getProductName() << " delivered from the location " << getId();
}
