#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Shape{
protected:
	int _r;
	int _w;
	int _h;

public:
	Shape(double r) : _r(r) {}
	Shape(double w, double h) : _w(w), _h(h) {}
	virtual double area(vector<Shape *>) = 0;
};

class Circle : public Shape{
public:
	Circle(double r) : Shape(r) {}
	double area(vector<Shape *>) { return _r*_r*atan(1)*4.0; }
};

class Triangle : public Shape{
public:
	Triangle(double s) : Shape(s) {}
	double area(vector<Shape *>) { return sqrt(3) * pow(_r, 2) / 4; }
};

class Rectangle : public Shape{
public:
	Rectangle(double w, double h) :Shape(w, h) {}
	double area(vector<Shape *>) { return  _w * _h ;}
};

int main()
{
	
	int n;
	char info;
	int value;
	int value2;
	double sum;
	vector<Shape*> collection;
	vector<int> answer;

	sum = 0;

	cin >> n;

	for(int i = 0 ; i < n + 1; i++)
	{
		cin >> info;
		if (info == 'C')
		{
			cin >> value;
			Circle c(value);
			collection.push_back(&c);
		}
		else if (info == 'R')
		{
			cin >> value;
			cin >> value2;
			Rectangle r(value, value2);
			collection.push_back(&r);
		}
		else
		{
			cin >> value;
			Triangle t(value);
			collection.push_back(&t);
		}
	}
	for (int i = 0; i < n + 1 ; i++)
	{
		sum += collection[i] -> area(collection);
	}
	cout << fixed << setprecision(2) << sum << endl;
}
