#ifndef OBJECTS_H
#define OBJECTS_H
#include <string>
using namespace std;
class Object {
public:
	Object();
	virtual double v() = 0; // ovde nema def al ce u buducnosti morati da je dobije, kad ima bar jednu ovo bice apstraktna klasa 
	virtual char label() = 0;
	virtual void print();
private:
	int id;
	static int last_id;



};

class Cube:public Object { //STA CE MI OVO PUBLIC???????
public:
	Cube(int a); // ima neka forica da se na konstruktor doda od koje klase potice i koji je onda defoultni konstruktor
	double v() override; // pisi ovo override da bi odmah znala da slucajno nisi napravila neki misstype 
	char label();
private:
	int a;
};

class Sphere :public Object { 
public:
	Sphere(int r);
	double v() override;
	char label();
private:
	int r;
};

class ObjectList { //ovo je mama klasa
public:
	ObjectList();
	~ObjectList();
	void addObject(Object * object);
protected: //da bi complex object mogla da im pristupi, al samo ona!!
	struct Elem {
		Elem(Object* object) { //odmah pravis konstruktor
			this->object = object;
			this->next = nullptr;
		}
		Object* object;
		Elem* next;
	};

	Elem *first, *last; 
	int object_counts;
};

class ComplexObject : public Object, public ObjectList {
public:
	ComplexObject(string info);
	double v() override;
	char label() override;
private:
	
};
#endif