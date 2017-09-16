#pragma once
#include <memory>
#include <string>
#include "../Headers/MFCPaintPrimitive.h"

namespace fractal_lines {
	extern BOOL g_bCheckLookCurLine;

	class BaseLine {
	public:
		BaseLine() :x_(0), y_(0), pdc_(nullptr), prect_(nullptr), line_len_(0), count_line_on_step(0) {}
		BaseLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect) :x_(0), y_(0), pdc_(pdc), prect_(prect), line_len_(0), count_line_on_step(0) {}
		virtual ~BaseLine() = default;
		virtual bool Draw(const unsigned& num);

	protected:
		void SetPen(const int& x, const int& y) noexcept { x_ = x; y_ = y; }
		void line(const int& dir, const double& len);
		void square(int x, int y, const int& dir, const double& len);
		void ResetPen() { ppen_.Reset(); }
		void ResetBrush() { pbrush_.Reset(); }
		void Clear() { if (pdc_.IsExist() && prect_.IsExist()) pdc_.SetDefaultBack(prect_); }

		auto GetRectWidth() const { return prect_.GetWidth(); }
		auto GetRectHeight() const { return prect_.GetHeight(); }

	private:
		int x_, y_;
		MFCPaintDC pdc_;
		MFCPen ppen_;
		MFCBrush pbrush_;
		MFCRect prect_;

	protected:	

		double line_len_;

		unsigned count_line_on_step;//количество вызовов реукрсии за один шаг
	};

	class TooDeepRecursionException {
		std::string err_msg_;
	public:
		TooDeepRecursionException() :err_msg_("Глубина рекурсивной прорисовки для данной кривой при текущем приближении больше чем установленное ограничение(2^16)!") {};

		inline std::string GetErrMsg() const { return err_msg_; }
	};
}
