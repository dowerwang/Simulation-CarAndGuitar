#include "year.h"

Year::Year()
{
    year = 0;
}
Year::~Year() {}
Year::Year(const Year& yr)
{
    if (this != &yr)
    {
        year = yr.year;
    }
}
int Year::getYear()
{
    return year;
}
int Year::operator%(const int& liczba)
{
    return (year % liczba);
}
Year& Year::operator++()
{
    year++;
    return *this;
}
Year& Year::operator=(const int& liczba)
{
    year = liczba;
    return *this;
}
Year& Year::operator=(const Year& yr)
{
    if (this != &yr)
    {
        year = yr.year;
    }
    return *this;
}
bool Year::operator>(const int &rok)
{
    if (this->year > rok)
        return true;
    else
        return false;
}
bool Year::operator<(const int &rok)
{
    if (this->year < rok)
        return true;
    else
        return false;
}
bool operator<(const int &rok, const Year &r)
{
    if(rok < r.year)
        return true;
    else
        return false;
}
std::istream&operator>>(std::istream& is, Year &data)
{
    is>>data.year;
    return is;
}

std::ostream & operator<<(std::ostream & is, Year & data)
{
	is << data.year;
	return is;
}
