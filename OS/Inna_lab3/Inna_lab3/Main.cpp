#include"System.h"

int main()
{
	cout << "enter interval: ";
	int interval;
	cin >> interval;

	cout << "enter number of queues: ";
	int num;
	cin >> num;

	System sys(interval, num);
	sys.process();

	system("pause");
	return 0;
}