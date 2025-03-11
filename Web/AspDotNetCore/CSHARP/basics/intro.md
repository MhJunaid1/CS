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
![alt text](image.png)
![alt text](image-1.png)

Double is the default data type used by csharp compiler when dealing with real numbers. If we don't follow
the proper conventions when declaring a  real number variables, compiler will consider them double like
in the below example:
![alt text](image-2.png)

Non Primitive Data Types
![alt text](image-3.png)

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




**Latest Dotnet**
The latest version of the .NET Runtime enables you to instantiate an object without having to repeat the type name (target-typed constructor invocation). For example, the following code will create a new instance of the Random class:
Random dice = new();