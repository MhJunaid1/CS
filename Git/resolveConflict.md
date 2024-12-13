### Resolving Conflicts When Pulling From a Branch

When working on a Git project, conflicts may arise while pulling changes from another branch. Here's a streamlined approach to handle conflicts, ensuring your changes remain intact while discarding incoming changes:

---

#### 1. **Pull Changes From Your Branch**
   Begin by pulling changes from the branch you wish to merge into your current branch. This action will highlight any conflicts that need resolution:
   ```bash
   git pull origin <branch-name>
   ```

---

#### 2. **Resolve Conflicts**
   Open the files with conflicts and modify them to **keep all of your changes** while discarding the changes from the pulled branch. Git marks conflicts like this:
   ```plaintext
   <<<<<<< HEAD
   Your changes
   =======
   Incoming changes from the pulled branch
   >>>>>>> <branch-name>
   ```
   Manually edit the file to retain only your desired changes.

---

#### 3. **Stash Your Changes**
   After resolving the conflicts, stash your changes to temporarily save your work without committing:
   ```bash
   git stash
   ```

---

#### 4. **Pull Again**
   Pull from the same branch again to ensure you have the latest updates without conflicts:
   ```bash
   git pull origin <branch-name>
   ```

---

#### 5. **Apply the Stash**
   Reapply your stashed changes to your branch:
   ```bash
   git stash apply
   ```

   This brings back your resolved changes on top of the pulled updates.

---

#### 6. **Finalize the Process**
   After verifying everything is in place, stage and commit your changes:
   ```bash
   git add .
   git commit -m "Resolved conflicts and applied changes"
   ```
   Finally, push your updated branch to the remote repository:
   ```bash
   git push origin <branch-name>
   ```

---

This approach ensures that your changes are preserved while successfully merging updates from the target branch.