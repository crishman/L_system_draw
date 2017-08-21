#include "stdafx.h"
#include "../Headers/SierpinskiLine.h"

SierpinskiLine::SierpinskiLine() :BaseLine() {
	count_line_on_step = 4;//одна линия пораждает четыре
}

void SierpinskiLine::A(unsigned k) {
	if (k) {
		A(k - 1);
		line(315, line_len);
		B(k - 1);
		line(0, 2 * line_len);
		D(k - 1);
		line(45, line_len);
		A(k - 1);
	}
}

void SierpinskiLine::B(unsigned k) {
	if (k) {
		B(k - 1);
		line(225, line_len);
		C(k - 1);
		line(270, 2 * line_len);
		A(k - 1);
		line(315, line_len);
		B(k - 1);
	}
}

void SierpinskiLine::C(unsigned k) {
	if (k) {
		C(k - 1);
		line(135, line_len);
		D(k - 1);
		line(180, 2 * line_len);
		B(k - 1);
		line(225, line_len);
		C(k - 1);
	}
}

void SierpinskiLine::D(unsigned k) {
	if (k) {
		D(k - 1);
		line(45, line_len);
		A(k - 1);
		line(90, 2 * line_len);
		C(k - 1);
		line(135, line_len);
		D(k - 1);
	}
}

void SierpinskiLine::Draw(unsigned n) {
	BaseLine::Draw(n);
	if (p_rect != nullptr) {
		Clear();
		line_len = p_rect->Width() / 8;
		auto x0 = (int)std::round(p_rect->Width() / 2);
		auto y0 = (int)std::round(p_rect->Height() / 2 - line_len);
		decltype(n) i = 0;

		do {
			++i;
			cur_pen.reset(new CPen(PS_SOLID, 1, RGB(255 - i * 5, 255 - i * 23, 255 - i * 30)));

			if (g_bCheckLookCurLine) {
				Clear();

				if (i ^ n)
					g_isCurDrawLine = FALSE;
			}

			x0 = (int)std::round(x0 - line_len * 7 / 9);
			line_len /= 2;
			y0 = (int)std::round(y0 - line_len * 4 / 5);
			SetPen(x0, y0);

			A(i);
			line(315, line_len);
			B(i);
			line(225, line_len);
			C(i);
			line(135, line_len);
			D(i);
			line(45, line_len);

			g_isCurDrawLine = TRUE;
		} while (i ^ n);
	}
}

//Sirpinski2
SierpinskiLine2::SierpinskiLine2() :BaseLine() {
	count_line_on_step = 3;//одна линия пораждает три
}

void SierpinskiLine2::A(unsigned i, int dir) {
	if (i) {
		B(i - 1, dir + 60);
		A(i - 1, dir);
		B(i - 1, dir + 300);
	}
	else
		line(dir, line_len);
}

void SierpinskiLine2::B(unsigned i, int dir) {
	if (i) {
		A(i - 1, dir + 300);
		B(i - 1, dir);
		A(i - 1, dir + 60);
	}
	else
		line(dir, line_len);
}

void SierpinskiLine2::Draw(unsigned n) {
	BaseLine::Draw(n);
	if (p_rect != nullptr) {
		Clear();
		line_len = p_rect->Width() / 2;
		auto x0 = (int)std::round(p_rect->Width() / 3);
		auto y0 = (int)std::round(p_rect->Height() * 5 / 6);
		decltype(n) i = 0;

		do {
			cur_pen.reset(new CPen(PS_SOLID, 1, RGB(200 - i * 5, 100 + i * 23, 255 - i * 15)));

			if (g_bCheckLookCurLine) {
				Clear();

				if (i ^ n)
					g_isCurDrawLine = FALSE;
			}

			SetPen(x0, y0);

			A(i, 0);
			line_len /= 2;
			++i;

			g_isCurDrawLine = TRUE;
		} while (i ^ n);
	}
}