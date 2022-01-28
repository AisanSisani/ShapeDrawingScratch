#include "Line.h"

Line::Line():Shape(2, '*', "DefaultLine") {};

Line::Line(char font, const char* lable) : Shape(2, font, lable) {};

Line::Line(int n, char f, const char* s) :Shape(2, f, s) {
	if (n != 2) {
		cout << "a Line can just have two points" << endl;
	}

};

void Line::show_side_lengths() const {
	cout << "Shape " << '"' << lable << "\":" << endl;
	cout << "Side lengths: " << endl;
		points[0].print_content();
		points[1].print_content();
		cout << '\t' << points[0].getlable() << '-' << points[1].getlable();
		cout << '\t' << ": " << distance(points[0], points[1]) << endl;
}