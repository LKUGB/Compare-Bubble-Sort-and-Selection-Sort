//
// Created by MSI on 2019/11/21.
//

#ifndef PROJECT_8_LKUGB_DATA_H
#define PROJECT_8_LKUGB_DATA_H
#include <iostream>
#include <string>

using namespace std;

class Data {
    public:
    // four data members with proper types
        string countryName;
        string localityName;
        string marketName;
        string itemName;
        string currency;
        string marketType;
        int yearRecorded;
        double pricePaid;

    //overload the output stream operator
        friend ostream& operator<<(ostream &os, Data &dt);
        //overload the comparison operators to compare a single attribute in the csv file (which is stored in the linked list as a protected member)
        friend bool operator< (const Data& dt, const Data& dt1);
    };



#endif //PROJECT_8_LKUGB_DATA_H
