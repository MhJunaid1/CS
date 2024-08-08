`IEnumerable<T>` is a fundamental interface in .NET used for iterating over a collection of objects. It is part of the `System.Collections.Generic` namespace and provides a way to access elements in a collection one at a time without exposing the underlying structure of the collection.

### Key Points

1. **Namespace and Interface**:
   - `IEnumerable<T>` is defined in the `System.Collections.Generic` namespace.
   - It is a generic interface, where `T` represents the type of elements in the collection.

2. **Purpose**:
   - The primary purpose of `IEnumerable<T>` is to allow iteration over a collection of items using a `foreach` loop.
   - It provides a way to access elements sequentially without exposing the underlying data structure (e.g., arrays, lists, etc.).

3. **Main Method**:
   - **`GetEnumerator()`**: This method returns an `IEnumerator<T>` that can be used to iterate over the collection. `IEnumerator<T>` provides the methods needed for iteration, such as `MoveNext()` and `Current`.

### Example

Here’s a basic example demonstrating how `IEnumerable<T>` is used in .NET:

```csharp
using System;
using System.Collections.Generic;

public class Program
{
    public static void Main()
    {
        // Create a list of integers
        List<int> numbers = new List<int> { 1, 2, 3, 4, 5 };
        
        // IEnumerable<int> reference to the list
        IEnumerable<int> enumerableNumbers = numbers;
        
        // Iterate over the IEnumerable using a foreach loop
        foreach (int number in enumerableNumbers)
        {
            Console.WriteLine(number);
        }
    }
}
```

### Explanation

1. **Creation of List**:
   - `List<int> numbers = new List<int> { 1, 2, 3, 4, 5 };` creates a list of integers.

2. **Casting to `IEnumerable<T>`**:
   - `IEnumerable<int> enumerableNumbers = numbers;` casts the `List<int>` to `IEnumerable<int>`. This allows iteration over the list using `IEnumerable`.

3. **Iteration**:
   - The `foreach` loop is used to iterate over the `IEnumerable<int>`. The `foreach` loop internally uses `GetEnumerator()` to get an enumerator and iterates through the collection.

### Interface Methods

- **`GetEnumerator()`**: Returns an `IEnumerator<T>` for iterating over the collection.

### Related Interfaces and Classes

- **`ICollection<T>`**: Extends `IEnumerable<T>` and adds methods for modifying the collection (e.g., adding or removing items).
- **`IList<T>`**: Extends `ICollection<T>` and provides indexed access to elements.
- **`IEnumerator<T>`**: Supports simple iteration over a collection. Provides methods to iterate through the collection (`MoveNext()`, `Reset()`) and access the current element (`Current`).

### Example with LINQ

`IEnumerable<T>` is also used extensively with LINQ (Language Integrated Query). LINQ methods operate on `IEnumerable<T>` and allow querying and manipulation of collections.

```csharp
using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    public static void Main()
    {
        List<int> numbers = new List<int> { 1, 2, 3, 4, 5 };
        
        // Use LINQ to filter and select elements
        IEnumerable<int> evenNumbers = numbers.Where(n => n % 2 == 0);
        
        foreach (int number in evenNumbers)
        {
            Console.WriteLine(number);
        }
    }
}
```

### Explanation

- **LINQ Query**: `numbers.Where(n => n % 2 == 0)` filters the list to get only even numbers. `Where` returns an `IEnumerable<int>`.
- **Iteration**: The `foreach` loop iterates over the filtered results.

### Summary

`IEnumerable<T>` is a fundamental interface in .NET for iterating over collections. It provides a standardized way to access elements in a collection one at a time and is integral to LINQ operations.