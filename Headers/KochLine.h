#ifndef KOCH_LINE_H
#define KOCH_LINE_H

#include "BaseLine.h"
#include <vector>

namespace fractal_lines {
	class KochLine : public BaseLine {
	protected:
		void A(const int& i, const int& dir);
		std::vector<int> dir_steps;

	public:
		KochLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect);
		virtual ~KochLine() = default;
		virtual bool Draw(const unsigned& n) override;
	};

	class KochStarLine : public KochLine {
	public:
		KochStarLine(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect) :KochLine(pdc, prect) {}
		virtual ~KochStarLine() = default;
		virtual bool Draw(const unsigned& n) override;
	};
}

#endif