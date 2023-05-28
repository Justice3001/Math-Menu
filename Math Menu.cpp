#include<iostream>
#include "calculator.h"
using namespace std;

void showMenu();

int main()
{
	int val, val2, choice;

	calculator obj;

	do
	{
		showMenu();

		cin >> choice;

		if (choice == 1)
		{
			cout << "Enter first number: ";
			cin >> val;

			cout << "enter second number: ";
			cin >> val2;

			obj.setNum(val, val2);

			cout << val << " + " << val2 << " = " << obj.getAdd() << endl;
		}
		else if (choice == 2)
		{
			cout << "Enter first number: ";
			cin >> val;

			cout << "enter second number: ";
			cin >> val2;

			obj.setNum(val, val2);

			cout << val << " - " << val2 << " = " << obj.getsub() << endl;
		}
		else if (choice == 3)
		{
			cout << "Enter first number: ";
			cin >> val;

			cout << "enter second number: ";
			cin >> val2;

			obj.setNum(val, val2);

			cout << val << " * " << val2 << " = " << obj.getMulti() << endl;
		}
		else if (choice == 4)
		{
			cout << "Enter first number: ";
			cin >> val;

			cout << "enter second number: ";
			cin >> val2;

			obj.setNum(val, val2);

			cout << val << " / " << val2 << " = " << obj.getDiv() << endl;
		}
		else
			cout << "okay bye!\n";

	} while (choice != 5);
}

void showMenu()
{
	cout << "This is a calculator program.\n";
	cout << " 1) Add\n 2) Subtract\n 3) Multiply\n 4) Divide\n 5) Exit\n";
	cout << "Enter selection: ";
}