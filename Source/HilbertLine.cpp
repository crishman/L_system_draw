#include "stdafx.h"
#include "../Headers/HilbertLine.h"

HilbertLine::HilbertLine() :BaseLine() {
	count_line_on_step = 4;//одна линия пораждает четыре
}

void HilbertLine::A(unsigned i) {
	if (i) {
		D(i - 1);
		line(180, line_len);
		A(i - 1);
		line(270, line_len);
		A(i - 1);
		line(0, line_len);
		B(i - 1);
	}
}

void HilbertLine::B(unsigned i) {
	if (i) {
		C(i - 1);
		line(90, line_len);
		B(i - 1);
		line(0, line_len);
		B(i - 1);
		line(270, line_len);
		A(i - 1);
	}
}

void HilbertLine::C(unsigned i) {
	if (i) {
		B(i - 1);
		line(0, line_len);
		C(i - 1);
		line(90, line_len);
		C(i - 1);
		line(180, line_len);
		D(i - 1);
	}
}

void HilbertLine::D(unsigned i) {
	if (i) {
		A(i - 1);
		line(270, line_len);
		D(i - 1);
		line(180, line_len);
		D(i - 1);
		line(90, line_len);
		C(i - 1);
	}
}

void HilbertLine::Draw(unsigned n) {
	BaseLine::Draw(n);
	if (p_rect != nullptr) {
		Clear();
		line_len = p_rect->Width() / 2;
		auto x0 = (int)std::round(line_len);
		auto y0 = (int)std::round(p_rect->Height() / 2);
		decltype(n) i = 0;

		do {
			++i;
			cur_pen.reset(new CPen(PS_SOLID, 1, RGB(255 - i * 25, 255 - i * 10, 255 - i * 15)));
			if (g_bCheckLookCurLine) {
				Clear();
				if (i ^ n)
					g_isCurDrawLine = FALSE;
			}
			line_len /= 2;
			x0 = (int)std::round(x0 + (line_len / 2));
			y0 = (int)std::round(y0 - (line_len / 2));
			SetPen(x0, y0);
			A(i);
			g_isCurDrawLine = TRUE;
		} while (i ^ n);
	}
}