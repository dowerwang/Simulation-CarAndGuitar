#ifndef YEAR_H
#define YEAR_H

#include <iostream>

class Year
{
    int year;

public:
    Year();
    ~Year();
    Year(const Year&);

    int getYear();

    int operator%(const int&);
    Year& operator++();
    Year& operator=(const int&);
    Year& operator=(const Year&);
    bool operator>(const int&);
    bool operator<(const int&);
    friend std::istream& operator>>(std::istream& is, Year& data);
	friend std::ostream& operator<<(std::ostream& is, Year& data);
    friend bool operator<(const int&, const Year&);
};
#endif // YEAR_H
