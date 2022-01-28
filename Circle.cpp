
#include "Circle.h"

Circle::Circle() : Shape(1, '*', "DefaultCircle") { r = 10; };
Circle::Circle(int r, char font, const char* lable) : Shape(1, font, lable) {
	this->r = r;
}
Circle::Circle(int radius, int n, char f, const char* s) :Shape(1, f, s) {
	r = radius;
	if (n != 1) {
		cout << "a Cicle can just have one points" << endl;
	};
};

void Circle::show_side_lengths() {
	cout << "Shape " << '"' << lable << "\":" << endl;
	cout << "Side lengths: " << endl;
	cout << '\t' << "Center: ";
	points[0].print_content();
	cout << '\t' << "Radius: " << r << endl;;
}

void Circle::draw(char** canvas){
	draw_circle(font, canvas, points[0].getx(), points[0].gety(), r);
}
