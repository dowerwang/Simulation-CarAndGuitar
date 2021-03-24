#ifndef CAR_H
#define CAR_H

#pragma once
#include <string>
#include <iostream>
#include <random>
#include <fstream>
#include <QString>

using namespace std;

class Car
{
    friend class CarShop;
    string type;
    int cost;
public:
	Car();
	Car(string tempType, int tempCost);
	~Car();
	void show_info();
	void save(QString sfilename);
};

#endif //CAR_H
