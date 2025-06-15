
---

### 🔁 `git merge`

**Used to combine branches in your local repository.**

#### 📌 What it does:

* Combines **two branches** (e.g., `feature` into `main`) into one.
* Creates a new **merge commit** if there are changes on both branches.

#### ✅ Use case:

You're working on a feature branch and want to merge it into `main` after finishing.

#### 📦 Example:

```bash
git checkout main
git merge feature-branch
```

This merges `feature-branch` into `main` on your local machine.

---

### 🌐 `git pull`

**Used to fetch changes from a remote repository and merge them into your current branch.**

#### 📌 What it does:

* `git pull = git fetch + git merge`
* First downloads (`fetches`) changes from the remote.
* Then merges them into your local branch.

#### ✅ Use case:

You're working on `main`, and someone else pushed updates to the remote — you run `git pull` to bring those changes into your local `main`.

#### 📦 Example:

```bash
git pull origin main
```

This fetches and merges the remote `main` branch into your local `main`.

---

### 🧠 Summary Table:

| Command     | Fetches Remote Changes | Merges Local Branches | Typical Use Case                |
| ----------- | ---------------------- | --------------------- | ------------------------------- |
| `git merge` | ❌ No                   | ✅ Yes                 | Merge feature branches locally  |
| `git pull`  | ✅ Yes                  | ✅ Yes                 | Update local branch from remote |

---