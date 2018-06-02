#include"Matrix.h"
//!!!!!!��� ������� �� ������� ����������� () ������ []

int main()
{
	Matrix matrix;
	int n = matrix.getN();

	cout << "===input matrix===" << endl;
	cout << matrix << "======\n\n";

	Matrix S(n, true);//������� �������

	//�������� �� ��������� ����� ���������
	//�� ����� �������� �������, �������� ������� ���� ��� � ������ 
	//������������� �������, � ����� ��������� ����� �����
	for (int k = n - 2; k >= 0; k--)
	{
		Matrix B(n, true);
		Matrix B1(n, true);

		//----------------------------------------
		//������� ��������, ���� �������, �� ���� ������� ����� ������� 0
		if (matrix(k + 1,k) == 0)
		{
			bool flag = false;
			for (int i = k; i >= 0; i--)//���� ���� � ���������� �������
			{
				if (matrix(k + 1, i) != 0)
				{
					flag = true;
					matrix.change(k+1, i);//������ ������ ����� �� �������
					break;
				}
			}
			if (!flag)//���� �� �������� ���� = 0
			{
				cout << "you can find some of the eigenvalues by solving the equation with the following parameters" << endl;
				for (int i = k+1; i < n; i++)
				{
					cout << matrix(k + 1,i) << "\t";//�������� �����������, ������� � �������, ��� ������� �� ��������� �����
				}
				cout << "\nTo find other eigenvalues start this program again with the following matrix" << endl;
				for (int i = 0; i < k + 1; i++)
				{
					for (int j = 0; j < k + 1; j++)
					{
						cout << matrix(i, j) << "\t";//�������� �������, ��� ������� ������� ���
					}
					cout << endl;
				}
				break;
			}
		}
		//--------------------------------------

		for (int i = 0; i < n; i++)//�������� ������� S �� S1
		{
			B(k,i) = -matrix(k + 1, i) / matrix(k + 1, k);
			B1(k, i) = matrix(k + 1, i);
		}
		B(k, k) = 1 / matrix(k + 1, k);

		S = S*B;//������� �������

		//���� �������� ����������
		cout << "---iteration " << n - 1 - k << "---\n";
		matrix = B1 * (matrix * B);
		cout << matrix << "------\n\n";
	}
	
	cout << "===matrix S===" << endl;
	cout << S << "======\n\n";

	//��������� ������� �������, ������� ����*����� ���������� �������, 
	//������������� ����� � ����� � ������� ����� �������
	//ϳ��� ����� �������� ����� ����� �������, �� ������� ������ � �������y ��� ��������� ������� �������

	//����������� �� ���������� ������� �������
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

		//���������� �������� ������ (�� �������� ������� �� ����� � ���� �������� ��� �������� �������)
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