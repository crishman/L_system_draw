#pragma once
#include "BaseLine.h"

class HilbertLine : public BaseLine {
	void A(unsigned i);
	void B(unsigned i);
	void C(unsigned i);
	void D(unsigned i);

public:
	HilbertLine();

	virtual void Draw(unsigned n) override;
};