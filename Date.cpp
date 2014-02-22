#include "Date.h"
#include "Year.h"
namespace Chrono {

Date::Date(int dd, Month mm,  Year yy)
		:y(yy),m(mm),d(dd) {
			if (!is_date(yy,mm,dd)) throw Invalid();
	}
	

void Date::add_day(int n){
	d += n;
}

void Date::add_year(int n){
	if (m == feb && d == 29 && !leapYear(y.year()+n)){
		m = march;
		d = 1;
	}
	y = y.year()+n;
}

Date::~Date(){};

// it's okay to use a global variable here
// it's declared static so it won't be used (declared) anywhere else
// and it is thread-safe
static const Date dd(1,Date::jan,Year(2001));

// according to MSVC2010 using an automatic static variable is not thread-safe
// so we use a global static const variable
const Date& default_date(){
	return dd;	// members of this const Date& will be copied in the default Date() constructor
}
// previous version, non thread-safe
// Date& default_date(){
// 	static Date dd(1,Date::jan,Year(2001));
// 	return dd;
// }


Date::Date()
	:y(default_date().year()),
	m(default_date().month()),
	d(default_date().day())
{}

bool leapYear(Year y){
	const int yy = y.year();
	return ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0);
}

bool is_date(Year y,Date::Month m, int d){
	if (m < Date::jan || m > Date::december)
		return false;
// year checking is done inside Year constructor
	int days_in_the_month = 31; // most months have 31 days
	switch (m){
	case Date::feb:
		days_in_the_month = leapYear(y) ? 29: 28;
		break;
	case Date::april:
	case Date::jun:
	case Date::sep:
	case Date::nov:
		days_in_the_month = 30;
		break;
	case Date::jan:
	case Date::march:
	case Date::may:
	case Date::jul:
	case Date::aug:
	case Date::oct:
	case Date::december:
		break;
	default:
		return false;
	}
	return (d <= days_in_the_month);

}

bool operator==(const Date& a, const Date& b){
	return a.year().year()==b.year().year() 
		&& a.month()==b.month()
		&&a.day()==b.day();
}
bool operator!=(const Date& a, const Date& b){
	return !(a==b);
}

}