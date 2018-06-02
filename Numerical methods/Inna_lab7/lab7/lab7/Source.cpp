#include<iostream>
#include<fstream>
#include<math.h>
#include<vector>
using  namespace std;

double func(double x, double y);
double r(double x);
void RungeKutta(double a, double b);
double RungeKuttaValue(double x, double y, double h);
void Adams(double a, double b);
vector<double> AdamsValue(double a, double b, double h);
double H(double x, double y, double h);

int main()
{
	double a, b;//borders
	ifstream file("file.txt");
	file >> a >> b;
	file.close();

	cout << "------Runge-Kutta method------\n\n";
	RungeKutta(a, b);
	cout << "-------------------------------\n\n";

	cout << "------Adams method------\n\n";
	Adams(a, b);
	cout << "-------------------------------\n\n";

	system("pause");
	return 0;
}

double func(double x, double y)
{
	return 1 - sin(1.4*x + y) + 1.8*y / (2 + x);
}

double r(double x)
{
	return round(x * 1000) / 1000;
}

void RungeKutta(double a, double b)
{
	//double h = H(a, b, 0.1);
	double h = 0.1;
	cout << "h = " << h << endl;
	double y = 0;
	double err = 0;
	cout << "__________________________\nx\ty\terror\n__________________________\n";
	for (double i = a; i <= b; i += h)
	{
		cout << i << "\t" << r(y) << "\t" << r(err) << endl;
		double temp = y;
		y = RungeKuttaValue(i, temp, h);
		err = RungeKuttaValue(i, temp, h / 2);
		err = (y - err) / (pow(2, 5) - 1);
	}
}

double RungeKuttaValue(double x, double y, double h)
{
	double k1 = func(x, y);
	double k2 = func(x + h / 2, y + h*k1 / 2);
	double k3 = func(x + h / 2, y + h*k2 / 2);
	double k4 = func(x + h, y + h*k3);
	return (y + h*(k1 + 2 * k2 + 2 * k3 + k4) / 6);
}

void Adams(double a, double b)
{
	//double h = H(a,b,0.1);
	double h = 0.1;
	cout << "h = " << h << endl;
	vector<double> vec = AdamsValue(a, b, h);
	vector<double> err = AdamsValue(a, b, h / 2);
	cout << "__________________________\nx\ty\terror\n__________________________\n";
	for (int i = 0; i < round((b - a) / h + 1); i++)
	{
		double error = (vec[i] - err[i]) / (pow(2, 4) - 1);
		cout << a + i*h << "\t" << r(vec[i]) << "\t" << r(error) << endl;
	}
}

vector<double> AdamsValue(double a, double b, double h)
{
	vector<double> vec = { 0 };
	for (int i = 0; i < 3; i++)
	{
		vec.push_back(RungeKuttaValue(a + i*h, vec[i], h));
	}

	for (int i = 4; i < round((b - a) / h + 1); i++)
	{
		vec.push_back(vec[i - 1] + (h / 24)*(55 * func(a + (i - 1)*h, vec[i - 1]) -
			59 * func(a + (i - 2)*h, vec[i - 2]) +
			37 * func(a + (i - 3)*h, vec[i - 3]) -
			9 * func(a + (i - 4)*h, vec[i - 4])));
	}

	for (int i = 4; i < round((b - a) / h + 1); i++)
	{
		vec[i] = vec[i - 1] + (h / 24)*(9 * func(a + i*h, vec[i]) +
			19 * func(a + (i - 1)*h, vec[i - 1]) -
			5 * func(a + (i - 2)*h, vec[i - 2]) +
			func(a + (i - 3)*h, vec[i - 3]));
	}

	return vec;
}

double H(double x, double y, double h)
{
	double k1 = func(x, y);
	double k2 = func(x + h / 2, y + h*k1 / 2);
	double k3 = func(x + h / 2, y + h*k2 / 2);

	if (abs((k2 - k3) / (k1 - k2)) <= 0.01) return h;
	else return H(x, y, h / 2);
}