#include "stdafx.h"
#include "../Headers/HilbertLine.h"
#include "../Headers/AddFunctions.h"

namespace fractal_lines {
	HilbertLine::HilbertLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect) :BaseLine(pdc, prect) {
		count_line_on_step = 4;//���� ����� ��������� ������
	}

	void HilbertLine::A(const int& i) {
		if (i) {
			D(i - 1);
			line(180, line_len_);
			A(i - 1);
			line(270, line_len_);
			A(i - 1);
			line(0, line_len_);
			B(i - 1);
		}
	}

	void HilbertLine::B(const int& i) {
		if (i) {
			C(i - 1);
			line(90, line_len_);
			B(i - 1);
			line(0, line_len_);
			B(i - 1);
			line(270, line_len_);
			A(i - 1);
		}
	}

	void HilbertLine::C(const int& i) {
		if (i) {
			B(i - 1);
			line(0, line_len_);
			C(i - 1);
			line(90, line_len_);
			C(i - 1);
			line(180, line_len_);
			D(i - 1);
		}
	}

	void HilbertLine::D(const int& i) {
		if (i) {
			A(i - 1);
			line(270, line_len_);
			D(i - 1);
			line(180, line_len_);
			D(i - 1);
			line(90, line_len_);
			C(i - 1);
		}
	}

	bool HilbertLine::Draw(const unsigned& n) {
		if (BaseLine::Draw(n)){
			line_len_ = GetRectWidth() / 2;
			auto x0 = custom_math::int_round(std::move(line_len_));
			auto y0 = custom_math::int_round(GetRectHeight() / 2);
			auto i = 0;

			do {				
				ResetPen();
				if (g_bCheckLookCurLine) {
					Clear();
				}
				line_len_ /= 2;
				x0 = custom_math::int_round(x0 + (line_len_ / 2));
				y0 = custom_math::int_round(y0 - (line_len_ / 2));
				SetPen(x0, y0);
				++i;
				A(i);
			} while (i != n);

			return true;
		}
		return false;
	}
}