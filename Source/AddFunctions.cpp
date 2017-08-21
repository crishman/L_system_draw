#include "stdafx.h"
#include <cmath> 
#include <map>
#include "../Headers/AddFunctions.h"

#define PI 3.14159265

std::map<int, double> sin_by_dir;
std::map<int, double> cos_by_dir;

const double koef_pi = PI / 180;

double get_sin(int dir) {
	auto sin_it = sin_by_dir.find(dir);
	double res;

	if (sin_it != sin_by_dir.end()) {
		res = sin_it->second;
	}
	else {
		res = std::sin(dir * koef_pi);
		sin_by_dir.insert(std::pair<int, double>(dir, res));
	}

	return res;
}

double get_cos(int dir) {
	auto cos_it = cos_by_dir.find(dir);
	double res;

	if (cos_it != cos_by_dir.end()) {
		res = cos_it->second;
	}
	else {
		res = std::cos(dir * koef_pi);
		cos_by_dir.insert(std::pair<int, double>(dir, res));
	}

	return res;
}