#include "Point.h"


int Point::getx() const { return x; }
int Point::gety() const { return y; }
const char* Point::getlable() const { return lable; }

void Point::setx(int x) { this->x = x; }
void Point::sety(int y) { this->y = y; }

void Point::setlable(const char* s) {
	delete lable;
	lable = new char[strlen(s) + 1];
	strcpy(lable, s);
}
Point::Point()
{
	x = 30;
	y = 30;
	char def[81] = "DefaultPoint"; 
	lable = new char[81];
	strcpy(lable, def);

}

Point::Point(const char* s, int x, int y) {
	this->x = x;
	this->y = y;
	lable = new char[strlen(s) + 1];
	strcpy(lable, s);
}

Point::Point(const Point& p) {
	this->x = p.x;
	this->y = p.y;
	lable = new char[strlen(p.lable) + 1];
	strcpy(lable, p.lable); p;
}

Point& Point::operator=(const Point& p) {

	delete lable;
	lable = new char[strlen(p.lable) + 1];
	strcpy(lable, p.lable);

	x = p.x;
	y = p.y;

	return *this;
}

Point::~Point()
{
	delete[] lable;
}

double distance(const Point& p1, const Point& p2) {
	return sqrt(pow((p1.getx() - p2.getx()), 2) + pow( (p1.gety() - p2.gety() ), 2) );
}

void Point::print_content() const{
	cout <<lable <<"(" <<x <<","<< y <<")"<< endl;
}



