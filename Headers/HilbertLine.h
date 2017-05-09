#pragma once
#include "BaseLine.h"

class HilbertLine : public BaseLine {
	void A(int i);
	void B(int i);
	void C(int i);
	void D(int i);

public:
	HilbertLine();
	virtual ~HilbertLine() {};

	virtual void Draw(int n);
};