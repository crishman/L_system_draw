#include "stdafx.h"
#include "../Headers/BaseLine.h"
#include "../Headers/AddFunctions.h"
#include <vector>
#include <cmath>
#include <algorithm>

BOOL g_bCheckLookCurLine = FALSE;

namespace fractal_lines {
	void BaseLine::Clear() {
		if (pdc_ != nullptr && prect_ != nullptr) {
			CBrush b(RGB(0, 0, 0));
			pdc_->FillRect(*prect_, &b);
		}
	}

	//метод для рисования линии длины len под углом dir из точки с координатами BaseLine::X, BaseLine::Y
	void BaseLine::line(const int& dir, const double& len) {
		if (pdc_ != nullptr && ppen_ != nullptr) {
			pdc_->SelectObject(ppen_.get());
			pdc_->MoveTo(x_, y_);
			x_ += custom_math::int_round(std::move(custom_math::cos(dir)*len));
			y_ -= custom_math::int_round(std::move(custom_math::sin(dir)*len));
			pdc_->LineTo(x_, y_);
		}
	}

	//метод для рисования квадрата длины len под углом dir из точки с координатами x, y
	void BaseLine::square(int x, int y, const int& dir, const double& len) {
		if (pdc_ != nullptr && pbrush_ != nullptr) {
			SetPen(x, y);
			std::vector<CPoint> plg(4);

			auto i = 0;
			std::for_each(plg.begin(), plg.end(), [&x, &y, &dir, &len, &i](CPoint& p) {	p.x = x;
			p.y = y;
			x += custom_math::int_round(custom_math::cos(dir + 90 * i) * len);
			y -= custom_math::int_round(custom_math::sin(dir + 90 * i) * len); });

			CRgn   rgn;
			rgn.CreatePolygonRgn(&plg[0], static_cast<int>(plg.size()), ALTERNATE);
			pdc_->FillRgn(&rgn, pbrush_.get());

			auto step = 0;
			std::for_each(plg.begin(), plg.end(), [&step, &dir, &len, this](CPoint& p) { this->line(dir + step, len); step += 90; });
		}
	}

	bool BaseLine::Draw(const unsigned& num)
	{
		if (std::pow(count_line_on_step, num) > 65536)//2^16
			throw TooDeepRecursionException();

		if (prect_ != nullptr) {
			Clear();
			return true;
		}

		return false;
	}
}