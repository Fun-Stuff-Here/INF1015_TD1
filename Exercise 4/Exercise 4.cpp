
#include <iostream>
#include <vector>
using namespace std;

int russianMultiplication(int firstNumber, int secondNumber)
{

    int sum = 0;
    //Matrix creation
    vector<int> multiplyMatrix[2];
    multiplyMatrix[0].push_back(firstNumber);
    multiplyMatrix[1].push_back(secondNumber);

    while (multiplyMatrix[0].back()!=1)
    {
        //c) d) add column 1 with even  value in columnn 0
        if (multiplyMatrix[0].back() % 2 != 0)
            sum += multiplyMatrix[1].back();
        //a) divide 2 for column 0 until 1 and b) multiply column 1 by 2
        multiplyMatrix[0].push_back(multiplyMatrix[0].back() / 2);
        multiplyMatrix[1].push_back(multiplyMatrix[1].back() * 2);
    }
    //last one is always kept (1%2 !=0) 
    return sum + multiplyMatrix[1].back();

}

struct test
{
    int expected;
    int result;
};


int main()
{
    //initialize tests
    int success = 0;
    const int numberOfTest = 3;
    test tests[numberOfTest] = {
        {56*78,russianMultiplication(56,78)},
        {37*129, russianMultiplication(37,129)},
        {345*987, russianMultiplication(345,987)} 
    };
    
    //run tests
    for (size_t i = 0; i < numberOfTest; i++)
    {
        success += (tests[i].expected == tests[i].result);
    }

    cout << success<<"/" << numberOfTest <<" tests passents." << endl;

}




