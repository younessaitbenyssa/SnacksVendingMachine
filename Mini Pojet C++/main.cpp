#include <iostream>
#include "classes.h"

using namespace std;

int main()
{
    cout << "====================================================VENDING MACHINE ====================================================\n";
    int k;
    Automat a(15,3);
    cout << "Admin (user enter 1 to continue): "; // The admin has the right to add elements the the machine by adding them in the file
    cin >> k ;
    if (k == 1234){
        int productId, price, mot1,mot2;
        string productName;
        ofstream File("input.txt");
        for (int i=0; i<15; i++){
        cout << "enter the price of your product: ";
        cin >> price;
        cout << "enter the name of your product: ";
        cin >> productName;
        cout << "enter the id of your product: ";
        cin >> productId;
        cout << "enter the motor1 of your product: ";
        cin >> mot1;
        cout << "enter the motor2 of your product: ";
        cin >> mot2;
        File << price <<"\n"<< productName <<"\n"<< productId <<"\n"<< mot1 <<"\n"<< mot2 << "\n";
        }
    }
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the input file." << endl;
        return 1;
    }
    int productId, price, mot1,mot2;
    string productName;
    while (inputFile >> price >> productName >> productId >> mot1 >> mot2) {
         if (mot2 != 0){
            a.addSlot(price,productName,productId,mot1,mot2);
        } else {
            a.addSlot(price,productName,productId ,mot1);
        }
    }
    inputFile.close();
    a.fillAll();
    while(1){
    cout << "========================================================= MENU =========================================================";
    affiche(a);
    cout<< "========================================================================================================================\n";
    keypad kp = a.getkeypad();
    int s = kp.getselection();
    if (s == -1){
        break;
    }else{
        if (a.isAvailable(s)){
            int pix;
            pix = a.getPrice(s);
            cout << "the price of your product is : " << pix;
            coinslot coin = a.getcoinslot();
            int sm;
            while (1){
                sm = coin.updatedcoinamount();
                if (pix <= sm || sm == 0)
                    break;
            }
            if (sm == 0){
                cout << "Your return is : ";
                coin.returncoins(pix);
                cout << "\n";
                continue;
            }
            a.dropSlot(s);
            cout << "\nYour return is : ";
            coin.returncoins(pix);
            cout << "\n";
        }else{
            cout << "the selected product is not available right now, choose another one or enter -1 to leave!!\n";
        }
    }
    }
    return 0;
}
