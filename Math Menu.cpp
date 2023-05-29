#include<iostream>
#include "calculator.h"
#include<vector>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include <sstream>
#include<iomanip>
using namespace std;

void showMenu();
void showMenu1();
void showMenu2();
int factorial(int);
string solveEquation(string);

int main()
{
	int val, val2, Calchoice, numberFactorial;
	char Mainchoice, MainchoiceAgain;
	double a, b, c, x1, x2;
	char x;
	string equation=" ";

	vector<int> value;


	do
	{

		showMenu2();
		cin >> Mainchoice;

		switch (toupper(Mainchoice))
		{

		 case 'A':

			do
			{
				showMenu();
				calculator obj;

				cin >> Calchoice;

				if (Calchoice == 1)
				{
					cout << "Enter first number: ";
					cin >> val;

					cout << "enter second number: ";
					cin >> val2;

					obj.setNum(val, val2);

					cout << val << " + " << val2 << " = " << obj.getAdd() << endl;
				}
				else if (Calchoice == 2)
				{
					cout << "Enter first number: ";
					cin >> val;

					cout << "enter second number: ";
					cin >> val2;

					obj.setNum(val, val2);

					cout << val << " - " << val2 << " = " << obj.getsub() << endl;
				}
				else if (Calchoice == 3)
				{
					cout << "Enter first number: ";
					cin >> val;

					cout << "enter second number: ";
					cin >> val2;

					obj.setNum(val, val2);

					cout << val << " * " << val2 << " = " << obj.getMulti() << endl;
				}
				else if (Calchoice == 4)
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

			} while (Calchoice != 5);

			break;

		 case 'B':
			showMenu1();
			cin >> numberFactorial;


			cout << "the factorial of " << numberFactorial << "! is ";
			cout << factorial(numberFactorial) << " or ";

			for (int index = numberFactorial; index > 0; index--)
			{
				if (index == 1)
				{
					cout << index << " ";

				}
				else
				{
					cout << index << "*";

				}
			}

			cout << "\n";

			break;

		 case 'C':

			cout << "\nA quadratic equation is given as: aX^2 + bX + c = 0\n";

			float a, b, c, x1, x2, discriminant, realPart, imaginaryPart;

			cout << "Enter coefficients a, b and c:\n";
			cout << "a:";
			cin >> a;

			cout << "b:";
			cin >> b;

			cout << "c:";
			cin >> c;

			discriminant = b * b - 4 * a * c;

			if (discriminant > 0) {
				x1 = (-b + sqrt(discriminant)) / (2 * a);
				x2 = (-b - sqrt(discriminant)) / (2 * a);
				cout << "Roots are real and different." << endl;
				cout << "x1 = " << x1 << endl;
				cout << "x2 = " << x2 << endl;
			}

			else if (discriminant == 0) {
				cout << "Roots are real and same." << endl;
				x1 = -b / (2 * a);
				cout << "x1 = x2 =" << x1 << endl;
			}

			else {
				realPart = -b / (2 * a);
				imaginaryPart = sqrt(-discriminant) / (2 * a);
				cout << "Roots are complex and different." << endl;
				cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
				cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
			}

			cout << "\n";

			
			break;

		 case 'D':

			 cout << "Examples: x+2=10, 5x+8=25, 6x+5=7x-30\n";
			 cout << "Enter an equation:";
			 cin.ignore();
			 getline(cin, equation);
			 cout <<setprecision(2) << showpoint << solveEquation(equation) << endl;

			 break;

		 case 'E':
			 cout << "okay bye";
			 exit(0);

		}


		cout << "Main Menu? (y/n)";
		cin >> MainchoiceAgain;

	} while (MainchoiceAgain == 'y');

}
	

	
void showMenu()
{
	cout << "This is a calculator program.\n";
	cout << " 1) Add\n 2) Subtract\n 3) Multiply\n 4) Divide\n 5) Exit\n\n";
	cout << "Enter selection: ";
}

void showMenu1()
{
	cout << "This program caculates the factorial of any number\n ";
	cout << "Enter a number: ";
}

void showMenu2()
{
	cout << "This is math calculator program\n";
	cout << "What type of calculator do you want:";
	cout << "A) Regular Calculator\t B) Factorial Solver\t C) Quadratic Equation Solver\t D) Single-Variable Equation Solver\t E) Exit\n";
}

int factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}
}

// Function to solve the given equation
string solveEquation(string equation)
{
	float n = equation.size(), sign = 1, coeff = 0;
	float total = 0, i = 0;

	// Traverse the equation
	for (int j = 0; j < n; j++) {
		if (equation[j] == '+' || equation[j] == '-') {
			if (j > i)
				total += sign * stoi(equation.substr(i, j - i));
			i = j;
		}

		// For cases such as: x, -x, +x
		else if (equation[j] == 'x') {
			if ((i == j) || equation[j - 1] == '+')
				coeff += sign;
			else if (equation[j - 1] == '-')
				coeff -= sign;
			else
				coeff += sign * stoi(equation.substr(i, j - i));
			i = j + 1;
		}

		// Flip sign once '=' is seen
		else if (equation[j] == '=') {
			if (j > i)
				total += sign * stoi(equation.substr(i, j - i));
			sign = -1;
			i = j + 1;
		}
	}

	// There may be a number left in the end
	if (i < n)
		total += sign * stoi(equation.substr(i));

	// For infinite solutions
	if (coeff == 0 && total == 0)
		return "Infinite solutions";

	// For no solution
	if (coeff == 0 && total)
		return "No solution";

	// x = total sum / coeff of x
	// '-' sign indicates moving
	// numeric value to right hand side
	float ans = -total / coeff;
	return "x=" + to_string(ans);
}