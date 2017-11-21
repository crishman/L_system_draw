#ifndef HOSPER_LINE_H
#define HOSPER_LINE_H

#include "BaseLine.h"

namespace fractal_lines {
	class HosperLine : public BaseLine {
		void A(const int& i, const int& dir);
		void B(const int& i, const int& dir);

	public:
		HosperLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect);
		virtual ~HosperLine() = default;
		virtual bool Draw(const unsigned& n) override;
	};
}

#endif