A **closure** is a programming concept where a function **remembers** the variables from its **lexical scope**, even if that function is executed **outside** that scope.

### 🔹 General Definition

A **closure** is:

* A function
* That captures and *closes over* its surrounding environment (variables)
* So that it can use those variables later, even after the outer function has finished executing

---

### 🔸 Example (in Python):

```python
def outer():
    message = "Hello"
    
    def inner():
        print(message)  # inner "remembers" message

    return inner

greet = outer()   # outer() runs and returns inner()
greet()           # Output: Hello
```

Even though `outer()` has finished, the `inner()` function still has access to `message`. This is a closure.

---

### 🔸 Why are closures useful?

Closures let you:

* Maintain **state** between function calls
* Implement **data hiding**
* Write **callbacks** and **higher-order functions**

---

### 🔹 Closures in Different Languages

#### ✅ Python

Full support—closures are used widely in decorators and functional programming.

#### ✅ JavaScript

Closures are used in nearly every callback, particularly in asynchronous code.

```javascript
function outer() {
  let count = 0;
  return function() {
    count++;
    console.log(count);
  }
}

const counter = outer();
counter(); // 1
counter(); // 2
```

#### ⚠️ C\#

C# supports closures via **captured variables in lambdas or anonymous methods**:

```csharp
Func<int> counter = null;
{
    int i = 0;
    counter = () => ++i;
}

Console.WriteLine(counter()); // 1
Console.WriteLine(counter()); // 2
```

The lambda keeps a reference to `i`.

#### ⚠️ Java (since 8)

Closures via **lambdas**, but variables must be **effectively final**:

```java
public class Test {
    public static void main(String[] args) {
        String msg = "Hi";
        Runnable r = () -> System.out.println(msg);  // msg must be final or effectively final
        r.run();
    }
}
```

#### ⚠️ C++

C++ has **lambda captures**, and you specify what variables to capture (`[]` syntax):

```cpp
int x = 5;
auto closure = [x]() { std::cout << x << std::endl; };
closure();  // Output: 5
```

You can also capture by reference `[&]`.

---

### 🔚 Summary

| Language   | Supports Closures? | Notes                                 |
| ---------- | ------------------ | ------------------------------------- |
| Python     | ✅ Yes              | Native support                        |
| JavaScript | ✅ Yes              | Fundamental concept                   |
| C#         | ✅ Yes              | Via lambdas and anonymous methods     |
| Java       | ⚠️ Partially       | Only with effectively final variables |
| C++        | ✅ Yes              | Via lambda capture                    |


