#include "stdafx.h"
#include "../Headers/MinkovskiyLine.h"

MinkovskiyLine::MinkovskiyLine() :BaseLine() {
	count_line_on_step = 8;//одна линия пораждает восемь
}

void MinkovskiyLine::A(unsigned i, int dir) {
	if (i) {
		A(i - 1, dir);
		A(i - 1, dir + 90);
		A(i - 1, dir);
		A(i - 1, dir + 270);
		A(i - 1, dir + 270);
		A(i - 1, dir);
		A(i - 1, dir + 90);
		A(i - 1, dir);
	}
	else
		line(dir, line_len);
}


void MinkovskiyLine::Draw(unsigned n) {
	BaseLine::Draw(n);
	if (p_rect != nullptr) {
		Clear();
		line_len = p_rect->Width() * 3 / 4;
		auto x0 = (int)std::round(p_rect->Width() / 2 - line_len / 2);
		auto y0 = (int)std::round(p_rect->Height() / 2);

		decltype(n) i = 0;

		do {
			++i;
			cur_pen.reset(new CPen(PS_SOLID, 1, RGB(100 + i*17, 200 - i * 20, 12 + i * 25)));
			if (g_bCheckLookCurLine) {
				Clear();
				if (i ^ n)
					g_isCurDrawLine = FALSE;
			}
			line_len /= 4;
			SetPen(x0, y0);
			A(i, 0);
			g_isCurDrawLine = TRUE;
		} while (i ^ n);
	}
}