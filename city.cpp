#include "city.h"

using namespace std;

City::City()
{
    date = 1;
    end_of_app = false;
}
City::~City(){}
void City::nextYear()
{
    for (int i = 0; i < 2; i++)
    {
        random_device rd;
        uniform_int_distribution<int> TypeOfDweller(1,2);
        switch(TypeOfDweller(rd))
        {
        case 1:
        {
            dwellers.emplace_back(make_shared<BaldDweller>(false));
            break;
        }
        case 2:
        {
            uniform_int_distribution<int> Color(0,3);
            switch(Color(rd))
            {
            case 0:
            {
                dwellers.emplace_back(make_shared<HairedDweller>("Blonde"));
                break;
            }
            case 1:
            {
                dwellers.emplace_back(make_shared<HairedDweller>("Dark"));
                break;
            }
            case 2:
            {
                dwellers.emplace_back(make_shared<HairedDweller>("White"));
                break;
            }
            case 3:
            {
                dwellers.emplace_back(make_shared<HairedDweller>("Red"));
                break;
            }
            }
        }
        }
    }
    for (unsigned long long i = 0; i < static_cast<unsigned long long>(dwellers.size()); i++)
    {
        ++(*(dwellers[i]));
    }
    ++date;

    for (auto x : dwellers)
    {
        x->salary();
        if(x->getDwellerInfoCar() == true)
        {
            x->payment(c_shop->insurance_price);
            c_shop->money_collected += c_shop->insurance_price;
        }
    }
    g_shop->delivery();
    c_shop->delivery();
    textGShop = g_shop->sell_items(dwellers);
    textCShop = c_shop->sell_items(dwellers);
}
int City::showDate()
{
    return date.getYear();
}
void City::readFile(QString ofilename)
{
    ifstream ReadFile;
    int tempAge, tempMoney;
    string tempName, tempSwitch, tempHair, tempWC, tempWG;
    bool tempHaveCar, tempHaveGuitar;

    ReadFile.open(ofilename.toStdString(), ios::in);
    //City//
    ReadFile>>name>>range>>date;
    //---------//
    ReadFile>>tempSwitch;
    //Dwellers//
    for(;;)
    {
        ReadFile>>tempName;
        if(tempName[0] == '-')
        {
            break;
        }
        ReadFile>>tempAge>>tempMoney>>tempHaveCar>>tempHaveGuitar>>tempWC>>tempWG>>tempHair;
        if(tempHair[0] == 0)
        {
            dwellers.emplace_back(make_shared<BaldDweller>(tempName, tempAge, tempMoney, tempHaveCar, tempHaveGuitar, tempWC, tempWG, false));
        }
        else
        {
            dwellers.emplace_back(make_shared<HairedDweller>(tempName, tempAge, tempMoney, tempHaveCar, tempHaveGuitar, tempWC, tempWG, tempHair));
        }
    }
    //GuitarShop//
    ReadFile>>g_shop->money_collected;
    //-------//
    ReadFile>>tempSwitch;
    //Guitars//
    for(;;)
    {
        ReadFile>>tempWG;
        if(tempWG[0] == '-')
        {
            break;
        }
        ReadFile>>tempMoney;
        //add guitar
        g_shop->guitars.push_back(guitar(tempWG, tempMoney));
    }
    //CarShop//
    ReadFile >> c_shop->money_collected >> c_shop->insurance_price;
    //-------//
    ReadFile>>tempSwitch;
    //Cars//
    for(;;)
    {
        ReadFile>>tempWC;
        if(tempWC[0] == '-')
        {
            break;
        }
        ReadFile>>tempMoney;
        //add car
        c_shop->cars.push_back(Car(tempWC, tempMoney));
    }
    ReadFile.close();
}
void City::saveFile(QString sfilename)
{
    ofstream file;
    file.open(sfilename.toStdString(), ios::out);
    file << name << " " << range << " " << date << endl;
    file << "---" << endl;
    for(auto x: dwellers)
    {
        x->save(sfilename);
    }
    g_shop->save(sfilename);
    c_shop->save(sfilename);

    file.close();
}
void City::setRange(const int r)
{
    this->range = r;
}
void City::setName(const string name)
{
    this->name = name;
}
void City::setInsurance(int insurance)
{
    c_shop->insurance_price = insurance;
}
void City::setEndOfApp(const bool end_of_app)
{
    this->end_of_app = end_of_app;
}
int City::getRangeOfCity()
{
    return range;
}
