#pragma once

#include"Shape.h"

class Quadrilateral :public Shape {
public:
	Quadrilateral() ;
	Quadrilateral(char font, const char* lable);
	Quadrilateral(int n, char f, const char* s);
};