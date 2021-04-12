#include <iostream>
#include "Employee.h"
#include "ChacheMemory.h"
#include <memory>
#include <string>

using namespace std;

int main()
{
    ChacheMemory<int, Employee> map;
	Employee e1;
	Employee e2;
	string fileName = "emps.bin";
	e1.load(fileName);
	e2.load(fileName);
	map.add(1, e1);
	map.add(2, e2);
}
