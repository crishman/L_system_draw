#pragma once
#include "BaseLine.h"
#include <vector>

extern int left_delta;
extern int right_delta;

class NakedPifagorTree : public BaseLine {
	void A(const unsigned& i, const int& dir, int x, int y);
	std::vector<double> line_lens;

public:
	NakedPifagorTree();
	virtual ~NakedPifagorTree() = default;
	virtual void Draw(const unsigned& n) override;
};

class PifagorTree : public BaseLine {
	void A(const unsigned& i, const int& dir, int x, int y, const double& len);

public:
	PifagorTree();
	virtual ~PifagorTree() = default;
	virtual void Draw(const unsigned& n) override;
};