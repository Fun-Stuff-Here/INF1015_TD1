// Exercise 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <array>
using namespace std;



//Array choisi arbitrairement
array<int, 7> myArray{ -3, 0, 5, 6, 8, 10 };

//Cette fonction demande un nombre en entrée et vérifie que l'entrée est valide.
int getValidValueToAdd()
{
	string inputValue;
	int value;
	bool isInteger = false;
	cout << "Veuillez saisir un nombre : ";
	cin >> inputValue;
	while (!isInteger)
	{
		try
		{
			value = stoi(inputValue);
			isInteger = true;
		}

		//https://en.cppreference.com/w/cpp/string/basic_string/stol pour les exceptions possibles avec stoi()
		catch (std::invalid_argument)
		{
			cout << "Veuillez saisir un nombre valide : ";
			cin >> inputValue;
		}
		catch (std::out_of_range)
		{
			cout << "Veuillez saisir un nombre valide : ";
			cin >> inputValue;
		}
	}
	return value;
}

int getIndexForNewValue(int valueToAdd)
{
	int indexForValue;
	for (int i = 0; i < myArray.max_size(); i++)
	{
		if (valueToAdd <= myArray[i])
		{
			indexForValue = i;
			break;
		}
		indexForValue = myArray.max_size() - 1;
	}
	return indexForValue;
}

void displayArray(int endIndex)
{
	for (int i = 0; i < endIndex; ++i)
	{
		cout << ' ' << myArray[i];
		if (i != endIndex - 1)
			cout << ',';
	}
	cout << '}' << endl;
}


void insertNewValue(int newValue, int indexNewValue)
{
	int nextValue = newValue;
	int tempValue;
	for (int i = indexNewValue; i < myArray.max_size(); i++)
	{
		tempValue = myArray[i];
		myArray[i] = nextValue;
		nextValue = tempValue;
	}
}

int main()
{
	cout << "Tableau avant insertion = {";
	displayArray(myArray.max_size() - 1);

	int valueToAdd = getValidValueToAdd();
	cout << "Nombre entier à insérer : " << valueToAdd << endl;

	int indexNewValue = getIndexForNewValue(valueToAdd);
	insertNewValue(valueToAdd, indexNewValue);

	cout << "Tableau après insertion = {";
	displayArray(myArray.max_size());

	return 0;
}