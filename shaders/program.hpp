#pragma once
#include "Shader.hpp"

class Program {
	void bind(float* points);
	void activate();
	int type;
	int ID;
public:
	void draw(float*);
	Program(Shader*, int);
};