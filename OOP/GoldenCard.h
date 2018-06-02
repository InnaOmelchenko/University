#pragma once
#include "Card.h"
class GoldenCard :
	public Card
{
public:
	void TakeCredit(float) override;
	void GetBenefits();

	GoldenCard();
	~GoldenCard();
};

