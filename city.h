#ifndef CITY_H
#define CITY_H
#pragma once
#include "dweller.h"
#include "BaldDweller.h"
#include "haireddweller.h"
#include "year.h"
#include "CarShop.h"
#include "guitarshop.h"
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <Windows.h>
#include <memory>
#include <QtTest/QTest>
#include <QCloseEvent>

using namespace std;

class City
{
    vector<shared_ptr<Dweller>> dwellers;


    friend class CarShop;

    shared_ptr<GuitarShop> g_shop{new GuitarShop};
    shared_ptr<CarShop> c_shop{new CarShop};

    Year date;
    int range;

    string name, textCShop, textGShop;

    friend class wnd_Shop;
public:
    City();
    ~City();

    bool end_of_app;
    void setRange(const int range);
    void setName(const string name);
    void setInsurance(int insurance);
    void setEndOfApp(const bool end_of_app);
    void nextYear();
    int showDate();
    int getRangeOfCity();
    void readFile(QString ofilename);
    void saveFile(QString sfilename);
};

#endif // CITY_H
