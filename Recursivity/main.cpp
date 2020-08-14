#include <iostream>

using namespace std;

int sumaIterativa(int n, int &c)
{
	// This functions calculates the summation of 1 up to 'n'.
	// It uses an iterative method.

	if (n == 0)
	{
		return 0;
	} else
	{
		int sum = 0;
		c = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += i;
			c++;
		}
		return sum;
	}
}

int sumaDirecta(int n, int &c)
{
	// This functions calculates the summation of 1 up to 'n'.
	// It uses a recursive method.

	(n == 0) ? c=0 : c=1; 
	
	return (n*(n+1))/2; 
}

int sumaRecursiva(int n, int &c)
{
	// This functions calculates the summation of 1 up to 'n'.
	// It uses a recursive method.
	c++;
	return n <= 1 ? 1 : n + sumaRecursiva((n-1), c); 
}

int factorial(int n, int &c)
{
	// This functions calculates the factorial of an integer.
	// It uses a recursive method.
	c++; 
	return (n <= 1) ? 1 : n * factorial(n - 1, c);
}

void patronSpaces(int spaces, int &c)
{
	if (spaces == 0) 
		return;
	c++; 
	cout << " ";

	patronSpaces(spaces - 1, c);
}

void patronAsterisks(int asterisks, int &c)
{
	if (asterisks == 0) 
		return;
	c++; 
	cout << "* ";

	patronAsterisks(asterisks - 1, c);
}

void patronFigura(int n, int control, int &c)
{
	// This functions creates a command line pyramid pattern of '*'.
	// It uses a recursive method.

	if (n == 0) 
		return;
	c++;

	patronSpaces(n-1, c);
	patronAsterisks(control - n + 1, c);
	
	cout << endl; 

	patronFigura(n - 1, control, c);
}

void patronCaracteres(int n, int &c)
{
	patronFigura(n,n, c);
}

int fibonacciRecursivo(int n, int &c)
{
	// This functions calculates the fibonacci number of 'n' position.
	// It uses a recursive method.
	c++;
	return (n <= 1) ? n : fibonacciRecursivo(n - 1, c) + fibonacciRecursivo(n - 2, c);
}

double bacteriaRecursiva(double day, double population, int &c)
{
	// This functions calculates the bacteria population
	// after 'n' dates considering growth and death daily %
	// It uses a recursive method.
	c++;
	return (day < 1) ? population : bacteriaRecursiva(day-1,(population*(3.78-2.34)), c);
}

double inversionRecursiva(double month, double endmoney, int &c)
{
	// This functions calculates the 'End Amount of certain
	// investment.
	// It uses a recursive method.
	c++;
	return (month < 1) ? endmoney : inversionRecursiva(month-1,(endmoney*(1.1875)), c);
}

long potenciaRecursiva(int y, int n, int &c )
{
	// This functions calculates the result of a number
	// raised to a certain power. 
	// It uses a recursive method.
	c++;
	return (y <= 1) ? n : n*potenciaRecursiva(y-1,n, c);
}

int main()
{
	// This code shows the concept of recursion and iteration 
    // Each called function is an example of one or another 
	// Of the concepts shown. 
	int n, c, y; 
	double  time, initialBacteria = 1.00, startMoney; 

	// SUMMATIONS - Recursive, Iterative methods and formula.

	cout << "\n";

	cout << "Write the nth term for integers summation (try 1000)" << endl;
	cin >> n;

	cout << "\n";

	cout << "Iterative sum answer    : " << sumaIterativa(n, c) << endl;
	cout << "                   Pasos: " << c << endl;
	cout << "Direct sum answer       : " << sumaDirecta(n, c) << endl;
	cout << "                   Pasos: " << c << endl;
	c = 0;
	cout << "Recursive sum answer    : " << sumaRecursiva(n, c) << endl;
	cout << "                   Pasos: " << c << endl;

 	cout << "\n\n";
	
	// Factorial - Recursive.
	   // Simple program with just 1 recursive problem that was
	   // based on multiplication.
	cout << "Write the integer factorial you need (try 5)" << endl;
	cin >> n;
	cout << "\n";
	c = 0;
	cout << "The answer is           : " << factorial(n, c) << endl;
	cout << "                   Pasos: " << c << endl;

  cout << "\n\n";
	
	// Asteriks Triangle Pattern - Recursive
	   // This is a little bit complex program
	   // We had to break the problem into 3 recursive subproblem: rows, spaces, asterisks.
	   // Rows contained the subproblems of spaces and asterisks.
	cout << "How many rows of '*' do you want the triangle to be?" << endl;
	cin >> n;
	cout << "\n";
	c = 0;
	patronCaracteres(n, c);
	cout << "                   Pasos: " << c << endl;

	cout << "\n\n";
	
	// Fibonacci Term - Recursive
		 // This program was simple, induction does help.
		 // But the truth s that the implementation repeats a lot of work. 
	   // There are better ways to solve it like Dynammic Programming.
	cout << "Write the nth term you want of fibonnaci series" << endl;
	cin >> n;
	cout << "\n";
	c = 0;
	cout << fibonacciRecursivo(n, c) << endl;
	cout << "                   Pasos: " << c << endl;

	cout << "\n\n";
	
	// Bacteria's population (378% growth & 234% death rates/day) - Recursive.
		 // This program has low complexity, again just multiplication of previous number.
	cout << "Write the nth day to know the bacteria population" << endl;
	cin >> time;
	cout << "\n";
	c = 0;
	cout << bacteriaRecursiva(time, initialBacteria, c) << endl;
	cout << "                   Pasos: " << c << endl;
	
	cout << "\n\n";
	
	// Investment's End Money (18.75% Monthly Interest) - Recursive.
		 // This program has low complexity, again just multiplication of previous number.
	cout << "Write your savings so we can calculate the end amount" << endl;
	cin >> startMoney;
	cout << "\n";
	cout << "How many months will you keep it in the bank?" << endl;
	cin >> time;
	cout << "\n";
	c = 0;
	cout << inversionRecursiva(time, startMoney, c) << endl;
	cout << "                   Pasos: " << c << endl;

	// X^Y - Recursive.
		 // This program has low complexity, again just multiplication of previous number.
	cout << "Write the base number" << endl;
	cin >> n;
	cout << "\n";
	cout << "Write the exponent" << endl;
	cin >> y;
	cout << "\n";
	c = 0;
	cout << potenciaRecursiva(y, n, c) << endl;
	cout << "                   Pasos: " << c << endl;
}

	