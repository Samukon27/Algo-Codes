// lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
const int n = 4;
#include <iostream>
using namespace std;
struct IW
{
	int val;
	int weight;
};
int factorial(int n)//gets factorial of n
{
	int product = 1;
	for (int i = 1; i <= n; i++)
	{
		product = product * i;
	}
	return product;
}
int AssignmentProblem(int JobAssignment[n][n], int(&OptSolution)[n])//return Optimum time and pass by refrence the Optimum Solution
{
	int combination[n];
	for (int i = 0; i < n; i++)
	{
		combination[i] = i;
	}
	int curmin = 0, min = 999999;
	for (int i = 0; i < factorial(n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			curmin = curmin + JobAssignment[j][combination[j]];
		}
		if (curmin < min)
		{
			min = curmin;
			for (int k = 0; k < n; k++)
			{
				OptSolution[k] = combination[k];
			}
		}
		curmin = 0;
		swap(combination[i % (n - 1)], combination[(i % (n - 1)) + 1]);
	}
	return min;
}
int TSP(int Graph[n][n], int StartPos, int(&optPath)[n + 1])//return Optimum distance and pass by refrence the Optimum Path
{
	int combination[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		if (i >= StartPos)
		{
			combination[i] = i + 1;
		}
		else
		{
			combination[i] = i;
		}
	}
	int curmin = 0, min = 999999;
	for (int i = 0; i < factorial(n - 1); i++)
	{
		curmin = curmin + Graph[StartPos][combination[0]] + Graph[combination[n - 2]][StartPos];
		for (int j = 0; j < n - 2; j++)
		{
			curmin = curmin + Graph[combination[j]][combination[j + 1]];
		}
		cout << curmin << endl;
		if (curmin < min)
		{
			min = curmin;
			for (int k = 0; k < n; k++)
			{
				optPath[k + 1] = combination[k];
			}
		}
		curmin = 0;
		swap(combination[i % (n - 2)], combination[(i % (n - 2)) + 1]);
	}
	optPath[0] = StartPos;
	optPath[n] = StartPos;
	return min;
}
int KnapSack(IW ItemWeight[n], int(&optSolution)[n], int maxweight)//return Optimum value and pass by refrence the Optimum Solution
{
	int combination[n];
	int counter = 0;
	int bestcounter;
	for (int i = 0; i < n; i++)
	{
		combination[i] = i;
	}
	int CurWeight = 0;
	int curmax = 0, max = 0;
	for (int i = 0; i < factorial(n); i++)
	{
		CurWeight = 0;
		for (int j = 0; j < n; j++)
		{
			if ((CurWeight + ItemWeight[combination[j]].weight) <= maxweight)
			{
				curmax = curmax + ItemWeight[combination[j]].val;
				counter++;
			}
			CurWeight = CurWeight + ItemWeight[combination[j]].weight;
		}
		if (curmax > max)
		{
			max = curmax;
			bestcounter = counter;
			for (int k = 0; k < bestcounter; k++)
			{
				optSolution[k] = combination[k];
			}
		}
		counter = 0;
		curmax = 0;
		swap(combination[i % (n - 1)], combination[(i % (n - 1)) + 1]);
	}
	return max;
}
int main()
{
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
