#pragma once
#include <memory>
#include <vector>

extern BOOL g_bCheckLookCurLine;
extern BOOL g_isCurDrawLine;


class BaseLine {	
	int X;
	int Y;

	//CPaintDC *p_dc;
	std::shared_ptr<CPaintDC> p_dc;

protected:
	//CRect *rect;
	std::shared_ptr<CRect> p_rect;
	std::unique_ptr<CPen> cur_pen;
	std::unique_ptr<CBrush> cur_brush;

	double line_len;

public:
	BaseLine();
	virtual ~BaseLine() {};
	virtual void Draw(int num) = 0;

	//void SetPaintDC(CPaintDC *dc) { p_dc = dc; }
	void SetPaintDC(std::shared_ptr<CPaintDC> dc) { p_dc = dc; }
	//void SetRect(CRect *r) { rect = r; }
	void SetRect(std::shared_ptr<CRect> rect) { p_rect = rect; }
	
	void Clear();
protected:
	//void Clear();
	void SetPen(int x, int y);
	void line(int dir, double len);
	void square(int x, int y, int dir, int len);
};
