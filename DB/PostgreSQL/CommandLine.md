Tool used for command line is called psql

The command:

```bash
psql -U postgres -d Employees -f employees.sql
```

is used to **execute a SQL script (`employees.sql`)** on a PostgreSQL database named `Employees` using the user `postgres`.

---

### 🔍 Breakdown of the command:

| Part               | Meaning                                                         |
| ------------------ | --------------------------------------------------------------- |
| `psql`             | The PostgreSQL command-line tool                                |
| `-U postgres`      | Connect using the **user** `postgres`                           |
| `-d Employees`     | Target the **Employees** database                               |
| `-f employees.sql` | Read and execute the SQL commands from the file `employees.sql` |

---

### 🎯 Purpose:

This command is typically used to:

* **Initialize a database** (e.g., create tables, insert seed data)
* **Restore a backup** from a SQL file
* **Run a batch of SQL commands** from a file rather than typing them manually

---
