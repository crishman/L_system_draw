#pragma once
#include <memory>
#include "../Headers/InterfacePaintPrimitive.h"
#include <vector>

namespace fractal_lines {

	class MFCPen : public IPen<CPen> {
	public:
		MFCPen() :ppen_(nullptr) {}
		~MFCPen() = default;

	private:
		MFCPen(const MFCPen&);
		MFCPen& operator=(const MFCPen&);

	public:
		void Reset() override;
		CPen* GetPen() const override { return ppen_.get(); }
		bool IsExist() const override { return (ppen_ != nullptr); }

	private:
		std::unique_ptr<CPen> ppen_;
	};

	class MFCBrush : public IBrush<CBrush> {
	public:
		MFCBrush() :pbrush_(nullptr) {}
		~MFCBrush() = default;

	private:
		MFCBrush(const MFCBrush&);
		MFCBrush& operator=(const MFCBrush&);

	public:
		void Reset() override;
		CBrush* GetBrush() const  override { return pbrush_.get(); }
		bool IsExist() const override { return (pbrush_ != nullptr); }

	private:
		std::unique_ptr<CBrush> pbrush_;
	};

	
	class MFCRect : public IRect<CRect> {
	public:
		MFCRect(std::shared_ptr<CRect> prect) :prect_(prect) {}
		~MFCRect() = default;

	private:
		MFCRect(const MFCRect&);
		MFCRect& operator=(const MFCRect&);

	public:
		CRect* GetRect() const override { return prect_.get(); }
		bool IsExist() const override { return (prect_ != nullptr); }
		int GetWidth() const override { return IsExist() ? prect_->Width() : 0; }
		int GetHeight() const override { return IsExist() ? prect_->Height() : 0; }
	private:
		std::shared_ptr<CRect> prect_;
	};

	class MFCPaintDC : public IPaintDC<CBrush, std::vector<CPoint>, CPen, CRect> {
	public:
		MFCPaintDC(std::shared_ptr<CPaintDC> pdc) :pdc_(pdc) {}
		~MFCPaintDC() = default;

	private:
		MFCPaintDC(const MFCPaintDC&);
		MFCPaintDC& operator=(const MFCPaintDC&);

	public:
		void SetDefaultBack(const IRect<CRect>& r) override;
		void SetNewBack(const IBrush<CBrush>& p, std::vector<CPoint>& plg) override;
		void MoveTo(const int& x, const int& y) override;
		void LineTo(const int& x, const int& y) override;
		void SetPen(const IPen<CPen>& p) override;
		bool IsExist() const override { return (pdc_ != nullptr); }

	private:
		std::shared_ptr<CPaintDC> pdc_;
	};
}