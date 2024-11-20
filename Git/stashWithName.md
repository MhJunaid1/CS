You can name your stash in Git by adding a message after the `git stash push` command. This helps keep your stashes organized and makes it easier to identify them later.

Here’s how to name your stash:

```bash
git stash push -m "Your stash message here"
```

For example:

```bash
git stash push -m "Fix for issue #123 - temporary changes"
```

This command will create a stash with the specified message, and you can view it later using:

```bash
git stash list
```

The output might look like this:

```
stash@{0}: On main: Fix for issue #123 - temporary changes
stash@{1}: WIP on main: 9a1c0d3 Added new feature
```

### Additional Tips

1. **Stash Naming with Untracked Changes**: You can combine this with options to include untracked files:
   ```bash
   git stash push -m "Message here" -u
   ```

2. **Apply or Drop a Specific Stash**: To apply or drop a specific named stash, reference it by its index or message:
   ```bash
   git stash apply stash@{0}
   git stash drop stash@{0}
   ```

Using a descriptive message with `-m` helps keep track of multiple stashes, especially when working on multiple changes at once.