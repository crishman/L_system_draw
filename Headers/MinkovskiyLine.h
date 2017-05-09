#pragma once
#include "BaseLine.h"

class MinkovskiyLine : public BaseLine {
	void A(int i, int dir);

public:

	MinkovskiyLine();
	virtual ~MinkovskiyLine() {};

	virtual void Draw(int n);
};