#include "Employee.h"

int ID_SIZE = 50;

void Employee::load(string fileName){
    ifstream file(fileName, std::ios::binary);
	int idSize;
	char tempId[ID_SIZE];
	file.read((char*)&idSize, sizeof(int));
	file.read((char*)tempId, idSize);
    this->id = tempId;
	tempId[idSize] = '\0';
	file.read((char*)&(this->salary) , sizeof(int));
	file.read((char*)&(this->seniority), sizeof(int));

    file.close();

    return;
}

	/* *** Check ***
	 * ChachedMap<int, Employee> map;
	 * Employee e1;
	 * Employee e2;
	 * string fileName = "emps.bin";
	 * e1.load(fileName);
	 * e2.load(fileName);
	 * map.add(1, e1);
	 * map.add(2, e2);
	 */
