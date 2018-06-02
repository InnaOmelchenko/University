#include"Matrix.h"

double precision(double num)
{
	num = (int)(num*1000);
	return num/1000;
}

ostream & operator<<(ostream & out, const Matrix & matr)
{
	for (int i = 0; i < matr.n; i++)
	{
		for (int j = 0; j < matr.n; j++)
		{
			cout << precision(matr.nums[i][j]) << "\t";
		}
		cout << endl;
	}
	return out;
}

Matrix::Matrix()
{
	ifstream file("file.txt");
	file >> n;
	nums = new double*[n];
	for (int i = 0; i < n; i++)
	{
		nums[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			file >> nums[i][j];
		}
	}
	file.close();
}

Matrix::Matrix(const Matrix & rhs)
{
	n = rhs.n;
	nums = new double*[n];
	for (int i = 0; i < n; i++)
	{
		nums[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			nums[i][j] = rhs.nums[i][j];
		}
	}
}

Matrix::Matrix(int num, bool flag)
{
	n = num;
	nums = new double*[n];
	for (int i = 0; i < n; i++)
	{
		nums[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			nums[i][j] = 0;
			if (flag && i == j)
			{
				nums[i][j] = 1;
			}
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < n; i++)
	{
		delete[] nums[i];
	}
}

int Matrix::getN()
{
	return n;
}

void Matrix::change(int k, int m)
{
	for (int i = 0; i < n; i++)//change rows
	{
		double temp = nums[k][i];
		nums[k][i] = nums[k][m];
		nums[k][m] = temp;
	}
	for (int i = 0; i < n; i++)//change columns
	{
		double temp = nums[i][k];
		nums[i][k] = nums[i][m];
		nums[i][m] = temp;
	}
}

double & Matrix::operator()(int i, int j)
{
	return nums[i][j];
}

Matrix Matrix::operator*(Matrix & rhs)
{
	Matrix temp(n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int m = 0; m < n; m++)
			{
				temp.nums[i][j] += nums[i][m] * rhs(m,j);
			}
		}
	}

	return temp;
}

Matrix & Matrix::operator=(Matrix & rhs)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			nums[i][j] = rhs(i, j);
		}
	}
	return *this;
}