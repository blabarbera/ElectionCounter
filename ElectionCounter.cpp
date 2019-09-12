//This program uses dynamic arrays.

#include <iostream>
#include <iomanip>
#include <string>
#include <regex>

using namespace std;

int getWinner(int votes[], int size);

int main() {

	//const to hold max size of each array
	//const int total = 5; Original code without dynamic arrays

	//declare arrays
	//string candidates[total]; Original code without dynamic arrays
	//int votes[total];
	//double percent[total];

	//declare variables
	int total, *votes;
	double sum = 0, *percent;
	int winnerIndex;
	string str; 
	string *candidates;

	cout << "Enter the number of candidates: ";
	cin >> total;
	cout << endl;

	candidates = new string[total];
	percent = new double[total];
	votes = new int[total];

	for (int i = 0; i < total; i++)
	{
		cout << "Enter the name of candidate " << (i + 1) << ": ";
		cin.ignore();
		getline(cin, str);
		candidates[i] = str;
		cout << endl;

		cout << "Enter the number of votes for " << candidates[i] << ": ";
		cin >> str;
		votes[i] = stoi(str);
		cout << endl;
	}

	//calculate the total number of votes
	for (int i = 0; i < total; i++)
	{
		sum = sum + votes[i];
	}

	//calculate the percent of votes for each candidate
	for (int i = 0; i < total; i++)
	{
		percent[i] = votes[i] / sum * 100;
	}

	for (int i = 0; i < total; i++)
	{
		if (i == 0)
		{
			cout << left << setw(15) << "Candidate" << left << setw(15) << "Votes Received" << left << setw(15) << "% of Total Votes" << endl;
			cout << left << setw(15) << candidates[i] << left << setw(15) << votes[i] << setw(15) << setprecision(2) << fixed << percent[i] << endl;
		}
		else
		{
			cout << left << setw(15) << candidates[i] << left << setw(15) << votes[i] << setw(15) << setprecision(2) << fixed << percent[i] << endl;
		}
	}

	cout << left << setw(15) << "Total" << left << setw(15) << setprecision(0) << fixed << sum << endl;

	//get winnerIndex
	winnerIndex = getWinner(votes, total);

	//show winner of election
	cout << "The Winner of the Election is " << candidates[winnerIndex] << " (" << votes[winnerIndex] << ")" << endl;

	delete [] candidates;
	delete [] votes;
	delete [] percent;

	return 0;
}

int getWinner(int votes[], int size)
{
	int max, loc = 0;
	max = votes[0];

	for (int i = 1; i < size; i++)
	{
		if (votes[i] > max)
		{
			max = votes[i];
			loc = i;
		}
	}
	return loc;
}
