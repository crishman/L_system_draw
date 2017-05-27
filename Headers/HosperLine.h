#pragma once
#include "BaseLine.h"

class HosperLine : public BaseLine {
	void A(unsigned i, int dir);
	void B(unsigned i, int dir);

public:
	HosperLine();
	virtual void Draw(unsigned n) override;
};