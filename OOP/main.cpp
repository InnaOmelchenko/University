#include<iostream>
#include<conio.h>
#include"Bank.h"
#include"Client.h"
#include"EBank.h"
#include"Card.h"
#include"GoldenCard.h"

using namespace std;

int main()
{
	cout << "Inna Omelchenko. IS-61. Version 5" << endl;
	cout << "Modeling started..." << endl;
	Bank bank;
	Client cl;
	Card card = Card();
	GoldenCard golden = GoldenCard();
	cl.AddCard(card);
	cl.AddCard(golden);
	//base card take credit
	card.TakeCredit(1000);
	//golden card ovveride take credit
	golden.TakeCredit(1000);
	card.TakeCredit(200000); 

	cout << endl << "Initialization using friend overloaded << and >> operations: " << endl;
	cin >> bank >> bank.ElectronicBank >> cl >> cl.ListOfCards.begin().operator*();

	cout << endl << bank << bank.ElectronicBank << cl << cl.ListOfCards.begin().operator*() << endl;
	cout << "For demonstrasion we will using overloaded operators to 2 Cards, please enter 2 Cards: " << endl;
	Card c1, c2, c3; Card *heap;
	cout << "First: " << endl;
	cin >> c1;
	cout << "Second: " << endl;
	cin >> c2;
	
	cout << "Operator new and delete: " << endl;
	heap = new Card;
	delete heap;
	cout << endl << "operator= : " << (c3 = c1) << endl;
	cout << "operator== : " << (c3 == c1) << endl;
	cout << "operator[]: set value of [0] to 1000 UAH: "; cl[0].ChangeSummary(1000);
	cout << endl << "operator[]: get value of [0]: " << cl[0] << endl;
	cout << endl << "End of modeling..." << endl;

	system("pause");

	return 0;
}