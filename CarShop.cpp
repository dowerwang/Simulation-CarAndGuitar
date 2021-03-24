#include "CarShop.h"
#define size_of_delivery 3


CarShop::CarShop()
{
	for (int i = 0; i < size_of_delivery; i++)
	{
		cars.push_back(Car());
	}
    money_collected = 0;
}
CarShop::~CarShop() {}
QString CarShop::show_info()
{
    return "Money collected: " + QString::number(money_collected) + " zl";
}
void CarShop::delivery()
{
	for (int i = 0; i < size_of_delivery; i++)
	{
		cars.push_back(Car());
	}
}
string CarShop::sell_items(vector<shared_ptr<Dweller>> clients)
{
    showInfo = "";
	for (unsigned int j = 0; j < clients.size(); j++)
	{
		for (unsigned int i = 0; i < cars.size(); i++)
		{
            if (clients[j]->getDwellerMoney() > cars[i].cost && clients[j]->getDwellerWantedCarBrand() == cars[i].type && clients[j]->getDwellerInfoCar() == false)
			{
                clients[j]->payment(cars[i].cost);
                clients[j]->setCarInfo(true);
				money_collected += cars[i].cost;
                showInfo += cars[i].type + " sold to " + clients[j]->getDwellerName() + " for "
                        + std::to_string(cars[i].cost) + " zl\n";
				cars.erase(cars.begin() + i);
				i--;
				break;
			}
		}
	}
    return showInfo;
}
void CarShop::save(QString sfilename)
{
    ofstream file;
    file.open(sfilename.toStdString(), ios::app);
    file << money_collected << " " << insurance_price << endl;
    file << "---" << endl;
    for (auto x : cars)
    {
        x.save(sfilename);
    }
    file << "---" << endl;
    file.close();
}
