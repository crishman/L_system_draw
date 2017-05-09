#pragma once
#include "BaseLine.h"

class LeviLine : public BaseLine {

	void A(int i, int dir);

public:
	LeviLine();
	virtual ~LeviLine() {};

	virtual void Draw(int n);
};