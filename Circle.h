#pragma once
#include"Shape.h"


class Circle :public Shape {
private:
	int r;  //radius
public:
	Circle(); //default constructor
	Circle(int r, char font, const char* lable); //constructor
	Circle(int radius, int n, char f, const char* s); //constructor n-> in case the user enter the number of points handles the error

	virtual void show_side_lengths(); //shows the  point and radius
	virtual void draw(char** canvas); //draw the circle
};

