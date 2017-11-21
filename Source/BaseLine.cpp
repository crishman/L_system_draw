#include "stdafx.h"
#include "../Headers/BaseLine.h"
#include "../Headers/AddFunctions.h"
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include "../Headers/MFCPaintPrimitive.h"

namespace fractal_lines {

	BOOL g_bCheckLookCurLine = FALSE;

	struct BaseLineImpl{
		BaseLineImpl(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect) :pdc_(pdc), prect_(prect) {}

		MFCPaintDC pdc_;
		MFCPen ppen_;
		MFCBrush pbrush_;
		MFCRect prect_;
	};

	BaseLine::BaseLine()
		: x_(0)
		, y_(0)
		, impl_(nullptr)
		, line_len_(0)
		, count_line_on_step(0)
	{}

	BaseLine::BaseLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect)
	try
		: x_(0)
		, y_(0)
		, impl_(new BaseLineImpl(pdc, prect))
		, line_len_(0)
		, count_line_on_step(0)
	{
	}
	catch (...){
		if (impl_ != nullptr)
			delete impl_;
	}

	BaseLine::~BaseLine() {
		if (impl_ != nullptr)
			delete impl_;
	}

	//метод для рисования линии длины len под углом dir из точки с координатами BaseLine::X, BaseLine::Y
	void BaseLine::line(const int& dir, const double& len) {
		if (impl_ == nullptr)
			throw pimpl_nullptr_exception();
		
		if (impl_->pdc_.IsExist() && impl_->prect_.IsExist()) {
			impl_->pdc_.SetPen(impl_->ppen_);
			impl_->pdc_.MoveTo(x_, y_);
			x_ += custom_math::int_round(custom_math::cos(dir)*len);
			y_ -= custom_math::int_round(custom_math::sin(dir)*len);
			impl_->pdc_.LineTo(x_, y_);
		}
	}

	//метод для рисования квадрата длины len под углом dir из точки с координатами x, y
	void BaseLine::square(int x, int y, const int& dir, const double& len) {
		if (impl_ == nullptr)
			throw pimpl_nullptr_exception();
		
		if (impl_->pdc_.IsExist() && impl_->pbrush_.IsExist()) {
			SetPen(x, y);
			std::vector<CPoint> plg(4);

			auto i = 0;
			std::for_each(plg.begin(), plg.end(), [&x, &y, &dir, &len, &i](CPoint& p) {
				p.x = x;
				p.y = y;
				x += custom_math::int_round(custom_math::cos(dir + 90 * i) * len);
				y -= custom_math::int_round(custom_math::sin(dir + 90 * i) * len); 
			});
			
			impl_->pdc_.SetNewBack(impl_->pbrush_, plg);

			auto step = 0;
			std::for_each(plg.begin(), plg.end(), [&step, &dir, &len, this](CPoint& p) { this->line(dir + step, len); step += 90; });
		}
	}

	void BaseLine::ResetPen() {
		if (impl_ == nullptr)
			throw pimpl_nullptr_exception();
		impl_->ppen_.Reset();
	}

	void BaseLine::ResetBrush() {
		if (impl_ == nullptr)
			throw pimpl_nullptr_exception();
		impl_->pbrush_.Reset();
	}

	void BaseLine::Clear() {
		if (impl_ == nullptr)
			throw pimpl_nullptr_exception();
		if (impl_->pdc_.IsExist() && impl_->prect_.IsExist())
			impl_->pdc_.SetDefaultBack(impl_->prect_);
	}

	int BaseLine::GetRectWidth() const {
		if (impl_ == nullptr)
			throw pimpl_nullptr_exception();
		return impl_->prect_.GetWidth();
	}

	int BaseLine::GetRectHeight() const {
		if (impl_ == nullptr)
			throw pimpl_nullptr_exception();
		return impl_->prect_.GetHeight();
	}

	bool BaseLine::Draw(const unsigned& num)
	{
		if (std::pow(count_line_on_step, num) > 65536)//2^16
			throw TooDeepRecursionException();

		if (impl_ == nullptr)
			throw pimpl_nullptr_exception();

		if (impl_->prect_.IsExist()) {
			Clear();
			std::srand(static_cast<unsigned int>(std::time(nullptr)));
			return true;
		}

		return false;
	}
}