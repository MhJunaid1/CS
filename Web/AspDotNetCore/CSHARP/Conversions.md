Compilers make safe conversions
The C# compiler sees a potential problem in the making. The variable second is of type string, so it might be set to a different value like "hello". If the C# compiler attempted to convert "hello" to a number that would cause an exception at runtime. To avoid this possibility, the C# compiler doesn't implicitly perform the conversion from string to int for you.

From the C# compiler's perspective, the safer operation would be to convert int into a string and perform concatenation instead.

If you intend to perform addition using a string, the C# compiler requires you to take more explicit control of the process of data conversion. In other words, it forces you to be more involved so that you can put the proper precautions in place to handle the possibility that the conversion could throw an exception.

If you need to change a value from the original data type to a new data type and the change could produce an exception at run time, you must perform a data conversion.

To perform data conversion, you can use one of several techniques:

Use a helper method on the data type
Use a helper method on the variable
Use the Convert class' methods


The term widening conversion means that you're attempting to convert a value from a data type that could hold less information to a data type that can hold more information. In this case, a value stored in a variable of type int converted to a variable of type decimal, doesn't lose information.

When you know you're performing a widening conversion, you can rely on implicit conversion. The compiler handles implicit conversions.



The term narrowing conversion means that you're attempting to convert a value from a data type that can hold more information to a data type that can hold less information. In this case, you may lose information such as precision (that is, the number of values after the decimal point). An example is converting value stored in a variable of type decimal into a variable of type int. If you print the two values, you would possibly notice the loss of information.

When you know you're performing a narrowing conversion, you need to perform a cast. Casting is an instruction to the C# compiler that you know precision may be lost, but you're willing to accept it.

If you're unsure whether you lose data in the conversion, write code to perform a conversion in two different ways and observe the changes. Developers frequently write small tests to better understand the behaviors, as illustrated with the next sample.

Delete or use the line comment operator // to comment out the code from the previous exercise step, and add the following code:

```
decimal myDecimal = 1.23456789m;
float myFloat = (float)myDecimal;

Console.WriteLine($"Decimal: {myDecimal}");
Console.WriteLine($"Float  : {myFloat}");
```
Output:
Decimal: 1.23456789
Float  : 1.2345679


Use ToString() to convert a number to a string

Every data type variable has a ToString() method. What the ToString() method does depends on how it's implemented on a given type. However, on most primitives, it performs a widening conversion. While this isn't strictly necessary (since you can rely on implicit conversion in most cases) it can communicate to other developers that you understand what you're doing and it's intentional.

Here's a quick example of using the ToString() method to explicitly convert int values into strings.

Delete or use the line comment operator // to comment out the code from the previous exercise step, and add the following code:

```
int first = 5;
int second = 7;
string message = first.ToString() + second.ToString();
Console.WriteLine(message);
```
Output:
57


Convert a string to an int using the Parse() helper method
Most of the numeric data types have a Parse() method, which converts a string into the given data type. In this case, you use the Parse() method to convert two strings into int values, then add them together.

```
string first = "5";
string second = "7";
int sum = int.Parse(first) + int.Parse(second);
Console.WriteLine(sum);
```

Output:
12



Convert a string to a int using the Convert class
The Convert class has many helper methods to convert a value from one type into another. In the following code example, you convert a couple of strings into values of type int.

```
string value1 = "5";
string value2 = "7";
int result = Convert.ToInt32(value1) * Convert.ToInt32(value2);
Console.WriteLine(result);
```
Output:
35

The ToInt32() method has 19 overloaded versions allowing it to accept virtually every data type.

you used the Convert.ToInt32() method with a string here, but you should probably use TryParse() when possible.

So, when should you use the Convert class? The Convert class is best for converting fractional numbers into whole numbers (int) because it rounds up the way you would expect.


Compare casting and converting a decimal into an int
int value = (int)1.5m; // casting truncates
Console.WriteLine(value);
```
int value2 = Convert.ToInt32(1.5m); // converting rounds up
Console.WriteLine(value2);
```
Output:
1
2


Casting truncates and converting rounds
When you're casting int value = (int)1.5m;, the value of the float is truncated so the result is 1, meaning the value after the decimal is ignored completely. You could change the literal float to 1.999m and the result of casting would be the same.

When you're converting using Convert.ToInt32(), the literal float value is properly rounded up to 2. If you changed the literal value to 1.499m, it would be rounded down to 1.


Use TryParse()
The TryParse() method does several things simultaneously:

It attempts to parse a string into the given numeric data type.
If successful, it stores the converted value in an out parameter, explained in following section.
It returns a bool to indicate whether the action succeeded or failed.
You can use the Boolean return value to take action on the value (like performing some calculation), or display a message if the parse operation was unsuccessful.


Out parameters
Methods can return a value or return "void" - meaning they return no value. Methods can also return values through out parameters, which are defined just like an input parameter, but include the out keyword.

TryParse() a string into an int

```
string value = "102";
int result = 0;
if (int.TryParse(value, out result))
{
   Console.WriteLine($"Measurement: {result}");
}
else
{
   Console.WriteLine("Unable to report the measurement.");
}
```


When calling a method with an out parameter, you must use the keyword out before the variable, which holds the value. The out parameter is assigned to the result variable in the code (int.TryParse(value, out result). You can then use the value the out parameter contains throughout the rest of your code using the variable result.

The int.TryParse() method returns true if it successfully converted the string variable value into an int; otherwise, it returns false. So, surround the statement in an if statement, and then perform the decision logic, accordingly.

The converted value is stored in the int variable result. The int variable result is declared and initialized before this line of code, so it should be accessible both inside the code blocks that belong to the if and else statements, as well as outside of them.

The out keyword instructs the compiler that the TryParse() method doesn't return a value the traditional way only (as a return value), but also communicates an output through this two-way parameter.

When you run the code, you should see the following output:

Output:
Measurement: 102

the C# Compiler implicitly converts the null value to an empty string for presentation.