**Lexical scope** (also known as **static scope**) is a rule in programming that determines how variable names are resolved **based on where functions and blocks are defined**, **not** where they are called.

---

### 🔹 In simple terms:

> A variable is **accessible** within the block of code where it was **defined** and in any inner blocks, but **not outside**.

Lexical scope is set **at compile time**, not at runtime.

---

### 🔸 Example (in JavaScript):

```javascript
function outer() {
  let message = "Hello";

  function inner() {
    console.log(message); // ✅ can access 'message'
  }

  inner();
}

outer();
```

Even though `message` is not defined in `inner()`, it is accessible because `inner()` is defined **within the lexical scope** of `outer()`.

---

### 🔹 Why is it called “lexical”?

* "Lexical" means **related to the text/code** itself.
* So, lexical scope is based on how your code is **written (structured)**, not how it's **executed**.

---

### 🔸 Example in Python:

```python
def outer():
    x = 10
    def inner():
        print(x)  # inner uses x from outer
    inner()
```

Here, `inner()` has access to `x` because it is **lexically enclosed** in `outer()`.

---

### 🔸 Dynamic Scope vs Lexical Scope

| Feature           | Lexical Scope             | Dynamic Scope               |
| ----------------- | ------------------------- | --------------------------- |
| Variable resolved | Where function is defined | Where function is called    |
| Used in           | Most modern languages     | Some older or special cases |

Most modern languages like **JavaScript**, **Python**, **C#**, and **Java** use **lexical scope**.

---

### 🔹 Visualizing Lexical Scope

Imagine nested boxes:

* Each function creates a box (scope)
* Inner boxes can access variables in outer boxes, but **not the other way around**


