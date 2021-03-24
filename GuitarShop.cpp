#include "guitarshop.h"
#define size_of_delivery 4

GuitarShop::GuitarShop()
{
	for (int i = 0; i < size_of_delivery; i++)
	{
        guitars.push_back(guitar());
	}
    money_collected = 0;
}
GuitarShop::~GuitarShop() {}
QString GuitarShop::show_info()
{
    return "Money collected: " + QString::number(money_collected) + " zl";
}
void GuitarShop::delivery()
{
	for (int i = 0; i < size_of_delivery; i++)
	{
		guitars.push_back(guitar());
	}
}

string GuitarShop::sell_items(vector<shared_ptr<Dweller>> clients)
{
    showInfo = "";
	for (unsigned int j = 0; j < clients.size(); j++)
	{
		for (unsigned int i = 0; i < guitars.size(); i++)
		{
            if (clients[j]->getDwellerMoney() > guitars[i].cost && clients[j]->getDwellerWantedGuitarType() == guitars[i].type && clients[j]->getDwellerInfoGuitar() == false)
            {
                clients[j]->payment(guitars[i].cost);
                clients[j]->setGuitarInfo(true);
				money_collected += guitars[i].cost;
                showInfo += guitars[i].type + " guitar sold to " + clients[j]->getDwellerName() + " for "
                        + std::to_string(guitars[i].cost) + " zl\n";
				guitars.erase(guitars.begin() + i);
				i--;
				break;
			}
		}
	}
    return showInfo;
}
void GuitarShop::save(QString sfilename)
{
    ofstream file;
    file.open(sfilename.toStdString(), ios::app);
    file << "---" << endl;
    file << money_collected << endl;
	file << "---" << endl;
	for (auto x : guitars)
	{
        x.save(sfilename);
	}
	file << "---" << endl;
    file.close();
}
