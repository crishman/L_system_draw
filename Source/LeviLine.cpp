#include "stdafx.h"
#include "../Headers/LeviLine.h"
#include "../Headers/AddFunctions.h"

namespace fractal_lines {
	LeviLine::LeviLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect) :BaseLine(pdc, prect) {
		count_line_on_step = 2;//���� ����� ��������� ���
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
			line_len_ = GetRectWidth() / 3;
			auto x0 = custom_math::int_round(GetRectWidth() / 2 - line_len_ / 3);
			auto y0 = custom_math::int_round(GetRectHeight() * 5 / 6);

			auto i = 0;

			do {
				ResetPen();
				if (g_bCheckLookCurLine) {
					Clear();
				}

				line_len_ = line_len_ / std::sqrt(2);
				SetPen(x0, y0);
				++i;
				A(i, 0);
			} while (i != n);

			return true;
		}
		return false;
	}
}