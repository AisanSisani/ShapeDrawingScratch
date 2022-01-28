

#pragma once
#include <string.h>
#include <math.h>
#include <iostream>
#include "Point.h"
using namespace std;


class Shape {
protected:
	int no_of_points; //maximum number of points in the shape
	int curr_no_of_points; //current number of points added to the shape
	char font;
	char* lable;
	Point* points;

public:
	Shape();
	Shape(int, char, const char*); 
	Shape(const Shape&);
	~Shape();

	int get_curr_no_of_points() const;
	int get_no_of_points() const;
	char get_font() const;
	const char* get_lable() const;
	const Point* get_points() const; 

	//no setter for number of points it destroys the points array structure
	void set_font(char);
	void set_lable(const char*); 
	void set_points(const Point* , int); 

	void add_points(const Point&); 
	
	
	virtual void show_side_lengths() const;
	virtual void draw(char** canvas);
};

void draw_line(char font, char** canvas, int x0, int y0, int x1, int y1);

//gets a number and a max number if the number plus one 
//reaches max number returns 0 else return number plus one
int successor(int, int); 

void draw8Points(char font, char** canvas, int xc, int yc, int x, int y);
void draw_circle(char font, char** canvas, int xc, int yc, int r);