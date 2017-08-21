#pragma once
#include "BaseLine.h"

class HosperLine : public BaseLine {
	void A(const unsigned& i, const int& dir);
	void B(const unsigned& i, const int& dir);

public:
	HosperLine();
	virtual ~HosperLine() = default;
	virtual void Draw(const unsigned& n) override;
};