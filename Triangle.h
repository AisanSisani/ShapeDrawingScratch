#pragma once

#include"Shape.h"

class Triangle :public Shape {
public:
	Triangle();
	Triangle(char font, const char* lable);
	Triangle(int n, char f, const char* s);
};
