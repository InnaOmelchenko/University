/***********************************************************************
* Module:  Bank.h
* Author:  Inna Omelchenko
* Modified: 9 окт€бр€ 2017 г. 2:31:58
* Purpose: Declaration of the class Bank
***********************************************************************/


#if !defined(__ObjectOrientedModel_1_Bank_h)
#define __ObjectOrientedModel_1_Bank_h

#include<iostream>
#include<string>
#include "Client.h"
#include "EBank.h"

using namespace std;

class Bank
{
public:
	Bank();
	Bank(string name, float currency);
	Bank(const EBank eBank);
	Bank(const Bank & bank);
	~Bank();

   void RegisterClient(Client client);
   void OpenAccount(Client client);

   string getName() const { return Name; }										// inline + const
   void setName(string name) { Name = name; }									// inline
   float getCurrencyReserve() const { return CurrencyReserve; }					// inline + const
   void setCurrencyReserve(float reserve) { CurrencyReserve = reserve; }		// inline
   EBank getEbank() const { return ElectronicBank; }							// inline + const
   void setEbank(EBank & ebank);

   void displayInfo() const { cout << "Name: " << Name << ", Reserve: " << CurrencyReserve << endl; } // inline + const

   bool isBankrupt() const { return (CurrencyReserve <= 0) ? true : false; }	// inline + const

   EBank ElectronicBank;

   // FRIENDY FUNCTION
   friend ostream& operator<< (ostream& os, const Bank bank);
   friend istream& operator>> (istream& is, Bank& bank);

   // OPERATORS
   Bank& operator= (Bank& bank);
   friend bool operator== (const Bank& left, const Bank& right);
   friend bool operator!= (const Bank& left, const Bank& right);

protected:
private:

	void changeCurrencyReserve(float delta);
   float CurrencyReserve;

   string Name;
   string Adress;

};

#endif