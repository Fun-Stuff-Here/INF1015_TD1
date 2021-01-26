#include <iostream>
#include <iomanip>
using namespace std;


double calculateLimit(int precision)
{
	double term = 1;
	double nextTerm = sqrt(term + 2);
	double precisionFactor = pow(0.1, precision);

	while (abs(term - nextTerm) > precisionFactor)
	{
		term = nextTerm;
		nextTerm = sqrt(term + 2);
	}
	return nextTerm;
}


int main()
{
	int precision = 5;
	double limit = calculateLimit(precision);


	double truncatedLimit = trunc(limit * pow(10, precision)) / pow(10, precision);

	cout << "La limite arondie de la suite à " << precision << " décimales près est ";
	cout << fixed << setprecision(precision);
	cout << limit << endl;

	cout << "La limite tronquée de la suite à " << precision << " décimales près est ";
	cout << truncatedLimit;
	return 0;
}