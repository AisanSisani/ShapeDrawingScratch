#pragma once

#include "Shape.h"

class Image {
private:
	char* lable;
	int precedence;
	Shape** list_shape;
	int no_shapes; //stors the current number of shapes in the list_shapes  
	bool show;     //a variable used when toggle is used False->not show
public:
	Image(); //default constructor
	//three constructors
	Image(const char*);
	Image(int);
	Image(const char*, int);


	Image(const Image&); //copy constructor
	~Image();

	int get_precedence() const;
	char* get_lable() const;
	bool get_show() const;

	void set_show(bool);
	void set_precedence(int n);
	void set_lable(const char*);

	void add_shape(Shape&);

	void draw_image(char** canvas); //needs renderers class and canvas
	void draw_one_type_shapes(char**, int); //only one shape

	void show_detail_one_shape(const Shape&) const;
	void show_detail_all_shapes() const; 
	void search_shape(const char*) const; //using lable shows all the content

	friend void sort_images(Image** list, int);
};