#include "FileIO.h"
#include <filesystem>



/*
You need to:

1- Add your headers.
2- Change the "run" function below accordingly.
3- Build your project. A sample output is provided under "sample.txt". Simply drag this over to your exe.
*/

/*
******************************
Include your headers from here
******************************
*/

#include "Point.h"
#include "Shape.h"
#include "Circle.h"
#include "Quadrilateral.h"
#include "Triangle.h"
#include "Line.h"
#include "Image.h"
#include "Renderer.h"



/* DO: Put your student number here.*/
const string foutname("e227907.txt");

/*
******************************
To here
******************************
*/

using std::string;
using std::getline;

// setup the result file to be saved as this file's name
FileIO::FileIO() :
	result(foutname) { }

void FileIO::loadFile(Renderer& R, const char* fname) {
	ifstream f(fname);
	if(f.is_open())
		run(R, f);
}

/*
****************************************************************************
You only need to change this function here! NO OTHER FUNCTION NEEDS CHANGES!
****************************************************************************
*/
void FileIO::run(Renderer& R, ifstream& f) {
	string tmp, header, objtype, buf;
	int precedence = 0, pts = 0, x, y;
	size_t ptcount = 0, shapecount = 0;
	char font;
	istringstream ss;

	// redirect the output buffer to use the result file                           
	auto coutbuffer = cout.rdbuf(result.rdbuf());

	while (getline(f, tmp)) { //gets the stirng from the input file f
		// comment
		if (tmp[0] == '#')
			continue;
		// image definition
		
		
		if (!tmp.compare("image")) {
			// DO: Create your image here
			Image* img;
			img = new Image();
			
			// read label
			getline(f, tmp);
			// DO: Set the label of your image here
			char* s = new char[tmp.size() + 1];
			strcpy(s, tmp.c_str());
			img->set_lable(s);

		


			// read precedence
			getline(f, tmp);
			ss.str(tmp);
			ss >> precedence >> shapecount;
			resetStream(ss);

			// DO: Set the precedence of your image here
			img->set_precedence(precedence);

			// while not another image block
			// DO: Define your shape pointer to be null here, and define a null Point pointer
			Shape* shP = NULL;
			Point* pP = NULL;
			
			while (shapecount) {                                 /*gets the shapes of the image*/
				getline(f, tmp);
				// get shape tag and the value seperately
				header = tmp.substr(0, 5);
				objtype = tmp.substr(6);

				// read the label and font
				getline(f, tmp);                                    /*tmp= "line 0"*/
				buf = tmp;                                         /*buf= "line 0"  shape lable*/
				getline(f, tmp);                                    /*tmp= "font *"*/
				font = tmp.substr(5)[0];                            /*font = '*'   */
				if (!objtype.compare("line")) {
					// DO: Create your line here
					char* s = new char[buf.size() + 1];
					strcpy(s, buf.c_str());
					shP= new Line(font, s);
					
					ptcount = 2;
				}
				else if (!objtype.compare("quad")) {
					// DO: Create your quad here
					char* s = new char[buf.size() + 1];
					strcpy(s, buf.c_str());
					shP = new Quadrilateral(font, s);
					
					ptcount = 4;
				}
				else if (!objtype.compare("triangle")) {
					// DO: Create your triangle here
					char* s = new char[buf.size() + 1];
					strcpy(s, buf.c_str());
					shP = new Triangle(font, s);
					
					ptcount = 3;
				}
				else if (!objtype.compare("circle")) {
					// get radius
					getline(f, tmp);
					ss.str(tmp);
					ss >> x;                                             /*x=radius*/
					resetStream(ss);

					// DO: Create your circle here
					char* s = new char[buf.size() + 1];
					strcpy(s, buf.c_str());
					shP = new Circle(x, font, s);

					
					ptcount = 1;
				}


				for (size_t i = 0; i < ptcount; ++i) {
					// read point name and coords
					getline(f, buf);                            /*buf="p0" point lable*/
					getline(f, tmp);                           /*tmp="0 0"*/
					ss.str(tmp);
					ss >> x >> y;                             /*x and y of points ithink they are int*/
					resetStream(ss);

					// DO: Build your point and add it to your shape here
					char* s = new char[buf.size() + 1];
					strcpy(s, buf.c_str()); 
					pP = new Point(s, x, y);
					shP->add_points(*pP);
					
				}
				// this was shape so we add it
				if (!header.compare("shape")) {
					--shapecount;
					// DO: Add your shape to the image here
					img->add_shape(*shP);

					
				}
			}
			// DO: Add your image to the renderer
			R.add_image(*img);
			
		}
		else if (!tmp.compare("draw")) {
			// DO: Use the renderer to draw the images here                               /*draw all the images 1.render images*/
			R.render_images();
			
		}
		else if (!tmp.compare("toggleDraw")) {                                           /*4. toggle rendering precedence*/
			// DO: Call your renderer function to toggle the draw order from btf to ftb and vice versa
			R.toggle_order();
			
		}
		else if (!tmp.compare("specificDraw")) {                  /*we have just x here*/   /*3.render only specific shapes*/
			getline(f, tmp);
			ss.str(tmp);
			ss >> x;
			resetStream(ss);
			// DO: Call your renderer function to draw only specific shapes
			R.render_specific_shapes(x);
			
		}
		else if (!tmp.compare("toggleImage")) {
			getline(f, tmp);                                       
			// DO: Call your renderer function to toggle a specific image's draw, given label
			char* s = new char[tmp.size() + 1];
			strcpy(s, tmp.c_str());
			R.toggle_drawing_image(s);
			
		}
		else if (!tmp.compare("details")) {                                                   /*5.details of images*/
			// DO: Call your method to show details of everything in the renderer   
			R.show_detail_images();
			
		}
		else if (!tmp.compare("search")) {
			getline(f, tmp);                                                                  /*tmp = image lable*/
			// DO: Do your image search thing from renderer here, and display its details
			// If no image is found, you can print "Image not found."
			char* s = new char[tmp.size() + 1];
			strcpy(s, tmp.c_str());
			R.search_image(s);
		}
	}
	// restore the output buffer to normal -- close before doing so so the output is properly written
	result.close();
	cout.rdbuf(coutbuffer);
	cout << "File was parsed and ran successfully.\n";
}

void FileIO::resetStream(istringstream& ss) const {
	ss.str(string());
	ss.clear();
}
