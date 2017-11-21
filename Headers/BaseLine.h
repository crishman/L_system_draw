#ifndef BASE_LINE_H
#define BASE_LINE_H

#include <memory>
#include <string>
#include <exception>

namespace fractal_lines {
	extern BOOL g_bCheckLookCurLine;

	struct BaseLineImpl;

	class BaseLine {
	public:
		BaseLine();
		BaseLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect);
		virtual ~BaseLine();
		virtual bool Draw(const unsigned& num);

	protected:
		void SetPen(const int& x, const int& y) noexcept { x_ = x; y_ = y; }
		void line(const int& dir, const double& len);
		void square(int x, int y, const int& dir, const double& len);
		void ResetPen();
		void ResetBrush();
		void Clear();

		int GetRectWidth() const;
		int GetRectHeight() const;

	private:
		int x_, y_;
		BaseLineImpl* impl_;

	protected:	

		double line_len_;

		unsigned count_line_on_step;//количество вызовов реукрсии за один шаг
	};

	class TooDeepRecursionException : std::exception {
		std::string err_msg_;
	public:
		TooDeepRecursionException() :err_msg_("√лубина рекурсивной прорисовки дл€ данной кривой при текущем приближении больше чем установленное ограничение(2^16)!") {};

		inline std::string GetErrMsg() const { return err_msg_; }
	};

	class pimpl_nullptr_exception : std::exception {
		std::string err_msg_;
	public:
		pimpl_nullptr_exception() :err_msg_("Ќе определен указатель на реализацию!") {};

		inline std::string GetErrMsg() const { return err_msg_; }
	};
}

#endif