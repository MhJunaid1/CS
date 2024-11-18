To remove files from the staging area in Git without deleting them or affecting your working directory, you can use the following command:

```bash
git restore --staged <file>
```

### **Examples:**

1. To unstage a specific file:
   ```bash
   git restore --staged file1.txt
   ```
2. To unstage multiple files:
   ```bash
   git restore --staged file1.txt file2.txt
   ```
3. To unstage all files:
   ```bash
   git restore --staged .
   ```

---

### **Older Git Versions (before 2.23):**

If you're using an older Git version that doesn't support `git restore`, you can achieve the same result with:

1. To unstage a specific file:
   ```bash
   git reset HEAD file1.txt
   ```
2. To unstage all files:
   ```bash
   git reset HEAD .
   ```

---

### **Important Notes:**

- **Files remain in the working directory.** This command only removes the files from the staging area; your changes to the files will still exist locally.
- If you want to discard changes altogether (unstage and revert changes), use:
  ```bash
  git checkout -- <file>
  ```

Let me know if you need further assistance!