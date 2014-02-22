#pragma once
#include "../std_lib_facilities.h"
#include "Year.h"

namespace Chrono {

class Date {
public:
	enum Month {
		jan = 1,
		feb,
		march,
		april,
		may,
		jun,
		jul,
		aug,
		sep,
		oct,
		nov,
		december,
	};


	Date(int d, Month m,  Year y);
	Date();	// default constructor
	~Date();


	class Invalid {
	public:
		const char *what(const char *msg){return msg;};
		const char *what(){
			return what("Invalid Date");
		};

	}; // to be used as exception

	Month month() const {return m;};
	int day() const {return d;};
	Year year() const {return y;};


	void add_day(int n);
	void add_year(int n);

private:
	int d;
	Month m;
	Year y;
	
};

bool is_date(Year y,Date::Month m, int d);

bool leapYear(Year y);

bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);

ostream& operator<<(ostream& os,const Date& d);
istream& operator>>(istream& is,Date& dd);


}// chrono