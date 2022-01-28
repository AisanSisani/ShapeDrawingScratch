#pragma once
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;


class Point
{
protected:
	int x;
	int y;
	char *lable;
public:
	Point();
	Point(const char*, int, int); 
	Point(const Point&);
	~Point();
	Point& operator=(const Point&);  

	int getx() const;
	int gety() const;
	const char* getlable() const;

	void setx(int x);
	void sety(int y);
	void setlable(const char* s);

	friend double distance(const Point&, const Point&);
	void print_content() const;
};

