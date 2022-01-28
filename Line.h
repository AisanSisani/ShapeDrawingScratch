#pragma once
#include"Shape.h"


class Line:public Shape {
public:
	Line();
	Line(char font, const char* lable);
	Line(int n, char f, const char* s);

	void show_side_lengths() const;
};
 