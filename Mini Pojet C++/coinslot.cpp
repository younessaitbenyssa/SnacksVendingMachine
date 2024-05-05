#include "coinslot.h"
coinslot::coinslot(){
    coinAmount = 0;
}
int coinslot::updatedcoinamount(){
    int inserted;
    cout << "\ninsert a coin of type 1,5,10,20,50,100,200 or type -1 to cancel : " ;
    cin >> inserted;
    if (inserted == -1){
        return 0;
    }
    coinAmount+=inserted;
    cout << "you entered :  " << coinAmount;
    return coinAmount;
}
int coinslot::getcoinamount(){
    return coinAmount;
}
void coinslot::clear(){
    coinAmount = 0;
}
void coinslot::returncoins(int p){
    int r;
    if (coinAmount>=p){
        r = coinAmount - p;
    }else{
       r = coinAmount;
    }
    int ds = r / 200;
    r = r % 200;
    int cent = r / 100;
    r = r%100;
    int ciq = r / 50;
    r = r%50;
    int vin = r / 20;
    r = r%20;
    int dix = r / 10;
    r = r % 10;
    int cinq = r / 5;
    r = r % 5;
    int one = r ;
    if (ds != 0){
        cout <<ds<<"*2 euros ";
    }
    if (cent != 0){
        cout << " " <<cent<<"*1 euros";
    }
    if (ciq != 0){
        cout <<" "<<ciq<<"*0.5 euros ";
    }
    if (vin != 0){
        cout <<" "<<vin<<"*0.2 euros ";
    }
    if (dix != 0){
        cout <<" "<<dix<<"*0.1 euros ";
    }
    if (cinq != 0){
        cout <<" "<<cinq<<"*0.05 euros ";
    }
    if (one != 0){
        cout <<" "<<one<<"*0.01 euros ";
    }
}
