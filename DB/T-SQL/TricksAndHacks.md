### Some Useful DB Tricks/Hacks:

#### 1. **`sp_helptext` Command**:
   - **Purpose**: Use `sp_helptext` to view the definition of a stored procedure, function, or view.
   - **Syntax**: 
     ```sql
     EXEC sp_helptext 'stored_procedure_name';
     ```
   - **Example**:
     ```sql
     EXEC sp_helptext 'GetEmployeeDetails';
     ```

#### 2. **Multiple Line Selection in SQL Server Management Studio (SSMS)**:
   - **Trick**: To select multiple lines or columns, use `Alt + Shift` and drag the cursor to select the desired lines.
   - **Use Case**: This is helpful for editing or copying multiple rows of data in a query without selecting each one individually.

#### 3. **Toggle Result Window (Ctrl + R)**:
   - **Trick**: Press **`Ctrl + R`** to quickly hide or show the result window in SQL Server Management Studio (SSMS).
   - **Use Case**: This is great for a cleaner workspace when you're focusing on writing or modifying queries.

#### 4. **Format SQL Code (Ctrl + K, Ctrl + D)**:
   - **Trick**: Press **`Ctrl + K, Ctrl + D`** to automatically format your SQL code. This is useful for maintaining a consistent and readable code style.

#### 5. **Display Database Table and View Information (sp_help)**:
   - **Purpose**: Use `sp_help` to display details about a table or view, including columns, data types, constraints, etc.
   - **Syntax**: 
     ```sql
     EXEC sp_help 'table_name';
     ```

#### 6. **Display Current User (User and Permissions)**:
   - **Trick**: To find out the current user, use:
     ```sql
     SELECT USER_NAME();
     ```

#### 7. **Check Active Connections in SQL Server**:
   - **Trick**: To see a list of active connections to the database:
     ```sql
     SELECT * FROM sys.dm_exec_sessions WHERE is_user_process = 1;
     ```

#### 8. **Switch Between Multiple Query Windows (Ctrl + Tab)**:
   - **Trick**: Use **`Ctrl + Tab`** to quickly switch between multiple open query windows within SSMS.

#### 9. **SQL Server Query Plan (Ctrl + M)**:
   - **Trick**: Press **`Ctrl + M`** before executing a query to show the query execution plan. This helps analyze and optimize queries.

#### 10. **Backup Database with T-SQL**:
   - **Trick**: To create a database backup from SQL query window:
     ```sql
     BACKUP DATABASE [YourDatabase] TO DISK = 'C:\Backup\YourDatabase.bak';
     ```

#### 11. **Create a Table from a Query Result**:
   - **Trick**: Use `SELECT INTO` to create a new table from a query result.
     ```sql
     SELECT * INTO new_table_name FROM existing_table WHERE condition;
     ```

#### 12. **Find Table Dependencies**:
   - **Trick**: To find all dependent objects of a specific table (e.g., views, functions, stored procedures):
     ```sql
     EXEC sp_depends 'your_table_name';
     ```

#### 13. **Database Size**:
   - **Trick**: Check the size of a database:
     ```sql
     EXEC sp_spaceused;
     ```

