#include "Renderer.h"

Renderer::Renderer() {

	list_image = new Image * [5];
	for (int i = 0; i < 5; i++) {
		list_image[i] = NULL; 
	}

	no_images = 0;
	render_order = 0;

	canvas = new char* [81];
	for (int i = 0; i < 81; i++)
		canvas[i] = new char[81];

	for (int i = 0; i < 81; i++) {
		for (int j = 0; j < 81; j++) {
			canvas[i][j] = ' ';
		}
	}
}

Renderer::~Renderer() {
	for (int i = 0; i < 81; i++)
		delete[] canvas[i];
	delete[] canvas;

	/*for (int i = 0; i < 5; i++)  I am not deleting them because of concept of aggrigation
		delete list_image[i];*/
	delete[] list_image;
}
void sort_images(Image** list, int no_images) {
	int i, key ,j;
	Image* inside_key;
	for (i = 1; i < no_images; i++) {
		key = list[i]->get_precedence();
		inside_key = list[i];
		j = i - 1;

		while (j >= 0 && list[j]->get_precedence() > key) {
			list [j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = inside_key;
	}
}

void Renderer::add_image(Image& img) {
	if (no_images < 5) {
		list_image[no_images] =&img;
		no_images++;

		sort_images(list_image, no_images);
	}
	else {
		cout << "this rendere is full of images! no more space!" << endl;
	}
}

void Renderer::search_image(const char* s) const{
	int found = 0;
	for (int i = 0; i < no_images; i++) {
		if (!strcmp(list_image[i]->get_lable(), s)) {
			list_image[i]->show_detail_all_shapes();
			found = 1;
		}
	}
	if (!found) cout << "Shape not found" << endl;
}

void Renderer::show_detail_images() const {

	for (int i = 0; i < no_images; i++) {
		list_image[i]->show_detail_all_shapes();
	}
}

void Renderer::toggle_order() {
	if (render_order == 0) render_order = 1;
	else render_order = 0;
}

void Renderer::clear_canvas() {

	for (int i = 0; i < 81; i++) {
		for (int j = 0; j < 81; j++) {
			 canvas[i][j] = ' ';
		}
	}
}


char** Renderer::get_canvas() const {
	return canvas;
}

void  Renderer::print_canvas(){
	for (int i = 0; i < 83; i++) cout << '#';
	cout << endl;
	for (int i = 0; i < 81; i++) {
		cout << '#';
		for (int j = 0; j < 81; j++) {
			cout << canvas[j][i];
		}
		cout << '#';
		cout << endl;
	}


	for (int i = 0; i < 83; i++) cout << '#';
	cout << endl;
	clear_canvas();
}

void Renderer::toggle_drawing_image(const char* s) {
	int found=0;
	for (int i = 0; i < no_images; i++) {
		if (!strcmp(list_image[i]->get_lable(), s)) {
			found = 1;
			list_image[i]->set_show(!(list_image[i]->get_show()));
		}
	}
	if (found == 0) {
		cout << "image can not be found" << endl;
	}
}

void Renderer::render_images() {
	if (render_order == 0) {
		for (int i = 0; i < no_images; i++) {
			if (list_image[i]->get_show()) {
				list_image[i]->draw_image(canvas);
			}
		}
	}
	else {
		for (int i = no_images-1; i >= 0; i--) {
			if (list_image[i]->get_show()) {
				list_image[i]->draw_image(canvas);
			}
		}
	}
	
	print_canvas();
	clear_canvas(); 
}

void Renderer::render_specific_shapes(int type) {

	for (int i = 0; i < no_images; i++) {
		if (list_image[i]->get_show()) {
			list_image[i]->draw_one_type_shapes(canvas, type);
		}
		
	}

	print_canvas();
	clear_canvas();
}

