#pragma once
#include "BaseLine.h"
#include <vector>

extern int left_delta;
extern int right_delta;

namespace fractal_lines {
	class NakedPifagorTree : public BaseLine {
		void A(const int& i, const int& dir, const int& line_lens_size, int x, int y);
		std::vector<double> line_lens;

	public:
		NakedPifagorTree(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect);
		virtual ~NakedPifagorTree() = default;
		virtual void Draw(const unsigned& n) override;
	};

	class PifagorTree : public BaseLine {
		void A(const int& i, const int& dir, int x, int y, const double& len);

	public:
		PifagorTree(std::shared_ptr<CPaintDC> pdc, std::shared_ptr<CRect> prect);
		virtual ~PifagorTree() = default;
		virtual void Draw(const unsigned& n) override;
	};
}