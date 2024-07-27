# Git Bash and Commands

Git Bash is used similarly to a Linux/Unix terminal. Commands like `touch`, `mkdir`, `rm`, `rmdir`, and `cat` are available on Windows/MacOS.

## Initializing a Git Repository

- When you initialize an empty Git repository, the branch is not allocated until the first commit.
- The default branch name after `git init` is `master`. On GitHub, it is `main`, so change the local name to `main` from `master`.

## Configuring Git

```bash
git config --global user.name "your_username"
git config --global user.email "your_email"
```

Use these commands to set your username and email.

## Checking Git Configuration

```bash
git config --global --list
```

Check if changes have been committed.

## Basic Git Commands

- `git init`: Initialize an empty Git repo.
- `ls -lart`: Show all the files in a Git repo (created by `git init`).
- `git status`: See the status of files.
- `git status -s`: See the short status.

## Staging and Committing Changes

- `git add filename.extension`: Start tracking untracked file modifications.
- `git add -A`: Add all untracked files to the staging area.
- `git commit -m "message for commit"`: Commit changes with a message.
- `git commit -a -m "commit all the changes"`: Commit all changes without explicitly adding them to the staging area.

## Checking Out and Logging

- `git checkout filename.extension`: Get the version of a file from the last commit.
- `git checkout -f`: Checkout all files from the previous commit.
- `git log`: View all commits in the Git repo.
- `git log --oneline`: View commits in one line that is hash and the commit description.
- `git log -p -<number>`: View a specific number of recent commits (press `q` to quit).
- `git checkout <commit-hash>`: Open a files till a specific commit.

## Diff and Ignore

- `git diff`: Compare the working tree with the staging area.
- `git diff --staged`: Compare the staging area with the last commit.
- `.gitignore filename`: Ignore a specific file in any location of the Git repo.
- `.gitignore /filename`: Ignore a file in the current directory of the `.gitignore`.
- `.gitignore *.extension`: Ignore all files of a specific extension.
- `.gitignore foldername/`: Ignore a folder.

## Branching and Merging

- `git branch`: See all the branches in the repo.
- `git branch branchName`: Create a new branch.
- `git branch -m newName`: Change the current branch name.
- `git checkout branchName`: Switch to a specific branch.
- `git merge branchName`: Merge a branch into the main branch.


## Stash

Stashing in Git allows you to save your current changes temporarily without committing them, making it easier to switch branches or work on different tasks without losing progress.

### Basic Stash Commands

- `git stash`: Save your changes to the stash.
- `git stash list`: List all stashed changes.
- `git stash apply`: Reapply the most recent stash.
- `git stash pop`: Apply the most recent stash and remove it from the list.
- `git stash drop`: Delete a specific stash.

### Using Stash in VS Code

1. **Stash Changes**: Open the Source Control panel, click on the `...` menu, and select "Stash Changes."
2. **Apply Stash**: Go to the same menu and select "Apply Stash."
3. **View Stashes**: View stashes in the Source Control panel under the stashes section.
4. **Pop Stash**: Apply and remove the stash using the "Pop Stash" option.

This integration makes it easy to manage stashes directly within the VS Code interface.


## Removing Git from Local Repository

To delete a Git repository from your local system:

```bash
rm -rf .git
```

This will delete all configurations related to Git. You can also delete `.git` manually by showing hidden files because `.git` is hidden by default.

## Using SSH for GitHub

To push code from your local machine using Git, you need to add an SSH key to your GitHub account. Here are the steps:

1. Generate an SSH key pair using the following command in your terminal or Git Bash window:

    ```bash
    ssh-keygen -t ed25519 -C "your_email@example.com"
    ```

2. Press enter when prompted to enter a passphrase and choose the default location to save the key.

3. Display the public key:

    ```bash
    cat ~/.ssh/id_ed25519.pub
    ```

4. Enter this public key in your GitHub SSH key settings to start pushing code to GitHub.

## Adding Multiple SSH Keys

For more information on adding multiple SSH keys, visit [this article](https://connkat.medium.com/setting-up-multiple-ssh-keys-on-one-computer-75f068d972d9).

## Pushing to GitHub

Prefer SSH over HTTP for pushing code to GitHub:

```bash
git remote add origin git@github.com:yourusername/repository.git
git push -u origin main
```

The `-u` flag sets the upstream branch to the remote repository's main branch, allowing future `git push` and `git pull` commands without specifying the branch.

## Forking on GitHub

A fork on GitHub is a copy of a repository that allows users to contribute to open-source projects or create their own versions of existing projects. This enables developers to work on their version of a project without affecting the main codebase.