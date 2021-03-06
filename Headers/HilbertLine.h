#ifndef HILBERT_LINE_H
#define HILBERT_LINE_H

#include "BaseLine.h"

namespace fractal_lines {
	class HilbertLine : public BaseLine {
		void A(const int& i);
		void B(const int& i);
		void C(const int& i);
		void D(const int& i);

	public:
		HilbertLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect);
		virtual ~HilbertLine() = default;

		virtual bool Draw(const unsigned& n) override;
	};
}

#endif