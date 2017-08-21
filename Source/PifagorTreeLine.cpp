#include "stdafx.h"
#include "../Headers/PifagorTreeLine.h"
#include "../Headers/AddFunctions.h"
#include <math.h>

int left_delta = 0;
int right_delta = 0;

//naked Pifagore tree
NakedPifagorTree::NakedPifagorTree() :BaseLine() {
	count_line_on_step = 2;//одна линия пораждает две
}

void NakedPifagorTree::A(unsigned i, int dir, int x, int y) {
	if (i) {
		x += (int)std::round(get_cos(dir)*line_lens[line_lens.size() - i - 1]);
		y -= (int)std::round(get_sin(dir)*line_lens[line_lens.size() - i - 1]);

		A(i - 1, dir + 45 + left_delta, x, y);
		A(i - 1, dir + 315 + right_delta, x, y);		
	}
	else {
		SetPen(x, y);
		line(dir, line_len);
	}
}

void NakedPifagorTree::Draw(unsigned n) {
	BaseLine::Draw(n);
	if (p_rect != nullptr) {
		Clear();
		line_len = p_rect->Width() / 4;
		auto x0 = (int)std::round(p_rect->Width() / 2);
		auto y0 = (int)std::round(p_rect->Height() / 2 + line_len);

		decltype(n) i = 0;

		line_lens.clear();

		do {
			cur_pen.reset(new CPen(PS_SOLID, 1, RGB(i * 25, 255 - i * 20, 0)));
			if (g_bCheckLookCurLine) {
				Clear();
				if (i ^ n)
					g_isCurDrawLine = FALSE;
			}
			line_len = line_len / 2 * std::sqrt(2);
			line_lens.push_back(line_len);
			A(i, 90, x0, y0);
			++i;
			g_isCurDrawLine = TRUE;
		} while (i ^ n);
	}
}

//Pifagore tree

PifagorTree::PifagorTree() :BaseLine() {
	count_line_on_step = 2;//одна линия пораждает две
}

void PifagorTree::A(unsigned i, int dir, int x, int y, double len) {
	if (i) {
		x += (int)std::round(get_cos(dir + 90)*len);
		y -= (int)std::round(get_sin(dir + 90)*len);

		auto len1 = (int)std::round(len * get_cos(45 + left_delta + right_delta));

		A(i - 1, dir + 45 + left_delta + right_delta, x, y, len1);

		x += (int)std::round(get_cos(dir + 45 + left_delta + right_delta)*len1);
		y -= (int)std::round(get_sin(dir + 45 + left_delta + right_delta)*len1);
		auto len2 = (int)std::round(len * get_sin(45 + left_delta + right_delta));
		A(i - 1, dir - 45 + right_delta + left_delta, x, y, len2);
	}
	else
		square(x, y, dir, (int)std::round(len));
}

void PifagorTree::Draw(unsigned n) {
	BaseLine::Draw(n);
	if (p_rect != nullptr) {
		Clear();
		line_len = p_rect->Width() / 8;
		auto x0 = (int)std::round(p_rect->Width() / 2);
		auto y0 = (int)std::round(p_rect->Height() / 2 + 2*line_len);

		decltype(n) i = 0;

		do {
			cur_pen.reset(new CPen(PS_SOLID, 1, RGB(i * 5, 255 - i * 20, 100 + i *11)));
			cur_brush.reset(new CBrush());
			cur_brush->CreateSolidBrush(RGB(0, i*22, 200 - i*10));
			if (g_bCheckLookCurLine) {
				Clear();
				if (i ^ n)
					g_isCurDrawLine = FALSE;
			}
			A(i, 0, x0, y0, line_len);
			++i;
			g_isCurDrawLine = TRUE;
		} while (i ^ n);
	}
}