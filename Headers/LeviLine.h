#pragma once
#include "BaseLine.h"

class LeviLine : public BaseLine {

	void A(const unsigned& i, const int& dir);

public:
	LeviLine();
	virtual ~LeviLine() = default;

	virtual void Draw(const unsigned& n) override;
};