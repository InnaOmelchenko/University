#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

double func(double x);
double trap(double a, double b);
double gauss(double a, double b);

int main()
{
	double a, b;
	ifstream file("file.txt");
	file >> a >> b;
	file.close();

	cout << "Method of trapeziy: " << trap(a, b) << endl;
	cout << "Method of Gauss: " << gauss(a, b) << endl;

	system("pause");
	return 0;
}

double func(double x)
{
	return (x + 1)*sin(x);
}

double trap(double a, double b)
{
	int n = 1000;//number of parts
	double h = (b - a) / n;//step
	double xi = a + h;//first value
	double sum = 0;//value of the integral

	for (int i = 1; i < n-1; i++, xi+=h)
	{
		sum += func(xi);
	}
	sum *= 2;
	sum = sum + func(a) + func(b);
	sum *= h / 2;

	return sum;
}

double gauss(double a, double b)
{
	//n=5 (for maximum accuracy)
	double xs[5][2] = { {0, 128. / 225},
		{sqrt(5 - 2 * sqrt(10 / 7)) / 3, (322 + 13 * sqrt(70)) / 900},
		{-sqrt(5 - 2 * sqrt(10 / 7)) / 3, (322 + 13 * sqrt(70)) / 900},
		{sqrt(5 + 2 * sqrt(10 / 7)) / 3, (322 - 13 * sqrt(70)) / 900},
		{-sqrt(5 + 2 * sqrt(10 / 7)) / 3, (322 - 13 * sqrt(70)) / 900 } };//точки поділу відрізку

	double sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += xs[i][1] * func((b - a)*xs[i][0] / 2 + (a + b) / 2);
	}
	sum *= (b - a) / 2;

	return sum;
}