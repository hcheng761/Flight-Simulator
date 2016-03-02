/*	Final Project CSCE 113 - 501
	Cheng, Howard
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

class Flight	{
		string flightnum;
		string gatenum;
	public:
		string destin;
		string dtime;
		int dnum;
		string get_fn() {return flightnum;}
		string get_des() {return destin;}
		string get_dt() {return dtime;}
		string get_gn() {return gatenum;}
		Flight()  {}
		Flight	(string fl, string d1, string d2, string g, int d3)	{flightnum = fl; destin = d1; dtime = d2; gatenum = g; dnum = d3;}
		
		int dtime_assign(Flight& f, string dtime);
		void bubble_sort();
		void dtime_assign();
		friend istream& operator>> (istream& is, Flight& f);
		friend ostream& operator<< (ostream& os, Flight& f);
		friend bool operator== (Flight& f1, Flight& f2);
};

//------------------------------------------------------------------------------------

struct dtime_sort	{	//Compares two Flight objects
	bool operator() (const Flight& f1, const Flight& f2)	{
		return f1.dnum < f2.dnum;
		}
};

//------------------------------------------------------------------------------------

int dtime_assign(Flight& f, string dtime)	{	//For selection order, turns departure time strings into ints
	int dtime_num;
	if (dtime.length() == 5){dtime.erase (dtime.begin()+2);}
	else if (dtime.length() == 4) {dtime.erase (dtime.begin()+1);}
	istringstream s1(dtime);
	s1 >> dtime_num;

	f.dnum = dtime_num;
	return f.dnum;
}

//------------------------------------------------------------------------------------	
istream& operator>> (istream& is, Flight& f)	{
	is >> f.flightnum;
	
	is >> f.destin;
	is >> f.dtime;
	is >> f.gatenum;

	return is;
}
//------------------------------------------------------------------------------------

ostream& operator<< (ostream& os, Flight& f)	{
	os << left << setw(12) << f.flightnum << setw(10) << f.destin << setw(10) << f.dtime << setw(10) << f.gatenum << endl;
	return os;
}
//------------------------------------------------------------------------------------

//class flightpos	{