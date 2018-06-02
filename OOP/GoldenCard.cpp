#include "GoldenCard.h"



GoldenCard::GoldenCard()
{
}

void GoldenCard::TakeCredit(float money) 
{
	cout << "Credit: " << money << "[for 5 % - Golden card]" << endl;
}

void GoldenCard::GetBenefits() 
{
	cout << "benefits of golden card";
}

GoldenCard::~GoldenCard()
{
}
