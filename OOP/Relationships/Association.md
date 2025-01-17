# Association in Object-Oriented Programming

Association is a relationship between two or more classes where:
- Each class has its own lifecycle.
- There is **no ownership** between the associated classes.
- The associated classes are independent of each other and can exist without one another.

In UML diagrams, **association** is represented by a solid line connecting the classes.

---

## Example: Association Between `Student` and `Course`

Below is an example in C++ demonstrating the association between the `Student` and `Course` classes.

### Code Implementation

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int id;

public:
    Student(string n, int i) : name(n), id(i) {}

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

class Course {
private:
    string name;
    int code;
    vector<Student*> students;

public:
    Course(string n, int c) : name(n), code(c) {}

    void addStudent(Student* s) {
        students.push_back(s);
    }

    void displayInfo() {
        cout << "Course Name: " << name << endl;
        cout << "Course Code: " << code << endl;
        cout << "Enrolled Students: " << endl;
        for (Student* s : students) {
            s->displayInfo();
        }
    }
};

int main() {
    // Creating Student objects
    Student* s1 = new Student("John Doe", 123);
    Student* s2 = new Student("Jane Smith", 456);

    // Creating a Course object
    Course* c1 = new Course("Computer Science", 101);

    // Associating students with the course
    c1->addStudent(s1);
    c1->addStudent(s2);

    // Displaying course information
    c1->displayInfo();

    return 0;
}
