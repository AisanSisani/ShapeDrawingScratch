//Aisan Sisani 2279073


#include "Point.h"
#include "Circle.h"
#include "Quadrilateral.h"
#include "Triangle.h"
#include "Line.h"
#include "Renderer.h"

#include "FileIO.h"

#include <iostream>

using std::cout;
using std::cin;

int main(int argc, char* argv[]) {
	// define the renderer object here
	Renderer R;

	if (argc < 2) {
		int option;      //stores the option which user chooses
		char lable[81];  //stores the lables for different objects which user chooses
		char font;       //stores the font for different objects which user chooses
		int x, y;        //stores the needed different int values different objects which user chooses
		int exit = 0;    //a var for the control over terminating the program
		int ptcount;     //stores the number of points for different shapes

		while (exit != 1) {
			cout << "Welcome to Interactive Shape Drawing!" << endl;
			cout << "1.Describe an Image" << endl;
			cout << "2.Render Images" << endl;
			cout << "3.Exit" << endl;
			cout << '>';
			cin >> option;


			if (option == 1) {
				//defining the image by heap
				Image* img;               
				img = new Image();
				

				cout << "Enter a lable for the image:" << endl;
				cout << '>';
				cin >> lable;
				img->set_lable(lable);



				cout << "Enter the precedence for this image:" << endl;
				cout << '>';
				cin >> x;
				img->set_precedence(x);


				Shape* shP = NULL;
				Point* pP = NULL;

				option = 1; //by default so that we enter the while loop
				while (option != 5) {
					cout << "Enter shape type to add to this image:" << endl;
					cout << '\t' << "1. Circle" << endl;
					cout << '\t' << "2. Line" << endl;
					cout << '\t' << "3. Triangle" << endl;
					cout << '\t' << "4. Quadrilateral" << endl;
					cout << '\t' << "5. finish Image" << endl;
					cout << '>';
					cin >> option;


					if (option == 2) {  //if line is chosen
						cout << "Enter a lable for the shape:" << endl;
						cout << '>';
						cin >> lable;

						cout << "Enter a font to use:" << endl;
						cout << '>';
						cin >> font;

						shP = new Line(font, lable);

						ptcount = 2;
					}
					else if (option == 4) { //if quadrilateral is chosen is chosen
						cout << "Enter a lable for the shape:" << endl;
						cout << '>';
						cin >> lable;

						cout << "Enter a font to use:" << endl;
						cout << '>';
						cin >> font;

						shP = new Quadrilateral(font, lable);

						ptcount = 4;
					}
					else if (option == 3) { //if tirangle is chosen
						cout << "Enter a lable for the shape:" << endl;
						cout << '>';
						cin >> lable;

						cout << "Enter a font to use:" << endl;
						cout << '>';
						cin >> font;

						shP = new Triangle(font, lable);

						ptcount = 3;
					}
					else if (option == 1) { //if circle is chosen
						cout << "Enter a lable for the shape:" << endl;
						cout << '>';
						cin >> lable;

						cout << "Enter a font to use:" << endl;
						cout << '>';
						cin >> font;

						cout << "Enter the radius for the shape:" << endl;
						cout << '>';
						cin >> x;

						shP = new Circle(x, font, lable);

						ptcount = 1;
					}
					else if (option == 5) {
						//do nothing
					}
					else {
						cout << "option is not valid" << endl;
					}

					//if a shape was chosen gets the points and adds to the shape
					if (option == 1 || option == 2 || option == 3 || option == 4) { 
						for (int i = 0; i < ptcount; ++i) {
							cout << "Enter point " << i + 1 << ":" << endl;
							cout << '>';
							cin >> x >> y;

							cout << "Enter a lable for the point:" << endl;
							cout << '>';
							cin >> lable;

							pP = new Point(lable, x, y);
							shP->add_points(*pP);

						}
					}

					// if a shape was chossen adds the shape to image
					if (option == 1 || option == 2 || option == 3 || option == 4) {
						img->add_shape(*shP);
					}
				}

				//adds the image to the renderer class using aggrigation
				R.add_image(*img);

			}

			else if (option == 2) {
				int exit = 0; //for the control over the termination of the loop
				while (!exit) {
					cout << '\t' << "1. Render images" << endl;
					cout << '\t' << "2. Toggle display of an image" << endl;
					cout << '\t' << "3. Render only specific shapes" << endl;
					cout << '\t' << "4. Toggle rendering precedenece" << endl;
					cout << '\t' << "5. Details of images" << endl;
					cout << '\t' << "6. Exit" << endl;
					cout << '>';
					cin >> option;

					if (option == 1) {
						R.render_images();
					}
					else if (option == 2) {
						cout << "Enter the name of the image to be toggled:" << endl;
						cout << '>';
						cin >> lable;
						R.toggle_drawing_image(lable);
					}
					else if (option == 3) {
						cout << "Enter the type of the shapes to be rendered:" << endl;
						cout << '\t' << "1. Circle" << endl;
						cout << '\t' << "2. Line" << endl;
						cout << '\t' << "3. Triangle" << endl;
						cout << '\t' << "4. Quadrilateral" << endl;
						cout << '>';
						cin >> option;
						if (option > 0 && option < 5) {
							R.render_specific_shapes(option);
						}
						else {
							cout << "Invalid Type" << endl;
						}

					}
					else if (option == 4) {
						R.toggle_order();
					}
					else if (option == 5) {
						R.show_detail_images();
					}
					else if (option == 6) {
						exit = 1;
					}
					else {
						cout << "Invalid option" << endl;
					}
				}

			}
			else if (option == 3) {
				cout << endl << "Goodbye!" << endl;
				exit = 1;
			}
			else {
				cout << "this option is not valid" << endl;
			}
		}


	}
	else {
		// file IO -- load your renderer here
		FileIO finput;
		finput.loadFile(R, argv[1]);

		int stop;
		cin >> stop;
	}

	
	return 0;
}
