#include "Slot.h"
Slot::Slot(int yd , string name , int prix , int mt1id , int mt2id):id(yd), productName(name), price(prix), moteur1(mt1id) , numProduits(0), moteur2(mt2id){
}
Slot::~Slot(){};
int Slot::getId(){
    return id;
}
void Slot::setProductName(string name){
    productName = name;
}

void Slot::setprice(int prix){
    price = prix;
}
int Slot::getPrice(){
    return price;
}
string Slot::getProductName(){
    return productName;
}
int Slot::getNumProducts(){
    return numProduits;
}
void Slot::setNumProducts(int n){
    numProduits = n;
}
