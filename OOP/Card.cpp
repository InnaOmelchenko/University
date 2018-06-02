/***********************************************************************
 * Module:  Card.cpp
 * Author:  Inna Omelchenko
 * Modified: 9 окт€бр€ 2017 г. 2:31:58
 * Purpose: Implementation of the class Card
 ***********************************************************************/

#include "Card.h"
#include <Windows.h>
#include <iostream>

int Card::numbersOfCards = 0;
float Card::generalTransactionSummary = 0;

void Card::TakeCredit(float money) 
{
	try 
	{
		if (money > creditLimit)
			throw exception();
		cout << "Credit: " << money << "[for 15 % - Standart card]" << endl;
	}
	catch(exception)
	{
		cout << "Credit limit error! (Standart card - " << money 
			<< ">" << creditLimit << ")" << endl;
	} 
}

Card::Card() : Number("1234 0000 5678 0000"), PIN("0000"), CIV("000")
{
	cout << "Card created!" << endl;
	DebtLimit = 0; Summary = 0;
	numbersOfCards++;
}

Card::Card(string num, string pin, string civ, float debtlimit) : Number(num), PIN(pin), CIV(civ)
{
	DebtLimit = 0; Summary = 0;
	numbersOfCards++;
}

Card::Card(string num) : Number(num), PIN("0000"), CIV("000")
{
	DebtLimit = 0; Summary = 0;
	numbersOfCards++;
}

Card::Card(const Card & card) 
{
	Number = card.Number;
	PIN = card.PIN;
	CIV = card.CIV;
	DebtLimit = card.DebtLimit;
	Summary = card.Summary;
	numbersOfCards++;
}

Card::~Card()
{
	numbersOfCards--;
}

void Card::showCardsInformation()
{
	cout << "Number of cards: " << numbersOfCards << ", General transaction summary: " << generalTransactionSummary << endl;
}

////////////////////////////////////////////////////////////////////////
// Name:       Card::changeDebt()
// Purpose:    Implementation of Card::PayOffDebt()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Card::changeDebt(float delta)
{
	if (DebtLimit + delta <= creditLimit){
		DebtLimit += delta;
		generalTransactionSummary += abs(delta);
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Card::ChangeSummary()
// Purpose:    Implementation of Card::ChangeSummary()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Card::ChangeSummary(float delta)
{
	if (Summary + delta <= moneyLimit) {
		Summary += delta;
		generalTransactionSummary += abs(delta);
	}
}
bool Card::Acces(string password) const
{
	return (PIN == password) ? true : false;
}

bool Card::AccesbyCIV(string civ) const
{
	return (civ == CIV) ? true : false;
}

/*string Card::getNumber()
{
	return Number;
}

float Card::getSummary()
{
	return Summary;
}

float Card::getDebt()
{
	return DebtLimit;
}

void Card::displayInfo()
{
	cout << "Card: Number: " << Number << ", Money: " << Summary - DebtLimit << endl;
}*/

Card& Card::operator=(Card& card1)
{
	Number = card1.Number;
	PIN = card1.PIN;
	CIV = card1.CIV;
	Summary = card1.Summary;
	DebtLimit = card1.DebtLimit;

	return *this;
}

Card & Card::operator%=(float number)
{
	Summary /= number;
	return *this;
}

Card & Card::operator&=(float number)
{
	return *this = *this & number;
}

float Card::operator()(Card & card)
{
	return card.Summary;
}

float Card::operator*(Card & card)
{
	return card.DebtLimit;
}

Card & Card::operator*=(float number)
{
	return *this = *this * number;
}

Card & Card::operator++()
{
	return *this += 1;
}

Card & Card::operator--()
{
	return *this = *this - 1;
}

Card & Card::operator+=(float number)
{
	return *this = *this + number;
}

Card & Card::operator-=(float number)
{
	return *this = *this - number;
}

Card & Card::operator->()
{
	return *this;
}

Card & Card::operator->*(Card & right)
{
	right += (*this).Summary;
	Summary = 0;
	return *this;
}

Card & Card::operator/=(float number)
{
	Summary /= number;
	return *this;
}

ostream & operator<<(ostream & os, const Card card)
{
	return cout << "Card: Number: " << card.Number << ", Money: " << card.Summary - card.DebtLimit << endl;
}

istream & operator >> (istream & is, Card& card)
{
	cout << "Enter Card's Number/PIN/CIV: ";
	return cin >> card.Number >> card.PIN >> card.CIV;
}

bool operator==(const Card & left, const Card & right)
{
	return left.Number == right.Number;
}

bool operator!=(const Card & left, const Card & right)
{
	return left.Number != right.Number;
}

Card & operator!(const Card & card)
{
	Card c = card;
	c.Summary = c.moneyLimit - c.Summary;
	return c;
}

Card & operator%(const Card & left, float number)
{
	Card c = left;
	c.Summary = c.Summary / number;
	return c;
}

Card & operator&(const Card & left, float number)
{
	Card c = left;
	c.Summary *= number;
	return c;
}

bool operator&&(const Card & left, const Card & right)
{
	return left.Summary == right.Summary;
}

bool operator||(const Card & left, const Card & right)
{
	return left.Summary != right.Summary;
}

Card & operator*(const Card & left, float number)
{
	Card c = left;
	c.Summary *= number;

	return c;
}

Card & operator+(const Card & left, float number)
{
	Card c(left);
	c.Summary += number;

	return c;
}

Card & operator+(const Card & left)
{
	Card c = left;
	return c;
}

Card & operator-(const Card & left, float number)
{
	Card c = left;
	c.Summary -= number;
	return c;
}

Card & operator-(const Card & left)
{
	Card c = left;
	c.DebtLimit += c.Summary;
	c.Summary = 0;
	return c;
}

Card & operator/(const Card & left, float number)
{
	Card c = left;
	c.Summary /= number;

	return c;
}

bool operator<(const Card & left, const Card & right)
{
	return left.Summary < right.Summary;
}

bool operator>(const Card & left, const Card & right)
{
	return left.Summary > right.Summary;
}

bool operator<=(const Card & left, const Card & right)
{
	return left.Summary <= right.Summary;
}

bool operator>=(const Card & left, const Card & right)
{
	return left.Summary >= right.Summary;
}

ostream & operator<<=(ostream & os, const Card card)
{
	return os << card;
}

istream & operator>>=(istream & is, Card & card)
{
	return is >> card;
}

Card & operator^(const Card & left, float number)
{
	return left * number;
}

Card & operator|(const Card & left, float number)
{
	return Card();
}

Card & operator~(const Card & card)
{
	return !card;
}

Card & Card::operator^=(float number)
{
	Card c = *this;
	c.Summary *= number;
	return c;
}

Card & Card::operator|=(float number)
{
	return *this = *this + number;
}

void * Card::operator new(size_t size)
{
	cout << "Memory issued" << endl;
	return malloc(size);
}

void Card::operator delete(void * p)
{
	cout << "Memory freed" << endl;
	free(p);
}