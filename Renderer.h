#pragma once
#include "Image.h"

//draw groups of Images 
class Renderer{
private:
	Image** list_image;  
	int no_images;    //stores the current number of images in list_image
	char** canvas; 
	int render_order; //a var that shpws the rendering order 
	                  // if zero printing from less precedence to high
	                  //and if one vice versa

public:
	Renderer();
	~Renderer();

	char** get_canvas() const;
	void add_image(Image&);
	void search_image(const char*) const; 
	void show_detail_images() const; 

	void toggle_order(); 
	void toggle_drawing_image(const char* s); 
	
	void render_images(); 
	void render_specific_shapes(int type); //renders based on the number of points

	void clear_canvas();
	void print_canvas();

};