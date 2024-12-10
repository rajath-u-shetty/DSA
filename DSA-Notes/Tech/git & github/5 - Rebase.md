
# Rebase Conflicts

Full disclosure: a lot of `rebase`'s bad rep comes from conflicts! _Fear not_. It's nothing you can't handle with just a smidge of practice.

Rebasing feels scarier because it rewrites Git history, which means if you're not careful, you can lose work in an unrecoverable way. But as long as you understand what's going on, it will make your (and your team's) Git history cleaner and easier to understand.

## Assignment

Switch to a new branch called `banned` (a new copy of the `main` branch). Add a new file: `customers/banned.csv` with the following content:

```csv
first_name,last_name,company,title
Kayha,tbd,TheMarchOfTime,sidekick
sam,ctrlman,closedai,ceo
```


Commit that with a message starting with `I:`.

Switch back to `main` and add the same file, but with these contents:

```csv
first_name,last_name,company,title
Ballan,Agrandian,Boots.lore,Protagonist
sam,ctrlman,closedai,ceo
```

# Make the Conflict

Before we move on, I just want to remind you that it's not often that you'll be creating your _own_ conflicts. We're doing so because you probably don't have any friends to practice with... I kid, but even if you do have many developer friends, let's just make all the changes ourselves so you don't need to bother them.

In the "real world," what happens most often is:

1. You switch to a new branch, say `fix_bug`, which is a copy of `main`.
2. While you're fixing the bug, someone else merges _their_ changes into `main`.
3. You fix the bug, and it so happens that you edited the same files (and lines) that the other person did.
4. You open a Pull Request to merge (or rebase) `fix_bug` into `main`, then Git tells you there's a conflict.
5. You resolve the conflict on your branch.
6. You complete the Pull Request with the conflict resolved.

## Assignment

1. Switch to the `banned` branch
2. Rebase it onto `main`. (This rewrites the Git history of the `banned` branch. Remember, you don't want to rewrite the history of a shared branch like `main`).
3. To see the changes to the commit history, run:

```
git log --all --oneline
```


While you should get a conflict, you might also notice something... _odd_. This time, the `HEAD` pointer contains `main`'s changes rather than `banned`'s! That's because `rebase` checks out the _source_ branch, in this case `main`, so it can then replay the changes from `banned` on top of it.

_If you had merged `main` instead of using `rebase`, `HEAD` would still point to `banned` because git doesn't switch branches under-the-hood during a merge._ However, you kinda need to think in reverse with `rebase`... `--theirs` represents the `banned` branch which, in reality, is usually "our" changes.

3. Run `git branch`. Notice that you're _not on a branch!_. You should see something like this:

```
* (no branch, rebasing banned)
  banned
  main
```

Because you're in the middle of a rebase, you're in a special state called "detached HEAD." This is a temporary state that allows you to resolve the conflict before you continue the rebase.

