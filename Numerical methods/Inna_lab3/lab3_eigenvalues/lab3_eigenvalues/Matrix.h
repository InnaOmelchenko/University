#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

class Matrix
{
private:
	int n;//������� �����(��������)
	double ** nums;//�������� �������

public:
	friend ostream & operator<<(ostream & out, const Matrix & matr);//���� �������

	Matrix();//����������� ��� ��������� ������� � �����, ��������� � �����
	Matrix(int num, bool flag = false);//����������� ��� ��������� �������� ������� (flag=true) ��� ������� ������� (flag=false)
	Matrix(const Matrix & rhs);//������������-���������
	~Matrix();//�������� �������

	int getN();//�������� ������� �����(��������) �������
	void change(int k, int m);//���� ����� �� �������� ������
	double & operator()(int i, int j);//��������� �������� ������� �� �������� [i][j]
	Matrix operator*(Matrix & rhs);//�������� �������
	Matrix & operator=(Matrix & rhs);//���������
};

#endif