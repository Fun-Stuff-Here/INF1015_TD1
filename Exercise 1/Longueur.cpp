// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{


	size_t total = 0;
	int i = 0;
	string motCourt = "";
	string motLong = "";
	string sentence;
	size_t start=0, end = 0;


	cout << "Saisissez une phrase : " << endl;
	getline(cin, sentence);

	while (end < sentence.size())
	{
		//get mot
		string mot = "";
		end = sentence.find(" ", start);
		mot = sentence.substr(start, end-start);
		start = end + 1;

		//moyenne
		total += mot.size();
		i++;

		//petit mot
		if (i == 1)
		{
			motCourt = mot;
			motLong = mot;
		}
		else
		{
			if (motCourt.size() > mot.size())
				motCourt = mot;

			if (motLong.size() < mot.size())
				motLong = mot;
		}

	}
	
	//calcul moyenne
	double moyenne = double(total) / i;

	cout << "Le mot le plus court est : "<< motCourt << endl;
	cout << "Le mot le plus long est : " << motLong << endl;
	cout << "La longueur moyenne est : " << std::setprecision(2) << moyenne << " lettres" << endl;
}

