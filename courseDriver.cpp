#include <iostream>
#include "course.h"

using namespace std;

const int MAX_COURSES = 5; // Maximum number of courses

int main()
{
    Course courses[MAX_COURSES];
    int numCourses = 0; // Current number of courses
    string name, code, studentName, studentId;
    char classification;
    int choice, courseIndex;
    bool found;

    while (true)
    {
        cout << "1. Create a course\n";
        cout << "2. Remove a course\n";
        cout << "3. List all courses\n";
        cout << "4. Enroll a student in a course\n";
        cout << "5. Remove a student from a course\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (numCourses < MAX_COURSES)
            {
                cout << "Enter course name: ";
                cin >> name;
                cout << "Enter course code: ";
                cin >> code;
                courses[numCourses++] = Course(name, code);
            }
            else
            {
                cout << "Maximum number of courses reached.\n";
            }
            break;

        case 2:
            cout << "Enter course name to remove: ";
            cin >> name;
            found = false;
            for (int i = 0; i < numCourses; i++)
            {
                if (courses[i].getName() == name)
                { // Using dot operator instead of arrow
                    found = true;
                    // Shift the remaining courses
                    for (int j = i; j < numCourses - 1; j++)
                    {
                        courses[j] = courses[j + 1];
                    }
                    numCourses--;
                    break;
                }
            }
            if (!found)
            {
                cout << "Course not found.\n";
            }
            break;

        case 3:
            for (int i = 0; i < numCourses; i++)
            {
                cout << i << ": " << courses[i] << endl;
            }
            break;

        case 4:
            cout << "Enter course name to enroll a student: ";
            cin.ignore();
            getline(cin, name);
            found = false;
            for (int i = 0; i < numCourses; i++)
            {
                if (courses[i].getName() == name)
                {
                    found = true;
                    cout << "Enter student name: ";
                    getline(cin, studentName);
                    cout << "Enter student ID: ";
                    getline(cin, studentId);
                    cout << "Enter student classification (char): ";
                    cin >> classification;
                    courses[i].addStudent(Student(studentName, studentId, classification));
                    break;
                }
            }
            if (!found)
            {
                cout << "Course not found.\n";
            }
            break;

        case 5:
            cout << "Enter course name to remove a student from: ";
            cin.ignore();
            cin >> name;
            found = false;
            for (int i = 0; i < numCourses; i++)
            {
                if (courses[i].getName() == name)
                {
                    found = true;
                    cout << "Enter student ID: ";
                    cin >> studentId;
                    courses[i].removeStudent(studentId);
                    break;
                }
            }
            if (!found)
            {
                cout << "Course not found.\n";
            }
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
