#pragma once
#include "BaseLine.h"

class KochLine : public BaseLine {
protected:
	void A(int i, int dir);

public:
	KochLine();
	virtual ~KochLine() {};
	virtual void Draw(int n);
};

class KochStarLine : public KochLine {
public:
	KochStarLine();
	virtual ~KochStarLine() {};
	virtual void Draw(int n);
};