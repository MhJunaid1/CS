**Dynamic scope** is a scoping rule where variables are resolved **based on the call stack at runtime**—not based on where functions are defined, but on **where they are called from**.

---

### 🔹 In simple terms:

> In **dynamic scope**, a variable is looked up in the **calling context** (the function that called the current function), rather than the **defining context**.

This contrasts with **lexical (static) scope**, where the structure of the code determines variable access.

---

### 🔸 Example of dynamic scope (in pseudocode):

```pseudocode
var = "global"

function foo() {
    print(var)
}

function bar() {
    var = "local"
    foo()   // prints "local" in dynamic scope
}

bar()
```

In **dynamic scope**, `foo()` would print `"local"` because it uses the `var` from the **calling function** (`bar()`), not from where `foo` is defined.

---

### 🔸 Dynamic vs Lexical Scope

| Feature             | Lexical Scope                     | Dynamic Scope                           |
| ------------------- | --------------------------------- | --------------------------------------- |
| Variable resolution | Based on code structure           | Based on call stack at runtime          |
| Variable source     | Where the function is **defined** | Where the function is **called**        |
| Common in           | JavaScript, Python, C, Java, C#   | Lisp (older versions), Bash, Emacs Lisp |

---

### 🔹 Dynamic Scope in Bash (real example):

```bash
function foo {
  echo $x
}

function bar {
  local x="bar value"
  foo
}

bar  # outputs: bar value
```

Here, `foo` accesses `x` from `bar` because Bash uses **dynamic scoping for functions**.

---

### 🔹 Why not used in most modern languages?

Dynamic scope can make code harder to **reason about and debug**, because it's not clear where a variable will be resolved from—its value depends on how the program executes, not how it's written.

---

