#include "Guitar.h"
#include"debug.h"

guitar::guitar()
{
	random_device rd;
	uniform_int_distribution<int> distype(1, 4);
	uniform_int_distribution<int> discost(100, 800);
	switch (distype(rd))
	{
	case(1): type = "acustic"; break;
	case(2): type = "bass"; break;
	case(3): type = "electric"; break;
	case(4): type = "classic"; break;
	}
	cost = discost(rd);
}
guitar::guitar(string tempType, int tempCost)
{
	cost = tempCost;
	type = tempType;
}

guitar::~guitar(){}

void guitar::show_info()
{
	cout << "Type: " << type << "\tCost: " << cost << endl;
}

void guitar::save(QString sfilename)
{
    ofstream myFile;
    myFile.open(sfilename.toStdString(), ios::app);
    myFile << type <<" " << cost << endl;
    myFile.close();
}
