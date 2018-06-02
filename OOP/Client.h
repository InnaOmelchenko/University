/***********************************************************************
* Module:  Client.h
* Author:  Inna Omelchenko
* Modified: 9 окт€бр€ 2017 г. 2:37:11
* Purpose: Declaration of the class Client
***********************************************************************/

#if !defined(__ObjectOrientedModel_1_Client_h)
#define __ObjectOrientedModel_1_Client_h

#include<string>
#include "Card.h"
#include <list>
#include <iostream>

using namespace std;

class EBank;
class Card;

class Client
{
public:
	Client();
	Client(string name, string number, string pass);
	Client(const Client& clnt);
	Client(string number);
	~Client();

	const float maxCards = 5;	// const
	static void showNumbersOfClients();	// static number of clients 

   void AddCard(Card card);
   void RemoveCard(Card card);
   void SelectService(void);
   bool Acces(string pass) const;		// const

   string getName() const { return FullName; }				// inline + const
   void setName(string name) { FullName = name; }				// inline
   string getNumber() const { return PhoneNumb; }			// inline + const
   void setNumber(string number) { PhoneNumb = number; }	// inline

   void displayInfo();

   list<Card> ListOfCards;

   // FRIENDLY
   friend ostream& operator << (ostream& os, const Client cl);
   friend istream& operator >> (istream& is, Client& cl);

   // Operator
   Client& operator= (Client& cl);
   friend bool operator== (const Client& cl, const Client& cl1);

   // Indexer
   Card& operator[](int num);

protected:
private:

	void refreshGeneralDebt();
	static int numberOfClients;	// static

   string FullName;
   float GeneralDebt; 
   string PhoneNumb;
   string password;
   int AmountOntheAcc; 
   int AccNumb; 


};

#endif