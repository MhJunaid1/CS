In C#, both `for` and `foreach` loops are used for iteration, but each has specific use cases based on performance, readability, and the data structure being iterated. Here's when to use a `foreach` loop over a `for` loop:

### 1. **Iterating Through Collections Where Index Access Is Not Needed**
   - Use `foreach` when you want to **iterate through each element** of a collection and don't need to manipulate or access elements by index.
   - It provides a more concise and readable way to loop through elements, especially in collections like `List`, `Array`, or `Dictionary`.

   **Example:**
   ```csharp
   List<string> names = new List<string> { "John", "Jane", "Doe" };
   foreach (string name in names)
   {
       Console.WriteLine(name);
   }
   ```

   - **When to use `foreach`**: 
     - When you only need to process each item.
     - When you don't care about the index position.
     - When you want a clean, readable syntax without managing loop control variables.

### 2. **When Working with Non-Indexable Collections**
   - `foreach` works well with collections that don't support random access by index, such as `IEnumerable<T>` or `LinkedList<T>`. In such cases, `for` would not work or would require additional logic to traverse the collection.

   **Example with IEnumerable**:
   ```csharp
   IEnumerable<int> numbers = Enumerable.Range(1, 5);
   foreach (int num in numbers)
   {
       Console.WriteLine(num);
   }
   ```

   - **When to use `foreach`**: 
     - When working with `IEnumerable`, `ICollection`, or `IList` where index-based access is either not supported or not needed.

### 3. **Improved Readability and Simplicity**
   - `foreach` simplifies the loop structure by handling the complexity of getting the next element and avoiding off-by-one errors.
   - It’s often preferred in scenarios where you want to avoid managing the loop counter or boundaries manually.

   **Example:**
   ```csharp
   string[] fruits = { "Apple", "Banana", "Cherry" };
   foreach (string fruit in fruits)
   {
       Console.WriteLine(fruit);
   }
   ```
   Compared to:
   ```csharp
   for (int i = 0; i < fruits.Length; i++)
   {
       Console.WriteLine(fruits[i]);
   }
   ```

### 4. **Avoiding Errors Related to Index Bounds**
   - `foreach` automatically handles iteration without worrying about index boundaries, reducing the risk of out-of-bounds exceptions that can occur with `for` loops.
   - This is especially useful in dynamic collections where the size of the collection can change.

### 5. **When You Don’t Intend to Modify the Collection**
   - `foreach` is designed for read-only iteration. If you don’t need to modify the elements or collection itself, `foreach` is ideal. However, if you need to modify the elements, `for` is preferred.
   - **Note**: Modifying a collection during iteration with `foreach` will cause an `InvalidOperationException`.

### When to **Not** Use `foreach`:
- **When You Need to Modify Elements in Place**: `foreach` provides read-only access to the elements, so if you need to modify the elements or work with their indices, use `for`.
  
  **Example**:
  ```csharp
  for (int i = 0; i < numbers.Length; i++)
  {
      numbers[i] += 1; // Modifying elements
  }
  ```

- **When You Need Index Access**: If you need to know the index of the current item or perform operations based on the index, use a `for` loop.
  
  **Example**:
  ```csharp
  for (int i = 0; i < array.Length; i++)
  {
      if (i % 2 == 0)
      {
          Console.WriteLine(array[i]); // Accessing by index
      }
  }
  ```

### Summary of When to Use `foreach`:
- **Simple iteration** through a collection without modifying it.
- **Improved readability** and simpler syntax for iterating over a collection.
- Iterating over collections that are **non-indexable**, such as `IEnumerable`.
- When you want to **avoid index management** and reduce the possibility of off-by-one errors.