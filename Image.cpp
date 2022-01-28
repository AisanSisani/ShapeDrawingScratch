#include "Image.h"

Image::Image() {
	lable = new char[81];
	strcpy(lable, "DefautImage");

	precedence = 0;
	no_shapes = 0;
	show = true;
	 
	list_shape = new Shape* [10]; 
	for (int i = 0; i < 10; i++) {
		list_shape[i] = NULL; 
	}
}

Image::Image(const char* s) {
	lable = new char[strlen(s) + 1];
	strcpy(lable, s);

	precedence = 0;
	no_shapes = 0;
	show = true;

	list_shape = new Shape * [10];
	for (int i = 0; i < 10; i++) {
		list_shape[i] = NULL; 
	}
}

Image::Image(int no) {
	lable = new char[81];
	strcpy(lable, "DefautImage");

	precedence = no;
	no_shapes = 0;
	show = true;
	list_shape = new Shape * [10];
	for (int i = 0; i < 10; i++) {
		list_shape[i] = NULL;
	}
}
Image::Image(const char* s, int no) {
	lable = new char[strlen(s) + 1];
	strcpy(lable, s);

	precedence = no;
	no_shapes = 0;
	show = true;
	list_shape = new Shape * [10];
	for (int i = 0; i < 10; i++) {
		list_shape[i] = NULL; 
	}
}

Image::Image(const Image& img) {
	lable = new char[strlen(img.get_lable()) + 1];
	strcpy(lable, img.get_lable());

	precedence = img.precedence;
	no_shapes = img.no_shapes;
	show = img.show;

	list_shape = new Shape * [10];
	for (int i = 0; i < 10; i++) {
		list_shape[i] = img.list_shape[i]; 
	}
}

Image::~Image() { 
	delete[] lable;

	/*for (int i = 0; i < 5; i++) I am not deleting them because of concept of aggrigation
		delete list_shape[i];*/
	delete[] list_shape;
}

int Image::get_precedence() const {
	return precedence;
}

char* Image::get_lable() const{
	return lable;
}

void Image::set_precedence(int no) {
	precedence = no;
}

void Image::set_lable(const char* s) {
	delete[] lable;

	lable = new char[strlen(s) + 1];
	strcpy(lable, s);
}

void Image::add_shape(Shape& sh) {
	if (no_shapes < 10) {
		list_shape[no_shapes] = &sh;
		no_shapes++;
	}
	else {
		cout << "this image is full of shapes! no more space!" << endl;
	}
}
void Image::show_detail_one_shape( const Shape& sh) const {
	sh.show_side_lengths();
}

void Image::show_detail_all_shapes() const {
	cout << "Image " << '"' << lable << "\" properties:" << endl;
	for (int i = 0; i < no_shapes; i++) {
		show_detail_one_shape(*(list_shape[i]));
	}
}

void Image::search_shape(const char* s) const {
	int found = 0;
	for (int i = 0; i < no_shapes; i++) {
		if (!strcmp(list_shape[i]->get_lable(), s)) {
			show_detail_one_shape(*(list_shape[i]));
			found = 1;
		}
	}
	if (!found) cout << "Shape not found" << endl;
}

void Image::draw_image(char** canvas) {
	for (int i = 0; i < no_shapes; i++) {
		list_shape[i]->draw(canvas);
	}
}

void Image::draw_one_type_shapes(char** canvas, int no_of_points) {
	
	for (int i = 0; i < no_shapes; i++) {
		if (list_shape[i]->get_no_of_points() == no_of_points) {
			list_shape[i]->draw(canvas);
		}
	}
}

bool Image::get_show() const {
	return show;
}

void Image::set_show(bool i) {
	show=i;
}