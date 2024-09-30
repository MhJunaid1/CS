Choose the right data type
With so many data types to choose from, what criteria should you use to choose the right data type for the particular situation?

When evaluating your options, you must weigh several important considerations. Often there's no one single correct answer, but some answers are more correct than others.

Choose the data type that meets the boundary value range requirements of your application
Your choice of a data type can help to set the boundaries for the size of the data you might store in that particular variable. For example, if you know a particular variable should only store a number between 1 and 10,000 otherwise it's outside of the boundaries of what would be expected, you would likely avoid byte and sbyte since their ranges are too low.

Furthermore, you would likely not need int, long, uint, and ulong because they can store more data than is necessary. Likewise, you would probably skip float, double, and decimal if you didn't need fractional values. You might narrow it down to short and ushort, of which both may be viable. If you're confident that a negative value would have no meaning in your application, you might choose ushort (positive unsigned integer, 0 to 65,535). Now, any value assigned to a variable of type ushort outside of the boundary of 0 to 65535 would throw an exception, thereby subtly helping you enforce a degree of sanity checking in your application.