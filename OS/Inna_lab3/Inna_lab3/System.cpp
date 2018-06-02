#include"System.h"

int System::val = 1;
int System::mainApp = 0;

System::System(int inter, int num)
	:interval(inter),
	numberOfQueues(num)
{
	queues = new queue<App>[numberOfQueues];
}

void System::process()
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < 20; i++)
	{
		if (i%interval == 0)//якщо з*явилась нова заявка
		{
			int num = rand() % numberOfQueues;
			App app(val, rand() % 10 + 1);
			val++;
			queues[num].push(app);
			cout << "New app created (number " << val-1 << ") with length: " << app.length << endl;
		}

		mainApp = findNext();//номер черги, яка зараз обслуговується
		if (mainApp == -1) return;
		queues[mainApp].front().length--;
		if (queues[mainApp].front().length <= 0)
		{
			queues[mainApp].pop();//видалення заявки, що вже обслужена
			mainApp = 0;
		}

		show();
		cout << "________________________________________________\n";
	}
}

void System::show()
{
	if (!queues[mainApp].empty())
	{
		cout << "Now working with app number " << queues[mainApp].front().num << endl << endl;
	}

	for (int i = 0; i < numberOfQueues; i++)
	{
		cout << "===queue " << i << "===" << endl;
		queue<App> temp = queues[i];
		while (!temp.empty())
		{
			cout << temp.front().num << " with following length " << temp.front().length << endl;
			temp.pop();
		}
		cout << endl;
	}
}

int System::findNext()
{
	if (mainApp == 0)
	{
		for (int i = 0; i < numberOfQueues; i++)
		{
			if (!queues[i].empty()) return i;
		}
		cout << "No more apps to deal with" << endl;
		return -1;
	}
	else
	{
		return mainApp;
	}
}