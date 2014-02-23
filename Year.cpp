#include "../std_lib_facilities.h"
#include "Year.h"

namespace Chrono {
	ostream& operator<<(ostream& os,const Year& y){
		os << y.year();
		return os;
	}

	istream& operator>>(istream& is,Year& y){

		int yy  = 0;	// invalid Year
		is >> yy;
		if (!is) return is;	// formatted reading fail, badbit and/or failbit is set

		y = Year(yy);
		return is;
	}
}