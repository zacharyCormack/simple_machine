#pragma once
#include "Shader.hpp"

class Program {
	void activate();
	int type;
	int ID;
public:
	void draw(unsigned, unsigned, unsigned);
	Program(Shader*, int);
};