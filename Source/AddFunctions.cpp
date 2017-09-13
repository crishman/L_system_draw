#include "stdafx.h"
#include <cmath> 
#include <map>
#include "../Headers/AddFunctions.h"

namespace custom_math {

	std::map<int, double> sin_by_dir;
	std::map<int, double> cos_by_dir;

	const double koef_pi = 3.14159265 / 180;

	double sin(const int& dir) {
		auto sin_it = sin_by_dir.find(dir);
		double res;

		if (sin_it != sin_by_dir.end()) {
			res = sin_it->second;
		}
		else {
			res = std::sin(dir * koef_pi);
			sin_by_dir.insert(std::pair<int, double>(std::move(dir), res));
		}

		return res;
	}

	double cos(const int& dir) {
		auto cos_it = cos_by_dir.find(dir);
		double res;

		if (cos_it != cos_by_dir.end()) {
			res = cos_it->second;
		}
		else {
			res = std::cos(dir * koef_pi);
			cos_by_dir.insert(std::pair<int, double>(std::move(dir), res));
		}

		return res;
	}

	int int_round(double&& d) {
		return static_cast<int>(std::round(d));
	}
}