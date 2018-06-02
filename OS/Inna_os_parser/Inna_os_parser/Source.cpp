#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

bool checkEmail(string str);
bool checkName(string str);
bool checkDomain(string str);

int main()
{
	vector<string> vec;

	ifstream input("input.txt");
	while (!input.eof())
	{
		string temp;
		input >> temp;
		vec.push_back(temp);
	}
	input.close();

	ofstream output("output.txt");
	output << "---VALID E-MAIL ADDRESSES---\n";
	for (int i = 0; i < vec.size(); i++)
	{
		if (checkEmail(vec[i]))
		{
			output << vec[i];
			output << "\n";
		}
	}
	output.close();

	system("pause");
	return 0;
}

bool checkEmail(string str)
{
	if (str.find('@') != std::string::npos)
	{
		if (checkName(str.substr(0, str.find('@'))) && checkDomain(str.substr(str.find('@') + 1)))
		{
			return true;
		}
	}
	return false;
}

bool checkName(string str)
{
	string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_";
	for (int i = 0; i < str.length(); i++)
	{
		if (chars.find(str[i]) == std::string::npos)
		{
			return false;
		}
	}
	return true;
}

bool checkDomain(string str)
{
	string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-.";
	for (int i = 0; i < str.length(); i++)
	{
		if (chars.find(str[i]) == std::string::npos)
		{
			return false;
		}
	}
	//
	int i = 0;
	int j = str.find('.');
	string temp = "";
	while (j != std::string::npos)
	{
		temp = str.substr(i, j - i);
		if (temp.length() == 0 || temp[0] == '-' || temp[temp.length() - 1] == '-')
		{
			return false;
		}
		
		i = ++j;
		j = str.find('.', j);
	}
	temp = str.substr(i, str.length() - i);
	if (temp.length() == 0 || temp[0] == '-' || temp[temp.length() - 1] == '-')
	{
		return false;
	}
	return true;
}