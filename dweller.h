#pragma once
#ifndef DWELLER_H
#define DWELLER_H

#include <iostream>
#include <QString>
#include <random>
#include <string>
#include "year.h"
#include <fstream>

using namespace std;

class Dweller
{
public:
    Dweller(){}
    virtual ~Dweller(){}
    virtual Dweller& operator++()=0;
    virtual string getDwellerName()=0;
    virtual int getDwellerMoney()=0;
    virtual string getDwellerWantedGuitarType()=0;
    virtual string getDwellerWantedCarBrand()=0;
    virtual bool getDwellerInfoGuitar()=0;
    virtual bool getDwellerInfoCar()=0;
    virtual void salary()=0;
    virtual void setCarInfo(bool haveCar)=0;
    virtual void setGuitarInfo(bool haveGuitar)=0;
    virtual void payment(int price)=0;
	virtual void save(QString sfilename) = 0;
};

#endif // DWELLER_H
