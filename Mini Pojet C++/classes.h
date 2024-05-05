#include "Slot.h"
#include"coinslot.h"
#include "keypad.h"
#include "dropcheck.h"
#include "wideslot.h"
#include "smallslot.h"
class Automat
{
    vector<Slot*> slots;
    int numSlot;
    int numProductsPerSlot;
    Slot* cached;
    coinslot Coinslot;
    keypad Keypad;
    dropcheck Dropcheck;
public:
    Automat(int,int);
    ~Automat();
    bool addSlot (int,string,int,int,int);
    bool addSlot (int,string,int,int);
    bool addSlot(Slot&);
    Slot* searchSlot(int);
    void changeSlot(int , string , int);
    int getPrice (int);
    int getNumPieces(int);
    bool isAvailable (int);
    bool dropSlot (int);
    void fillAll();
    void fill(int, int);
    friend void affiche(const Automat& automat);
    keypad getkeypad();
    coinslot getcoinslot();
    dropcheck getdropcheck();
};


