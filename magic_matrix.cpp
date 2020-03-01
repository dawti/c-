#include<iostream>
using namespace std;

void display_array(int[][20], int);
int main()
{
	int ar[20][20] = { 0 };
	int i, j, n, s;
	cout << "Enter the order of matrix: ";
	cin >> n;
	cout << "\n Enter the smallest number: ";
	cin >> s;

	i = 0;
	j = (n - 1) / 2;
	ar[i][j] = s;
	for (int k = 0; k < n * n; k++)
	{
		s++;
		if (i == 0)
		{
			if (j + 1 < n)
			{
				i = n - 1;
				j = j + 1;
				ar[i][j] = s;
				continue;
			}
		}
		if (j == n - 1)
		{
			if (i > 0)
			{
				i = i - 1;
				j = 0;
				ar[i][j] = s;
				continue;
			}
		}
		if (ar[i - 1][j + 1] == 0)
		{
			if ((i < n) && (j < n))
			{
				i = i - 1;
				j = j + 1;
				ar[i][j] = s;
				continue;
			}
		}
		i = i + 1;
		ar[i][j] = s;
	}
	display_array(ar, n);
	return 0;

}

void display_array(int ar[][20], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ar[i][j] << "\t";
		}
		cout << '\n';
	}
}