#include "motor.h"
#ifndef SLOT
#define SLOT
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
#endif // SLOT
