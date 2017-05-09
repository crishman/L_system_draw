#pragma once
#include "BaseLine.h"
#include <vector>

extern int left_delta;
extern int right_delta;

class NakedPifagorTree : public BaseLine {
	void A(int i, int dir, int x, int y);
	std::vector<double> line_lens;

public:
	NakedPifagorTree();
	virtual ~NakedPifagorTree() {};
	virtual void Draw(int n);
};

class PifagorTree : public BaseLine {
	void A(int i, int dir, int x, int y, double len);

public:
	PifagorTree();
	virtual ~PifagorTree() {};
	virtual void Draw(int n);
};