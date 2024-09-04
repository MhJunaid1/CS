Verbatim string literal
A verbatim string literal will keep all whitespace and characters without the need to escape the backslash. To create a verbatim string, use the @ directive before the literal string.
Console.WriteLine(@"    c:\source\repos    
        (this is where your code goes)");

Combine verbatim literals and string interpolation