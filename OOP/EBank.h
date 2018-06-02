/***********************************************************************
* Module:  EBank.h
* Author:  Inna Omelchenko
* Modified: 9 окт€бр€ 2017 г. 2:45:17
* Purpose: Declaration of the class EBank
***********************************************************************/

#if !defined(__ObjectOrientedModel_1_EBank_h)
#define __ObjectOrientedModel_1_EBank_h

#include<string>
#include<iostream>
#include"Card.h"

using namespace std;

class Bank;

class EBank
{
public:
	EBank();
	EBank(string name);
	EBank(const EBank & eb);
	~EBank();

	const float creditPercent = 1.1;			// const
	static void showNumberofTransActions();		// static

   void TransferMoney(Card & card, Card & card2, float money);
   void OpenDeposite(Card & card, float money);
   void CloseDeposite(Card & card);
   void AnExtractFromCard(Card & card, float money);
   void PayForCredit(Card & card, float money);
   void TakeCredit(Card & card, float money);

   string getName() const { return Ename; }
   void setName(string name);

   void displayInfo() const { cout << "EBank name: " << Ename << endl; }	// inline + const
  // Bank ** bank;
   // FRIENDLY
   friend ostream& operator << (ostream& os, const EBank ebank);
   friend istream& operator >> (istream& is, EBank& ebank);

   // OPERATORS
   EBank& operator= (EBank& ebank);
   friend bool operator== (const EBank& left, const EBank& right);
   friend bool operator!= (const EBank& left, const EBank& right);

protected:
private:

	static int numberOfTransActions;	// static
   string Ename;
   string email;


};

#endif