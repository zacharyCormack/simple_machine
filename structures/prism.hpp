#pragma once
#include "line.hpp"
#include "angle.hpp"

struct prism {
	line core;
	int thickness[2];
	angle rotation;
};