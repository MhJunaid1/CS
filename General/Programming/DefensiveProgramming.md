### **What is Defensive Programming?**  
**Defensive Programming** is a programming approach that focuses on **writing code that anticipates and handles potential errors, unexpected inputs, and failures** to make software more **robust, secure, and maintainable**.  

✅ **Key Principles of Defensive Programming:**  
1. **Validate Inputs** – Ensure all user inputs are checked before processing.  
2. **Use Error Handling** – Implement `try-catch` (or equivalent) to catch unexpected errors.  
3. **Fail Gracefully** – If an error occurs, handle it properly without crashing the program.  
4. **Avoid Assumptions** – Assume users and external systems may provide invalid or unexpected data.  
5. **Use Assertions** – Check for impossible conditions during development.  
6. **Limit Dependencies** – Reduce reliance on external factors that may change or fail.  

---

### **Example: Defensive Programming in Python**
Let's consider a **simple calculator** that **divides two numbers**. Without defensive programming, it may crash if invalid inputs are given.

❌ **Without Defensive Programming:**
```python
def divide(a, b):
    return a / b  # Will crash if b is 0!

print(divide(10, 0))  # ERROR: ZeroDivisionError
```

✅ **With Defensive Programming:**
```python
def divide(a, b):
    try:
        if not isinstance(a, (int, float)) or not isinstance(b, (int, float)):
            raise ValueError("Inputs must be numbers.")
        if b == 0:
            raise ZeroDivisionError("Cannot divide by zero.")
        return a / b
    except (ZeroDivisionError, ValueError) as e:
        print(f"Error: {e}")
        return None

print(divide(10, 0))  # Output: Error: Cannot divide by zero.
print(divide("10", 5))  # Output: Error: Inputs must be numbers.
print(divide(10, 2))  # Output: 5.0
```

---

### **Benefits of Defensive Programming**
✔ **Prevents crashes** by handling unexpected inputs.  
✔ **Improves security** by reducing vulnerabilities (e.g., SQL injection, buffer overflow).  
✔ **Enhances maintainability** by making code more resilient to changes.  
✔ **Better user experience** as errors are handled gracefully instead of showing cryptic error messages.  

---

### **Common Defensive Programming Techniques**
🛡 **Input Validation:** Check if user inputs are valid before using them.  
🔄 **Use Defaults:** Provide safe default values for optional parameters.  
⚠️ **Proper Error Handling:** Catch exceptions and handle them correctly.  
✅ **Assertions:** Ensure assumptions about the code are correct during development.  
🔍 **Logging & Monitoring:** Keep logs of unexpected issues for debugging.  

Too much defensive programming is going to bloat your code with too much validation