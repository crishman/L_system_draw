#pragma once
#include "BaseLine.h"

class MinkovskiyLine : public BaseLine {
	void A(unsigned i, int dir);

public:

	MinkovskiyLine();

	virtual void Draw(unsigned n) override;
};