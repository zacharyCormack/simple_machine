#pragma once
#include "line.hpp"
#include "angle.hpp"

struct prism
{
	line core;
	double thickness[2];
	struct angle rotation;
};