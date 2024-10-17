### Common Table Expression (CTE) in T-SQL

A **Common Table Expression (CTE)** is a temporary result set in T-SQL that can be referenced within a `SELECT`, `INSERT`, `UPDATE`, or `DELETE` statement. It allows for improved readability and modular code by enabling complex queries to be broken down into simpler parts. A CTE is defined using the `WITH` keyword and exists only for the duration of the query.

#### Syntax of a CTE

```sql
WITH CTE_name (column1, column2, ...) AS
(
    -- Query that defines the CTE
    SELECT ...
    FROM ...
    WHERE ...
)
-- Query using the CTE
SELECT *
FROM CTE_name;
```

- **CTE_name**: The name you give to the CTE.
- **column1, column2, ...**: Optional column aliases. If not provided, they will take the column names from the CTE query.
- **AS**: Defines the query block that populates the CTE.

### Example of a CTE

Below is an example where a CTE is used to break down a complex query into smaller parts. This CTE calculates the total sales per employee and then retrieves the employees who have exceeded a sales threshold.

```sql
-- Using a CTE to calculate total sales per employee
WITH EmployeeSales AS
(
    SELECT 
        EmployeeID,
        SUM(SalesAmount) AS TotalSales
    FROM Sales
    GROUP BY EmployeeID
)
-- Using the CTE in the main query
SELECT 
    EmployeeID, 
    TotalSales
FROM 
    EmployeeSales
WHERE 
    TotalSales > 10000;
```

In this example:
- The `EmployeeSales` CTE calculates the total sales per employee using `SUM(SalesAmount)` and `GROUP BY`.
- The main query uses the CTE to select employees whose total sales are greater than 10,000.

### Advantages of Using CTEs

1. **Simplifies Complex Queries**: A CTE can break down a complicated query into smaller, more understandable parts.
2. **Recursive Queries**: CTEs can be recursive, meaning they can refer to themselves, which is useful for hierarchical data.
3. **Improved Readability**: It improves the readability of SQL queries by making intermediate steps clearer.
4. **Reusability in the Same Query**: A CTE can be referenced multiple times within the same query, which can be more efficient than writing subqueries repeatedly.

### Recursive CTE Example

A **recursive CTE** is a CTE that references itself. It is commonly used to work with hierarchical data, such as finding all employees in a management hierarchy.

```sql
-- Recursive CTE to find employee hierarchy
WITH EmployeeHierarchy AS
(
    -- Anchor member (starting point)
    SELECT 
        EmployeeID, 
        ManagerID, 
        EmployeeName,
        1 AS Level
    FROM Employees
    WHERE ManagerID IS NULL -- Find top-level managers

    UNION ALL

    -- Recursive member (self-referencing)
    SELECT 
        e.EmployeeID, 
        e.ManagerID, 
        e.EmployeeName,
        eh.Level + 1
    FROM Employees e
    INNER JOIN EmployeeHierarchy eh ON e.ManagerID = eh.EmployeeID
)
SELECT 
    EmployeeID, 
    EmployeeName, 
    Level
FROM EmployeeHierarchy
ORDER BY Level;
```

In this recursive example:
- The CTE finds all top-level managers (`ManagerID IS NULL`) and assigns them a `Level` of 1.
- It then recursively finds employees reporting to these managers and increments the `Level`.

### Conclusion

A **CTE** in T-SQL provides a temporary, modular way of writing queries that makes complex SQL queries easier to manage and understand. They are especially useful for queries involving aggregation, recursion, or multiple references to the same data set.