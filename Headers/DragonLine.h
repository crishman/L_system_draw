#pragma once
#include "BaseLine.h"
#include <vector>

class DragonLine : public BaseLine {
	void A(int i, int dir, int x, int y);
	void B(int i, int dir, int x, int y);

	std::vector<double> last_len;
public:
	DragonLine();
	virtual ~DragonLine() {};

	virtual void Draw(int n);
};