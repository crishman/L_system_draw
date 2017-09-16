#include "stdafx.h"
#include "../Headers/MinkovskiyLine.h"
#include "../Headers/AddFunctions.h"
#include <algorithm>

namespace fractal_lines {
	MinkovskiyLine::MinkovskiyLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect)
		:BaseLine(pdc, prect)
		, dir_steps{ 0, 90, 0, 270 }
	{
		count_line_on_step = 8;//одна линия пораждает восемь
	}

	void MinkovskiyLine::A(const int& i, const int& dir) {
		if (i) {
			auto lmbdA = [&i, &dir, this](int& dir_step) { this->A(i - 1, dir + dir_step); };
			std::for_each(dir_steps.begin(), dir_steps.end(), lmbdA);
			std::for_each(dir_steps.rbegin(), dir_steps.rend(), lmbdA);
		}
		else
			line(dir, line_len_);
	}


	bool MinkovskiyLine::Draw(const unsigned& n) {
		if (BaseLine::Draw(n)){
			line_len_ = prect_->Width() * 3 / 4;
			auto x0 = custom_math::int_round(prect_->Width() / 2 - line_len_ / 2);
			auto y0 = custom_math::int_round(prect_->Height() / 2);

			auto i = 0;

			do {				
				ResetPen();
				if (g_bCheckLookCurLine) {
					Clear();
				}
				line_len_ /= 4;
				SetPen(x0, y0);
				++i;
				A(i, 0);
			} while (i != n);

			return true;
		}
		return false;
	}
}