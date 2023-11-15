#include <iostream>
using namespace std;

class Student
{
private:
    string name;

public:
    Student(string name);
    string getName() const;
    void setName(string name);
};

Student::Student(string name)
{
    this->name = name;
};

string Student::getName() const
{
    return name;
};

void Student::setName(string name)
{
    this->name = name;
}

int main()
{
    int numStudents = 2;
    Student **enrollment = new Student *[numStudents];
    Student **math = new Student *[numStudents];
    Student **science = new Student *[numStudents];

    enrollment[0] = new Student("Tom");
    enrollment[1] = new Student("Jerry");

    math[0] = enrollment[0];
    math[1] = enrollment[1];

    science[0] = enrollment[0];
    science[1] = enrollment[1];

    cout << science[0]->getName() << endl;

    cout << science[1]->getName() << endl;

    enrollment[0]->setName("bob");

    cout << science[0]->getName() << endl;
    cout << science[1]->getName() << endl;

    return 0;
}
