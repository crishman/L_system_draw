#ifndef MAKE_FRACTAL_H
#define MAKE_FRACTAL_H

#include <memory>
#include "../Headers/BaseLine.h"
#include "../Headers/HilbertLine.h"
#include "../Headers/SierpinskiLine.h"
#include "../Headers/KochLine.h"
#include "../Headers/PifagorTreeLine.h"
#include "../Headers/DragonLine.h"
#include "../Headers/HosperLine.h"
#include "../Headers/LeviLine.h"
#include "../Headers/MinkovskiyLine.h"

namespace fractal_lines {
	enum class _draw_line_mode : int {
		DRAW_LINE_DISABLED = 0,
		HILBERT_LINE,
		SIERPINSKI_LINE,
		KOCH_LINE,
		KOCH_STAR,
		NAKED_PIFAGORE_TREE,
		PIFAGORE_TREE,
		DRAGON_LINE,
		HOSPER_LINE,
		SIERPINSKI_LINE_2,
		LEVI_LINE,
		MINKOVSKIY_LINE
	};

	template<typename T, typename U>
	auto MakeFractalLines(std::shared_ptr<T> pdc, std::shared_ptr<U> prect, const _draw_line_mode& mode)
	{
		auto fractal_line = std::make_unique<BaseLine>();
		switch (mode)
		{
			case _draw_line_mode::HILBERT_LINE:
				fractal_line.reset(new HilbertLine(pdc, prect));
				break;
			case _draw_line_mode::SIERPINSKI_LINE:
				fractal_line.reset(new SierpinskiLine(pdc, prect));
				break;
			case _draw_line_mode::KOCH_LINE:
				fractal_line.reset(new KochLine(pdc, prect));
				break;
			case _draw_line_mode::NAKED_PIFAGORE_TREE:
				fractal_line.reset(new NakedPifagorTree(pdc, prect));
				break;
			case _draw_line_mode::PIFAGORE_TREE:
				fractal_line.reset(new PifagorTree(pdc, prect));
				break;
			case _draw_line_mode::KOCH_STAR:
				fractal_line.reset(new KochStarLine(pdc, prect));
				break;
			case _draw_line_mode::DRAGON_LINE:
				fractal_line.reset(new DragonLine(pdc, prect));
				break;
			case _draw_line_mode::HOSPER_LINE:
				fractal_line.reset(new HosperLine(pdc, prect));
				break;
			case _draw_line_mode::SIERPINSKI_LINE_2:
				fractal_line.reset(new SierpinskiLine2(pdc, prect));
				break;
			case _draw_line_mode::LEVI_LINE:
				fractal_line.reset(new LeviLine(pdc, prect));
				break;
			case _draw_line_mode::MINKOVSKIY_LINE:
				fractal_line.reset(new MinkovskiyLine(pdc, prect));
				break;
			default:
				break;
		}

		return fractal_line;
	}
}

#endif