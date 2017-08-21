#include "stdafx.h"
#include "../Headers/BaseLine.h"
#include <vector>
#include "../Headers/AddFunctions.h"
#include <math.h>

BOOL g_bCheckLookCurLine = FALSE;
BOOL g_isCurDrawLine = TRUE;

BaseLine::BaseLine() {
	p_dc = nullptr;
	p_rect = nullptr;
	X = Y = 0;
	line_len = 0;
	count_line_on_step = 0;
}

void BaseLine::Clear() {
	if (p_dc != nullptr && p_rect != nullptr) {
		CBrush b(RGB(0, 0, 0));
		p_dc->FillRect(*p_rect, &b);
	}
}

//Метод задания координат
void BaseLine::SetPen(const int& x, const int& y) noexcept {
	X = x;
	Y = y;
}

//метод для рисования линии длины len под углом dir из точки с координатами BaseLine::X, BaseLine::Y
void BaseLine::line(const int& dir, const double& len) {
	if (p_dc != nullptr && cur_pen != nullptr) {
		p_dc->SelectObject(*cur_pen);
		p_dc->MoveTo(X, Y);
		X += (int)std::round(get_cos(dir)*len);
		Y -= (int)std::round(get_sin(dir)*len);
		p_dc->LineTo(X, Y);
	}
}

//метод для рисования квадрата длины len под углом dir из точки с координатами x, y
void BaseLine::square(int x, int y, const int& dir, const double& len) {
	if (p_dc != nullptr && cur_brush != nullptr) {
		SetPen(x, y);
		CPoint plg[4];
		for (auto i = 0; i < 4; ++i) {
			plg[i].x = x;
			plg[i].y = y;
			x += (int)std::round(get_cos(dir + 90 * i) * len);
			y -= (int)std::round(get_sin(dir + 90 * i) * len);
		}

		CRgn   rgn;
		rgn.CreatePolygonRgn(plg, 4, ALTERNATE);
		p_dc->FillRgn(&rgn, cur_brush.get());

		line(dir, len);
		line(dir + 90, len);
		line(dir + 180, len);
		line(dir + 270, len);
	}
}

void BaseLine::Draw(const unsigned& num)
{
	if (std::pow(count_line_on_step, num) > 65536)//2^16
		throw TooDeepRecursionException();
}

