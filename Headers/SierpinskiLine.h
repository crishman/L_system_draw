#pragma once
#include "BaseLine.h"

namespace fractal_lines {
	class SierpinskiLine : public BaseLine {
		void A(const int& k);
		void B(const int& k);
		void C(const int& k);
		void D(const int& k);

	public:
		SierpinskiLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect);
		virtual ~SierpinskiLine() = default;
		virtual bool Draw(const unsigned& n) override;
	};

	class SierpinskiLine2 : public BaseLine {
		void A(const int& k, const int& dir);
		void B(const int& k, const int& dir);
	public:
		SierpinskiLine2(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect);
		virtual ~SierpinskiLine2() = default;
		virtual bool Draw(const unsigned& n) override;
	};
}