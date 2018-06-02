#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

void showMatrix(int n, double ** matrix, double * b);//outputtin the system
inline double precision(double num);

int main()
{
	ifstream file("file.txt");
	int n;//number of vars
	file >> n;

	//creating matrix and vector
	double ** matrix = new double*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[n];
	}
	double * b = new double[n];

	//reading matrix and vector from file
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			file >> matrix[i][j];
		}
		file >> b[i];
	}
	file.close();

	showMatrix(n, matrix, b);

	//building matrix T-----------------------------
	double ** T = new double*[n];
	for (int i = 0; i < n; i++)
	{
		T[i] = new double[n];
	}

	//working with first row
	T[0][0] = precision(sqrt(matrix[0][0]));
	for (int i = 1; i < n; i++)
	{
		T[0][i] = precision(matrix[0][i] / T[0][0]);
	}

	//working with all other rows
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				double sum = 0;
				for (int k = 0; k < i; k++)
				{
					sum += T[k][i] * T[k][i];
				}

				T[i][i] = precision(sqrt(matrix[i][i] - sum));
			}
			else if (i < j)
			{
				double sum = 0;
				for (int k = 0; k < i; k++)
				{
					sum += T[k][i] * T[k][j];
				}
				T[i][j] = precision((matrix[i][j] - sum) / T[i][i]);
			}
			else
			{
				T[i][j] = 0;
			}
		}
	}

	//show T
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << T[i][j] << "\t";
		}
		cout << endl;
	}*/
	//----------------------------------------------

	//going backwards
	double * y = new double[n];
	double * x = new double[n];

	y[0] = precision(b[0] / T[0][0]);
	for (int i = 1; i < n; i++)
	{
		double sum = 0;
		for (int j = 0; j < i; j++)
		{
			sum += T[j][i] * y[j];
		}
		y[i] = precision((b[i] - sum) / T[i][i]);
	}

	//showing y
	/*for (int i = 0; i < n; i++)
	{
		cout << y[i] << endl;
	}
	cout << "__________" << endl;*/

	x[n - 1] = precision(y[n - 1] / T[n - 1][n - 1]);
	for (int i = n - 2; i >= 0; i--)
	{
		double sum = 0;
		for (int j = i + 1; j < n; j++)
		{
			sum += T[i][j] * x[j];
		}
		x[i] = precision((y[i] - sum) / T[i][i]);
	}

	//showing results
	for (int i = 0; i < n; i++)
	{
		cout << x[i] << endl;
	}
	//----------------------------------------------

	//deleting matrices and vectors
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
		delete[] T[i];
	}
	delete[] b;
	delete[] y;
	delete[] x;

	system("pause");
	return 0;
}

void showMatrix(int n, double ** matrix, double * b)
{
	cout << "______________________\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << b[i] << endl;
	}
	cout << "_______________________\n\n";
}

double precision(double num)
{
	return ((round(num * 1000)) / 1000);
}