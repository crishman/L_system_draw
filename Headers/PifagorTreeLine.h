#pragma once
#include "BaseLine.h"
#include <vector>

extern int left_delta;
extern int right_delta;

class NakedPifagorTree : public BaseLine {
	void A(unsigned i, int dir, int x, int y);
	std::vector<double> line_lens;

public:
	NakedPifagorTree();
	virtual ~NakedPifagorTree() {};
	virtual void Draw(unsigned n) override;
};

class PifagorTree : public BaseLine {
	void A(unsigned i, int dir, int x, int y, double len);

public:
	PifagorTree();
	virtual void Draw(unsigned n) override;
};