#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<iostream>
using namespace std;


class calculator
{
private:
	int num, num2;

public:
	void setNum(int num, int num2);
	int getAdd() const;
	int getsub() const;
	int getMulti() const;
	int getDiv() const;
};

//constructor
void calculator::setNum(int thisnum, int thisnum2)
{
	num = thisnum;
	num2 = thisnum2;
}

int calculator::getAdd() const
{
	return num + num2;
}

int calculator::getsub() const
{
	return num - num2;
}

int calculator::getMulti() const
{
	return num * num2;
}

int calculator::getDiv() const
{
	if (num2 == 0)
	{
		cout << "can not divide by zero\n";

	}

	else
	{
		return num / num2;
	}
}

#endif