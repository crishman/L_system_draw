#pragma once
#include "BaseLine.h"

class HosperLine : public BaseLine {
	void A(int i, int dir);
	void B(int i, int dir);

public:
	HosperLine();
	virtual ~HosperLine() {};
	virtual void Draw(int n);
};