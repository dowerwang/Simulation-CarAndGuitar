#ifndef CARSHOP_H
#define CARSHOP_H

#pragma once
#include "dweller.h"
#include "Car.h"
#include <memory>

class CarShop
{
private:
	friend class City;
    vector<Car> cars;
    int money_collected, insurance_price;
    string showInfo;
public:
	CarShop();
	~CarShop();

    QString show_info();
    void delivery();
    string sell_items(vector<shared_ptr<Dweller>>);
	void save(QString sfilename);
};

#endif
