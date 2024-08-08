Sure, let's delve into the details with examples for each of these features in C# compared to C++.

### 1. Access Modifiers: Internal and Protected Internal

**Internal**: The `internal` modifier means that the member is accessible only within files in the same assembly (project).

```csharp
// Assembly1
public class InternalExample
{
    internal void InternalMethod()
    {
        Console.WriteLine("Internal Method");
    }
}

// Assembly1
public class TestInternal
{
    public void Test()
    {
        InternalExample example = new InternalExample();
        example.InternalMethod(); // Accessible
    }
}

// Assembly2
public class AnotherTest
{
    public void Test()
    {
        InternalExample example = new InternalExample();
        // example.InternalMethod(); // Not Accessible, compiler error
    }
}
```

**Protected Internal**: The `protected internal` modifier means that the member is accessible from any class in the same assembly, or from derived classes.

```csharp
// Assembly1
public class ProtectedInternalExample
{
    protected internal void ProtectedInternalMethod()
    {
        Console.WriteLine("Protected Internal Method");
    }
}

public class Derived : ProtectedInternalExample
{
    public void Test()
    {
        ProtectedInternalMethod(); // Accessible
    }
}

// Assembly2
public class AnotherTest : ProtectedInternalExample
{
    public void Test()
    {
        ProtectedInternalMethod(); // Accessible because of inheritance
    }
}
```

### 2. Properties (Getter and Setters) in C#

C# uses properties with `get` and `set` accessors to encapsulate fields, making code cleaner and more maintainable.

```csharp
public class Person
{
    private string name;

    // Property
    public string Name
    {
        get { return name; }
        set { name = value; }
    }
}

// Usage
Person person = new Person();
person.Name = "Alice";
Console.WriteLine(person.Name);
```

In C++, you typically use getter and setter functions:

```cpp
class Person {
private:
    std::string name;

public:
    std::string getName() const {
        return name;
    }

    void setName(std::string name) {
        this->name = name;
    }
};

// Usage
Person person;
person.setName("Alice");
std::cout << person.getName();
```

### 3. Inheritance

C# supports single inheritance for classes and multiple inheritance through interfaces.

```csharp
// Base class
public class Animal
{
    public void Eat()
    {
        Console.WriteLine("Eating");
    }
}

// Derived class
public class Dog : Animal
{
    public void Bark()
    {
        Console.WriteLine("Barking");
    }
}

// Usage
Dog dog = new Dog();
dog.Eat(); // Inherited method
dog.Bark();
```

C++ supports both single and multiple inheritance:

```cpp
class Animal {
public:
    void eat() {
        std::cout << "Eating";
    }
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << "Barking";
    }
};

// Usage
Dog dog;
dog.eat(); // Inherited method
dog.bark();
```

### 4. Nullable Types

C# provides nullable types using the `?` syntax, allowing value types to hold `null`.

```csharp
int? nullableInt = null;
if (nullableInt.HasValue)
{
    Console.WriteLine(nullableInt.Value);
}
else
{
    Console.WriteLine("No value");
}
```

In C++, you typically use pointers or other means to achieve similar functionality:

```cpp
std::optional<int> nullableInt = std::nullopt;
if (nullableInt.has_value())
{
    std::cout << nullableInt.value();
}
else
{
    std::cout << "No value";
}
```

### 5. Generics

C# uses generics to create classes, methods, and interfaces with a placeholder for the type.

```csharp
public class GenericClass<T>
{
    public T Value { get; set; }
}

// Usage
GenericClass<int> genericInt = new GenericClass<int>();
genericInt.Value = 10;
Console.WriteLine(genericInt.Value);
```

C++ uses templates to achieve similar functionality:

```cpp
template <typename T>
class GenericClass {
public:
    T value;
};

// Usage
GenericClass<int> genericInt;
genericInt.value = 10;
std::cout << genericInt.value;
```

### 6. Event Handling

C# has built-in support for events, making it easier to implement the observer pattern.

```csharp
public class Publisher
{
    public event EventHandler SomethingHappened;

    public void DoSomething()
    {
        // Raise the event
        SomethingHappened?.Invoke(this, EventArgs.Empty);
    }
}

public class Subscriber
{
    public void OnSomethingHappened(object sender, EventArgs e)
    {
        Console.WriteLine("Something happened");
    }
}

// Usage
Publisher publisher = new Publisher();
Subscriber subscriber = new Subscriber();

publisher.SomethingHappened += subscriber.OnSomethingHappened;
publisher.DoSomething();
```

In C++, you might use function pointers, callbacks, or other patterns to implement similar behavior.

### 7. Unified Type System

C# has a unified type system where all types derive from `object`, including primitive types.

```csharp
object obj = 42; // Boxing
int num = (int)obj; // Unboxing
Console.WriteLine(obj.GetType()); // System.Int32
```

In C++, primitive types are not derived from a common base type, and the language relies on templates and overloading to achieve polymorphism with primitive types.

```cpp
int num = 42;
std::cout << typeid(num).name(); // i (for int)
```

These examples illustrate some key differences and features in C# compared to C++, providing a deeper understanding of how these languages handle various programming constructs.