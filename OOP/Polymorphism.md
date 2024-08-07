# Polymorphism in C++

Polymorphism is a concept in object-oriented programming that allows objects to take on multiple forms or types. In C++, polymorphism is typically achieved through the use of virtual functions.

## Example of Polymorphism in C++

```cpp
#include <iostream>

class Animal {
public:
    virtual void makeSound() {
        std::cout << "This is the sound an animal makes." << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();

    for(int i = 0; i < 2; i++) {
        animals[i]->makeSound();
    }

    delete animals[0];
    delete animals[1];

    return 0;
}
```

### Output
```
Woof!
Meow!
```

## Explanation

In this example, we have an `Animal` class, which is the base class for `Dog` and `Cat` classes. The `Animal` class has a virtual function called `makeSound()`, which is overridden by both `Dog` and `Cat` classes.

In the `main()` function, we create an array of `Animal` pointers and assign a `Dog` object to the first pointer and a `Cat` object to the second pointer. When we call the `makeSound()` function on each element of the array, the actual implementation of the function that gets called is determined at runtime based on the type of the object pointed to. This is the essence of polymorphism - multiple types (in this case, `Dog` and `Cat`) can be treated as a common base type (`Animal`) and their behaviors can be determined at runtime based on their actual type.

In this example, the `makeSound()` function is overridden in both the `Dog` and `Cat` classes to produce different sounds, demonstrating the ability of polymorphism to provide different implementations of the same function for different types of objects.

## Types of Polymorphism

There are two main types of polymorphism in object-oriented programming:

### Compile-time Polymorphism
Also known as static polymorphism or early binding, this type of polymorphism is resolved at compile time, based on the types of the arguments and the function being called. It is achieved through function overloading and operator overloading.

- **Function Overloading:** Having multiple functions with the same name but different parameters or return types.
- **Operator Overloading:** Using the `+` operator to add two integers or concatenate two strings.
- **Templates:** Allow the definition of generic functions or classes that can operate on different types without specifying them explicitly.

### Runtime Polymorphism
Also known as dynamic polymorphism or late binding, this type of polymorphism is resolved at runtime, based on the actual type of the object being referenced. It is achieved through inheritance and virtual functions.

- **Inheritance:** Using a base class pointer to refer to a derived class object.
- **Virtual Functions:** Using the `virtual` keyword to override a base class function in a derived class.

Polymorphism provides a way to use a single interface to represent different underlying forms (data types). It allows for flexibility and the ability to extend functionality with minimal code changes.