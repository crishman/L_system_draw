#pragma once
#include "BaseLine.h"

class SierpinskiLine : public BaseLine {
	void A(const unsigned& k);
	void B(const unsigned& k);
	void C(const unsigned& k);
	void D(const unsigned& k);

public:
	SierpinskiLine();
	virtual ~SierpinskiLine() = default;
	virtual void Draw(const unsigned& n) override;
};

class SierpinskiLine2 : public BaseLine {
	void A(const unsigned& k, const int& dir);
	void B(const unsigned& k, const int& dir);
public:
	SierpinskiLine2();
	virtual ~SierpinskiLine2() = default;
	virtual void Draw(const unsigned& n) override;
};