#include <iostream>
#include <conio.h>
using namespace std;

class Point {
public:
	int x, y;
	Point() {
		printf("Point()\n");
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		printf("Point(int x, int y)\n");
		this->x = x;
		this->y = y;
	}
	Point(const Point& p) {
		printf("Point(const Point&p)\n");
		x = p.x;
		y = p.y;
	}
	~Point() {
		printf("~Point()\n");
		printf("%d, %d\n", x, y);

	}
	void move(int x, int y) {
		this->x += x;
		this->y += y;
	}
	void randomc();

};

void Point::randomc() {
	y = rand() % 20;
	x = rand() % 20;
}

class Point3d : public Point {
public:

	int z;

public:

	Point3d() : Point() {
		printf("Point3d()\n");
		z = 0;
	}
	Point3d(int x, int y, int z) : Point(x, y) {
		printf("Point3d(int x, int y, int z)\n");
		this->z = z;
	}
	Point3d(const Point3d& p) {
		printf("Point3d(const Point3d&p)\n");
		x = p.x;
		y = p.y;
		z = p.z;
	}
	~Point3d() {
		printf("~Point3d()\n");
		printf("%d, %d, %d\n", x, y, z);

	}
	void move(int x, int y) {
		this->x += x;
		this->y += y;
		this->z += z;
	}
	void randomc3d() {
		y = rand() % 20;
		x = rand() % 20;
		z = rand() % 20;
	}


};

class line {
protected:
	
	Point3d* p1;
	Point3d* p2;
public:
	line() {
		printf("line()\n");
		p1 = new Point3d;
		p2 = new Point3d;
	}
	line(int x1, int y1, int z1, int x2,int y2, int z2) {
		cout <<"line(int x1, int y1, int z1, int x2,int y2, int z2)"<<endl;
		p1 = new Point3d;
		p2 = new Point3d;
		this->p1->x = x1;
		this->p1->y = y1;
		this->p1->z = z1;
		this->p2->x = x2;
		this->p2->y = y2;
		this->p2->z = z2;

	}
	line(Point3d& p11, Point3d& p22) {
		printf("line(Point3d p1, Point3d p2)\n");
		p1 = new Point3d(p11);
		p2 = new Point3d(p22);
	}
	line(const line& l) {
		printf("line(const leni&l)\n");
		p1 = new Point3d(*(l.p1));
		p2 = new Point3d(*(l.p2));
	
	}
	~line() {
		printf("~line()\n");
		printf("%d, %d, %d, %d,%d,%d\n", p1->x,p1->y, p1->z, p2->x,p2->y, p2->z);
		delete p1;
		delete p2;
		

	}


};

class test : Point {

};

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "создание потомков";
	{
		Point3d* p = new Point3d(1, 2, 3);;
		Point3d* p2 = new Point3d(10, 20, 30);
		cout << "точки созданы"<<endl<<endl;
		line* l1= new line(*p,*p2);
		cout << "создана 1я линия" << endl << endl;
		line* l2 = new line(*l1);
		cout << "создана 2я линия" << endl << endl;
		line* l3 = new line(1,1,1,15,25,35);
		cout << "создана 3я линия" << endl << endl;
		delete l1;
		cout << "удалена 1я линия" << endl << endl;
		delete l2;
		cout << "удалена 2я линия" << endl << endl;
		delete l3;
		cout << "удалена 3я линия" << endl << endl;
		delete p;
		delete p2;
		

	}
	cout << "Конец" << endl << endl;


	cout << "помещение потомка в базовый класс";
	{
		Point* p = new Point3d(10, 20, 30);

		delete p;
	}
	cout << "Конец" << endl << endl;


	
	
	return 0;

}