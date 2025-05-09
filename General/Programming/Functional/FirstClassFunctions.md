
---

## 🔹 First-Class Functions: General Definition

A language supports **first-class functions** if functions can be:

1. **Assigned** to variables
2. **Passed** as arguments
3. **Returned** from other functions
4. **Stored** in data structures

This gives you **functional programming power**—you can build flexible, modular code where behavior (functions) can be treated as data.

---

## 🔸 First-Class Functions in Different Languages

### ✅ 1. **Python** (Full support)

Python has **native first-class functions**.

```python
def greet(name):
    return f"Hello, {name}"

def call_func(func, value):
    return func(value)

say_hi = greet
print(call_func(say_hi, "Alice"))  # Output: Hello, Alice
```

* Functions can be stored in variables, passed, returned.
* Python also supports lambdas and closures.

---

### ✅ 2. **C#** (Via **delegates**, **Func<>**, **Action<>**)

C# supports first-class functions through **delegates** and **lambda expressions**.

```csharp
Func<string, string> greet = name => $"Hello, {name}";

string result = greet("Bob");  // "Hello, Bob"
```

You can:

* Pass functions using `Func<>`, `Action<>`, or custom `delegate` types
* Return them from methods
* Store them in variables

> ✅ C# supports first-class functions **through constructs**, but not as naturally as Python.

---

### ⚠️ 3. **Java** (Since Java 8 — via **lambdas**, **functional interfaces**)

Java didn’t support true first-class functions until **Java 8**, which introduced **lambdas** and **functional interfaces**:

```java
import java.util.function.Function;

Function<String, String> greet = name -> "Hello, " + name;
System.out.println(greet.apply("Charlie"));  // "Hello, Charlie"
```

Java functions are not technically objects, but **functional interfaces** like `Function<T, R>`, `Consumer<T>`, etc., act as wrappers.

> ⚠️ Java simulates first-class function behavior through **functional interfaces**.

---

### ⚠️ 4. **C++** (Since C++11 — via **function pointers**, **std::function**, and **lambdas**)

C++ traditionally used function pointers. Since **C++11**, it supports **lambdas** and `std::function`.

```cpp
#include <iostream>
#include <functional>

std::string greet(std::string name) {
    return "Hello, " + name;
}

int main() {
    std::function<std::string(std::string)> f = greet;
    std::cout << f("Dave") << std::endl;
}
```

> ✅ C++ supports first-class function **behaviors**, but you must use specific types like `std::function` or lambdas.

---

## 🔚 Summary Table

| Feature                     | Python | C#              | Java (8+)                   | C++ (11+)              |
| --------------------------- | ------ | --------------- | --------------------------- | ---------------------- |
| Assign functions to vars    | ✅      | ✅ (`Func<>`)    | ⚠️ (via interface)          | ✅ (`std::function`)    |
| Pass as parameters          | ✅      | ✅               | ⚠️                          | ✅                      |
| Return from functions       | ✅      | ✅               | ⚠️                          | ✅                      |
| Closures / Lambdas          | ✅      | ✅               | ✅                           | ✅                      |
| Natural first-class support | ✅      | ⚠️ via delegate | ⚠️ via functional interface | ⚠️ via `std::function` |

---

