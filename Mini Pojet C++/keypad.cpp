#include "keypad.h"
int keypad::getselection(){
    int slect;
    cout << "enter product location (press -1 to cancel) : ";
    cin >> slect;
    return slect;
}
