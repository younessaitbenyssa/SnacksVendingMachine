#include "dropcheck.h"

bool dropcheck::productReleased(){
        int randomNum = rand() % 100;
        return randomNum < 90;
}
