#include "stdafx.h"
#include "../Headers/DragonLine.h"
#include <math.h>
#include "../Headers/AddFunctions.h"


DragonLine::DragonLine():BaseLine(){
	;
}

void DragonLine::A(int i, int dir, int x, int y) {
	if (i == 0) {
		SetPen(x, y);
		line(dir, line_len);
	}
	else {
		B(i-1, dir+45, x, y);
		x += (int)std::round(get_cos(dir + 45)*last_len[last_len.size() - i]);
		y -= (int)std::round(get_sin(dir + 45)*last_len[last_len.size() - i]);
		A(i-1, dir- 45, x, y);
	}
}

void DragonLine::B(int i, int dir, int x, int y) {
	if (i == 0) {
		A(i, dir, x, y);
	}
	else {
		B(i-1, dir-45, x, y);
		x += (int)std::round(get_cos(dir - 45)*last_len[last_len.size() - i]);
		y -= (int)std::round(get_sin(dir - 45)*last_len[last_len.size() - i]);
		A(i-1, dir+45, x, y);
	}
}

void DragonLine::Draw(int n) {	
	int i, x0, y0;
	if (p_rect != NULL) {
		Clear();
		line_len = p_rect->Width()/3;
		x0 = (int)std::round(p_rect->Width() / 2 - line_len / 3);
		y0 = (int)std::round(p_rect->Height() / 2 + line_len /4);

		i = 0;
		last_len.clear();

		do {
			i++;
			cur_pen.reset(new CPen(PS_SOLID, 1, RGB(i * 25, 0, 255-i*5)));
			if (g_bCheckLookCurLine) {
				Clear();
				if (i != n)
					g_isCurDrawLine = FALSE;
			}

			line_len = line_len / std::sqrt(2);
			last_len.push_back(line_len);
			A(i, 0, x0, y0);
			
			g_isCurDrawLine = TRUE;
		} while (i != n);
	}
}