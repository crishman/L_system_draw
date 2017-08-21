#include "stdafx.h"
#include "../Headers/HosperLine.h"

HosperLine::HosperLine() :BaseLine() {
	count_line_on_step = 7;//���� ����� ��������� ����
}

void HosperLine::A(unsigned i, int dir) {
	if (i) {
		A(i - 1, dir);
		B(i - 1, dir + 300);
		B(i - 1, dir + 180);
		A(i - 1, dir + 240);
		A(i - 1, dir);
		A(i - 1, dir);
		B(i - 1, dir + 60);
	}else {
		line(dir, line_len);		
	}
}

void HosperLine::B(unsigned i, int dir) {
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
		line(dir, line_len);		
	}
}

void HosperLine::Draw(unsigned n) {
	BaseLine::Draw(n);
	if (p_rect != nullptr) {
		Clear();
		line_len = p_rect->Width() / 4;
		auto x0 = (int)std::round(p_rect->Width() / 2);
		auto y0 = (int)std::round(p_rect->Height() / 2);

		decltype(n) i = 0;

		do {
			++i;
			cur_pen.reset(new CPen(PS_SOLID, 1, RGB(40, 210 - i * 10, 111 + i * 20)));
			if (g_bCheckLookCurLine) {
				Clear();
				if (i ^ n)
					g_isCurDrawLine = FALSE;
			}
			line_len /= 2.5;	
			if (i ^ 1) {
				x0 -= (int)std::round(line_len*std::sqrt(3) / 2);
				y0 -= (int)std::round(line_len);
			}
			SetPen(x0, y0);
			A(i, 90);			
			g_isCurDrawLine = TRUE;
		} while (i ^ n);
	}
}