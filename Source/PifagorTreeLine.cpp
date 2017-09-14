#include "stdafx.h"
#include "../Headers/PifagorTreeLine.h"
#include "../Headers/AddFunctions.h"


namespace fractal_lines {
	int left_delta = 0;
	int right_delta = 0;

	//naked Pifagore tree
	NakedPifagorTree::NakedPifagorTree(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect) :BaseLine(pdc, prect) {
		count_line_on_step = 2;//одна линия пораждает две
	}

	void NakedPifagorTree::A(const int& i, const int& dir, const int& line_lens_size, int x, int y) {
		if (i) {
			x += custom_math::int_round(std::move(custom_math::cos(dir)*line_lens[line_lens_size - i - 1]));
			y -= custom_math::int_round(std::move(custom_math::sin(dir)*line_lens[line_lens_size - i - 1]));

			A(i - 1, dir + 45 + left_delta, line_lens_size, x, y);
			A(i - 1, dir + 315 + right_delta, line_lens_size, x, y);
		}
		else {
			SetPen(x, y);
			line(dir, line_len_);
		}
	}

	bool NakedPifagorTree::Draw(const unsigned& n) {
		if (BaseLine::Draw(n)){
			line_len_ = prect_->Width() / 4;
			auto x0 = custom_math::int_round(std::move(prect_->Width() / 2));
			auto y0 = custom_math::int_round(std::move(prect_->Height() / 2 + line_len_));

			auto i = 0;

			line_lens.clear();

			do {
				ppen_.reset(new CPen(PS_SOLID, 1, RGB(i * 25, 255 - i * 20, 0)));
				if (g_bCheckLookCurLine) {
					Clear();
				}
				line_len_ = line_len_ / 2 * std::sqrt(2);
				line_lens.push_back(line_len_);
				A(i, 90, static_cast<int>(line_lens.size()), x0, y0);
				++i;
			} while (i != n);

			return true;
		}
		return false;
	}

	//Pifagore tree

	PifagorTree::PifagorTree(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect) :BaseLine(pdc, prect) {
		count_line_on_step = 2;//одна линия пораждает две
	}

	void PifagorTree::A(const int& i, const int& dir, int x, int y, const double& len) {
		if (i) {
			x += custom_math::int_round(std::move(custom_math::cos(dir + 90)*len));
			y -= custom_math::int_round(std::move(custom_math::sin(dir + 90)*len));
			auto len1 = custom_math::int_round(std::move(len * custom_math::cos(45 + left_delta + right_delta)));
			A(i - 1
			  , dir + 45 + left_delta + right_delta
			  , x
			  , y
			  , len1);

			x += custom_math::int_round(std::move(custom_math::cos(dir + 45 + left_delta + right_delta)*len1));
			y -= custom_math::int_round(std::move(custom_math::sin(dir + 45 + left_delta + right_delta)*len1));
			A(i - 1
			  , dir - 45 + right_delta + left_delta
			  , x
			  , y
			  , custom_math::int_round(std::move(len * custom_math::sin(45 + left_delta + right_delta))));
		}
		else
			square(x, y, dir, custom_math::int_round(std::move(const_cast<double&>(len))));
	}

	bool PifagorTree::Draw(const unsigned& n) {
		if (BaseLine::Draw(n)){
			line_len_ = prect_->Width() / 8;
			auto x0 = custom_math::int_round(std::move(prect_->Width() / 2));
			auto y0 = custom_math::int_round(std::move(prect_->Height() / 2 + 2*line_len_));

			auto i = 0;

			do {
				ppen_.reset(new CPen(PS_SOLID, 1, RGB(i * 5, 255 - i * 20, 100 + i *11)));
				pbrush_.reset(new CBrush());
				pbrush_->CreateSolidBrush(RGB(111, i*22, 200 - i*10));
				if (g_bCheckLookCurLine) {
					Clear();
				}
				A(i, 0, x0, y0, line_len_);
				++i;
			} while (i != n);

			return true;
		}
		return false;
	}
}