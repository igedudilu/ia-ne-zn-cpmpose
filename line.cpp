#include "line.h"
line::line() {
	printf("line()\n");
	p1 = new Point3d;
	p2 = new Point3d;
}
line::line(int x1, int y1, int z1, int x2, int y2, int z2) {
	printf("line(int x1, int y1, int z1, int x2,int y2, int z2)\n");
	p1 = new Point3d;
	p2 = new Point3d;
	this->p1->x = x1;
	this->p1->y = y1;
	this->p1->z = z1;
	this->p2->x = x2;
	this->p2->y = y2;
	this->p2->z = z2;

}
line::line(Point3d& p11, Point3d& p22) {
	printf("line(Point3d p1, Point3d p2)\n");
	p1 = new Point3d(p11);
	p2 = new Point3d(p22);
}
line::line(const line& l) {
	printf("line(const leni&l)\n");
	p1 = new Point3d(*(l.p1));
	p2 = new Point3d(*(l.p2));

}
line::~line() {
	printf("~line()\n");
	printf("%d, %d, %d, %d,%d,%d\n", p1->x, p1->y, p1->z, p2->x, p2->y, p2->z);
	delete p1;
	delete p2;


}
