//***********************************************************************************
// Karp-Rabin
//
// Created by Sebastian Wozniak on 2017.05.09
// Finished on 2017.06.04
//
//
//***********************************************************************************

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void KarpRabin(string pattern_, string data_);
void Read();
long long Power(long long x, unsigned long long y);

int main()
{
	Read();

	return 0;
}

void KarpRabin(string pattern_, string data_)
{
	string pattern = pattern_;
	string data = data_;
	const long alphabet = 256;
	unsigned long long patternValue = 0;
	unsigned long long checkingWordValue = 0;


	patternValue = (long long)pattern[0];
	checkingWordValue = (long long)data[0];

	for (long long i = 1; i < pattern.size(); i++)
	{
		patternValue = ((patternValue * alphabet) % alphabet) + (long long)pattern[i];
		checkingWordValue = ((checkingWordValue * alphabet) % alphabet) + (long long)data[i];
	}


	for (long long i = 0; i < data.size() - pattern.size() + 1; i++)
	{
		if (checkingWordValue == patternValue)
		{
			for (long long j = 0; j < pattern.size(); j++)
			{
				if (data[i + j] == pattern[j])
				{
					if (j == (pattern.size() - 1))
					{
						cout << i << " ";
					}
				}
				else
				{
					break;
				}
			}
		}

		checkingWordValue = checkingWordValue - ((long long)data[i] * (Power(alphabet, (pattern.size() - 1))));
		checkingWordValue = checkingWordValue * alphabet;
		checkingWordValue = checkingWordValue % alphabet;
		checkingWordValue = checkingWordValue + data[i + pattern.size()];
	}
	cout << endl;
}

long long Power(long long x, unsigned long long y)
{
	for (long i = 0; i < y; i++)
	{
		x *= x;
	}

	return x;
}

void Read()
{
	long numTest;
	cin >> numTest;
	string fileName, pattern, data;
	
	cin.ignore();

	for (long i = 0; i < numTest; i++)
	{
		getline(cin, fileName);
		getline(cin, pattern);

		ifstream input(fileName);

		if (!input.good())
		{
			return;
		}

		getline(input, data);

		input.close();
		
		KarpRabin(pattern, data);
	}
}