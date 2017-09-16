#include "stdafx.h"
#include "../Headers/BaseLine.h"
#include "../Headers/AddFunctions.h"
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

namespace fractal_lines {

	BOOL g_bCheckLookCurLine = FALSE;

	//метод для рисования линии длины len под углом dir из точки с координатами BaseLine::X, BaseLine::Y
	void BaseLine::line(const int& dir, const double& len) {
		if (pdc_.IsExist() && prect_.IsExist()) {
			pdc_.SetPen(ppen_);
			pdc_.MoveTo(x_, y_);
			x_ += custom_math::int_round(custom_math::cos(dir)*len);
			y_ -= custom_math::int_round(custom_math::sin(dir)*len);
			pdc_.LineTo(x_, y_);
		}
	}

	//метод для рисования квадрата длины len под углом dir из точки с координатами x, y
	void BaseLine::square(int x, int y, const int& dir, const double& len) {
		if (pdc_.IsExist() && pbrush_.IsExist()) {
			SetPen(x, y);
			std::vector<CPoint> plg(4);

			auto i = 0;
			std::for_each(plg.begin(), plg.end(), [&x, &y, &dir, &len, &i](CPoint& p) {	p.x = x;
																						p.y = y;
																						x += custom_math::int_round(custom_math::cos(dir + 90 * i) * len);
																						y -= custom_math::int_round(custom_math::sin(dir + 90 * i) * len); });

			pdc_.SetNewBack(pbrush_, plg);

			auto step = 0;
			std::for_each(plg.begin(), plg.end(), [&step, &dir, &len, this](CPoint& p) { this->line(dir + step, len); step += 90; });
		}
	}

	bool BaseLine::Draw(const unsigned& num)
	{
		if (std::pow(count_line_on_step, num) > 65536)//2^16
			throw TooDeepRecursionException();

		if (prect_.IsExist()) {
			Clear();
			std::srand(static_cast<unsigned int>(std::time(nullptr)));
			return true;
		}

		return false;
	}
}