#pragma once

#include<iostream>
#include<queue>
#include<time.h>
using namespace std;

struct App {
	int num;//����� ������ (�������� ��� �� �������������)
	int length;//������� ����, �� �� ����� ��������

	App(int val, int len) :num(val), length(len) {}
};

class System
{
private:
	int interval;//��������, � ���� ��� ������ ��������� � �������
	int numberOfQueues;

	queue<App> * queues;//����� ���� � ��������
	
	static int mainApp;//����� �����, ��� ����� �������������
	static int val;

public:
	System(int inter, int num);
	void process();//��������� ������� �������������� ������
	void show();//������� ���� ���� � ����� ������ ����
	int findNext();//������ �����, �� �� ���������������� ���������
};