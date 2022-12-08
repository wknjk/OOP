#include "Objects.h"
#include <iostream>;
#include <string>
using namespace std;
const double PI = 3.14153; // neki detalj cpp bice vise price o tome kasnije 
int Object::last_id = 0;
Object::Object()
{
	this->id = last_id++;

}

void Object::print()
{
	cout << label() << id << "(" << v() << ")";
	//ovo se ne desava u vreme prevodjenja nego u vreme izvrsavanja!! zato smem da je pisem u apstraktnoj klasi
}

Cube::Cube(int a) 
{
	this->a = a;
}

double Cube::v()
{
	return a*a*a;
}

char Cube::label()
{
	return 'C';
}

Sphere::Sphere(int r)
{
	this ->r = r;
}

double Sphere::v()
{
	return (4.0 / 3) * r * r * r * PI ;
}

char Sphere::label()
{
	return 'S';
}

ObjectList::ObjectList()
{
	first = last = nullptr;
	this->object_counts = 0;
}

ObjectList::~ObjectList()
{
	
	while (first) {
		Elem* curr = first;
		first = first->next;
		delete curr;
	}
	first = last = nullptr;
	this->object_counts = 0;
}

void ObjectList::addObject(Object * object)
{
	if (!first) {
		this->first = new Elem(object);;
		this->last = new Elem(object);;
	}
	else {
		this->last->next = new Elem(object);
		last = last->next;
	}
	this->object_counts++;
}

ComplexObject::ComplexObject(string info)
{
	int number = 0;
	for (int i = 0; i < info.length(); i++) {
		switch (info[i]) {
		case 'C':
			this->addObject(new Cube (number));	
			number = 0; 
			break;
		case 'S':
			this->addObject(new Sphere(number));
			number = 0; 
			break;
		case '1': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9': case '0':
			number = number * 10 + (info[i] - '0');
			break;
		default: 
			break;

		}
	}
}

double ComplexObject::v()
{
	return 0.0;
}

char ComplexObject::label()
{
	return 0;
}
