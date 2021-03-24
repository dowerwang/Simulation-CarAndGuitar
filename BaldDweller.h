#ifndef BALDDWELLER_H
#define BALDDWELLER_H
#pragma once

#include "dweller.h"
#include <QString>
#include <iostream>
#include <random>
#include <string>
#include "year.h"


using namespace std;

class BaldDweller : public Dweller
{
    friend class City;
    friend class CarShop;
    friend class GuitarShop;
    bool haveHair;
    bool haveCar;
    bool haveGuitar;
    int money;
    string wanted_type_guitar;
    string wanted_type_car;
    string Dweller_name;

    Year Dweller_age;

public:
    BaldDweller();
    BaldDweller(bool hair);
    BaldDweller(string tempName, int tempAge, int tempMoney, bool tempHaveCar, bool tempHaveGuitar, string tempWC, string tempWG, bool tempHair);
    ~BaldDweller();
    BaldDweller& operator++();
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

#endif // BALDDWELLER_H
