//
// Created by MSI on 2019/11/21.
//

#include "Data.h"

using namespace std;

//implementing overloaded operator <<
ostream& operator<<(ostream &os, Data &dt){
    os << dt.countryName << "," << dt.localityName << "," << dt.marketName << "," << dt.itemName << "," << dt.currency << "," << dt.marketType << "," << dt.yearRecorded << "," << dt.pricePaid;
    return os;
}


//implementing comparison operator for comparing the active season member
bool operator< (const Data& dt, const Data& dt1){
    if(dt.pricePaid < dt1.pricePaid){
        return true; //the current player is less experienced than the one that we are comparing him to
    }
    else{
        return false;
    }
}

