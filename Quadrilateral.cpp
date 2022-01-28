#include"Quadrilateral.h"

Quadrilateral::Quadrilateral() : Shape(4, '*', "DefaultQuadrilateral") {};
Quadrilateral::Quadrilateral(char font, const char* lable) : Shape(4, font, lable) {};
Quadrilateral::Quadrilateral(int n, char f, const char* s) :Shape(4, f, s) {
	if (n != 4) {
		cout << "a Quadrilateral can just have four points" << endl;
	}
}