#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

long long **G,**S;

void przypisanie(int n)
{
	G = new long long *[n];
	S = new long long* [n];
	for (int i = 0; i < n; i++)
	{
		G[i] = new long long[n];
		S[i] = new long long[n];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			G[i][j] = 0;
			S[i][j] = 0;
		}
	}
}

int Sum(int a, int b)
{
	if (a > 0 && b > 0)
		return 1;
	else
		return 0;
}
int M(int a, int b)
{
	if (a == 0 && b == 0)
		return 0;
	else
		return 1;
}

void losowanie(int n)
{
	cout << "Prawdopodobienstwo wystapienia krawedzi(0-100%)";
	int p;
	cin >> p;
	srand(time(NULL));
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			int a = (rand() % 101);
			if(a<=p)
				G[i][j] = 1;
			else
				G[i][j] = 0;
		}
	}
}

void Floyd_warshall(int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			S[i][j] = G[i][j];
			if (i == j)
				S[i][j] = 1;
		}
	}
	for (int k = 1; k < n; k++)
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				S[i][j] = M(S[i][j], Sum(S[i][k], S[k][j]));
				//S[i][j] = M(S[i][j], (S[i][k] && S[k][j]));
			}
		}
	}
}

int main()
{
	int n = 0;
	char choice = 1;
	cout << "1: Wlasny graf\n";
	cout << "2: Losowy graf\n";
	cout << "3: Wypisanie istniejacego grafu\n";
	cout << "4: Macierz sasiedztwa\n";
	cout << "0: Exit\n";
	while (choice != 48)
	{
		cin >> choice;
		switch (choice)
		{
		case 49:
		{
			cout << "Podaj wielkosc Grafu(1-4): ";
			while (n > 4 || n < 1)
				cin >> n;

			n = n + 1;
			przypisanie(n);
			int a;
			for(int x=1;x<n;x++)
				for (int y = 1; y < n; y++)
				{
					cout << "Podaj element Grafu["<<x<<"]["<<y<<"]: ";
					cin >> a;
					G[x][y] = a;
				}
		}
		break;
		case 50:
		{
			cout << "Podaj wielkosc Grafu: ";
			while (n < 1)
				cin >> n;

			n = n + 1;
			przypisanie(n);
			losowanie(n);
		}
		break;
		case 51:
		{
			for (int i = 1; i < n; i++)
			{
				for (int j = 1; j < n; j++)
				{
					cout << G[i][j] << " ";
				}
				cout << endl;
			}
		}
		break;
		case 52:
		{
			Floyd_warshall(n);
			for (int i = 1; i < n; i++)
			{
				for (int j = 1; j < n; j++)
				{
					cout << S[i][j] << " ";
				}
				cout << endl;
			}
		}
		break;
		case 48:
			break;
		default:
			cout << "Bledna opcja " << endl;
			break;
		}
	}
}
