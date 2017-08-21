#include "stdafx.h"
#include "../Headers/LeviLine.h"
#include <math.h>

LeviLine::LeviLine() :BaseLine() {
	count_line_on_step = 2;//одна линия пораждает две
}

void LeviLine::A(const unsigned& i, const int& dir) {
	if (i) {
		A(i - 1, dir + 45);
		A(i - 1, dir - 45);
	}
	else 
		line(dir, line_len);
}

void LeviLine::Draw(const unsigned& n) {
	BaseLine::Draw(n);
	if (p_rect != nullptr) {
		Clear();
		line_len = p_rect->Width() / 3;
		auto x0 = (int)std::round(p_rect->Width() / 2 - line_len / 3);
		auto y0 = (int)std::round(p_rect->Height() * 5/6);

		unsigned i = 0;

		do {
			++i;
			cur_pen.reset(new CPen(PS_SOLID, 1, RGB(180 - i * 15, 70, 255 - i * 15)));
			if (g_bCheckLookCurLine) {
				Clear();
				if (i ^ n)
					g_isCurDrawLine = FALSE;
			}

			line_len = line_len / std::sqrt(2);
			SetPen(x0, y0);
			A(i, 0);

			g_isCurDrawLine = TRUE;
		} while (i ^ n);
	}
}