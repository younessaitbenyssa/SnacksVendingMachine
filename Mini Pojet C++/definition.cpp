#include "classes.h"
Automat::Automat(int _numSlots, int _numProductsPerSlot) : numSlot(_numSlots), numProductsPerSlot(_numProductsPerSlot), cached(nullptr){
    slots.reserve(numSlot);
}
bool Automat::addSlot(int prix,string name,int slotid,int mt1 ,int mt2){
    Slot *s = new wideslot(prix,name,slotid,mt1,mt2);
    slots.push_back(s);
}
bool Automat::addSlot(int prix, string name, int slotid, int mt){
    Slot *s1 = new smallSlot (prix,name,slotid,mt,0);
    slots.push_back(s1);
}
void Automat::fillAll(){
    for (auto slot : slots){
        if (slot){
            slot->setNumProducts(numProductsPerSlot);
        }
    }
}
void Automat::fill(int slotid, int nump){
    Slot *slot = searchSlot (slotid);
    if (slot){
        slot->setNumProducts(nump);
    }
}
Automat::~Automat (){};
Slot* Automat::searchSlot(int sltid){
     if (cached != nullptr){
        if (sltid == cached->getId()){
            return cached;
        }
     }
    for (Slot *sl : slots){
        if (sl->getId() == sltid){
            cached = sl;
            return cached;
        }
    }
    return nullptr;
}
void Automat::changeSlot(int  slotid, string name, int price){
   Slot* slot = searchSlot(slotid);
   if (slot != nullptr) {
            slot->setProductName(name);
            slot->setprice(price);
        }
}
bool Automat::isAvailable (int slotid){
   Slot *slot = searchSlot(slotid);
   if (slot!=nullptr){
    if (slot->getNumProducts() > 0)
        return true;
   }
   return false;
}
int Automat::getPrice (int slotid){
   Slot *slot = searchSlot(slotid);
  if (slot != nullptr)
    return slot->getPrice();
}
bool Automat::dropSlot (int slotid){
    dropcheck drp = getdropcheck();
    Slot *sn = searchSlot(slotid);
    sn->drop();
    while(!drp.productReleased()){
    sn->drop();
    }
    int nmprd;
    nmprd = sn->getNumProducts();
    sn->setNumProducts(nmprd-1);
    return true;
}

int Automat::getNumPieces(int slotid){
    Slot *slot = searchSlot(slotid);
    if (slot != nullptr)
        return slot->getNumProducts();
}
keypad Automat::getkeypad(){
   return Keypad;
}
coinslot Automat::getcoinslot(){
    return Coinslot;
}
dropcheck Automat::getdropcheck(){
    return Dropcheck;
}
void affiche(const Automat& automat) {
    const int numRows = 5;
    const int numCols = 3;
    int count = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (count < automat.slots.size()) {
                cout << "|" << setw(13) << automat.slots[count]->getId() << " - " << setw(10) << automat.slots[count]->getProductName() << setw(13);
                count++;
            }
        }
        cout <<"|" << endl;
    }
    cout << "|" << setw(39) << "|" <<setw(39) << "|" << setw(39) << "|" <<endl;
}

