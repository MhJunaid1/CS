Window functions in SQL are a powerful feature that allows you to perform calculations across a set of table rows that are somehow related to the current row. Unlike aggregate functions, which group rows together to produce a single result for each group, window functions do not group the result set into a single output row. Instead, they perform aggregations and other calculations over a window (a subset of rows) defined by the `OVER` clause, while still retaining the individual rows in the result.

## Key Features of Window Functions

1. **Calculation Across a Set of Rows**: Window functions perform calculations across a set of table rows related to the current row, which is defined by the window specification.
2. **Retain Individual Rows**: Unlike aggregate functions that reduce the number of rows, window functions retain the original number of rows in the result set.
3. **Flexible Partitioning and Ordering**: You can define the window of rows using the `PARTITION BY` and `ORDER BY` clauses, allowing for complex and flexible calculations.
4. **PARTITION BY**: The `PARTITION BY` clause essentially groups together rows for the purpose of applying a window function operation to each group independently. This is similar to how the GROUP BY clause works for aggregate functions, but with PARTITION BY, the original rows are preserved, and the window function results are added as additional columns.

## Common Window Functions

### 1. `ROW_NUMBER()`

The `ROW_NUMBER()` function assigns a unique sequential integer to rows within a partition of a result set.

```sql
SELECT 
    employee_id,
    department_id,
    salary,
    ROW_NUMBER() OVER (PARTITION BY department_id ORDER BY salary DESC) AS row_num
FROM 
    employees;
```

### 2. `RANK()`

The `RANK()` function assigns a rank to each row within a partition of a result set. If two rows have the same rank, the next rank number is the previous rank number plus the number of tied rows.

```sql
SELECT 
    employee_id,
    department_id,
    salary,
    RANK() OVER (PARTITION BY department_id ORDER BY salary DESC) AS rank
FROM 
    employees;
```

### 3. `DENSE_RANK()`

The `DENSE_RANK()` function is similar to `RANK()`, but it does not skip rank numbers in the case of ties.

```sql
SELECT 
    employee_id,
    department_id,
    salary,
    DENSE_RANK() OVER (PARTITION BY department_id ORDER BY salary DESC) AS dense_rank
FROM 
    employees;
```

### 4. `NTILE()`

The `NTILE()` function distributes the rows in an ordered partition into a specified number of roughly equal groups or buckets.

```sql
SELECT 
    employee_id,
    department_id,
    salary,
    NTILE(4) OVER (PARTITION BY department_id ORDER BY salary DESC) AS quartile
FROM 
    employees;
```

### 5. `LAG()` and `LEAD()`

The `LAG()` function accesses data from a previous row in the same result set without using a self-join. Conversely, `LEAD()` accesses data from a subsequent row.

```sql
SELECT 
    employee_id,
    department_id,
    salary,
    LAG(salary, 1) OVER (PARTITION BY department_id ORDER BY salary) AS previous_salary,
    LEAD(salary, 1) OVER (PARTITION BY department_id ORDER BY salary) AS next_salary
FROM 
    employees;
```

### 6. `SUM()`, `AVG()`, `MAX()`, `MIN()`

These aggregate functions can be used as window functions to compute cumulative or moving aggregates.

```sql
SELECT 
    employee_id,
    department_id,
    salary,
    SUM(salary) OVER (PARTITION BY department_id ORDER BY employee_id) AS cumulative_salary
FROM 
    employees;
```

## Window Function Syntax

The general syntax for a window function is:

```sql
window_function() OVER (
    [PARTITION BY partition_expression]
    [ORDER BY sort_expression]
    [ROWS or RANGE frame_clause]
)
```

- **PARTITION BY**: Divides the result set into partitions to which the window function is applied.
- **ORDER BY**: Specifies the logical order of rows within each partition.
- **ROWS/RANGE**: Defines the frame or subset of rows within the partition to which the window function is applied.

## Example: Using Multiple Window Functions

```sql
SELECT 
    employee_id,
    department_id,
    salary,
    ROW_NUMBER() OVER (PARTITION BY department_id ORDER BY salary DESC) AS row_num,
    RANK() OVER (PARTITION BY department_id ORDER BY salary DESC) AS rank,
    SUM(salary) OVER (PARTITION BY department_id) AS total_salary
FROM 
    employees;
```

In this example:
- `ROW_NUMBER()` assigns a unique row number to each row within each department, ordered by salary in descending order.
- `RANK()` assigns ranks based on salary within each department.
- `SUM(salary)` calculates the total salary for each department.

## Conclusion

Window functions are a versatile and powerful feature in SQL that allow for complex calculations and data analysis over partitions of a result set. They provide a flexible way to perform operations such as ranking, cumulative totals, and moving averages without reducing the number of rows in the result set. By understanding and utilizing window functions, you can write more efficient and readable SQL queries.