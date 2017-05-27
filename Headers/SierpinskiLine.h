#pragma once
#include "BaseLine.h"

class SierpinskiLine : public BaseLine {
	void A(unsigned k);
	void B(unsigned k);
	void C(unsigned k);
	void D(unsigned k);

public:
	SierpinskiLine();
	virtual void Draw(unsigned n) override;
};

class SierpinskiLine2 : public BaseLine {
	void A(unsigned k, int dir);
	void B(unsigned k, int dir);
public:
	SierpinskiLine2();
	virtual void Draw(unsigned n) override;
};