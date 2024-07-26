#include <iostream>
#include <vector>
using namespace std;

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

int main()
{
    primeFactorization(10);
    return 0;
}