#ifndef GUITAR_H
#define GUITAR_H

#pragma once
#include <string>
#include <iostream>
#include <random>
#include <fstream>
#include <QString>
using namespace std;

class guitar
{
private:
	friend class GuitarShop;
    string type;
    int cost;
public:
	
	guitar();
	guitar(string tempType, int tempCost);
	~guitar();
	void show_info();
	void save(QString sfilename);
};

#endif
