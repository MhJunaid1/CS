# SQL Table Manipulation Example

This document explains various SQL operations such as creating new tables from existing tables, adding new columns with specific data, and checking for duplicate entries. Each section contains comments and adjustments to enhance understanding.

## Getting Information about a Table
To retrieve information related to the `DFTMessage` table, you can use the following command:

```sql
-- Press Alt+F1 to get the information related to DFTMessage
SELECT * FROM DFTMessage;
```

## Creating a New Table with Additional Column
In this query, we create a new temporary table from the existing `DFTMessage` table. The new table includes an additional column that contains row numbers, ordered by `DFTMessageID` in ascending order.

```sql
-- Creating a new table from the existing table with a new column
-- The new column will contain row numbers ordered by DFTMessageID asc
SELECT TOP 15 
    ROW_NUMBER() OVER (ORDER BY [DFTMessageID] ASC) AS RowNum,
    * 
INTO #temp_table_1 
FROM DFTMessage;

-- Checking the newly created table
SELECT * FROM #temp_table_1;
```

## Adding a New Column with Specific Data
In this section, we add a new column `LastName` to the temporary table `#temp_table_1` with repeated entries like `man1`, `man1`, `man2`, `man2`, and so on. But if we change
the condition from `(RowNum + 1)/2` to `RowNum` only we will get entries like `man1`, `man2`, `man3` and so on. Additionally, we set the `DOB` column to a fixed date `2010-01-01`.

```sql
-- Adding a new column LastName with repeated entries
DECLARE @i INT = 1;
DECLARE @max INT = 15;

WHILE @i <= @max
BEGIN
    UPDATE #temp_table_1
    SET
        [LastName] = 'man' + CAST((RowNum + 1) / 2 AS VARCHAR),
        [DOB] = '2010-01-01'
    WHERE RowNum = @i;
    SET @i = @i + 1;
END;
```

## Checking for Duplicate Entries
In the final query, we check for duplicate entries in the table `#temp_table_3`. The query uses the `DENSE_RANK()` function to find duplicates based on the `LastName` column, partitioned by `RowNum`.

```sql
-- Checking for duplicate entries in the table
SELECT * FROM (
    SELECT 
        DENSE_RANK() OVER(PARTITION BY [LastName] ORDER BY RowNum ASC) AS rank,
        *
    FROM #temp_table_3
) AS t1  
WHERE rank > 1;
```

This document provides a clear understanding of various SQL operations, helping users to manipulate tables, add columns, and check for duplicate entries effectively.