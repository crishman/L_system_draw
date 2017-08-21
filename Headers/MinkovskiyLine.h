#pragma once
#include "BaseLine.h"

class MinkovskiyLine : public BaseLine {
	void A(const unsigned& i, const int& dir);

public:

	MinkovskiyLine();
	virtual ~MinkovskiyLine() = default;

	virtual void Draw(const unsigned& n) override;
};