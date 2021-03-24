#ifndef HAIREDDWELLER_H
#define HAIREDDWELLER_H

#include "dweller.h"

class HairedDweller : public Dweller
{
    friend class City;
    friend class CarShop;
    friend class GuitarShop;
    bool haveCar;
    bool haveGuitar;
    int money;
    string wanted_type_guitar;
    string wanted_type_car;
    string Dweller_name;
    string HairColor;

    Year Dweller_age;
public:
    HairedDweller();
    HairedDweller(string color);
    HairedDweller(string tempName, int tempAge, int tempMoney, bool tempHaveCar, bool tempHaveGuitar, string tempWC, string tempWG, string tempHair);
    ~HairedDweller();
    HairedDweller& operator++();
    virtual string getDwellerName();
    virtual void salary();
    virtual int getDwellerMoney();
    virtual string getDwellerWantedGuitarType();
    virtual string getDwellerWantedCarBrand();
    virtual bool getDwellerInfoGuitar();
    virtual bool getDwellerInfoCar();
    virtual void setCarInfo(bool haveCar);
    virtual void setGuitarInfo(bool haveGuitar);
    virtual void payment(int price);
	virtual void save(QString sfilename);
};

#endif // HAIREDDWELLER_H
