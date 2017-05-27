#pragma once
#include "BaseLine.h"

class KochLine : public BaseLine {
protected:
	void A(unsigned i, int dir);

public:
	KochLine();
	virtual void Draw(unsigned n) override;
};

class KochStarLine : public KochLine {
public:
	KochStarLine();
	virtual void Draw(unsigned n) override;
};