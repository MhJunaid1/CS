In C#, a `struct` (short for structure) is a value type that is typically used to encapsulate small groups of related variables. Unlike classes, structs are usually used for lightweight objects such as coordinates, complex numbers, or key-value pairs. Here's a brief overview of the key features of structs in C#:

1. **Value Type**: Structs are value types, which means they are stored on the stack, and they hold the actual data. When a struct is assigned to a new variable, all the data is copied.

2. **No Inheritance**: Structs do not support inheritance, which means they cannot inherit from another struct or class, and they cannot be the base of a class. However, they can implement interfaces.

3. **Implicit Parameterless Constructor**: Structs have an implicit parameterless constructor that initializes all fields to their default values. You cannot define a parameterless constructor explicitly.

4. **Immutable Structs**: It's common to make structs immutable, meaning their state cannot be changed after creation. This can be done by making all fields read-only and only providing a constructor to set these fields.

5. **Use Cases**: Structs are typically used when you need to define simple data structures that are not intended to be modified after creation and that do not require the overhead of reference semantics.

Here’s an example of a struct in C#:

```csharp
public struct Point
{
    public int X { get; }
    public int Y { get; }

    public Point(int x, int y)
    {
        X = x;
        Y = y;
    }

    public override string ToString()
    {
        return $"({X}, {Y})";
    }
}

class Program
{
    static void Main()
    {
        Point p = new Point(3, 4);
        Console.WriteLine(p); // Output: (3, 4)
    }
}
```

In this example:
- The `Point` struct has two read-only properties, `X` and `Y`.
- The constructor initializes these properties.
- The `ToString` method is overridden to provide a string representation of the `Point`.

Structs are best used for simple data structures that are immutable and do not require the overhead of object-oriented features like inheritance.