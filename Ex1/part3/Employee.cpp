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
	 * 
	 */
