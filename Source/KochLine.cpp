#include "stdafx.h"
#include "../Headers/KochLine.h"

KochLine::KochLine() :BaseLine() {

}

void KochLine::A(int i, int dir) {
	if (i == 0)
		line(dir, line_len);
	else {
		A(i-1, dir);
		A(i-1, dir + 60);
		A(i-1, dir + 300);
		A(i-1, dir);
	}
}

void KochLine::Draw(int n) {
	int i, x0, y0;
	if (p_rect != NULL) {
		Clear();
		line_len = p_rect->Width() *3 / 4;
		x0 = (int)std::round(p_rect->Width() / 2 - line_len /2);
		y0 = (int)std::round(p_rect->Height() * 2/3);
		
		i = 0;

		do {
			i++;
			cur_pen.reset(new CPen(PS_SOLID, 1, RGB(0, 255 - i * 20, 0 + i * 15)));
			if (g_bCheckLookCurLine) {
				Clear();
				if (i != n)
					g_isCurDrawLine = FALSE;
			}
			line_len /= 3;
			SetPen(x0, y0);
			A(i, 0);
			g_isCurDrawLine = TRUE;
		} while (i != n);
	}
}

KochStarLine::KochStarLine() :KochLine() {

}

void KochStarLine::Draw(int n) {
	int i, x0, y0;
	if (p_rect != NULL) {
		Clear();
		line_len = p_rect->Width() / 3;
		x0 = (int)std::round(p_rect->Width() / 2);
		y0 = (int)std::round(p_rect->Height() / 2 - line_len /2);

		i = 0;

		do {
			i++;
			cur_pen.reset(new CPen(PS_SOLID, 1, RGB(0, 255 - i * 20, 0 + i * 15)));
			if (g_bCheckLookCurLine) {
				Clear();
				if (i != n)
					g_isCurDrawLine = FALSE;
			}
			line_len /= 3;
			SetPen(x0, y0);
			A(i, 300);
			A(i, 180);
			A(i, 60);
			g_isCurDrawLine = TRUE;
		} while (i != n);
	}
}