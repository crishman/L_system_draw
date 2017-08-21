#pragma once
#include <memory>
#include <vector>

extern BOOL g_bCheckLookCurLine;
extern BOOL g_isCurDrawLine;

class BaseLine {	
	int X;
	int Y;

	std::shared_ptr<CPaintDC> p_dc;

protected:
	std::shared_ptr<CRect> p_rect;
	std::unique_ptr<CPen> cur_pen;
	std::unique_ptr<CBrush> cur_brush;

	double line_len;

	unsigned count_line_on_step;//���������� ������� �������� �� ���� ���

public:
	BaseLine();
	virtual ~BaseLine() = default;
	virtual void Draw(const unsigned& num);

	void SetPaintDC(std::shared_ptr<CPaintDC> dc) { p_dc = dc; }
	void SetRect(std::shared_ptr<CRect> rect) { p_rect = rect; }
	
	void Clear();

protected:
	void SetPen(const int& x, const int& y) noexcept;
	void line(const int& dir, const double& len);
	void square(int x, int y, const int& dir, const double& len);
};

class TooDeepRecursionException {
public:
	TooDeepRecursionException() {};
};
