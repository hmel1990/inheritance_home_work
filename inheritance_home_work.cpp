#include<iostream>
using namespace std;
#include <string>
#include <cmath>


class Figure 
{
protected:
	float width;
	float height;	
public:

	Figure()
	{
		set_height(1);
		set_width(1);
	}

	void set_width(float width)
	{
		this->width = width;
	}
	float get_width()
	{
		return width;
	}


	void set_height(float height)
	{
		this->height = height;
	}


	float get_height()
	{
		return height;
	}

	float square()
	{
		return height * width;		
	}

	float perimetr()
	{
		return (height + width) * 2;
	}
	void draw()
	{
		cout << "\ndrawing figure";
	}
};

class Point:public Figure 
{
public:
	Point() 
	{
		set_height(0);
		set_width(0);
	}

	float perimetr() = delete;
	float square() = delete;

	void draw()
	{
		cout << "\ndrawing point";
	}
};


class Line:public Figure
{
public:
	Line()
	{
		set_height(0);
		set_width(1);
	}


	float perimetr() = delete;
	float square() = delete;
	void draw()
	{
		cout << "\ndrawing line";
	}
};

class Ellipse:public Figure
{
protected:
	float major_axis;
	float minor_axis;
public:

	void set_major_axis(float major_axis)
	{
		this->major_axis = major_axis;
	}

	void set_minor_axis(float minor_axis)
	{
		this->minor_axis = minor_axis;

	}

	float get_minor_axis()
	{
		return minor_axis;
	}

	float get_major_axis()
	{
		return major_axis;
	}

	Ellipse()
	{
		set_major_axis(2);
		set_minor_axis(1);
	}

	double square()
	{
		return 3.14159* minor_axis * major_axis;
	}
	double perimetr()
	{
		return 3.14159 * (3 * (major_axis + minor_axis) - sqrt((3 * major_axis + minor_axis) * (major_axis + 3 * minor_axis)));
	}


	void draw()
	{
		cout << "\ndrawing Ellipse";
	}

};


class Polygon :public Figure
{
protected:
	float length;
public:

	void set_length(float length)
	{
		this->length = length;
	}


	float get_length()
	{
		return length;
	}
	Polygon()
	{
		set_length(5);
	}
	void draw()
	{
		cout << "\ndrawing Polygon";
	}

	double square()
	{
		return (1.0 / 4) * sqrt(5 * (5 + 2 * sqrt(5))) * length * length;;
	}
	double perimetr()
	{
		return 5*length;
	}


};

class Circle :public Ellipse
{
public:
	Circle() {
		major_axis = minor_axis = 1; 
	}

	void set_radius(float radius) {
		major_axis = minor_axis = radius;
	}

	float get_radius() 
	{
		return major_axis; 
	}

	float square() 
	{
		return 3.14159 * major_axis * major_axis;
	}

	float perimetr() 
	{
		return 2 * 3.14159 * major_axis;
	}

	void draw()  
	{
		cout << "\nDrawing Circle";
	}
};
class Triangle : public Polygon {
public:
	Triangle() 
	{ 
		length = 1; 
	}

	float square()  {
		float height = sqrt(length * length - (length / 2) * (length / 2));
		return (length * height) / 2;
	}

	float perimetr()  
	{
		return 3 * length;
	}

	void draw()  
	{
		cout << "\nDrawing Triangle";
	}
};

class Quadrilateral : public Polygon {
public:
	Quadrilateral() { length = 1; }

	float square()  
	{
		return length * length; 

	}

	float perimetr()  
	{
		return 4 * length;
	}

	void draw()  
	{
		cout << "\nDrawing Quadrilateral";
	}
};
class Parallelogram : public Quadrilateral {};
class Rectangle : public Parallelogram 
{
public:
	float square()  
	{
		return width * height;
	}

	float perimetr()  
	{
		return 2 * (width + height);
	}

	void draw()  
	{
		cout << "\nDrawing Rectangle";
	}
};

class Rhombus : public Parallelogram {
public:
	float square()  
	{
		return (width * height) / 2; 
	}

	void draw()  
	{
		cout << "\nDrawing Rhombus";
	}
};
class Square : public Rectangle 
{
public:
	Square() 
	{ 
		width = height = 1; 
	}

	void set_side(float side) 
	{
		width = height = side;
	}

	float square()  
	{
		return width * width;
	}

	float perimetr()  
	{
		return 4 * width;
	}

	void draw()  
	{
		cout << "\nDrawing Square";
	}
};



int main()
{
	Figure f;
	f.set_height(10);
	f.set_width(5);
	cout << f.square();
	f.draw();

	Point p;
	p.draw();
}