#include "stdafx.h"
#include "../Headers/SierpinskiLine.h"
#include "../Headers/AddFunctions.h"

namespace fractal_lines {
	SierpinskiLine::SierpinskiLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect) :BaseLine(pdc, prect) {
		count_line_on_step = 4;//одна линия пораждает четыре
	}

	void SierpinskiLine::A(const int& k) {
		if (k) {
			A(k - 1);
			line(315, line_len_);
			B(k - 1);
			line(0, 2 * line_len_);
			D(k - 1);
			line(45, line_len_);
			A(k - 1);
		}
	}

	void SierpinskiLine::B(const int& k) {
		if (k) {
			B(k - 1);
			line(225, line_len_);
			C(k - 1);
			line(270, 2 * line_len_);
			A(k - 1);
			line(315, line_len_);
			B(k - 1);
		}
	}

	void SierpinskiLine::C(const int& k) {
		if (k) {
			C(k - 1);
			line(135, line_len_);
			D(k - 1);
			line(180, 2 * line_len_);
			B(k - 1);
			line(225, line_len_);
			C(k - 1);
		}
	}

	void SierpinskiLine::D(const int& k) {
		if (k) {
			D(k - 1);
			line(45, line_len_);
			A(k - 1);
			line(90, 2 * line_len_);
			C(k - 1);
			line(135, line_len_);
			D(k - 1);
		}
	}

	bool SierpinskiLine::Draw(const unsigned& n) {
		if (BaseLine::Draw(n)){
			line_len_ = GetRectWidth() / 8;
			auto x0 = custom_math::int_round(GetRectWidth() / 2);
			auto y0 = custom_math::int_round(GetRectHeight() / 2 - line_len_);
			auto i = 0;

			do {
				ResetPen();

				if (g_bCheckLookCurLine) {
					Clear();
				}

				x0 = custom_math::int_round(x0 - line_len_ * 7 / 9);
				line_len_ /= 2;
				y0 = custom_math::int_round(y0 - line_len_ * 4 / 5);
				SetPen(x0, y0);


				++i;
				A(i);
				line(315, line_len_);
				B(i);
				line(225, line_len_);
				C(i);
				line(135, line_len_);
				D(i);
				line(45, line_len_);
			} while (i != n);

			return true;
		}
		return false;
	}

	//Sirpinski2
	SierpinskiLine2::SierpinskiLine2(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect) :BaseLine(pdc, prect) {
		count_line_on_step = 3;//одна линия пораждает три
	}

	void SierpinskiLine2::A(const int& i, const int& dir) {
		if (i) {
			B(i - 1, dir + 60);
			A(i - 1, dir);
			B(i - 1, dir + 300);
		}
		else
			line(dir, line_len_);
	}

	void SierpinskiLine2::B(const int& i, const int& dir) {
		if (i) {
			A(i - 1, dir + 300);
			B(i - 1, dir);
			A(i - 1, dir + 60);
		}
		else
			line(dir, line_len_);
	}

	bool SierpinskiLine2::Draw(const unsigned& n) {
		if (BaseLine::Draw(n)){
			line_len_ = GetRectWidth() / 2;
			auto x0 = custom_math::int_round(GetRectWidth() / 3);
			auto y0 = custom_math::int_round(GetRectHeight() * 5 / 6);
			auto i = 0;

			do {
				ResetPen();

				if (g_bCheckLookCurLine) {
					Clear();
				}

				SetPen(x0, y0);

				A(i, 0);
				line_len_ /= 2;
				++i;
			} while (i != n);

			return true;
		}
		return false;
	}
}