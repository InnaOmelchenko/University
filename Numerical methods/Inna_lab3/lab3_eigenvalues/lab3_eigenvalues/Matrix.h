#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

class Matrix
{
private:
	int n;//кількість рядків(стовпців)
	double ** nums;//елементи матриці

public:
	friend ostream & operator<<(ostream & out, const Matrix & matr);//вивід матриці

	Matrix();//конструктор для створення матриці з даних, отриманих з файлу
	Matrix(int num, bool flag = false);//конструктор для ствоерння одиничної матриці (flag=true) або нульової матриці (flag=false)
	Matrix(const Matrix & rhs);//контструктор-копіювання
	~Matrix();//зничення матриці

	int getN();//отримати кількість рядків(стовпців) матриці
	void change(int k, int m);//зміна рядків та стовпців місцями
	double & operator()(int i, int j);//отримання елементу матриці за індексом [i][j]
	Matrix operator*(Matrix & rhs);//множення матриць
	Matrix & operator=(Matrix & rhs);//присвоєння
};

#endif