Window functions in SQL Server are a powerful set of functions used for performing calculations across a set of table rows that are related to the current row. These functions are often used to calculate running totals, rank, and moving averages, among other things. Unlike regular aggregate functions, window functions do not collapse rows into a single result row, but rather return the result for each row in the query.

### Types of Window Functions

1. **Aggregate Window Functions**:
   - These functions perform calculations similar to aggregate functions but do so across a specified range of rows (the window).
   - Examples: `SUM()`, `AVG()`, `MIN()`, `MAX()`, `COUNT()`

2. **Ranking Window Functions**:
   - These functions assign a rank or position to each row within the partition.
   - Examples: `ROW_NUMBER()`, `RANK()`, `DENSE_RANK()`, `NTILE()`

3. **Value Window Functions**:
   - These functions return a value from another row within the window frame.
   - Examples: `LAG()`, `LEAD()`, `FIRST_VALUE()`, `LAST_VALUE()`

4. **Statistical Window Functions**:
   - These functions perform statistical calculations.
   - Examples: `PERCENT_RANK()`, `CUME_DIST()`, `PERCENTILE_CONT()`, `PERCENTILE_DISC()`

### Syntax

The basic syntax of a window function is as follows:

```sql
<window_function> OVER (
    [PARTITION BY partition_expression, ...]
    [ORDER BY sort_expression [ASC|DESC], ...]
    [ROWS|RANGE BETWEEN frame_start AND frame_end]
)
```

- `OVER` clause: Defines the window or the set of rows the function should operate on.
- `PARTITION BY`: Divides the result set into partitions to which the window function is applied. The `PARTITION BY` clause essentially groups together rows for the purpose of
 applying a window function operation to each group independently. This is similar to how the GROUP BY clause works for aggregate functions, but with PARTITION BY, the original
  rows are preserved, and the window function results are added as additional columns.
- `ORDER BY`: Specifies the order of rows within each partition.
- `ROWS|RANGE BETWEEN`: Defines the frame of rows within each partition to apply the function.

### Examples

#### Aggregate Window Functions

1. **Running Total**:
   ```sql
   SELECT 
       OrderID, 
       OrderDate, 
       Amount, 
       SUM(Amount) OVER (ORDER BY OrderDate) AS RunningTotal
   FROM Orders;
   ```

#### Ranking Window Functions

2. **Ranking Rows**:
   ```sql
   SELECT 
       EmployeeID, 
       Salary, 
       ROW_NUMBER() OVER (ORDER BY Salary DESC) AS RowNum,
       RANK() OVER (ORDER BY Salary DESC) AS Rank,
       DENSE_RANK() OVER (ORDER BY Salary DESC) AS DenseRank
   FROM Employees;
   ```

#### Value Window Functions

3. **Accessing Previous/Next Row Values**:
   ```sql
   SELECT 
       OrderID, 
       OrderDate, 
       Amount, 
       LAG(Amount, 1, 0) OVER (ORDER BY OrderDate) AS PreviousAmount,
       LEAD(Amount, 1, 0) OVER (ORDER BY OrderDate) AS NextAmount
   FROM Orders;
   ```

### Use Cases

1. **Running Totals**: Summing values in a running total format.
2. **Rankings**: Ranking rows based on specific criteria, such as sales amounts or scores.
3. **Moving Averages**: Calculating averages over a sliding window of rows.
4. **Comparing Rows**: Comparing a value in a row with the previous or next row’s value.
5. **Statistical Distributions**: Calculating statistical measures such as percentiles.

### Practical Example

Suppose you have a table `Sales` with columns `EmployeeID`, `SaleDate`, and `SaleAmount`. You want to calculate the cumulative sales for each employee over time.

```sql
SELECT 
    EmployeeID,
    SaleDate,
    SaleAmount,
    SUM(SaleAmount) OVER (PARTITION BY EmployeeID ORDER BY SaleDate) AS CumulativeSales
FROM Sales;
```

In this example:
- `PARTITION BY EmployeeID` divides the sales data by each employee.
- `ORDER BY SaleDate` orders the sales chronologically for each employee.
- `SUM(SaleAmount) OVER (...)` calculates the running total of sales for each employee.

### Conclusion

Window functions are versatile and efficient for various analytical tasks in SQL Server. They allow you to perform complex calculations and analyses that are not possible with simple aggregate functions. By understanding and using window functions, you can significantly enhance your SQL querying capabilities.