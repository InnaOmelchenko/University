#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double det(double ** matrix, int n);

int main()
{
	cout << "Inna Omelchenko\t IS-61\t Lab2" << endl;
	ifstream file("file.txt");
	int n;
	file >> n;

	
	double ** matrix = new double*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[n];
	}
	double * b = new double[n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			file >> matrix[i][j];
		}
		file >> b[i];
	}
	file.close();

	cout << "Original matrix: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << "\t" << b[i] << endl;
	}
	cout << endl << endl;

	if (det(matrix, n) == 0)
	{
		cout << "determinanant = 0\ncannot solve" << endl;
		system("pause");
		exit(0);
	}

	double ** Al = new double *[n];
	for (int i = 0; i < n; i++)
	{
		Al[i] = new double[n];
	}
	double * bl = new double[n];

	double * X0 = new double[n];

	double * X = new double[n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)//���� �� ������� �� ������� �������
			{
				Al[i][j] = 1;//������ � ����� �������
			}
			else
			{
				Al[i][j] = matrix[i][j] / matrix[i][i];//�� ���� �������� ����� �� �������� ��� �������� �� ������� �������
			}
		}
		bl[i] = b[i] / matrix[i][i];//� ������ ������ ����� ��� �����
									//�� ������ ��� ���� ��� ���� �������  � �� ����� ������ �� �������� 
		X[i] = 0;//������������� ��� �� �������� ��������
		X0[i] = 0;//���� ������� ����� � ������������ �����
	}

	int k = 1;
	double max = 0;

	do
	{
		cout << "iteration " << k << endl;//�������� ������� �������� ������ ����������

		for (int i = 0; i < n; i++)
		{
			double sum = 0;
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					sum += Al[i][j] * X[j];//������ �� �������� ��� ����, �� �� ������� �������
										   //��� ������������� X[], � �� X0[], �� �� �������� ��������
										   //�� ����� ��������������� �����, �� ������� ��� �� ��� ��������
				}
			}
			X[i] = bl[i] - sum;//������� �� ���� �� �������� � ������� ������ �����
		}

		max = 0;//������� ���� ��������� �� �����, ���� �� ������� ���� ���� ���� ��� ������ � ������,
				//� ���� ����� �� ������, �� ���� ����� �� ��������� � �� ����� �� ������� � �����

		for (int i = 0; i < n; i++)
		{
			if (abs(X[i] - X0[i]) > max)
			{
				max = abs(X[i] - X0[i]);
			}
			X0[i] = X[i];
		}

		//������� ������ ����������
		for (int i = 0; i < n; i++)
		{
			cout << X[i] << "\t";
		}
		cout << "\nprecision = " << max << endl << endl;

		k++;

	} while (max > 0.001);

	cout << "\nVector X: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << X[i] << "\n";
	}
	cout << endl;

	
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] b;


	for (int i = 0; i < n; i++)
	{
		delete[] Al[i];
	}
	delete[] bl;
	delete[] X0;
	delete[] X;


	system("pause");
	return 0;
}

double det(double ** matrix, int n)
{
	if (n == 2)
	{
		return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
	}

	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		double ** temp = new double*[n-1];
		for (int k = 0; k < n - 1; k++)
		{
			temp[k] = new double[n-1];
		}

		for (int k = 1, l = 0; k < n; k++, l++)
		{
			for (int j = 0, m = 0; j < n; j++)
			{
				if (i == j)
				{
					continue;
				}
				else
				{
					temp[l][m] = matrix[k][j];
				}
				m++;
			}
		}

		sum += matrix[0][i] * pow(-1, i)*det(temp, n - 1);

		for (int k = 0; k < n - 1; k++)
		{
			delete[] temp[k];
		}
	}
	return sum;
}