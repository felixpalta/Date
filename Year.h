#pragma once
#include "../std_lib_facilities.h"

class Year {
public:
	class Invalid{
	public:
		const char *what(){
			static const char *msg = "Invalid Year";
			return msg;
		}
	};
	Year():y(min_year){};
	Year(int x): y(x) { if (x < min_year || x > max_year) throw Invalid();};

	int year() const {return y;}
private:
	static const int min_year = 1800;
	static const int max_year = 2100;
	int y;
};

ostream& operator<<(ostream& os,const Year& y);
istream& operator>>(istream& is,Year& y);