#include "motor.h"

moteur::moteur (int iid){
    id = iid;
}
void moteur::trigger(){
    cout << "\nMotor " << id << " is activated";
}
