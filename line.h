#include <stdio.h>
#include "Point3d.h"

using namespace std;

class line {
protected:

	Point3d* p1;
	Point3d* p2;
public:
	line();
	line(int x1, int y1, int z1, int x2, int y2, int z2);
	line(Point3d& p11, Point3d& p22);
	line(const line& l);
	~line();

};