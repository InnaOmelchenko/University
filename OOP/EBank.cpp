/***********************************************************************
* Module:  EBank.cpp
* Author:  Inna Omelchenko
* Modified: 9 окт€бр€ 2017 г. 2:45:17
* Purpose: Implementation of the class EBank
***********************************************************************/

#include "Bank.h"
#include "EBank.h"
#include "Client.h"
#include "Card.h"
#include <iostream>

using namespace std;

int EBank::numberOfTransActions = 0;

EBank::EBank() 
{
	cout << "E-Bank created!" << endl;
	Ename = "Ebank";
	email = "Ebank@ukr.net";
}

EBank::EBank(string name) : Ename(name)
{
	cout << "E-bank " << name << " created!" << endl;
}


EBank::EBank(const EBank & eb) 
{
	Ename = eb.Ename;
	email = eb.email;
}

EBank::~EBank()
{

}

void EBank::showNumberofTransActions()
{
	cout << "Number of Transactions: " << numberOfTransActions << endl;
}

////////////////////////////////////////////////////////////////////////
// Name:       EBank::TransferMoney()
// Purpose:    Implementation of EBank::TransferMoney()
// Return:     void
////////////////////////////////////////////////////////////////////////

void EBank::TransferMoney(Card & card, Card & card2, float money)
{
	card.ChangeSummary(-money);
	card2.ChangeSummary(money);
	cout << "Transfer: from " << card.getNumber() << " to " << card2.getNumber() << ", was transfered " << money << "...Rest: " << card.getSummary() - card.getDebt() << endl;
	numberOfTransActions++;
}

////////////////////////////////////////////////////////////////////////
// Name:       EBank::OpenDeposite()
// Purpose:    Implementation of EBank::ShowBalance()
// Return:     void
////////////////////////////////////////////////////////////////////////

void EBank::OpenDeposite(Card & card, float money)
{
	cout << "Opened deposite with summary: " << money << endl;
	numberOfTransActions++;
}

////////////////////////////////////////////////////////////////////////
// Name:       EBank::CloseDeposite()
// Purpose:    Implementation of EBank::TransferHistory()
// Return:     void
////////////////////////////////////////////////////////////////////////

void EBank::CloseDeposite(Card & card)
{
	cout << "Deposite closed" << endl;
	numberOfTransActions++;
}


////////////////////////////////////////////////////////////////////////
// Name:       EBank::PayForCredit()
// Purpose:    Implementation of EBank::OnlineDepositeReplenishment()
// Return:     void
////////////////////////////////////////////////////////////////////////

void EBank::PayForCredit(Card & card, float money)
{
	
	card.changeDebt(-money);
	cout << "Credit: " << card.getDebt() << " was payed with " << money << "...Rest: " << card.getSummary() - card.getDebt() << endl;
	numberOfTransActions++;
}

////////////////////////////////////////////////////////////////////////
// Name:       EBank::AnExtractFromCard()
// Purpose:    Implementation of EBank::AnExtractFromCard()
// Return:     void
////////////////////////////////////////////////////////////////////////

void EBank::AnExtractFromCard(Card & card, float money)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       EBank::TakeCredit()
// Purpose:    Implementation of EBank::AnExtractFromCard()
// Return:     void
////////////////////////////////////////////////////////////////////////
void EBank::TakeCredit(Card & card, float money)
{
	card.changeDebt(money*creditPercent);
	card.ChangeSummary(money);
	cout << "Credit: " << card.getDebt() << " was taken with " << money << "...Rest: " << card.getSummary() - card.getDebt() << endl;
	numberOfTransActions++;
}

/*string EBank::getName()
{
	return Ename;
}

void EBank::setName(string name)
{
	Ename = name;
}

void EBank::displayInfo()
{
	cout << "EBank name: " << Ename << endl;
}*/
ostream & operator<<(ostream & os, const EBank ebank)
{
	return cout << "EBank name: " << ebank.Ename << endl;
}

istream & operator >> (istream & is, EBank& ebank)
{
	cout << "Enter EBank's Name: ";
	return cin >> ebank.Ename;
}

bool operator==(const EBank & left, const EBank & right)
{
	return left.Ename == right.Ename;
}

bool operator!=(const EBank & left, const EBank & right)
{
	return left.Ename != right.Ename;
}
