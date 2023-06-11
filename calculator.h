#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<iostream>
using namespace std;


class calculator
{
private:
	int num, num2;

public:
    void setNumbers(int num, int num2);
    int getAddition() const;
    int getSubtraction() const;
    int getMultiplication() const;
    double getDivision() const;
};

//constructor
void calculator::setNumbers(int thisnum, int thisnum2)
{
	num = thisnum;
	num2 = thisnum2;
}

int calculator::getAddition() const
{
    // Return the sum of num and num2
    return num + num2;
}

int calculator::getSubtraction() const
{
    // Return the difference of num and num2
    return num - num2;
}

int calculator::getMultiplication() const
{
    // Return the product of num and num2
    return num * num2;
}

double calculator::getDivision() const
{
    if (num2 == 0)
    {
        // Handle division by zero error and display an error message
        cout << "Error: Division by zero is not allowed\n";
        return 0; // Return a default value to indicate an error
    }
    else
    {
        // Return the division of num by num2
        return num / num2;
    }
}


#endif