#pragma once
#include "BaseLine.h"
#include <vector>

class DragonLine : public BaseLine {
	void A(const unsigned& i, const int& dir, int x, int y);
	void B(const unsigned& i, const int& dir, int x, int y);

	std::vector<double> last_len;
public:
	DragonLine();
	virtual ~DragonLine() = default;

	virtual void Draw(const unsigned& n) override;
};