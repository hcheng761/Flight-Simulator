/*	Final Project CSCE 113 - 501
	Cheng, Howard
*/

#include "sort.h"
#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace std;

vector<Flight>sortout(string s)	{		//Read the text file of flights
	vector<Flight>fl(10);
	string tx = ".txt";
	string concat = s+tx;
	ifstream flist(concat);
	if (flist.is_open())	{
		for (int i = 0; i < 10; ++i)
			{
				flist >> fl[i];
				dtime_assign(fl[i], fl[i].dtime);	//Assign each flight with an integer form of departure time
			}
		flist.close();
	}

	else cout << "File could not be opened" << endl;	//If file could not be opened.
	
	return fl;
}

vector<Flight>select(vector<Flight>&s1, string s)	{	//Selection sort

	s1 = sortout(s);
	s1 = selection_sort(s1);
	return s1;
}

vector<Flight>bubble(vector<Flight>s2, string sr)	{	//Bubble sort
	s2 = sortout(sr);
	s2 = bubble_sort(s2);
	return s2;
}

int main(){
	vector<Flight>fin1;		
	vector<Flight>fin3;
	string st;
	cout << "Enter txt file name without extension:" << endl;
	cout << " " << endl;
	cin >> st;
	fin3 = sortout(st);	//Make copies of the flight vectors
	fin1 = sortout(st);
	vector<Flight>fin12a = fin1;
	vector<Flight>fin12b = fin1;
	for (int i = 0; i < 3; i++)	{cout << " " << endl;}
	cout << "Departure times not sorted:" << endl;			//Display unsorted flight vector
	cout << " " << endl;
	for (int i = 0; i < 10; i++)	{cout << fin1[i] << endl;}
	cout << " " << endl;
	
	vector<Flight>fin2;
	vector<Flight>bub;
	vector<int>be1(10), be2(10), be3(10), be4(10), be5(10), be6(10), be7(10), be8(10), be9(10), be0(10);
	vector<int>af1(10), af2(10), af3(10), af4(10), af5(10), af6(10), af7(10), af8(10), af9(10), af0(10);

	fin2 = select(fin1,st);
	cout << " " << endl;
	bub = bubble(fin3,st);
//--------------------------------------------------------------------------
	
	be1[0] = 0;								//Determine initial position of flight at ith iteration
	for (int i = 1; i < fin1.size(); i++)	//Departure times are considered
		{	
			if (i == 1)	{
			int c = fin12b[1].dnum;		//c is the departure number of interest
			vector<int>temp = dnumsort(fin12a, i);	//Sort the vector to the point where the dnum of interest is considered in selection sort
			int d = before(temp,c);		//determine index of flight
			be2[1] = d;		//store the index in vector in initial positions
			}
			
			if (i != 1)	{
			int m = i - 1;
			int c = fin12b[0].dnum;
			vector<int>temp = dnumsort(fin12a, m);
			int d = before(temp,c);
			be1[i] = d;
			}
		}
		
	for (int i = 0; i < fin1.size(); i++)	//Determine final position of flight at ith iteration
		{
			int c = fin12b[0].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			af1[i] = d;		//store index in vector of final positions
		}

//-------------------------------------------------------------------------
		
	be2[0] = 1;	
	for (int i = 1; i < fin1.size(); i++)
		{	if (i == 1)	{
			int c = fin12b[1].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			be2[1] = d;
			}
		
			else if (i > 1)	{
			int m = i - 1;
			int c = fin12b[1].dnum;
			vector<int>temp = dnumsort(fin12a, m);
			int d = before(temp,c);
			be2[i] = d;
			}
		}
	for (int i = 0; i < fin1.size(); i++)	
		{
			int c = fin12b[1].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			af2[i] = d;
		}
//-------------------------------------------------------------------------
		
	be3[0] = 2;
	for (int i = 1; i < fin1.size(); i++)
		{	if (i == 1)	{
			int c = fin12b[2].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			be3[1] = d;
			}
		
			else if (i > 1)	{
			int m = i - 1;
			int c = fin12b[2].dnum;
			vector<int>temp = dnumsort(fin12a, m);
			int d = before(temp,c);
			be3[i] = d;
			}
		}
	for (int i = 0; i < fin1.size(); i++)	
		{
			int c = fin12b[2].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			af3[i] = d;
		}
//-------------------------------------------------------------------------		
	be4[0] = 3;
	for (int i = 1; i < fin1.size(); i++)
		{	if (i == 1)	{
			int c = fin12b[3].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			be4[1] = d;
			}
		
			else if (i > 1)	{
			int m = i - 1;
			int c = fin12b[3].dnum;
			vector<int>temp = dnumsort(fin12a, m);
			int d = before(temp,c);
			be4[i] = d;
			}
		}
	for (int i = 0; i < fin1.size(); i++)	
		{
			int c = fin12b[3].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			af4[i] = d;
		}
//-------------------------------------------------------------------------
		
	be5[0] = 4;	
	for (int i = 1; i < fin1.size(); i++)
		{	if (i == 1)	{
			int c = fin12b[4].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			be5[1] = d;
			}
		
			else if (i > 1)	{
			int m = i - 1;
			int c = fin12b[4].dnum;
			vector<int>temp = dnumsort(fin12a, m);
			int d = before(temp,c);
			be5[i] = d;
			}
		}
	for (int i = 0; i < fin1.size(); i++)	
		{
			int c = fin12b[4].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			af5[i] = d;
		}
//-------------------------------------------------------------------------
		
	be6[0] = 5;	
	for (int i = 1; i < fin1.size(); i++)
		{	if (i == 1)	{
			int c = fin12b[5].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			be6[1] = d;
			}
		
			else if (i > 1)	{
			int m = i - 1;
			int c = fin12b[5].dnum;
			vector<int>temp = dnumsort(fin12a, m);
			int d = before(temp,c);
			be6[i] = d;
			}
		}
	for (int i = 0; i < fin1.size(); i++)	
		{
			int c = fin12b[5].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			af6[i] = d;
		}
//-------------------------------------------------------------------------
		
	be7[0] = 6;	
	for (int i = 1; i < fin1.size(); i++)
		{	if (i == 1)	{
			int c = fin12b[6].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			be7[1] = d;
			}
		
			else if (i > 1)	{
			int m = i - 1;
			int c = fin12b[6].dnum;
			vector<int>temp = dnumsort(fin12a, m);
			int d = before(temp,c);
			be7[i] = d;
			}
		}
	for (int i = 0; i < fin1.size(); i++)	
		{
			int c = fin12b[6].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			af7[i] = d;
		}
//-------------------------------------------------------------------------
		
	be8[0] = 7;
	for (int i = 1; i < fin1.size(); i++)
		{	if (i == 1)	{
			int c = fin12b[7].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			be8[1] = d;
			}
		
			else if (i > 1)	{
			int m = i - 1;
			int c = fin12b[7].dnum;
			vector<int>temp = dnumsort(fin12a, m);
			int d = before(temp,c);
			be8[i] = d;
			}
		}
	for (int i = 0; i < fin1.size(); i++)	
		{
			int c = fin12b[7].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			af8[i] = d;
		}
//-------------------------------------------------------------------------
		
	be9[0] = 8;	
	for (int i = 1; i < fin1.size(); i++)
		{	if (i == 1)	{
			int c = fin12b[8].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			be9[1] = d;
			}
		
			else if (i > 1)	{
			int m = i - 1;
			int c = fin12b[8].dnum;
			vector<int>temp = dnumsort(fin12a, m);
			int d = before(temp,c);
			be9[i] = d;
			}
		}
	
	for (int i = 0; i < fin1.size(); i++)	
		{
			int c = fin12b[8].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			af9[i] = d;
		}
//-------------------------------------------------------------------------
		
	be0[0] = 9;	
	for (int i = 1; i < fin1.size(); i++)
		{	if (i == 1)	{
			int c = fin12b[9].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			be0[1] = d;
			}
		
			else if (i > 1)	{
			int m = i - 1;
			int c = fin12b[9].dnum;
			vector<int>temp = dnumsort(fin12a, m);
			int d = before(temp,c);
			be0[i] = d;
			}
		}
	
	for (int i = 0; i < fin1.size(); i++)	
		{
			int c = fin12b[9].dnum;
			vector<int>temp = dnumsort(fin12a, i);
			int d = before(temp,c);
			af0[i] = d;
		}
		
		
//-------------------------------------------------------------------------

	
//--------------------------------------------------------------------------

	vector<int>diff1(10);
	for (int i = 0; i < diff1.size(); ++i)	{diff1[i] = 9;}	//Can't figure out why the for loop works for every flight except the first and last ones.
	/*for (int i = 0; i < 9; ++i)
		{	
			if (af1[i+1]-be1[i+1] == af1[i]-be1[i])
				for (int j = i; j >= 0; j--)
				{
					if (diff1[j] != 0)
					{diff1[i] = (diff1[j]);}
				}
			
			else diff1[i] = af1[i]-be1[i];
		}
	
	if (af1[9] - be1[9] == af1[8]-be1[8])
		{diff1[9] = diff1[8];}
		
	else if (af1[9] - be1[9] != af1[8]-be1[8])
		{diff1[9] = af1[9] - be1[9];}*/

//--------------------------------------------------------------------------	

	vector<int>diff2(10);			//Store the difference between initial and final positions of the moved flights
	for (int i = 0; i < 9; ++i)		//Differences would be used as multiples for graphing the lines
		{	
			if (af2[i]-be2[i] == af2[i+1]-be2[i+1])
				for (int j = i; j >= 0; j--)
				{
					if (diff2[j] != 0)
					{diff2[i] = (diff2[j]);}
				}
			
			else diff2[i] = af2[i]-be2[i];
		}
	
	if (af2[9] - be2[9] == af2[8]-be2[8])
		{diff2[9] = diff2[8];}
		
	else if (af2[9] - be2[9] != af2[8]-be2[8])
		{diff2[9] = af2[9] - be2[9];}

//--------------------------------------------------------------------------	

	vector<int>diff3(10);
	for (int i = 0; i < 9; ++i)
		{	
			if (af3[i]-be3[i] == af3[i+1]-be3[i+1])
				for (int j = i; j >= 0; j--)
				{
					if (diff3[j] != 0)
					{diff3[i] = (diff3[j]);}
				}
			
			else diff3[i] = af3[i]-be3[i];
		}
	
	if (af3[9] - be3[9] == af3[8]-be3[8])
		{diff3[9] = diff3[8];}
		
	else if (af3[9] - be3[9] != af3[8]-be3[8])
		{diff3[9] = af3[9] - be3[9];}

//--------------------------------------------------------------------------	

	vector<int>diff4(10);
	for (int i = 0; i < 9; ++i)
		{	
			if (af4[i]-be4[i] == af4[i+1]-be4[i+1])
				for (int j = i; j >= 0; j--)
				{
					if (diff4[j] != 0)
					{diff4[i] = (diff4[j]);}
				}
			
			else diff4[i] = af4[i]-be4[i];
		}
	
	if (af4[9] - be4[9] == af4[8]-be4[8])
		{diff4[9] = diff4[8];}
		
	else if (af4[9] - be4[9] != af4[8]-be4[8])
		{diff4[9] = af4[9] - be4[9];}

//--------------------------------------------------------------------------	

	vector<int>diff5(10);
	for (int i = 0; i < 9; ++i)
		{	
			if (af5[i]-be5[i] == af5[i+1]-be5[i+1])
				for (int j = i; j >= 0; j--)
				{
					if (diff5[j] != 0)
					{diff5[i] = (diff5[j]);}
				}
			
			else diff5[i] = af5[i]-be5[i];
		}
	
	if (af5[9] - be5[9] == af5[8]-be5[8])
		{diff5[9] = diff5[8];}
		
	else if (af5[9] - be5[9] != af5[8]-be5[8])
		{diff5[9] = af5[9] - be5[9];}

//--------------------------------------------------------------------------	

	vector<int>diff6(10);
	for (int i = 0; i < 9; ++i)
		{	
			if (af6[i]-be6[i] == af6[i+1]-be6[i+1])
				for (int j = i; j >= 0; j--)
				{
					if (diff6[j] != 0)
					{diff6[i] = (diff6[j]);}
				}
			
			else diff6[i] = af6[i]-be6[i];
		}
	
	if (af6[9] - be6[9] == af6[8]-be6[8])
		{diff6[9] = diff6[8];}
		
	else if (af6[9] - be6[9] != af6[8]-be6[8])
		{diff6[9] = af6[9] - be6[9];}

//--------------------------------------------------------------------------	

	vector<int>diff7(10);
	for (int i = 0; i < 9; ++i)
		{	
			if (af7[i]-be7[i] == af7[i+1]-be7[i+1])
				for (int j = i; j >= 0; j--)
				{
					if (diff7[j] != 0)
					{diff7[i] = (diff7[j]);}
				}
			
			else diff7[i] = af7[i]-be7[i];
		}
	
	if (af7[9] - be7[9] == af7[8]-be7[8])
		{diff7[9] = diff7[8];}
		
	else if (af7[9] - be7[9] != af7[8]-be7[8])
		{diff7[9] = af7[9] - be7[9];}

//--------------------------------------------------------------------------	

	vector<int>diff8(10);
	for (int i = 0; i < 9; ++i)
		{	
			if (af8[i]-be8[i] == af8[i+1]-be8[i+1])
				for (int j = i; j >= 0; j--)
				{
					if (diff8[j] != 0)
					{diff8[i] = (diff8[j]);}
				}
			
			else diff8[i] = af8[i]-be8[i];
		}
	
	if (af8[9] - be8[9] == af8[8]-be8[8])
		{diff8[9] = diff8[8];}
		
	else if (af8[9] - be8[9] != af8[8]-be8[8])
		{diff8[9] = af8[9] - be8[9];}

//--------------------------------------------------------------------------	

	vector<int>diff9(10);
	for (int i = 0; i < 9; ++i)
		{	
			if (af9[i]-be9[i] == af9[i+1]-be9[i+1])
				for (int j = i; j >= 0; j--)
				{
					if (diff9[j] != 0)
					{diff9[i] = (diff9[j]);}
				}
			
			else diff9[i] = af9[i]-be9[i];
		}
	
	if (af9[9] - be9[9] == af9[8]-be9[8])
		{diff9[9] = diff9[8];}
		
	else if (af9[9] - be9[9] != af9[8]-be9[8])
		{diff9[9] = af9[9] - be9[9];}

//--------------------------------------------------------------------------	
	
	vector<int>diff0(10);
	
	for (int i = 0; i < 10; ++i)	{	diff0[i] = -9;}
	/*for (int i = 0; i < 9; ++i)
		{	
			if (af0[i]-be0[i] == af0[i+1]-be0[i+1])
				for (int j = i; j >= 0; j--)
				{
					if (diff0[j] != 0)
					{diff0[i] = (diff0[j]);}
				}
			
			else diff0[i] = af0[i]-be0[i];
		}
	
	if (af0[9] - be0[9] == af0[8]-be0[8])
		{diff0[9] = diff0[8];}
		
	else if (af0[9] - be0[9] != af0[8]-be0[8])
		{diff0[9] = af0[9] - be0[9];}*/

//--------------------------------------------------------------------------	
	Simple_window win1(Point(0,200),1010,1000,"Departure times");
	Line h111(Point(10,100),Point(200,100));  // Selection sort boxes
	Line h121(Point(10,500),Point(200,500));
	Line v111(Point(10,100),Point(10,500));
	Line v121(Point(200,100),Point(200,500));
	Line h211(Point(750,100),Point(940,100));
	Line h221(Point(750,500),Point(940,500));
	Line v211(Point(750,100),Point(750,500));
	Line v221(Point(940,100),Point(940,500));
	
	Text it(Point(450,30), "Iteration");
	Text i0(Point(250,60), "1");
	Text i1(Point(300,60), "2");
	Text i2(Point(350,60), "3");
	Text i3(Point(400,60), "4");
	Text i4(Point(450,60), "5");
	Text i5(Point(500,60), "6");
	Text i6(Point(550,60), "7");
	Text i7(Point(600,60), "8");
	Text i8(Point(650,60), "9");
	Text i9(Point(700,60), "10");
	
	
	Line d0(Point(200,120), Point(250,120+40*diff1[0]));		//First unsorted flight
	Line d1(Point(250,120+40*diff1[0]), Point(300,120+40*diff1[1]));
	Line d2(Point(300,120+40*diff1[1]), Point(350,120+40*diff1[2]));
	Line d3(Point(350,120+40*diff1[2]), Point(400,120+40*diff1[3]));
	Line d4(Point(400,120+40*diff1[3]), Point(450,120+40*diff1[4]));
	Line d5(Point(450,120+40*diff1[4]), Point(500,120+40*diff1[5]));
	Line d6(Point(500,120+40*diff1[5]), Point(550,120+40*diff1[6]));
	Line d7(Point(550,120+40*diff1[6]), Point(600,120+40*diff1[7]));
	Line d8(Point(600,120+40*diff1[7]), Point(650,120+40*diff1[8]));
	Line d9(Point(650,120+40*diff1[8]), Point(700,120+40*diff1[9]));
	Line d10(Point(700,120+40*diff1[9]), Point(750,120+40*diff1[9]));
	
	Line e0(Point(200,160), Point(250,160+40*diff2[0]));		//Second unsorted flight
	Line e1(Point(250,160+40*diff2[0]), Point(300,160+40*diff2[1]));
	Line e2(Point(300,160+40*diff2[1]), Point(350,160+40*diff2[2]));
	Line e3(Point(350,160+40*diff2[2]), Point(400,160+40*diff2[3]));
	Line e4(Point(400,160+40*diff2[3]), Point(450,160+40*diff2[4]));
	Line e5(Point(450,160+40*diff2[4]), Point(500,160+40*diff2[5]));
	Line e6(Point(500,160+40*diff2[5]), Point(550,160+40*diff2[6]));
	Line e7(Point(550,160+40*diff2[6]), Point(600,160+40*diff2[7]));
	Line e8(Point(600,160+40*diff2[7]), Point(650,160+40*diff2[8]));
	Line e9(Point(650,160+40*diff2[8]), Point(700,160+40*diff2[9]));
	Line e10(Point(700,160+40*diff2[9]), Point(750,160+40*diff2[9]));
	
	Line g0(Point(200,200), Point(250,200+40*diff3[0]));		//Third sorted flight
	Line g1(Point(250,200+40*diff3[0]), Point(300,200+40*diff3[1]));
	Line g2(Point(300,200+40*diff3[1]), Point(350,200+40*diff3[2]));
	Line g3(Point(350,200+40*diff3[2]), Point(400,200+40*diff3[3]));
	Line g4(Point(400,200+40*diff3[3]), Point(450,200+40*diff3[4]));
	Line g5(Point(450,200+40*diff3[4]), Point(500,200+40*diff3[5]));
	Line g6(Point(500,200+40*diff3[5]), Point(550,200+40*diff3[6]));
	Line g7(Point(550,200+40*diff3[6]), Point(600,200+40*diff3[7]));
	Line g8(Point(600,200+40*diff3[7]), Point(650,200+40*diff3[8]));
	Line g9(Point(650,200+40*diff3[8]), Point(700,200+40*diff3[9]));
	Line g10(Point(700,200+40*diff3[9]), Point(750,200+40*diff3[9]));
	
	Line h0(Point(200,240), Point(250,240+40*diff4[0]));		//Fourth sorted flight
	Line h1(Point(250,240+40*diff4[0]), Point(300,240+40*diff4[1]));
	Line h2(Point(300,240+40*diff4[1]), Point(350,240+40*diff4[2]));
	Line h3(Point(350,240+40*diff4[2]), Point(400,240+40*diff4[3]));
	Line h4(Point(400,240+40*diff4[3]), Point(450,240+40*diff4[4]));
	Line h5(Point(450,240+40*diff4[4]), Point(500,240+40*diff4[5]));
	Line h6(Point(500,240+40*diff4[5]), Point(550,240+40*diff4[6]));
	Line h7(Point(550,240+40*diff4[6]), Point(600,240+40*diff4[7]));
	Line h8(Point(600,240+40*diff4[7]), Point(650,240+40*diff4[8]));
	Line h9(Point(650,240+40*diff4[8]), Point(700,240+40*diff4[9]));
	Line h10(Point(700,240+40*diff4[9]), Point(750,240+40*diff4[9]));
	
	Line k0(Point(200,280), Point(250,280+40*diff5[0]));		//Fifth sorted flight
	Line k1(Point(250,280+40*diff5[0]), Point(300,280+40*diff5[1]));
	Line k2(Point(300,280+40*diff5[1]), Point(350,280+40*diff5[2]));
	Line k3(Point(350,280+40*diff5[2]), Point(400,280+40*diff5[3]));
	Line k4(Point(400,280+40*diff5[3]), Point(450,280+40*diff5[4]));
	Line k5(Point(450,280+40*diff5[4]), Point(500,280+40*diff5[5]));
	Line k6(Point(500,280+40*diff5[5]), Point(550,280+40*diff5[6]));
	Line k7(Point(550,280+40*diff5[6]), Point(600,280+40*diff5[7]));
	Line k8(Point(600,280+40*diff5[7]), Point(650,280+40*diff5[8]));
	Line k9(Point(650,280+40*diff5[8]), Point(700,280+40*diff5[9]));
	Line k10(Point(700,280+40*diff5[9]), Point(750,280+40*diff5[9]));
	
	Line l0(Point(200,320), Point(250,320+40*diff6[0]));
	Line l1(Point(250,320+40*diff6[0]), Point(300,320+40*diff6[1]));
	Line l2(Point(300,320+40*diff6[1]), Point(350,320+40*diff6[2]));
	Line l3(Point(350,320+40*diff6[2]), Point(400,320+40*diff6[3]));
	Line l4(Point(400,320+40*diff6[3]), Point(450,320+40*diff6[4]));
	Line l5(Point(450,320+40*diff6[4]), Point(500,320+40*diff6[5]));
	Line l6(Point(500,320+40*diff6[5]), Point(550,320+40*diff6[6]));
	Line l7(Point(550,320+40*diff6[6]), Point(600,320+40*diff6[7]));
	Line l8(Point(600,320+40*diff6[7]), Point(650,320+40*diff6[8]));
	Line l9(Point(650,320+40*diff6[8]), Point(700,320+40*diff6[9]));
	Line l10(Point(700,320+40*diff6[9]), Point(750,320+40*diff6[9]));
	
	Line m0(Point(200,360), Point(250,360+40*diff7[0]));
	Line m1(Point(250,360+40*diff7[0]), Point(300,360+40*diff7[1]));
	Line m2(Point(300,360+40*diff7[1]), Point(350,360+40*diff7[2]));
	Line m3(Point(350,360+40*diff7[2]), Point(400,360+40*diff7[3]));
	Line m4(Point(400,360+40*diff7[3]), Point(450,360+40*diff7[4]));
	Line m5(Point(450,360+40*diff7[4]), Point(500,360+40*diff7[5]));
	Line m6(Point(500,360+40*diff7[5]), Point(550,360+40*diff7[6]));
	Line m7(Point(550,360+40*diff7[6]), Point(600,360+40*diff7[7]));
	Line m8(Point(600,360+40*diff7[7]), Point(650,360+40*diff7[8]));
	Line m9(Point(650,360+40*diff7[8]), Point(700,360+40*diff7[9]));
	Line m10(Point(700,360+40*diff7[9]), Point(750,360+40*diff7[9]));

	Line n0(Point(200,400), Point(250,400+40*diff8[0]));
	Line n1(Point(250,400+40*diff8[0]), Point(300,400+40*diff8[1]));
	Line n2(Point(300,400+40*diff8[1]), Point(350,400+40*diff8[2]));
	Line n3(Point(350,400+40*diff8[2]), Point(400,400+40*diff8[3]));
	Line n4(Point(400,400+40*diff8[3]), Point(450,400+40*diff8[4]));
	Line n5(Point(450,400+40*diff8[4]), Point(500,400+40*diff8[5]));
	Line n6(Point(500,400+40*diff8[5]), Point(550,400+40*diff8[6]));
	Line n7(Point(550,400+40*diff8[6]), Point(600,400+40*diff8[7]));
	Line n8(Point(600,400+40*diff8[7]), Point(650,400+40*diff8[8]));
	Line n9(Point(650,400+40*diff8[8]), Point(700,400+40*diff8[9]));
	Line n10(Point(700,400+40*diff8[9]), Point(750,400+40*diff8[9]));
	
	Line o0(Point(200,440), Point(250,440+40*diff9[0]));
	Line o1(Point(250,440+40*diff9[0]), Point(300,440+40*diff9[1]));
	Line o2(Point(300,440+40*diff9[1]), Point(350,440+40*diff9[2]));
	Line o3(Point(350,440+40*diff9[2]), Point(400,440+40*diff9[3]));
	Line o4(Point(400,440+40*diff9[3]), Point(450,440+40*diff9[4]));
	Line o5(Point(450,440+40*diff9[4]), Point(500,440+40*diff9[5]));
	Line o6(Point(500,440+40*diff9[5]), Point(550,440+40*diff9[6]));
	Line o7(Point(550,440+40*diff9[6]), Point(600,440+40*diff9[7]));
	Line o8(Point(600,440+40*diff9[7]), Point(650,440+40*diff9[8]));
	Line o9(Point(650,440+40*diff9[8]), Point(700,440+40*diff9[9]));
	Line o10(Point(700,440+40*diff9[9]), Point(750,440+40*diff9[9]));
	
	Line p0(Point(200,480), Point(250,480+40*diff0[0]));
	Line p1(Point(250,480+40*diff0[0]), Point(300,480+40*diff0[1]));
	Line p2(Point(300,480+40*diff0[1]), Point(350,480+40*diff0[2]));
	Line p3(Point(350,480+40*diff0[2]), Point(400,480+40*diff0[3]));
	Line p4(Point(400,480+40*diff0[3]), Point(450,480+40*diff0[4]));
	Line p5(Point(450,480+40*diff0[4]), Point(500,480+40*diff0[5]));
	Line p6(Point(500,480+40*diff0[5]), Point(550,480+40*diff0[6]));
	Line p7(Point(550,480+40*diff0[6]), Point(600,480+40*diff0[7]));
	Line p8(Point(600,480+40*diff0[7]), Point(650,480+40*diff0[8]));
	Line p9(Point(650,480+40*diff0[8]), Point(700,480+40*diff0[9]));
	Line p10(Point(700,480+40*diff0[9]), Point(750,480+40*diff0[9]));
	
	//(same, +40*whatever), Point(same, +40*whatever
	
	Line hl1(Point(10,140),Point(200,140));	//Horizontal lines (Left box)
	Line hl2(Point(10,180),Point(200,180));
	Line hl3(Point(10,220),Point(200,220));
	Line hl4(Point(10,260),Point(200,260));
	Line hl5(Point(10,300),Point(200,300));
	Line hl6(Point(10,340),Point(200,340));
	Line hl7(Point(10,380),Point(200,380));
	Line hl8(Point(10,420),Point(200,420));
	Line hl9(Point(10,460),Point(200,460));
	
	Line hr1(Point(750,140),Point(940,140));	//Horizontal lines (Right box)
	Line hr2(Point(750,180),Point(940,180));
	Line hr3(Point(750,220),Point(940,220));
	Line hr4(Point(750,260),Point(940,260));
	Line hr5(Point(750,300),Point(940,300));
	Line hr6(Point(750,340),Point(940,340));
	Line hr7(Point(750,380),Point(940,380));
	Line hr8(Point(750,420),Point(940,420));
	Line hr9(Point(750,460),Point(940,460));
	
	Text fl1(Point(20,120), fin12b[0].destin);
	Text fl2(Point(20,160), fin12b[1].destin);
	Text fl3(Point(20,200), fin12b[2].destin);
	Text fl4(Point(20,240), fin12b[3].destin);
	Text fl5(Point(20,280), fin12b[4].destin);
	Text fl6(Point(20,320), fin12b[5].destin);
	Text fl7(Point(20,360), fin12b[6].destin);
	Text fl8(Point(20,400), fin12b[7].destin);
	Text fl9(Point(20,440), fin12b[8].destin);
	Text fl0(Point(20,480), fin12b[9].destin);
	
	Text fr11(Point(820,120), fin2[0].destin);
	Text fr12(Point(820,160), fin2[1].destin);
	Text fr13(Point(820,200), fin2[2].destin);
	Text fr14(Point(820,240), fin2[3].destin);
	Text fr15(Point(820,280), fin2[4].destin);
	Text fr16(Point(820,320), fin2[5].destin);
	Text fr17(Point(820,360), fin2[6].destin);
	Text fr18(Point(820,400), fin2[7].destin);
	Text fr19(Point(820,440), fin2[8].destin);
	Text fr10(Point(820,480), fin2[9].destin);
	
	//Boxes
	win1.attach(h111);
	win1.attach(h121);
	win1.attach(h211);
	win1.attach(h221);
	win1.attach(v111);
	win1.attach(v121);
	win1.attach(v211);
	win1.attach(v221);
	
	//Dividing horizontal lines
	win1.attach(hl1);
	win1.attach(hl2);
	win1.attach(hl3);
	win1.attach(hl4);
	win1.attach(hl5);
	win1.attach(hl6);
	win1.attach(hl7);
	win1.attach(hl8);
	win1.attach(hl9);
	win1.attach(hr1);
	win1.attach(hr2);
	win1.attach(hr3);
	win1.attach(hr4);
	win1.attach(hr5);
	win1.attach(hr6);
	win1.attach(hr7);
	win1.attach(hr8);
	win1.attach(hr9);
	
	//Destinations unsorted
	win1.attach(fl1);
	win1.attach(fl2);
	win1.attach(fl3);
	win1.attach(fl4);
	win1.attach(fl5);
	win1.attach(fl6);
	win1.attach(fl7);
	win1.attach(fl8);
	win1.attach(fl9);
	win1.attach(fl0);
	
	//Destinations selection sorted
	win1.attach(fr11);
	win1.attach(fr12);
	win1.attach(fr13);
	win1.attach(fr14);
	win1.attach(fr15);
	win1.attach(fr16);
	win1.attach(fr17);
	win1.attach(fr18);
	win1.attach(fr19);
	win1.attach(fr10);
	
	win1.attach(i0);
	win1.attach(i1);
	win1.attach(i2);
	win1.attach(i3);
	win1.attach(i4);
	win1.attach(i5);
	win1.attach(i6);
	win1.attach(i7);
	win1.attach(i8);
	win1.attach(i9);
	win1.attach(it);
	
	//Departure lines
	win1.attach(d0);
	win1.attach(d1);
	win1.attach(d2);
	win1.attach(d3);
	win1.attach(d4);
	win1.attach(d5);
	win1.attach(d6);
	win1.attach(d7);
	win1.attach(d8);
	win1.attach(d9);
	win1.attach(d10);
	
	win1.attach(e0);
	win1.attach(e1);
	win1.attach(e2);
	win1.attach(e3);
	win1.attach(e4);
	win1.attach(e5);
	win1.attach(e6);
	win1.attach(e7);
	win1.attach(e8);
	win1.attach(e9);
	win1.attach(e10);
	 
	win1.attach(g0);
	win1.attach(g1);
	win1.attach(g2);
	win1.attach(g3);
	win1.attach(g4);
	win1.attach(g5);
	win1.attach(g6);
	win1.attach(g7);
	win1.attach(g8);
	win1.attach(g9);
	win1.attach(g10);
	
	win1.attach(h0);
	win1.attach(h1);
	win1.attach(h2);
	win1.attach(h3);
	win1.attach(h4);
	win1.attach(h5);
	win1.attach(h6);
	win1.attach(h7);
	win1.attach(h8);
	win1.attach(h9);
	win1.attach(h10);
	
	win1.attach(k0);
	win1.attach(k1);
	win1.attach(k2);
	win1.attach(k3);
	win1.attach(k4);
	win1.attach(k5);
	win1.attach(k6);
	win1.attach(k7);
	win1.attach(k8);
	win1.attach(k9);
	win1.attach(k10);
	
	win1.attach(l0);
	win1.attach(l1);
	win1.attach(l2);
	win1.attach(l3);
	win1.attach(l4);
	win1.attach(l5);
	win1.attach(l6);
	win1.attach(l7);
	win1.attach(l8);
	win1.attach(l9);
	win1.attach(l10);
	
	win1.attach(m0);
	win1.attach(m1);
	win1.attach(m2);
	win1.attach(m3);
	win1.attach(m4);
	win1.attach(m5);
	win1.attach(m6);
	win1.attach(m7);
	win1.attach(m8);
	win1.attach(m9);
	win1.attach(m10);
	
	win1.attach(n0);
	win1.attach(n1);
	win1.attach(n2);
	win1.attach(n3);
	win1.attach(n4);
	win1.attach(n5);
	win1.attach(n6);
	win1.attach(n7);
	win1.attach(n8);
	win1.attach(n9);
	win1.attach(n10);
	
	win1.attach(o0);
	win1.attach(o1);
	win1.attach(o2);
	win1.attach(o3);
	win1.attach(o4);
	win1.attach(o5);
	win1.attach(o6);
	win1.attach(o7);
	win1.attach(o8);
	win1.attach(o9);
	win1.attach(o10);
	
	win1.attach(p0);
	win1.attach(p1);
	win1.attach(p2);
	win1.attach(p3);
	win1.attach(p4);
	win1.attach(p5);
	win1.attach(p6);
	win1.attach(p7);
	win1.attach(p8);
	win1.attach(p9);
	win1.attach(p10);
	
	win1.wait_for_button();
	return 0;
}
