
#include <iostream>
#include <vector>
using namespace std;

int russianMultiplication(int firstNumber, int secondNumber)
{

    int sum = 0;

    while (firstNumber!=1)
    {
        //c) d) add column 1 with even  value in columnn 0
        if (firstNumber % 2 != 0)
            sum += secondNumber;
        //a) divide 2 for column 0 until 1 and b) multiply column 1 by 2 bit manipulation
        //https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
        firstNumber >> 1;
        secondNumber << 1;
    }
    //last one is always kept (1%2 !=0) 
    return sum + secondNumber;

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




