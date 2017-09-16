#pragma once
#include "BaseLine.h"
#include <vector>

namespace fractal_lines {
	class DragonLine : public BaseLine {
		void A(const int& i, int&& dir, const int& last_len_size, int x, int y);
		void B(const int& i, int&& dir, const int& last_len_size, int x, int y);

		std::vector<double> line_lens;
	public:
		DragonLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect);
		virtual ~DragonLine() = default;

		virtual bool Draw(const unsigned& n) override;
	};
}