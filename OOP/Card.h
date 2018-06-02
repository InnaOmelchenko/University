/***********************************************************************
 * Module:  Card.h
 * Author:  Inna Omelchenko
 * Modified: 9 октября 2017 г. 2:31:58
 * Purpose: Declaration of the class Card
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_1_Card_h)
#define __ObjectOrientedModel_1_Card_h

#include<string>
#include<iostream>

using namespace std;

class Card
{
public:
	Card();
	Card(string num, string pin, string civ, float debtlimit);
	Card(string num);
	Card(const Card& card);
	~Card();

	static void showCardsInformation();		// static

	bool Acces(std::string password) const;	// const
	bool AccesbyCIV(string civ) const;		// const

	const float creditLimit = 10000;		// const
	const float moneyLimit = 100000;		// const

	string getNumber() const { return Number; }	// inline + const
	float getSummary() const { return Summary; } // inline + const
	float getDebt() const { return DebtLimit; }		// inline + const

	bool Acces(std::string password); // Вхід до акаунта
	bool AccesbyCIV(string civ);	 // перевірка CIV

	virtual void TakeCredit(float money); 

	void displayInfo() const { cout << "Card: Number: " << Number << ", Money: " << Summary - DebtLimit << endl; } // inline + const

	void ChangeSummary(float delta);
	void changeDebt(float delta);


	// FRIENDLY
	friend ostream& operator << (ostream& os, const Card card);
	friend istream& operator >> (istream& is, Card& card);

	// Operators
	Card& operator= (Card& card1);
	friend bool operator == (const Card& left, const Card& right);
	friend bool operator != (const Card& left, const Card& right);
	friend Card& operator! (const Card& card);
	friend Card& operator% (const Card& left, float number);
	Card& operator%= (float number);
	friend Card& operator& (const Card& left, float number);
	friend bool operator && (const Card& left, const Card& right);
	friend bool operator || (const Card& left, const Card& right);
	Card& operator&= (float number);
	float operator() (Card& card);
	float operator* (Card& card);
	friend Card& operator* (const Card& left, float number);
	Card& operator*= (float number);
	friend Card& operator+ (const Card& left, float number);
	friend Card& operator+ (const Card& left);
	Card& operator++ ();
	Card& operator-- ();
	Card& operator += (float number);
	friend Card& operator- (const Card& left, float number);
	friend Card& operator- (const Card& left);
	Card& operator -= (float number);
	Card& operator-> ();
	Card& operator->* (Card& right);
	Card& operator/= (float number);
	friend Card& operator/ (const Card& left, float number);
	friend bool operator < (const Card& left, const Card& right);
	friend bool operator > (const Card& left, const Card& right);
	friend bool operator <= (const Card& left, const Card& right);
	friend bool operator >= (const Card& left, const Card& right);
	friend ostream& operator <<= (ostream& os, const Card card);
	friend istream& operator >>= (istream& is, Card& card);
	Card& operator^= (float number);
	friend Card& operator^ (const Card& left, float number);
	Card& operator|= (float number);
	friend Card& operator| (const Card& left, float number);
	friend Card& operator~ (const Card& card);

	// new && delete
	void *operator new(size_t size);
	void operator delete(void *p);


protected:
private:

	static int numbersOfCards;					// static
	static float generalTransactionSummary;		// static

	string Number;
	string PIN;
	string CIV;
	float Summary;
	float DebtLimit;


};

#endif