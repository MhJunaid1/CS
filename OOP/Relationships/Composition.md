# Composition in Object-Oriented Programming

**Composition** is a type of relationship between two classes where:
- One class **owns** another class and is responsible for its creation, destruction, and lifetime management.
- The owned class **cannot exist independently** of the owning class.

In C++, composition is implemented using member variables that are instances of another class. 
- When the owning class is created, it instantiates the owned class as a member variable.
- When the owning class is destroyed, the owned class is also destroyed.

---

## Example: Composition Between `Car` and `Engine`

Below is an example in C++ demonstrating composition, where a `Car` owns an `Engine`.

### Code Implementation

```cpp
#include <iostream>
#include <string>

using namespace std;

class Engine {
private:
    int cylinders;
    float displacement;

public:
    Engine(int cyl, float disp) : cylinders(cyl), displacement(disp) {}

    void start() {
        cout << "Starting engine with " << cylinders 
             << " cylinders and " << displacement 
             << " liters displacement." << endl;
    }
};

class Car {
private:
    string make;
    string model;
    Engine engine;

public:
    Car(string mk, string mdl, int cyl, float disp) 
        : make(mk), model(mdl), engine(cyl, disp) {}

    void start() {
        cout << "Starting car: " << make << " " << model << endl;
        engine.start();
    }
};

int main() {
    // Creating a Car object
    Car* myCar = new Car("Ford", "Mustang", 8, 5.0);

    // Starting the car
    myCar->start();

    return 0;
}
