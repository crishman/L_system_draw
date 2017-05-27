#include "stdafx.h"
#include "../Headers/DragonLine.h"
#include <math.h>
#include "../Headers/AddFunctions.h"


DragonLine::DragonLine():BaseLine(){
	count_line_on_step = 2;//���� ����� ��������� ���
}

void DragonLine::A(unsigned i, int dir, int x, int y) {
	if (i) {
		B(i - 1, dir + 45, x, y);
		x += (int)std::round(get_cos(dir + 45)*last_len[last_len.size() - i]);
		y -= (int)std::round(get_sin(dir + 45)*last_len[last_len.size() - i]);
		A(i - 1, dir - 45, x, y);
	}
	else {
		SetPen(x, y);
		line(dir, line_len);		
	}
}

void DragonLine::B(unsigned i, int dir, int x, int y) {
	if (i) {
		B(i - 1, dir - 45, x, y);
		x += (int)std::round(get_cos(dir - 45)*last_len[last_len.size() - i]);
		y -= (int)std::round(get_sin(dir - 45)*last_len[last_len.size() - i]);
		A(i - 1, dir + 45, x, y);
	}
	else {
		A(i, dir, x, y);		
	}
}

void DragonLine::Draw(unsigned n) {
	BaseLine::Draw(n);
	if (p_rect != nullptr) {
		Clear();
		line_len = p_rect->Width()/3;
		auto x0 = (int)std::round(p_rect->Width() / 2 - line_len / 3);
		auto y0 = (int)std::round(p_rect->Height() / 2 + line_len /4);

		decltype(n) i = 0;
		last_len.clear();

		do {
			++i;
			cur_pen.reset(new CPen(PS_SOLID, 1, RGB(i * 25, 0, 255-i*5)));
			if (g_bCheckLookCurLine) {
				Clear();
				if (i ^ n)
					g_isCurDrawLine = FALSE;
			}

			line_len = line_len / std::sqrt(2);
			last_len.push_back(line_len);
			A(i, 0, x0, y0);
			
			g_isCurDrawLine = TRUE;
		} while (i ^ n);
	}
}