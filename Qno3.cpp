#include <iostream>
#include <vector>
using namespace std;


// Q no.3_1
void primeFactorization(int num)
{
	vector<int> factors;
	while (num % 2 == 0)
	{
		factors.push_back(2);
		num /= 2;
	}

	for (int i = 3; i * i <= num; i += 2)
	{
		while (num % i == 0)
		{
			factors.push_back(i);
			num /= i;
		}
	}
	if (num > 2)
	{
		factors.push_back(num);
	}
	for (int i = 0; i < factors.size(); i++)
	{
		if (i < factors.size() - 1)
		{
			cout << factors[i] << " * ";
		}
		else
		{
			cout << factors[i];
		}
	}
}

//  Q no.3_2

int findGcd(int num1, int num2)
{
	if (num2 == 0)
	{
		return num1;
	}
	else findGcd(num2, num1 % num2);
}

// Q No.3_3

int lcm(int num1, int num2)
{
	int gcd = findGcd(num1, num2);
	return (num1 * num2) / gcd;
}

// Q No. 3_4

int bezoitCoeff(int num1, int num2, int& a, int& b)
{
	if (num2 == 0)
	{
		a = 1;
		b = 0;
		return num1;
	}
	else {
		int a1, b1;
		int gcd = bezoitCoeff(num2, num1 % num2, a1, b1);
		a = b1;
		b = a1 - (num1 / num2) * b1;
		return gcd;
	}
}

int main()
{
	// Q no. 3_1
	//primeFactorization(10);
	// *****	Q No. 3_2
	int first, second;
	/*cout << "enter gcd number 1 : "; cin >> first;
	cout << "enter gcd number 2 : "; cin >> second;
	cout << "Gcd of " << first << "and " << second << " : " << findGcd(first,second);
	*/

	// ********		Q No. 3_3

	/*cout << "Enter lcm number 1: "; cin >> first;
	cout << "Enter lcm number 2: "; cin >> second;
	cout << "Lcm of " << first << " and " << second << " is: " << lcm(first, second);*/
	int bezA, bezB;
	cout << "Enter number1 for bezoit coefficient: "; cin >> first;
	cout << "Enter number2 for bezoit coefficient: "; cin >> second;
	bezoitCoeff(first, second, bezA, bezB);
	cout << "Bezoit coefficeints are : " << bezA << " and " << bezB  << endl;
	return 0;
}