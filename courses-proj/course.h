
#include <string>
#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    string id;
    char classification;

public:
    Student();
    Student(const string &name, const string &id, char classification);
    friend ostream &operator<<(ostream &os, const Student &student);
};

class Roster
{
private:
    Student *contents;
    int size;
    int capacity;
    void resize();

public:
    Roster();
    ~Roster();
    void addStudent(const Student &student);
    void removeStudent(const string &studentId);
    friend ostream &operator<<(ostream &os, const Roster &roster);
};
class Course
{
private:
    string name;
    string code;
    Roster roster;

public:
    Course();
    Course(const string &name, const string &code);
    void addStudent(const Student &student);
    void removeStudent(const string &studentId);
    friend ostream &operator<<(ostream &os, const Course &course);

    string getName() const;
};
