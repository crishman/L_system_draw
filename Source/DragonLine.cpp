#include "stdafx.h"
#include "../Headers/DragonLine.h"
#include "../Headers/AddFunctions.h"
#include "../Headers/MakeFractal.h"

namespace fractal_lines {
	DragonLine::DragonLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect) :BaseLine(pdc, prect) {
		count_line_on_step = 2;//одна линия пораждает две
	}

	void DragonLine::A(const int& i, int&& dir, const int& last_len_size, int x, int y) {
		if (i) {
			B(i - 1, dir + 45, last_len_size, x, y);
			x += custom_math::int_round(custom_math::cos(dir + 45)*line_lens[last_len_size - i]);
			y -= custom_math::int_round(custom_math::sin(dir + 45)*line_lens[last_len_size - i]);
			A(i - 1, dir - 45, last_len_size, x, y);
		}
		else {
			SetPen(x, y);
			line(dir, line_len_);
		}
	}

	void DragonLine::B(const int& i, int&& dir, const int& last_len_size, int x, int y) {
		if (i) {
			B(i - 1, dir - 45, last_len_size, x, y);
			x += custom_math::int_round(custom_math::cos(dir - 45)*line_lens[last_len_size - i]);
			y -= custom_math::int_round(custom_math::sin(dir - 45)*line_lens[last_len_size - i]);
			A(i - 1, dir + 45, last_len_size, x, y);
		}
		else {
			A(i, std::move(dir), last_len_size, x, y);
		}
	}

	bool DragonLine::Draw(const unsigned& n) {
		if (BaseLine::Draw(n)){
			line_len_ = prect_->Width() / 3;
			auto x0 = custom_math::int_round(prect_->Width() / 2 - line_len_ / 3);
			auto y0 = custom_math::int_round(prect_->Height() / 2 + line_len_ / 4);

			auto i = 0;
			line_lens.clear();

			do {				
				ResetPen();
				if (g_bCheckLookCurLine) {
					Clear();
				}

				line_len_ = line_len_ / std::sqrt(2);
				line_lens.push_back(line_len_);
				++i;
				A(i, 0, static_cast<int>(line_lens.size()), x0, y0);
			} while (i != n);
		
			return true;
		}
		return false;
	}	
}