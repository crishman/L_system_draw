#include "stdafx.h"
#include "../Headers/BaseLine.h"
#include <vector>
#include "../Headers/AddFunctions.h"
#include <exception>


BOOL g_bCheckLookCurLine = FALSE;
BOOL g_isCurDrawLine = TRUE;

BaseLine::BaseLine() {
	p_dc = NULL;
	p_rect = NULL;
	X = Y = 0;
	line_len = 0;
}

void BaseLine::Clear() {
	if (p_dc != NULL && p_rect != NULL) {
		CBrush b(RGB(0, 0, 0));
		p_dc->FillRect(*p_rect, &b);
	}
}

//����� ������� ���������
void BaseLine::SetPen(int x, int y) {
	X = x;
	Y = y;
}

//����� ��� ��������� ����� ����� len ��� ����� dir �� ����� � ������������ BaseLine::X, BaseLine::Y
void BaseLine::line(int dir, double len) {
	if (p_dc != NULL && cur_pen != NULL) {
		p_dc->SelectObject(*cur_pen);
		p_dc->MoveTo(X, Y);
		X += (int)std::round(get_cos(dir)*len);
		Y -= (int)std::round(get_sin(dir)*len);
		p_dc->LineTo(X, Y);
	}
}

//����� ��� ��������� �������� ����� len ��� ����� dir �� ����� � ������������ x, y
void BaseLine::square(int x, int y, int dir, int len) {
	SetPen(x, y);
	CPoint plg[4];
	for (auto i = 0; i < 4; i++) {
		plg[i].x = x;
		plg[i].y = y;
		x += (int)std::round(get_cos(dir + 90*i)*len);
		y -= (int)std::round(get_sin(dir + 90 * i)*len);		
	}

	CRgn   rgn;
	rgn.CreatePolygonRgn(plg, 4, ALTERNATE);	
	p_dc->FillRgn(&rgn, cur_brush.get());

	line(dir, len);
	line(dir+ 90, len);
	line(dir + 180, len);
	line(dir + 270, len);
}

