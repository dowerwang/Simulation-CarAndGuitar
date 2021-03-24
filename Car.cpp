#include "debug.h"
#include "Car.h"

Car::Car()
{
    random_device rd;
    uniform_int_distribution<int> distype(1, 7);
    uniform_int_distribution <int> discost(300,1000);;

    switch (distype(rd))
    {
    case(1): type = "Suzuki"; break;
    case(2): type = "BMW"; break;
    case(3): type = "Opel"; break;
    case(4): type = "Fiat"; break;
    case(5): type = "Seat"; break;
    case(6): type = "Toyota"; break;
    case(7): type = "Hyundai"; break;
    }
    cost = discost(rd);

}
Car::Car(string tempType, int tempCost)
{
    cost = tempCost;
    type = tempType;
}

Car::~Car(){}

void Car::show_info()
{
    cout << "Type: " << type << "\tCost: " << cost << endl;
}

void Car::save(QString sfilename)
{
    ofstream myFile;
    myFile.open(sfilename.toStdString(), ios::app);
    myFile << type <<" " << cost << endl;
    myFile.close();
}
