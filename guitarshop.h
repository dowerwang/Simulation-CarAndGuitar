#ifndef GUITARSHOP_H
#define GUITARSHOP_H
#pragma once
#include "Guitar.h"
#include "dweller.h"
#include <QString>
#include <memory>

class GuitarShop
{
private:
    friend class City;

    vector <guitar> guitars;
    int money_collected;
    string showInfo;
public:
    GuitarShop();
    ~GuitarShop();

    QString show_info();
    void delivery();
    string sell_items(vector<shared_ptr<Dweller>>);
	void save(QString sfilename);
};
#endif // GUITARSHOP_H
