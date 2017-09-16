#include "stdafx.h"
#include "../Headers/MFCPaintPrimitive.h"

namespace fractal_lines {
//MFCPaint
	void MFCPen::Reset() {
		auto r = []() { return rand() % 255; };
		ppen_.reset(new CPen(PS_SOLID, 1, RGB(r(), r(), r())));
	}

//MFCBrush
	void MFCBrush::Reset() {
		auto r = []() { return rand() % 255; };
		pbrush_.reset(new CBrush());
		pbrush_->CreateSolidBrush(RGB(r(), r(), r()));
	}
	
//MFCPaintDC	
	void MFCPaintDC::SetDefaultBack(const IRect<CRect>& r) {
		CBrush b(RGB(0, 0, 0));
		pdc_->FillRect(r.GetRect(), &b);
	}

	void MFCPaintDC::SetNewBack(const IBrush<CBrush>& p, std::vector<CPoint>& plg) {
		CRgn   rgn;
		rgn.CreatePolygonRgn(&plg[0], static_cast<int>(plg.size()), ALTERNATE);
		pdc_->FillRgn(&rgn, p.GetBrush());
	}

	void MFCPaintDC::MoveTo(const int& x, const int& y) {
		pdc_->MoveTo(x, y);
	}

	void MFCPaintDC::LineTo(const int& x, const int& y) {
		pdc_->LineTo(x, y);
	}

	void MFCPaintDC::SetPen(const IPen<CPen>& p) {
		pdc_->SelectObject(p.GetPen());
	}
}