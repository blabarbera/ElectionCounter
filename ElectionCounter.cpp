//Instructions: Redo Programming Exercise 7 of Chapter 8 using dynamic arrays.
//The instructions have been posted for your convenience.You must
//ask the user for the number of candidates and then create the 
//appropriate arrays to hold the data.
//
//Original  Program Instructions: Write a program that allows the user 
//to enter the last names of five candidates in a local election and 
//the number of votes received by each candidate.The program should then 
//output each candidate’s name, the number of votes received, and the 
//percentage of the total votes received by the candidate.Your program 
//should also output the winner of the election.

#include <iostream>
#include <iomanip>
#include <string>
#include <regex>

using namespace std;

//Declare function to determine winner
int getWinner(int votes[], int size);

int main() {

	//const to hold max size of each array
	//const int total = 5; Original code without dynamic arrays

	//declare arrays
	//string candidates[total]; Original code without dynamic arrays
	//int votes[total];
	//double percent[total];

	//declare variables and pointers
	int total, *votes;
	double sum = 0, *percent;
	int winnerIndex;
	string str; 
	string *candidates;

	//Get total number of candidates
	cout << "Enter the number of candidates: ";
	cin >> total;
	cout << endl;

	//declare dynamic arrays according to the total number of candidates input by the user
	candidates = new string[total];
	percent = new double[total];
	votes = new int[total];

	for (int i = 0; i < total; i++)
	{
		cout << "Enter the name of candidate " << (i + 1) << ": ";
		cin.ignore(); //Flush stream before getline
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
			//Format and print header row and first row of election results
			cout << left << setw(15) << "Candidate" << left << setw(15) << "Votes Received" << left << setw(15) << "% of Total Votes" << endl;
			cout << left << setw(15) << candidates[i] << left << setw(15) << votes[i] << setw(15) << setprecision(2) << fixed << percent[i] << endl;
		}
		else
		{
			//Format and print the remaining election results
			cout << left << setw(15) << candidates[i] << left << setw(15) << votes[i] << setw(15) << setprecision(2) << fixed << percent[i] << endl;
		}
	}

	//Format and print total votes cast
	cout << left << setw(15) << "Total" << left << setw(15) << setprecision(0) << fixed << sum << endl;

	//get winnerIndex
	winnerIndex = getWinner(votes, total);

	//show winner of election
	cout << "The Winner of the Election is " << candidates[winnerIndex] << " (" << votes[winnerIndex] << ")" << endl;

	//Delete dynamic arrays from mem
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
