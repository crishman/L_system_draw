#pragma once
#include "BaseLine.h"
#include <vector>

namespace fractal_lines {
	extern int left_delta;
	extern int right_delta;

	class NakedPifagorTree : public BaseLine {
		void A(const int& i, const int& dir, const int& line_lens_size, int x, int y);
		std::vector<double> line_lens;

	public:
		NakedPifagorTree(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect);
		virtual ~NakedPifagorTree() = default;
		virtual bool Draw(const unsigned& n) override;
	};

	class PifagorTree : public BaseLine {
		void A(const int& i, const int& dir, int x, int y, const double& len);

	public:
		PifagorTree(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect);
		virtual ~PifagorTree() = default;
		virtual bool Draw(const unsigned& n) override;
	};
}