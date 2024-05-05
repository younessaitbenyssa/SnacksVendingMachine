#include <bits/stdc++.h>
using namespace std;
class coinslot
{
    int insertedamount;
    int coinAmount;
    vector<int> coinvaleus  = {200, 100, 50, 20, 10, 5, 1};
public:
    coinslot();
    int updatedcoinamount();
    int getcoinamount();
    void clear();
    void returncoins(int);
};
class keypad
{
public:
    int getselection();
};
class dropcheck
{
public:
    bool productReleased();
};

class moteur
{
    int id;
public:
    moteur (int);
    void trigger();
};
class Slot
{
    protected:
    string productName ;
    int id;
    int numProduits;
    int price;
    moteur moteur1;
    moteur moteur2;
public:
    Slot (int ,string, int , int ,int);
    ~Slot();
    virtual void drop() = 0;
    string getProductName();
    void setProductName(string);
    int getNumProducts();
    void setNumProducts(int);
    int getPrice();
    void setprice(int);
    int getId();
};
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
    void fillt(int ,string, int, int, int);
    friend void affiche(const Automat& automat);
    keypad getkeypad();
    coinslot getcoinslot();
    dropcheck getdropcheck();
};
class smallSlot : public Slot
{
    moteur motor1;
public:
    smallSlot(int ,string, int, int, int);
    void drop();
};
class wideslot : public Slot
{
    moteur motor1;
    moteur motor2;
public:
    wideslot(int, string, int, int, int);
    void drop();
};
