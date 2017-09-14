#pragma once
#include <memory>
#include <string>

extern BOOL g_bCheckLookCurLine;

namespace fractal_lines {
	class BaseLine {
	public:
		BaseLine() :x_(0), y_(0), pdc_(nullptr), prect_(nullptr), ppen_(nullptr), pbrush_(nullptr), line_len_(0), count_line_on_step(0) {}
		BaseLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect) :x_(0), y_(0), pdc_(pdc), prect_(prect), ppen_(nullptr), pbrush_(nullptr), line_len_(0), count_line_on_step(0) {}
		virtual ~BaseLine() = default;
		virtual bool Draw(const unsigned& num);

		void Clear();

	protected:
		void SetPen(const int& x, const int& y) noexcept { x_ = x; y_ = y; }
		void line(const int& dir, const double& len);
		void square(int x, int y, const int& dir, const double& len);

	private:
		int x_, y_;
		std::shared_ptr<CPaintDC> pdc_;

	protected:
		std::shared_ptr<CRect> prect_;
		std::unique_ptr<CPen> ppen_;//cur_pen
		std::unique_ptr<CBrush> pbrush_;//cur_brush

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
