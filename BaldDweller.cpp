#include "BaldDweller.h"

using namespace std;

BaldDweller::BaldDweller(){}
BaldDweller::BaldDweller(string tempName, int tempAge, int tempMoney, bool tempHaveCar, bool tempHaveGuitar,
                         string tempWC, string tempWG, bool tempHair)
{
    Dweller_name = tempName;
    Dweller_age = tempAge;
    money = tempMoney;
    haveCar = tempHaveCar;
    haveGuitar = tempHaveGuitar;
    wanted_type_car = tempWC;
    wanted_type_guitar = tempWG;
    haveHair = tempHair;
}
BaldDweller::BaldDweller(bool hair) 
{
    random_device rd;
    uniform_int_distribution<int> disletter(97, 122);
	haveHair = hair;
    haveCar = false;
    haveGuitar = false;
    Dweller_age = 1;
    for (int i = 0; i < 6; i++)
    {
        string temp;
        temp = static_cast<char>(disletter(rd));
        Dweller_name += temp;
    }
    Dweller_name[0] = static_cast<char>(toupper(Dweller_name[0]));


    uniform_int_distribution<int> distypeguitar(1, 4);
    uniform_int_distribution<int> distypecar(1, 7);
    uniform_int_distribution<int> dismoney(10000, 800000);
    switch (distypeguitar(rd))
    {
    case(1): wanted_type_guitar = "acustic"; break;
    case(2): wanted_type_guitar = "bass"; break;
    case(3): wanted_type_guitar = "electric"; break;
    case(4): wanted_type_guitar = "classic"; break;
    }
    switch (distypecar(rd))
    {
    case(1): wanted_type_car = "Suzuki"; break;
    case(2): wanted_type_car = "BMW"; break;
    case(3): wanted_type_car = "Opel"; break;
    case(4): wanted_type_car = "Fiat"; break;
    case(5): wanted_type_car = "Seat"; break;
    case(6): wanted_type_car = "Toyota"; break;
    case(7): wanted_type_car = "Hyundai"; break;
    }
    money = dismoney(rd);
}
BaldDweller::~BaldDweller() {}
BaldDweller& BaldDweller::operator++()
{
	++Dweller_age;
	return *this;
}
string BaldDweller::getDwellerName()
{
    return Dweller_name;
}
void BaldDweller::salary()
{
    money += 100;
}
int BaldDweller::getDwellerMoney()
{
    return money;
}
string BaldDweller::getDwellerWantedGuitarType()
{
    return wanted_type_guitar;
}
string BaldDweller::getDwellerWantedCarBrand()
{
    return wanted_type_car;
}
bool BaldDweller::getDwellerInfoCar()
{
    return haveCar;
}
bool BaldDweller::getDwellerInfoGuitar()
{
    return haveGuitar;
}
void BaldDweller::setCarInfo(bool haveCar)
{
    this->haveCar = haveCar;
}
void BaldDweller::setGuitarInfo(bool haveGuitar)
{
    this->haveGuitar = haveGuitar;
}
void BaldDweller::payment(int price)
{
    money -= price;
}
void BaldDweller::save(QString sfilename)
{
    ofstream myFile;
    myFile.open(sfilename.toStdString(), ios::app);
    myFile << Dweller_name <<" "<< Dweller_age <<" "<< money <<" "<< haveCar <<" "<< haveGuitar <<" "<< wanted_type_car <<" "
           << wanted_type_guitar <<" "<< haveHair << endl;
	myFile.close();
}
