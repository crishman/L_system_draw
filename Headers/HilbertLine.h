#pragma once
#include "BaseLine.h"

class HilbertLine : public BaseLine {
	void A(const unsigned& i);
	void B(const unsigned& i);
	void C(const unsigned& i);
	void D(const unsigned& i);

public:
	HilbertLine();
	virtual ~HilbertLine() = default;

	virtual void Draw(const unsigned& n) override;
};