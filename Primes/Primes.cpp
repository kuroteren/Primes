// Primes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

#define CLS "\033[2J\033[1;1H"

int main()
{
	unsigned long int x = 1, y, max;
	vector<int> listing;
	bool prime = true;

	do {
		cout << "Enter max number to test up to (Max number: " << ULONG_MAX << "): ";
		cin >> max;
	} while (max == 0);

	for (x; x <= max ; x++)
	{
		prime = true;

		cout << CLS;

		cout << "Completed: " << (double)((x / max)*100) << "%" << endl;

		for (auto it = listing.begin(); it != listing.end(); it++)
		{
			if (listing.size() == 0)
			{
				prime = true;
				break;
			}

			y = x % *it;

			if (y == 0 && *it != 1)
			{
				prime = false;
				break;
			}
		}

		if (prime)
		{
			listing.push_back(x);
		}
	}

	cout << "The primes within limit(1::" << max << ") are:" << endl;

	for (auto it = listing.begin(); it != listing.end(); it++)
	{
		cout << *it << ", ";
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
