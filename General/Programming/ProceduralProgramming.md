### **What is Procedural Programming?**  
Procedural Programming is a programming paradigm that follows a **step-by-step** approach to solving a problem. It is based on procedures (also called functions) that contain a sequence of instructions to be executed.  

✅ **Key Features:**  
- Code is organized into functions (or procedures).  
- Uses **global and local variables** to store data.  
- Follows a **top-down** approach, where the program is executed linearly.  
- Relies on **loops** (`for`, `while`) and **conditional statements** (`if-else`).  
- Commonly used in languages like **C, Pascal, and Python**.  

---

### **Example of Procedural Programming (C Language)**
Let's say we want to write a program to **calculate the sum of two numbers** using procedural programming.

```c
#include <stdio.h>

// Function to calculate sum
int addNumbers(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2, sum;
    
    // Taking input from the user
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    // Calling function
    sum = addNumbers(num1, num2);
    
    // Display result
    printf("The sum is: %d\n", sum);

    return 0;
}
```

---

### **How This Code Follows Procedural Programming?**
1. **Divides the program into functions**  
   - `addNumbers(int a, int b)` is a **procedure** that performs the addition.
   - `main()` is the entry point that handles user input and function calls.

2. **Executes line by line (Top-Down Approach)**  
   - User inputs two numbers → Function calculates sum → Result is displayed.

3. **Uses Global and Local Variables**  
   - `num1`, `num2`, and `sum` are **local variables** used inside `main()`.  

---

### **Advantages of Procedural Programming**  
✔ **Easy to write and understand** for small programs.  
✔ **Code reuse** through functions.  
✔ **Good for beginners** due to its simplicity.  

### **Disadvantages**  
❌ **Difficult to manage large programs** (no encapsulation).  
❌ **Code duplication** since data is not bundled with its behavior (unlike OOP).  

