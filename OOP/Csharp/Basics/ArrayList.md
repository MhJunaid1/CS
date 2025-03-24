### **Differences Between List, Array, and ArrayList in C#**

| Feature       | `List<T>` (Generic List) | `Array` | `ArrayList` (Non-generic) |
|--------------|-----------------|--------|-------------|
| **Namespace** | `System.Collections.Generic` | `System` | `System.Collections` |
| **Type Safety** | ✅ **Type-safe** (Generic) | ✅ **Type-safe** | ❌ **Not type-safe** (Stores `object`) |
| **Performance** | Fast, as it stores strongly typed elements | Fastest (fixed-size, contiguous memory allocation) | Slower (boxing/unboxing overhead for value types) |
| **Resizable?** | ✅ **Yes**, dynamic resizing | ❌ **No**, fixed size | ✅ **Yes**, dynamic resizing |
| **Flexibility** | ✅ Can grow/shrink dynamically | ❌ Fixed size once created | ✅ Can grow/shrink dynamically |
| **Memory Allocation** | **Heap allocation** (dynamic growth with extra capacity) | **Stack/Heap** (depends on type) | **Heap allocation** |
| **Usage Recommendation** | Preferred for most **collections** | Best for **fixed-size** datasets | Legacy (should avoid using) |

---

### **Code Examples**

#### **1. Array (Fixed Size)**
```csharp
int[] numbers = new int[3] { 1, 2, 3 };
Console.WriteLine(numbers[1]); // Output: 2
```

#### **2. List<T> (Generic, Resizable)**
```csharp
List<int> numbers = new List<int> { 1, 2, 3 };
numbers.Add(4);  // Dynamic resizing
Console.WriteLine(numbers[3]); // Output: 4
```

#### **3. ArrayList (Non-generic, Avoid Using)**
```csharp
ArrayList numbers = new ArrayList { 1, "two", 3.0 };
numbers.Add(4); // Mixed types allowed (bad practice)
Console.WriteLine(numbers[1]); // Output: two (stored as object)
```

---

### **Key Takeaways**
- **Use `List<T>`** whenever possible (modern, type-safe, flexible).
- **Use `Array`** when working with fixed-size collections for better performance.
- **Avoid `ArrayList`** because it lacks type safety (legacy).

