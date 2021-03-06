/*by from tkariclook*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <climits>
#include <sstream>
using namespace std;
double sma(int64_t i)
{
	double temp = 0;
	for (int64_t n = 0; n <= i; n++)
		temp += n;
	return temp / i;
}

double std_deviation(double var)
{
	if (var == 1)
		return  0;
	else {
		double sum = 0;
		double mean = sma(var);
		size_t i;
		for (i = 1; i <= var; i++)
			sum += (i - mean) * (i - mean);
		return sqrt(sum / (var - 1));
	}
}

int main()
{
	// make file for work if it  absent 
	/*ofstream myfile;
	myfile.open("new.tsv");
	for(int64_t i=1;i<10000002;i++)
	myfile << i<<"\n";
	myfile.close();
	*/
	ifstream infile;
	ofstream outfile;
	string fileloc = "new.tsv";//variance_calc.tsv  too mush for my system
	infile.open(fileloc);
	if (!infile)
	{
		cout << "open fail" << endl;
	}
	double x = 0;
	int64_t i = 0;
	string s;
	while (getline(infile, s))
	{
		i++;
		stringstream geek(s);
		geek >> x;
		if (i == 1 || i == 100 || i == 1000000 || i == 500000000) {
			cout << "sma #" << i << " " << sma(x) << "\n";
			cout << "std #" << i << " " << std_deviation(x) << "\n";
		}
	}
	infile.close();
	cin.get();
	return 0;

}