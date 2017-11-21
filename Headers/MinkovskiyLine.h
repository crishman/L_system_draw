#ifndef MINKOVSKIY_LINE_H
#define MINKOVSKIY_LINE_H

#include "BaseLine.h"
#include <vector>

namespace fractal_lines {
	class MinkovskiyLine : public BaseLine {
		void A(const int& i, const int& dir);
		std::vector<int> dir_steps;

	public:

		MinkovskiyLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect);
		virtual ~MinkovskiyLine() = default;

		virtual bool Draw(const unsigned& n) override;
	};
}

#endif