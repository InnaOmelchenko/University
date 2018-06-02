#pragma once

#include<iostream>
#include<queue>
#include<time.h>
using namespace std;

struct App {
	int num;//номер заявки (потрібний для її ідентифікації)
	int length;//кількість байт, які ще треба обробити

	App(int val, int len) :num(val), length(len) {}
};

class System
{
private:
	int interval;//інтервал, з яким нові заявки приходять в систему
	int numberOfQueues;

	queue<App> * queues;//масив черг з заявками
	
	static int mainApp;//номер черги, яка зараз обслуговується
	static int val;

public:
	System(int inter, int num);
	void process();//симуляція процесу обслуговування заявок
	void show();//вивести стан черг в даний момент часу
	int findNext();//знайти чергу, що має обслуговвуватись наступною
};