**Introduction to .NET Framework**

In C++, source code is compiled directly into machine code, making it dependent on the specific machine architecture (e.g., x86).

![C++ Compilation Process](<cpp archi.png>)

**Java's Approach to Platform Independence**

Java introduced the concept of intermediate code (bytecode) to achieve platform independence.
![Java Bytecode](<java archi.png>)


**C# and the .NET Framework**

C# adopted a similar approach to create a machine-independent language.

![C# Intermediate Language](<csharp archi.png>)

**Code Organization in C#**

In C#, code is organized using classes, namespaces, and assemblies:

![C# Code Organization](<csharp code org.png>)

**Assemblies in a C# Application**

An application can consist of multiple assemblies:

![Application Assemblies](<csharp assemblies.png>) 

**Data Types**

We need to assign a value to a variable at the time of declaration, else compiler will throw an error.



![alt text](<naming conventions.png>)

---

### 🐫 **CamelCase**
**Definition**: A naming style where the first word is lowercase, and each subsequent word starts with an uppercase letter.

**Example**:
```csharp
string userName;
bool isLoggedIn;
```

---

### 🐍 **PascalCase**
**Definition**: Similar to CamelCase, but **every** word, including the first, starts with an uppercase letter.

**Example**:
```csharp
class UserProfile {}
string FirstName;
void GetUserInfo() {}
```

---

### 🇭🇺 **Hungarian Notation**
**Definition**: A naming style that prefixes variable names with letters indicating their **type** or **usage**.

**Example**:
```csharp
int iCount;       // 'i' for integer
string strName;   // 'str' for string
bool bIsVisible;  // 'b' for boolean
```

---

![alt text](image.png)
![alt text](image-1.png)

Double is the default data type used by csharp compiler when dealing with real numbers. If we don't follow
the proper conventions when declaring a  real number variables, compiler will consider them double like
in the below example:

![alt text](image-2.png)

**Overflowing**
If we go beyond the limit of a real number data type, compiler will assign zero to it.

![alt text](image-5.png)

If we want to throw an exception at runtime also, we use the below approach:

![alt text](image-6.png)

**Scope of a Variable**

![alt text](image-7.png)

**Implicit Type Conversion**

![alt text](image-8.png)

**Explicit Type Converstion**

The below example won't work:
![alt text](image-9.png)
You need to tell the compiler explicitly that you are aware of data loss, but you still want to convert it:
![alt text](image-10.png)
![alt text](image-11.png)
![alt text](image-12.png)
![alt text](image-13.png)

String, Int32 they are imported from dotnet library, while int, string are not, but they are the
same thing

![alt text](image-16.png)

**Non-primitive Data Types**

![alt text](image-3.png)

**Static Methods**

Static methods are created per class rather than the per instance of the class in memory
![alt text](image-14.png)

**Strings**
Strings are immutable:
![alt text](image-15.png)

**Enums**

![alt text](image-17.png)
![alt text](image-18.png)

**Value Types and Reference Types**

![s](image-19.png)
![alt text](image-20.png)

Below ss hightlight how memoery is managed on stack:

![alt text](image-21.png)
![alt text](image-22.png)

and the below ss shows how memory is managed on heap of reference types:

![alt text](image-23.png)
![alt text](image-24.png)

**Foreach Loop**

![alt text](image-25.png)

**Random Class**

![alt text](<Screenshot (72).png>)

**Latest Dotnet**
The latest version of the .NET Runtime enables you to instantiate an object without having to repeat the type name (target-typed constructor invocation). For example, the following code will create a new instance of the Random class:
Random dice = new();

**Multi Dimmensional Arrays**
![alt text](image-27.png)
Below is the code snippet of how we use multi dimmensional arrays in C#
![alt text](image-28.png)

**Jaggad Arrays**

![alt text](image-30.png)

Below ss highlights the difference between the jaggad arrays and the multi dimmensional arrays:

![alt text](image-31.png)

**Lists in C#**

![alt text](image-32.png)
![alt text](image-33.png)
![alt text](image-34.png)

Lists in action:

![alt text](image-35.png)

**Working with DateTime**

![alt text](image-36.png)
![alt text](image-37.png)

TimeSpan

![alt text](image-38.png)
![alt text](image-39.png)

**Strings**

![alt text](image-40.png)
![alt text](image-41.png)
![alt text](image-42.png)
![alt text](image-43.png)
![alt text](image-44.png)

ToString takes formatters as parameters

![alt text](image-45.png)
![alt text](image-46.png)
![alt text](image-47.png)

StringBuilder

![alt text](image-48.png)
![alt text](image-49.png)
![alt text](image-50.png)
![alt text](image-51.png)
![alt text](image-52.png)

**Working with files**

![alt text](image-53.png)
![alt text](image-54.png)
![alt text](image-55.png)
![alt text](image-56.png)
![alt text](image-57.png)
![alt text](image-58.png)
![alt text](image-60.png)

File provides static whereas Fileinfo is instantiated:

![alt text](image-61.png)

Directory

![alt text](image-62.png)
![alt text](image-63.png)

Working with path:

![alt text](image-64.png)