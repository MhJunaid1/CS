To merge a branch in Git, you bring the changes from one branch (usually called the **feature branch**) into another branch (typically the **main branch** or **development branch**). 

Here are the steps to perform a merge:

---

### **Step-by-Step Guide to Merging a Branch**

#### 1. **Switch to the Target Branch**
   The target branch is the branch you want to merge changes into. Use the `git switch` or `git checkout` command to switch to the branch.

   ```bash
   git switch main
   # or
   git checkout main
   ```

#### 2. **Merge the Source Branch**
   Use the `git merge` command to merge the source branch (the branch with the changes you want to incorporate).

   ```bash
   git merge feature-branch
   ```

   This will bring the changes from `feature-branch` into `main`.

---

### **Example Workflow**

1. Start with two branches: `main` and `feature-branch`.
2. Switch to `main`:
   ```bash
   git switch main
   ```
3. Merge `feature-branch` into `main`:
   ```bash
   git merge feature-branch
   ```
4. If there are no conflicts, Git will merge the branches and provide a success message.

---

### **Handling Merge Conflicts**
If there are conflicting changes between the branches, Git will pause the merge and highlight the conflicts. You will need to resolve the conflicts manually:

1. Open the conflicting files in your text editor. Conflicted areas will look like this:
   ```plaintext
   <<<<<<< HEAD
   Current changes in `main`.
   =======
   Incoming changes from `feature-branch`.
   >>>>>>> feature-branch
   ```

2. Edit the file to resolve the conflict and remove the conflict markers (`<<<<<<<`, `=======`, `>>>>>>>`).

3. Mark the conflicts as resolved by running:
   ```bash
   git add <file-name>
   ```

4. Complete the merge by committing the changes:
   ```bash
   git commit
   ```

5. If you encounter conflicts during a merge and decide not to resolve them, you can run:
   ```bash
   git merge --abort
  
---

### **Fast-Forward vs Three-Way Merge**

- **Fast-Forward Merge:**
  - Happens when the target branch has no additional commits compared to the source branch.
  - The `main` branch pointer is simply moved forward to the same commit as the `feature-branch`.

  Example:
  ```bash
  git merge feature-branch
  ```

- **Three-Way Merge:**
  - Happens when both branches have diverged.
  - Git creates a new merge commit that combines the changes from both branches.

---

### **Summary**
To merge a branch:
1. Switch to the target branch (e.g., `main`):  
   ```bash
   git switch main
   ```

2. Merge the source branch (e.g., `feature-branch`):  
   ```bash
   git merge feature-branch
   ```

3. Resolve conflicts if needed and commit.