#include <iostream>
using namespace std;

#include "Objects.h"


int main() {
	Object* cube = new Cube(2);
	cout << cube->v();
	return 0;
}