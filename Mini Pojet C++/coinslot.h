#include <bits/stdc++.h>
using namespace std;
#ifndef COINSLOT
#define COINSLOT
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
#endif // COINSLOT
