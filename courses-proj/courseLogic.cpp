#include "course.h"
#include <iostream>
using namespace std;

Course::Course(const string &name, const string &code)
    : name(name), code(code) {}

Course::Course()
{
}
string Course::getName() const
{
    return name;
}

void Course::addStudent(const Student &student)
{
    roster.addStudent(student);
}

void Course::removeStudent(const string &studentId)
{
    roster.removeStudent(studentId);
}

ostream &operator<<(ostream &os, const Course &course)
{
    os << "Course: " << course.name << " [" << course.code << "]" << endl;
    os << course.roster;
    return os;
}

Roster::Roster() : size(0), capacity(5)
{
    contents = new Student[capacity];
}

Roster::~Roster()
{
    delete[] contents;
}

void Roster::addStudent(const Student &student)
{
    if (size == capacity)
    {
        resize();
    }
    contents[size++] = student;
}

void Roster::removeStudent(const string &studentId)
{
    // Implement student removal logic
}

void Roster::resize()
{
    capacity += 5;
    Student *newContents = new Student[capacity];

    for (int i = 0; i < size; ++i)
    {
        newContents[i] = contents[i]; // Copy existing Student objects to the new array
    }

    delete[] contents;      // Delete the old array
    contents = newContents; // Point contents to the new array
}

ostream &operator<<(ostream &os, const Roster &roster)
{
    for (int i = 0; i < roster.size; ++i)
    {
        os << roster.contents[i] << endl;
    }
    return os;
}

Student::Student(const string &name, const string &id, char classification)
    : name(name), id(id), classification(classification) {}

Student::Student()
{
}

ostream &operator<<(ostream &os, const Student &student)
{
    os << "Student: " << student.name << " [ID: " << student.id << ", Classification: " << student.classification << "]";
    return os;
}
