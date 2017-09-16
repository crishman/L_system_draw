#include "stdafx.h"
#include "../Headers/HosperLine.h"
#include "../Headers/AddFunctions.h"

namespace fractal_lines {
	HosperLine::HosperLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect) :BaseLine(pdc, prect) {
		count_line_on_step = 7;//одна линия пораждает семь
	}

	void HosperLine::A(const int& i, const int& dir) {
		if (i) {
			A(i - 1, dir);
			B(i - 1, dir + 300);
			B(i - 1, dir + 180);
			A(i - 1, dir + 240);
			A(i - 1, dir);
			A(i - 1, dir);
			B(i - 1, dir + 60);
		}
		else {
			line(dir, line_len_);
		}
	}

	void HosperLine::B(const int& i, const int& dir) {
		if (i) {
			A(i - 1, dir + 60);
			B(i - 1, dir);
			B(i - 1, dir);
			B(i - 1, dir + 240);
			A(i - 1, dir + 180);
			A(i - 1, dir + 300);
			B(i - 1, dir);
		}
		else {
			line(dir, line_len_);
		}
	}

	bool HosperLine::Draw(const unsigned& n) {
		if (BaseLine::Draw(n)){
			line_len_ = prect_->Width() / 4;
			auto x0 = custom_math::int_round(prect_->Width() / 2);
			auto y0 = custom_math::int_round(prect_->Height() / 2);

			auto i = 0;

			do {				
				ResetPen();
				if (g_bCheckLookCurLine) {
					Clear();
				}
				line_len_ /= 2.5;
				if (i != 1) {
					x0 -= custom_math::int_round(line_len_*std::sqrt(3) / 2);
					y0 -= custom_math::int_round(std::move(line_len_));
				}
				SetPen(x0, y0);
				++i;
				A(i, 90);
			} while (i != n);

			return true;
		}
		return false;
	}
}