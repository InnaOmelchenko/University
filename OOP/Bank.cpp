/***********************************************************************
* Module:  Bank.cpp
* Author:  Inna Omelchenko
* Modified: 9 окт€бр€ 2017 г. 2:31:58
* Purpose: Implementation of the class Bank
***********************************************************************/

#include "EBank.h"
#include "Client.h"
#include "Bank.h"
#include <iostream>
#include <Windows.h>

using namespace std;

Bank::Bank() : Name("Unknow"), CurrencyReserve(0), ElectronicBank(), Adress() 
{
	cout << "Bank created!" << endl;
}


Bank::Bank(string name, float currency) : Name(name), CurrencyReserve(currency), ElectronicBank("E" + name)
{
	cout << "Bank " << name << " created!" << endl;
}

Bank::Bank(const EBank eBank) : Name("Unknow"), CurrencyReserve(0), ElectronicBank(eBank)
{

}

Bank::Bank(const Bank & bank) : Name(bank.Name), CurrencyReserve(bank.CurrencyReserve), ElectronicBank(bank.ElectronicBank)
{
}

Bank::~Bank()
{

}

////////////////////////////////////////////////////////////////////////
// Name:       Bank::RegisterClient()
// Purpose:    Implementation of Bank::RegisterClient()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Bank::RegisterClient(Client client)
{
	cout << "Client " << client.getName() << " was registered!" << endl;
}

////////////////////////////////////////////////////////////////////////
// Name:       Bank::OpenAccount()
// Purpose:    Implementation of Bank::OpenAccount()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Bank::OpenAccount(Client client)
{
	try {
		client.ListOfCards.clear();
		client.AddCard(Card("1234 5678 123 4565", "7845", "658", 0));
		cout << client.getName() << " has opened account!" << endl;
	}
	catch (exception) 
	{
		cout << client.getName() << " can not open account!" << endl;
	}
}

/*string Bank::getName()
{
	return Name;
}

void Bank::setName(string name)
{
	Name = name;
}

float Bank::getCurrencyReserve()
{
	return CurrencyReserve;
}

void Bank::setCurrencyReserve(float reserve)
{
	CurrencyReserve = reserve;
}

EBank Bank::getEbank()
{
	return ElectronicBank;
}

void Bank::setEbank(EBank & ebank)
{
	ElectronicBank = ebank.getName();
}*/

/*void Bank::displayInfo()
{
	cout << "Name: " << Name << ", Reserve: " << CurrencyReserve << endl;
}

bool Bank::isBankrupt()
{
	return (CurrencyReserve <= 0) ? true : false;
}
*/

Bank & Bank::operator=(Bank & bank)
{
	CurrencyReserve = bank.CurrencyReserve;
	Name = bank.Name;

	return (*this);
}

void Bank::changeCurrencyReserve(float delta)
{
	CurrencyReserve += delta;
}

ostream & operator<<(ostream & os, const Bank bank)
{
	return cout << "Name: " << bank.Name << ", Reserve: " << bank.CurrencyReserve << endl;
}

istream & operator >> (istream & is, Bank& bank)
{
	cout << "Enter Bank's Name/Currency Reserve: ";
	return cin >> bank.Name >> bank.CurrencyReserve;
}

bool operator==(const Bank & left, const Bank & right)
{
	return left.CurrencyReserve == right.CurrencyReserve &&
		left.Name == right.Name;
}

bool operator!=(const Bank & left, const Bank & right)
{
	return left.CurrencyReserve != right.CurrencyReserve ||
		left.Name != right.Name;
}