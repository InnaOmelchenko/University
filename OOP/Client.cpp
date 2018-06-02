/***********************************************************************
* Module:  Client.cpp
* Author:  Inna Omelchenko
* Modified: 9 окт€бр€ 2017 г. 2:37:11
* Purpose: Implementation of the class Client
***********************************************************************/

#include "Bank.h"
#include "EBank.h"
#include "Client.h"
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

int Client::numberOfClients = 0;

Client::Client() : FullName("Unknown"), PhoneNumb("Unknown"), password("0000"), GeneralDebt(), AmountOntheAcc(), AccNumb()
{
	cout << "Client created!" << endl;
}

Client::Client(string name, string number, string pass) : FullName(name), PhoneNumb(number), password(pass), GeneralDebt(), AmountOntheAcc(), AccNumb()
{
	cout << "Client " << name << " created!" << endl;
	Card card;
	ListOfCards.push_back(card);
	numberOfClients++;
}

Client::Client(const Client & clnt)
{
	FullName = clnt.FullName;
	password = clnt.password;
	ListOfCards = clnt.ListOfCards;
	PhoneNumb = clnt.PhoneNumb;
	GeneralDebt = clnt.GeneralDebt;
	numberOfClients++;
}

Client::Client(string number) : FullName("Unknown"), PhoneNumb(number), password("0000"), GeneralDebt(), AmountOntheAcc(), AccNumb()
{
	numberOfClients++;
}

Client::~Client()
{
	ListOfCards.clear();
	numberOfClients--;
}

void Client::showNumbersOfClients()
{
	cout << "Number of clients: " << numberOfClients << endl;
}

////////////////////////////////////////////////////////////////////////
// Name:       Client::AddCard()
// Purpose:    Implementation of Client::AddCard()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Client::AddCard(Card card)
{
	if (ListOfCards.size() <= maxCards)
		ListOfCards.push_back(card);
}

////////////////////////////////////////////////////////////////////////
// Name:       Client::RemoveCard()
// Purpose:    Implementation of Client::RemoveCard()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Client::RemoveCard(Card card)
{
	for (auto it = ListOfCards.begin(); it != ListOfCards.end(); it++)
	{
		if ((*it).getNumber() == card.getNumber())
			ListOfCards.erase(it);
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Client::Acces(std::string pass)
// Purpose:    Implementation of Client::Acces()
// Parameters:
// - pass
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Client::Acces(std::string pass) const
{
	return (password == pass) ? true : false;
}

/*string Client::getName()
{
	return FullName;
}

void Client::setName(string name)
{
	FullName = name;
}

string Client::getNumber()
{
	return PhoneNumb;
}

void Client::setNumber(string number)
{
	PhoneNumb = number;
} */

void Client::displayInfo()
{
	refreshGeneralDebt();
	cout << "Name: " << FullName << ", Telephone: " << PhoneNumb << " GeneralDebt: " << GeneralDebt << endl;
}

void Client::refreshGeneralDebt()
{
	GeneralDebt = 0;

	for (auto it : ListOfCards)
	{
		GeneralDebt += it.getDebt();
	}
}

Client& Client::operator=(Client& cl)
{
	GeneralDebt = cl.GeneralDebt;
	ListOfCards = cl.ListOfCards;
	FullName = cl.FullName;
	password = cl.password;
	PhoneNumb = cl.PhoneNumb;

	return *this;
}

bool operator==(const Client& cl, const Client& cl1)
{
	return cl.GeneralDebt == cl1.GeneralDebt &&
		//cl.ListOfCards. == cl1.ListOfCards &&
		cl.FullName == cl1.FullName &&
		cl.password == cl1.password &&
		cl.PhoneNumb == cl1.PhoneNumb;
}

Card &Client::operator[](int num)
{
	if (num > ListOfCards.size() - 1 || num < 0 || ListOfCards.empty())
		throw invalid_argument("Index out of range!");

	list<Card>::iterator it = ListOfCards.begin();
	int i = 0;

	for (it, i; it != ListOfCards.end(); it++, i++)
	{
		if (i == num)
			break;
	}

	return (*it);
}

ostream & operator<<(ostream & os, Client cl)
{
	cl.refreshGeneralDebt();
	return cout << "Name: " << cl.FullName << ", Telephone: " << cl.PhoneNumb << " GeneralDebt: " << cl.GeneralDebt << endl;
}

istream & operator >> (istream & is, Client& cl)
{
	cout << "Enter Client's Name/Telephone number/Password: ";
	return cin >> cl.FullName >> cl.PhoneNumb >> cl.password;
}
