#include "../std_lib_facilities.h"
#include "Date.h"

using namespace Chrono;

int main()
try 
{
	try {
	Date lol(1,Date::april,2050);
	Date wut = lol;	// copy constructor
	if (wut==lol) cout << "yup" << endl;	// operator test
	cout << wut.day() << endl;

	Date dflt;	// default constructor
	cout << dflt.year().year() << endl;

	cout << "Year: " << lol.year().year() << endl;
	cout << "Month: " << lol.month() << endl;
	cout << "Day: " << lol.day() << endl;
	cout << "Leap?: " << (leapYear(lol.year()) ? "Yes": "No") << endl;

	//another operator tests
	cout << wut << endl;

	cout << "create a new Year object" << endl;
	Year newyear;
	cin >> newyear;
	if (!cin) error("Failed to input a year");
		
	cout << newyear << endl;

	}
	catch(Date::Invalid e){
		error(e.what());
	}
	catch(Year::Invalid e){
		error(e.what());
	}

	cout << "Reached end..." << endl;
	keep_window_open();

}

catch(runtime_error& e){
	cout << e.what() << endl;
	keep_window_open();
}

