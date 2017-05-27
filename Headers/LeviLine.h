#pragma once
#include "BaseLine.h"

class LeviLine : public BaseLine {

	void A(unsigned i, int dir);

public:
	LeviLine();

	virtual void Draw(unsigned n) override;
};