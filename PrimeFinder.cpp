// PrimeFinder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    // 0, 1, and negatives are not prime
    if (n <= 1)
    {
        return false;
    }
    // All factors are less than sqrt
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// int1 can't be more than 7 digits
int concatenate(int int1, int int2)
{
    int int2_copy = int2;
    do
    {
        int1 *= 10;
        int2_copy /= 10;
    } while (int2_copy);

    return int1 + int2;
    
}

bool isNextNumber(string str, int index)
{
    if (isdigit(str[index])) return true;

    else return false;
}

vector<int> primeNumberPrinter(string str)
{
    vector<int> primes;

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if (isdigit(c))
        {
            // Turn char into int
            int currentNumber = c - '0';

            // If prime add it to primes list
            if (isPrime(currentNumber))
            {
                primes.push_back(currentNumber);
            }
            // Counter for while loop
            int counter = i + 1;
            while (isNextNumber(str, counter))
            {
                int nextNumber = str[counter] - '0';
                currentNumber = concatenate(currentNumber, nextNumber);

                if (isPrime(currentNumber))
                {
                    primes.push_back(currentNumber);
                }
                counter += 1;
            }
        }
    }
    return primes;
}


void testConcatenate()
{
    cout << "Testing concatenate" << endl;
    int num1 = 45474534;
    int num2 = 3;

    if (concatenate(num1, num2) == 454745343)
    {
        cout << "Test Passed!" << endl;
    }
    else cout << "Test Failed" << endl;
    //cout << concatenate(num1, num2) << endl;
}

void tesIsPrime()
{
    cout << "Testing isPrime" << endl;

    for (int i = 0; i < 10; i++)
    {
        if (isPrime(i))
        {
            cout << i << endl;
            printf("printf true : %d\n", true);
        }
        else
        {
            cout << i << endl;
            printf("printf false: %d\n", false);
        }
    }

}

int main()
{
    string str = "abc2134kd31";
    vector<int> primes = primeNumberPrinter(str);

    for (const auto& num : primes) {
        cout << num << " ";
    }
    cout << endl;

    // Testing
    testConcatenate();
    tesIsPrime();
}