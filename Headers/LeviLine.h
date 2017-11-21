#ifndef LEVI_LINE_H
#define LEVI_LINE_H

#include "BaseLine.h"

namespace fractal_lines {
	class LeviLine : public BaseLine {

		void A(const int& i, const int& dir);

	public:
		LeviLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect);
		virtual ~LeviLine() = default;

		virtual bool Draw(const unsigned& n) override;
	};
}

#endif