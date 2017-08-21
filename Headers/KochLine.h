#pragma once
#include "BaseLine.h"

class KochLine : public BaseLine {
protected:
	void A(const unsigned& i, const int& dir);

public:
	KochLine();
	virtual ~KochLine() = default;
	virtual void Draw(const unsigned& n) override;
};

class KochStarLine : public KochLine {
public:
	KochStarLine();
	virtual ~KochStarLine() = default;
	virtual void Draw(const unsigned& n) override;
};