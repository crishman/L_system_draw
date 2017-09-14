#include "stdafx.h"
#include "../Headers/LeviLine.h"
#include "../Headers/AddFunctions.h"

namespace fractal_lines {
	LeviLine::LeviLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect) :BaseLine(pdc, prect) {
		count_line_on_step = 2;//одна линия пораждает две
	}

	void LeviLine::A(const int& i, const int& dir) {
		if (i) {
			A(i - 1, dir + 45);
			A(i - 1, dir - 45);
		}
		else
			line(dir, line_len_);
	}

	bool LeviLine::Draw(const unsigned& n) {
		if (BaseLine::Draw(n)){
			line_len_ = prect_->Width() / 3;
			auto x0 = custom_math::int_round(std::move(prect_->Width() / 2 - line_len_ / 3));
			auto y0 = custom_math::int_round(std::move(prect_->Height() * 5 / 6));

			auto i = 0;

			do {
				++i;
				ppen_.reset(new CPen(PS_SOLID, 1, RGB(180 - i * 15, 70, 255 - i * 15)));
				if (g_bCheckLookCurLine) {
					Clear();
				}

				line_len_ = line_len_ / std::sqrt(2);
				SetPen(x0, y0);
				A(i, 0);
			} while (i != n);

			return true;
		}
		return false;
	}
}