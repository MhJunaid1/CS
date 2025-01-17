# Aggregation in Object-Oriented Programming

Aggregation is a specialized form of association where:
- One class contains a reference to another class.
- The contained class **can exist independently** of the container class.
- The contained class is **not owned** by the container class and can be shared between multiple container classes.

In UML diagrams, **aggregation** is represented by an **empty diamond shape** on the side of the container class.

---

## Example: Aggregation Between `Person` and `Address`

Below is an example in C++ demonstrating aggregation, where a `Person` contains a reference to an `Address` object.

### Code Implementation

```cpp
#include <iostream>
#include <string>

using namespace std;

class Address {
private:
    string street;
    string city;
    string state;
    string zipCode;

public:
    Address(string st, string ct, string stt, string zip) 
        : street(st), city(ct), state(stt), zipCode(zip) {}

    void displayInfo() {
        cout << "Street: " << street << endl;
        cout << "City: " << city << endl;
        cout << "State: " << state << endl;
        cout << "Zip Code: " << zipCode << endl;
    }
};

class Person {
private:
    string name;
    int age;
    Address* address;

public:
    Person(string n, int a, Address* addr) 
        : name(n), age(a), address(addr) {}

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << endl;
        address->displayInfo();
    }
};

int main() {
    // Creating an Address object
    Address* addr = new Address("123 Main St", "Anytown", "CA", "12345");

    // Creating Person objects with a shared Address reference
    Person* p1 = new Person("John Doe", 25, addr);
    Person* p2 = new Person("Jane Smith", 30, addr);

    // Displaying information
    p1->displayInfo();
    p2->displayInfo();

    return 0;
}
