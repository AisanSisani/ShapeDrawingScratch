#include "Triangle.h"

Triangle::Triangle() : Shape(3, '*', "DefaultTriangle") {};
Triangle::Triangle(char font, const char* lable) : Shape(3, font, lable) {};
Triangle::Triangle(int n, char f, const char* s) :Shape(3, f, s) {
	if (n != 3) {
		cout << "a Triangle can just have three points" << endl;
	}

}