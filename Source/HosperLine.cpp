#include "stdafx.h"
#include "../Headers/HosperLine.h"
#include "../Headers/AddFunctions.h"

namespace fractal_lines {
	HosperLine::HosperLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect) :BaseLine(pdc, prect) {
		count_line_on_step = 7;//���� ����� ��������� ����
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

	void HosperLine::Draw(const unsigned& n) {
		BaseLine::Draw(n);
		if (prect_ != nullptr) {
			Clear();
			line_len_ = prect_->Width() / 4;
			auto x0 = custom_math::int_round(std::move(prect_->Width() / 2));
			auto y0 = custom_math::int_round(std::move(prect_->Height() / 2));

			auto i = 0;

			do {
				++i;
				ppen_.reset(new CPen(PS_SOLID, 1, RGB(40, 210 - i * 10, 111 + i * 20)));
				if (g_bCheckLookCurLine) {
					Clear();
				}
				line_len_ /= 2.5;
				if (i != 1) {
					x0 -= custom_math::int_round(std::move(line_len_*std::sqrt(3) / 2));
					y0 -= custom_math::int_round(std::move(line_len_));
				}
				SetPen(x0, y0);
				A(i, 90);
			} while (i != n);
		}
	}
}