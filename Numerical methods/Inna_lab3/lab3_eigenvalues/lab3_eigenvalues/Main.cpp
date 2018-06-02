#include"Matrix.h"
//!!!!!!для доступу по індексу використано () замість []

int main()
{
	Matrix matrix;
	int n = matrix.getN();

	cout << "===input matrix===" << endl;
	cout << matrix << "======\n\n";

	Matrix S(n, true);//зведена матриця

	//зведення до нормальної форми Фробеніуса
	//на виході отримаємо матрицю, елементи першого ряду якої і будуть 
	//коефіцієнтами рівняння, з якого знаходимо власні числа
	for (int k = n - 2; k >= 0; k--)
	{
		Matrix B(n, true);
		Matrix B1(n, true);

		//----------------------------------------
		//обробка ситуацій, коли елемент, на який потрібно ділити дорівнює 0
		if (matrix(k + 1,k) == 0)
		{
			bool flag = false;
			for (int i = k; i >= 0; i--)//якщо зліва є ненульовий елемент
			{
				if (matrix(k + 1, i) != 0)
				{
					flag = true;
					matrix.change(k+1, i);//міняємо місцями рядки та стовпці
					break;
				}
			}
			if (!flag)//якщо всі елементи зліва = 0
			{
				cout << "you can find some of the eigenvalues by solving the equation with the following parameters" << endl;
				for (int i = k+1; i < n; i++)
				{
					cout << matrix(k + 1,i) << "\t";//виводимо коефіцієнти, отримані з матриці, вже зведеної до нормальної форми
				}
				cout << "\nTo find other eigenvalues start this program again with the following matrix" << endl;
				for (int i = 0; i < k + 1; i++)
				{
					for (int j = 0; j < k + 1; j++)
					{
						cout << matrix(i, j) << "\t";//виводимо матрицю, яку потрібно зводити далі
					}
					cout << endl;
				}
				break;
			}
		}
		//--------------------------------------

		for (int i = 0; i < n; i++)//побудова матриць S та S1
		{
			B(k,i) = -matrix(k + 1, i) / matrix(k + 1, k);
			B1(k, i) = matrix(k + 1, i);
		}
		B(k, k) = 1 / matrix(k + 1, k);

		S = S*B;//зведена матриця

		//вивід проміжних результатів
		cout << "---iteration " << n - 1 - k << "---\n";
		matrix = B1 * (matrix * B);
		cout << matrix << "------\n\n";
	}
	
	cout << "===matrix S===" << endl;
	cout << S << "======\n\n";

	//Отримавши зведену матрицю, потрібно розв*язати алгебраїчне рівняння, 
	//коефіцієнтами якого є числа з першого рядка матриці
	//Після цього отримаємо власні числа матриці, які потрібно ввести в програмy для знайдення власних векторів

	//знаходження та нормування власних векторів
	for (int k = 0; k < n; k++)
	{
		cout << "enter eigenvalue: ";
		double lambda;
		cin >> lambda;

		cout << "eigenvector " << k + 1 << endl;
		double * vec = new double[n];
		for (int i = 0; i < n; i++)
		{
			double temp = 0;
			for (int j = 0; j < n; j++)
			{
				temp += S(i, j) * pow(lambda, (n - j - 1));
			}
			vec[i] = temp;
		}

		//нормування власного ветору (всі елементи діляться на корінь з суми квадратів всіх елементів вектору)
		double temp = 0;
		for (int i = 0; i < n; i++)
		{
			temp += vec[i] * vec[i];
		}
		temp = sqrt(temp);
		for (int i = 0; i < n; i++)
		{
			cout << vec[i] / temp << endl;
		}
		cout << "-----------\n\n";
	}

	system("pause");
	return 0;
}