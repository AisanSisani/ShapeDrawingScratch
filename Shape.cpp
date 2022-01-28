

#include "Shape.h"

int successor(int i, int maxPone) {
	i++;
	if (i == maxPone) i = 0;
	return i;
}

Shape::Shape() {

	no_of_points = 5;
	curr_no_of_points = 0;
	font = '*';
	lable = new char[81];
	strcpy(lable, "DefaultShape");
	points = new Point[5]; 
}

Shape::Shape(int no, char f, const char* s) {

	no_of_points = no;
	curr_no_of_points = 0;
	font = f;
	lable = new char[strlen(s) + 1];
	strcpy(lable, s);
	points = new Point[no];
}

Shape::Shape(const Shape& sh) {
	no_of_points = sh.get_no_of_points();
	curr_no_of_points = sh.get_curr_no_of_points();
	font = sh.get_font();
	lable = new char[strlen(sh.get_lable()) + 1];
	strcpy(lable, sh.get_lable());

	points = new Point[no_of_points];
	for (int i = 0; i < no_of_points; i++) {
		points[i].setx(sh.get_points()[i].getx());
		points[i].sety(sh.get_points()[i].gety());
		points[i].setlable(sh.get_points()[i].getlable());
	}
}

Shape::~Shape() {
	delete[] lable;
	delete[] points;
}

int Shape::get_curr_no_of_points() const {
	return curr_no_of_points;
}

int Shape::get_no_of_points() const {
	return no_of_points;
}

char Shape::get_font() const {
	return font;
}

 const char* Shape::get_lable() const { 
	return lable;
}

const Point* Shape::get_points() const {
	return points;
}


void Shape::set_font(char f) {
	font = f;
}
void Shape::set_lable(const char* s) {
	delete[] lable;
	lable = new char[strlen(s) + 1];
	strcpy(lable, s);
}

void Shape::set_points(const Point* p, int no) {
	delete[] points;
	points = new Point[no];
	no_of_points = no;
	curr_no_of_points = 0;

	for (int i = 0; i < no; i++) {
		points[i].setx(p[i].getx());
		points[i].sety(p[i].gety());
		points[i].setlable(p[i].getlable());
	}

}

void Shape::add_points(const Point& p) {
	if (curr_no_of_points == no_of_points) {
		cout << "no more place for points in this shape" << endl;
	}
	else {
		points[curr_no_of_points].setx(p.getx());
		points[curr_no_of_points].sety(p.gety());
		points[curr_no_of_points].setlable(p.getlable());
		curr_no_of_points++;
	}
}


void Shape::show_side_lengths() const {
	cout << "Shape " << '"' << lable << "\":" << endl;
	cout << "Side lengths: " << endl;
	for (int i = 0; i < curr_no_of_points; i++) {
		cout << '\t';
		points[i].print_content();
		cout << '\t' << points[i].getlable() << '-' << points[successor(i, curr_no_of_points)].getlable();
		cout << '\t' << ": " << distance(points[i], points[successor(i, curr_no_of_points)]) << endl;
	}
}

void draw_line(char font, char** canvas, int x0, int y0, int x1, int y1) {
	int slope_inc;

	int dx = x1 - x0;
	int dy = y1 - y0;

	int xs = 1;
	int ys = 1;

	if (dy < 0) {
		dy = -dy;
		ys = -1;
	}
	if (dx < 0) {
		dx = -dx;
		xs = -1;
	}

	dy = 2 * dy;
	dx = 2 * dx;

	canvas[x0][y0] = font;

	slope_inc = 0;

	if (dx > dy) {
		slope_inc = dy - dx / 2; 
		while (x0 != x1) {
			if (slope_inc >= 0) {
				y0 = y0 + ys;
				slope_inc = slope_inc - dx;
			}
			x0 = x0 + xs;
			slope_inc = slope_inc + dy;

			canvas[x0][y0] = font;
		}
	}
	else {
		slope_inc = dx - dy / 2;      
		while (y0 != y1) {
			if (slope_inc >= 0) {
				x0 = x0 + xs;
				slope_inc = slope_inc - dy;
			}
			y0 = y0 + ys;
			slope_inc = slope_inc + dx;

			canvas[x0][y0] = font;
		}
	}


}


void Shape::draw(char** canvas) {
	for (int i = 0; i < curr_no_of_points; i++) {
		draw_line(font, canvas, points[i].getx(), points[i].gety(), points[successor(i, curr_no_of_points)].getx(), points[successor(i, curr_no_of_points)].gety());
	}
}

	void draw_circle(char font, char** canvas, int xc, int yc, int r) {
		int x = 0;
		int y = r;
		int d = 3 - 2 * r;
		draw8Points(font, canvas, xc, yc, x, y);

		while (y >= x) {
			x++;

			if (d > 0) {
				y--;
				d = d + 4 * (x - y) + 6;
			}
			else {
				d = d + 4 * x + 6;
			}
			draw8Points(font, canvas, xc, yc, x, y);
		}
	}

	void draw8Points(char font, char** canvas, int xc, int yc, int x, int y) {
		canvas[xc + x][yc + y] = font;
		canvas[xc - x][yc + y] = font;
		canvas[xc + x][yc - y] = font;
		canvas[xc - x][yc - y] = font;
		canvas[xc + y][yc + x] = font;
		canvas[xc - y][yc + x] = font;
		canvas[xc + y][yc - x] = font;
		canvas[xc - y][yc - x] = font;
	}



