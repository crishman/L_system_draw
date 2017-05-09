#pragma once
#include "BaseLine.h"

class SierpinskiLine : public BaseLine {
	void A(int k);
	void B(int k);
	void C(int k);
	void D(int k);

public:
	SierpinskiLine();
	virtual ~SierpinskiLine() {};
	void Draw(int n);
};

class SierpinskiLine2 : public BaseLine {
	void A(int k, int dir);
	void B(int k, int dir);
public:
	SierpinskiLine2();
	virtual ~SierpinskiLine2() {};
	virtual void Draw(int n);
};