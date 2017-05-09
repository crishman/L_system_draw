#include "stdafx.h"
#include "../Headers/LeviLine.h"
#include <math.h>

LeviLine::LeviLine() :BaseLine() {

}

void LeviLine::A(int i, int dir) {
	if (i == 0)	
		line(dir, line_len);
	else {
		A(i - 1, dir + 45);
		A(i - 1, dir - 45);
	}
}

void LeviLine::Draw(int n) {
	int i, x0, y0;
	if (p_rect != NULL) {
		Clear();
		line_len = p_rect->Width() / 3;
		x0 = (int)std::round(p_rect->Width() / 2 - line_len / 3);
		y0 = (int)std::round(p_rect->Height() * 5/6);

		i = 0;

		do {
			i++;
			cur_pen.reset(new CPen(PS_SOLID, 1, RGB(180 - i * 15, 70, 255 - i * 15)));
			if (g_bCheckLookCurLine) {
				Clear();
				if (i != n)
					g_isCurDrawLine = FALSE;
			}

			line_len = line_len / std::sqrt(2);
			SetPen(x0, y0);
			A(i, 0);

			g_isCurDrawLine = TRUE;
		} while (i != n);
	}
}