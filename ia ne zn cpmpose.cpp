#include <iostream>
#include <conio.h>
#include "Point.h"
#include "Point3d.h"
#include "line.h"

void Point::randomc() {
	y = rand() % 20;
	x = rand() % 20;
}
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "создание потомков\n";
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


	cout << "помещение потомка в базовый класс\n";
	{
		Point* p = new Point3d(10, 20, 30);

		delete p;
	}
	cout << "Конец" << endl << endl;


	
	
	return 0;

}
