#include "stdafx.h"
#include "../Headers/MinkovskiyLine.h"

MinkovskiyLine::MinkovskiyLine() :BaseLine() {
	count_line_on_step = 8;//одна линия пораждает восемь
}

void MinkovskiyLine::A(int i, int dir) {
	if (i == 0)
		line(dir, line_len);
	else {
		A(i - 1, dir);
		A(i - 1, dir + 90);
		A(i - 1, dir);
		A(i - 1, dir + 270);
		A(i - 1, dir + 270);
		A(i - 1, dir);
		A(i - 1, dir + 90);
		A(i - 1, dir);
	}
}


void MinkovskiyLine::Draw(int n) {
	BaseLine::Draw(n);
	int i, x0, y0;
	if (p_rect != NULL) {
		Clear();
		line_len = p_rect->Width() * 3 / 4;
		x0 = (int)std::round(p_rect->Width() / 2 - line_len / 2);
		y0 = (int)std::round(p_rect->Height() / 2);

		i = 0;

		do {
			i++;
			cur_pen.reset(new CPen(PS_SOLID, 1, RGB(100 + i*17, 200 - i * 20, 12 + i * 25)));
			if (g_bCheckLookCurLine) {
				Clear();
				if (i != n)
					g_isCurDrawLine = FALSE;
			}
			line_len /= 4;
			SetPen(x0, y0);
			A(i, 0);
			g_isCurDrawLine = TRUE;
		} while (i != n);
	}
}