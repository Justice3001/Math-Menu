#include<iostream>
#include "calculator.h"
#include<vector>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include <sstream>
#include<iomanip>
#include<cctype>
#include<limits>

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
	bool isValid = false;

	vector<int> value;
	                                           

	do
	{

		showMenu2();
		

		while (!isValid)
		{
			std::cout << "Enter a selection (A-E):";
			std::cin >> Mainchoice;

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			Mainchoice = std::tolower(Mainchoice);

			// Check if the input is within the valid range
			if (Mainchoice >= 'a' && Mainchoice <= 'e') {
				isValid = true;
			}
			else {
				std::cout << "Invalid input! Please try again." << std::endl;
			}
		}

		

	

		switch (toupper(Mainchoice)) //user can type in lowercase or uppercase character
		{

		 case 'A':

			do
			{
				showMenu();
				calculator obj;

				std::cin >> Calchoice;


				//for addition
				if (Calchoice == 1)
				{
					std::cout << "Enter first number: ";
					std::cin >> val;

					std::cout << "enter second number: ";
					std::cin >> val2;

					obj.setNum(val, val2);

					std::cout << val << " + " << val2 << " = " << obj.getAdd() << endl;
				}

				//for subtraction
				else if (Calchoice == 2)
				{
					std::cout << "Enter first number: ";
					std::cin >> val;

					std::cout << "enter second number: ";
					std::cin >> val2;

					obj.setNum(val, val2);

					std::cout << val << " - " << val2 << " = " << obj.getsub() << endl;
				}

				//for mulitplication
				else if (Calchoice == 3)
				{
					std::cout << "Enter first number: ";
					std::cin >> val;

					std::cout << "enter second number: ";
					std::cin >> val2;

					obj.setNum(val, val2);

					std::cout << val << " * " << val2 << " = " << obj.getMulti() << endl;
				}

				//for division
				else if (Calchoice == 4)
				{
					std::cout << "Enter first number: ";
					std::cin >> val;

					std::cout << "enter second number: ";
					std::cin >> val2;

					obj.setNum(val, val2);

					std::cout << val << " / " << val2 << " = " << obj.getDiv() << endl;
				}
				else
					std::cout << "okay bye!\n";

			} while (Calchoice != 5);

			break;

		 case 'B':
			showMenu1();
			std::cin >> numberFactorial;


			std::cout << "the factorial of " << numberFactorial << "! is ";
			std::cout << factorial(numberFactorial) << " or ";

			//outputs the factorial in the form n*(n-1)*(n-2)*...*1 or example: 4!=4*3*2*1
			for (int index = numberFactorial; index > 0; index--)
			{
				if (index == 1)
				{
					std::cout << index << " ";

				}
				else
				{
					std::cout << index << "*";

				}
			}

			std::cout << "\n";

			break;

		 case 'C':

			//requires understanding of quadratic equations and how to apply formula

			std::cout << "\nA quadratic equation is given as: aX^2 + bX + c = 0\n";

			float a, b, c, x1, x2, discriminant, realPart, imaginaryPart;

			std::cout << "Enter coefficients a, b and c:\n";
			std::cout << "a:";
			std::cin >> a;

			std::cout << "b:";
			std::cin >> b;

			std::cout << "c:";
			std::cin >> c;

			discriminant = b * b - 4 * a * c; //finds the discriminant or (b2 - 4ac)

			//D > 0, the roots are real and distinct
			if (discriminant > 0)
			{
				//x = [-b ± √(b2 - 4ac)]/2a (applies quadratic formula)
				// discriminant=(b2 - 4ac)
				x1 = (-b + sqrt(discriminant)) / (2 * a); 
				x2 = (-b - sqrt(discriminant)) / (2 * a);
				std::cout << "Roots are real and different." << endl;
				std::cout << "x1 = " << x1 << endl;
				std::cout << "x2 = " << x2 << endl;
			}

			//D = 0, the roots are real and equal.
			else if (discriminant == 0)
			{
				std::cout << "Roots are real and same." << endl;
				x1 = -b / (2 * a);
				std::cout << "x1 = x2 =" << x1 << endl;
			}

			//D < 0, the roots do not exist or the roots are imaginary
			else
			{
				realPart = -b / (2 * a);
				imaginaryPart = sqrt(-discriminant) / (2 * a);
				std::cout << "Roots are complex and different." << endl;
				std::cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
				std::cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
			}

			std::cout << "\n";

			
			break;

		 case 'D':
			 std::cout << "Can solve single variable equations only.\n ";
			 std::cout << "Examples: x+2=10, 5x+8=25, 6x+5=7x-30\n";
			 std::cout << "Enter an equation:";
			 std::cin.ignore();
			 getline(std::cin, equation);
			 std::cout <<setprecision(2) << showpoint << solveEquation(equation) << endl;

			 break;

		 case 'E':
			 std::cout << "okay bye";
			 exit(0);

		}


		std::cout << "Main Menu? (y/n)";
		std::cin >> MainchoiceAgain;

	} while (MainchoiceAgain == 'y');

}
	

//calculator menu
void showMenu()
{
	std::cout << "This is a calculator program.\n";
	std::cout << " 1) Add\n 2) Subtract\n 3) Multiply\n 4) Divide\n 5) Exit\n\n";
	std::cout << "Enter selection: ";
}

//factorial menu
void showMenu1()
{
	std::cout << "This program caculates the factorial of any number\n ";
	std::cout << "Enter a number: ";
}

//main menu
void showMenu2()
{
	std::cout << "This is math calculator program\n";
	std::cout << "What type of calculator do you want:\n";
	std::cout << "A) Regular Calculator\t B) Factorial Solver\t C) Quadratic Equation Solver\t D) Single-Variable Equation Solver\t E) Exit\n";
}

//Recursive function to find factorial
int factorial(int n)
{
	//base case
	if (n == 0)
	{
		return 1;
	}

	//recurive case
	else
	{
		return n * factorial(n - 1);  //fuction calls itself. n gets smaller with each call until it reaches 0.
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