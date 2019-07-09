// Primes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <ctime>

using namespace std;

#define CLS "\033[2J\033[1;1H"

int main()
{
	unsigned long int x = 1, y, max;
	int loopFormat = 0;
	vector<int> listing;
	bool prime = true;
	clock_t start;

	do {
		cout << "Enter max number to test up to (Max number: " << ULONG_MAX << "): ";
		cin >> max;
	} while (max <= 0 || max > ULONG_MAX);

	start = clock();

	for (x; x <= max ; x++)
	{
		prime = true;

		cout << CLS;

		cout << "Completed: " << (((double)x / (double)max)*100) << "%\t (" << x << "/" << max << ")" << endl;

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

	cout << "The primes within limit(1::" << max << ") are:" << endl << endl;

	for (auto it = listing.begin(); it != listing.end(); it++)
	{
		loopFormat++;
		
		cout << *it;

		loopFormat = loopFormat % 15;

		if (loopFormat == 0) {
			cout << endl;
		}
		else
		{
			cout << "\t";
		}
	}

	double execution = (clock() - start) / (double)CLOCKS_PER_SEC;

	cout << endl << endl << "Execution time: " << execution << " seconds" << endl;
	system("pause");
}
