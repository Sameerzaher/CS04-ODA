#include <string>
#include <fstream>

using namespace std;

class Employee {
public:
    void load(string fileName);    
private:
    string id;
    int salary;
    int seniority;
};
