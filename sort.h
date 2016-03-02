/*	Final Project CSCE 113 - 501
	Cheng, Howard
*/

#include "flight.h"
#include "std_lib_facilities_4.h"

using namespace std;

vector<Flight>selection_sort(vector<Flight>&f)
{
	int n = f.size();
	
	cout << " " << endl;
	cout << "Departure times ordered with selection sort:" << endl;
	cout << " " << endl;
	
	
	for (int i = 0; i < n; i++)		//Repeat so every element is considered for sorting.
		{
			int min = i;
			for (int j = i+1; j < n; ++j)	//See if there is a smaller number than ith number
			{
				if (f[min].dnum > f[j].dnum)
				{
					min = j;	//Make the smallest known number the smallest number's index
				}
			}
						
			int t = f[min].dnum;		//Swap the flights
			Flight t2 = f[min];			
			f[min].dnum = f[i].dnum;
			f[min] = f[i];
			f[i].dnum = t;
			f[i] = t2;
		}
		
	for (int i = 0; i < n; i++) {cout << f[i] << endl;}
	return f;
}

	

//------------------------------------------------------------------------------------

vector<Flight>bubble_sort(vector<Flight> f)
{
	vector<Flight>f2;
	Flight fli;
	int n = f.size();

	cout << "Departure times ordered with bubble sort:" << endl;
	cout << " " << endl;
	for (int i2 = n - 1; i2 > 0; --i2)	//Traverses through vector
		{
		for (int i = 0; i < i2; ++i)
			{
				int j=i+1;	//Traverses to check if there are earlier times
				if (f[i].dnum > f[j].dnum)
					{
						int t = f[i].dnum;
						Flight t2 = f[i];
						f[i].dnum = f[j].dnum;
						f[i] = f[j];
						f[j].dnum = t;
						f[j] = t2;
					}
			}
		}
	
	for (int i = 0; i < n; ++i)
		{
			cout << f[i] << endl;
		}
		
	return f;
}

//-----------------------------------------------------------------------------------------------------------------------------------

vector<int>dnumsort(vector<Flight>f, int it)	//Used for sorting the vector flights up to a certain point
{	
	vector<int>out;	
	int n = f.size();
	for (int i = 0; i < it; ++i)
		{
			int min = i;
			for (int j = i+1; j < n; ++j)
			{
				if (f[min].dnum > f[j].dnum)
				{
					min = j;
				}
			}
						
			int t = f[min].dnum;		
			f[min].dnum = f[i].dnum;
			f[i].dnum = t;
		}
		
		for (int i = 0; i < n; ++i)
		{
			out.push_back(f[i].dnum);	//Push back the vector that is sorted to an extent

		}
	return out;
}



//-----------------------------------------------------------------------------------------------------------------------------------

int before(vector<int>&f, int d)		//Uses the returned vector above and determines the index of the flight of interest
{
	vector<int>::iterator i = f.begin();
	
	i = find(f.begin(), f.end(), d);
	int n;
	if (i != f.end())
	{
		n = distance (f.begin(), i);
		return n;
	}
		//find and return the position of the number of interest
}

//-----------------------------------------------------------------------------------------------------------------------------------

int after(vector<int>&f, int d)		//Uses the same method as the before function
{
	vector<int>::iterator i = f.begin();
	
	i = find(f.begin(), f.end(), d);
	int n;
	if (i != f.end())
	{
		n = distance (f.begin(), i);
		return n;
	}
		//find and return the position of the number of interest
}

//keep pushing back & comparing until a smaller number is found, push back the position before and after before swapping
//if not involved, push back a zero
//make sure its sorted before moving on to the next dnum of interest
//check the rest of the vector		
