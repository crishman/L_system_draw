#include "stdafx.h"
#include "../Headers/KochLine.h"
#include "../Headers/AddFunctions.h"
#include <algorithm>

namespace fractal_lines {
	KochLine::KochLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect)
		:BaseLine(pdc, prect)
		, dir_steps{ 0, 60, 300, 0 }
	{
		count_line_on_step = 4;//одна линия пораждает четыре
	}

	void KochLine::A(const int& i, const int& dir) {
		if (i) {
			auto lmbdA = [&i, &dir, this](int& dir_step) { this->A(i - 1, dir + dir_step); };
			std::for_each(dir_steps.begin(), dir_steps.end(), lmbdA);
		}
		else
			line(dir, line_len_);
	}

	bool KochLine::Draw(const unsigned& n) {
		if (BaseLine::Draw(n)){
			line_len_ = prect_->Width() * 3 / 4;
			auto x0 = custom_math::int_round(prect_->Width() / 2 - line_len_ / 2);
			auto y0 = custom_math::int_round(prect_->Height() * 2 / 3);

			auto i = 0;

			do {				
				ResetPen();
				if (g_bCheckLookCurLine) {
					Clear();
				}
				line_len_ /= 3;
				SetPen(x0, y0);
				++i;
				A(i, 0);
			} while (i != n);

			return true;
		}
		return false;
	}

	bool KochStarLine::Draw(const unsigned& n) {
		if (BaseLine::Draw(n)){
			line_len_ = prect_->Width() / 3;
			auto x0 = custom_math::int_round(prect_->Width() / 2);
			auto y0 = custom_math::int_round(prect_->Height() / 2 - line_len_ / 2);

			auto i = 0;

			std::vector<int> vdir{ 300, 180, 60 };

			do {
				ResetPen();
				if (g_bCheckLookCurLine) {
					Clear();
				}
				line_len_ /= 3;
				SetPen(x0, y0);
				++i;
				std::for_each(vdir.begin(), vdir.end(), [&i, this](int& dir) { this->A(i, dir); });
			} while (i != n);

			return true;
		}
		return false;
	}
}