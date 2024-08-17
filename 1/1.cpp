#include <iostream>
using namespace std;
const int N = 3, M = 4; 
int main()
{
	setlocale(LC_ALL, "Russian");
	int i, j, k;
	double A[N][M] = { 10, -2, 1, 6, -3, -10, 1, -23, 4, -1, 10, 2 }, B[N], C[N][N], X[N], f, Cnorm, bnorm, Nsh, a = 0, Cmax = 0, bmax = 0;
	cout << " A:" << endl;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			cout << " " << A[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
	
	for (i = 0; i < N; i++)
	{
		f = A[i][i];
		for (j = 0; j < M; j++)
			A[i][j] /= f;
		B[i] = A[i][M - 1];
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			cout << " " << A[i][j] << "\t";
		cout << endl;
	}
	cout << endl;

	cout << endl << " C:" << endl;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i == j)
				C[i][j] = 0;
			else
				C[i][j] = A[i][j];
			cout << " " << C[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << " b:" << endl;
	for (i = 0; i < N; i++)
	{
		X[i] = 0;
		cout << " " << B[i] << endl;
	}




	for (i = 0; i < N; i++)
	{
		a = 0;
		for (j = 0; j < N; j++)
		{
			a += abs(C[i][j]);
		}
		if (Cmax < a)
			Cmax = a;
	}
	cout << "||C||inf=" << Cmax << "; ";

	for (i = 0; i < N; i++)
	{
		bmax += abs(B[i]);
	}
	cout << "||b||inf=" << bmax << "; ";

	Nsh = log((0.01 * (1 - Cmax)) / bmax) / log(Cmax) + 1;
	cout << "N=" << Nsh;


	for (i = 1; i < Nsh; i++)
	{
		cout << endl << " X[" << i << "]:" << endl;
		for (j = 0; j < N; j++)
		{
			f = B[j];
			for (k = 0; k < N; k++)
			{
				f -= X[k] * C[j][k];
			}
			X[j] = f;
			cout << X[j] << endl;
		}
	}
	return 0;
}