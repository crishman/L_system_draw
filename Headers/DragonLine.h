#pragma once
#include "BaseLine.h"
#include <vector>

class DragonLine : public BaseLine {
	void A(unsigned i, int dir, int x, int y);
	void B(unsigned i, int dir, int x, int y);

	std::vector<double> last_len;
public:
	DragonLine();

	virtual void Draw(unsigned n) override;
};