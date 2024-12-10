# What is a Fork?

We created a fork of the official MegaCorp™ repo inside _your_ GitHub account. It's a copy of the original that you can modify without affecting the original.

You may have noticed that there is no manual entry for `git fork`

![git fork](https://storage.googleapis.com/qvault-webapp-dynamic-assets/course_assets/eRQE2c3.png)

Why?

Forking _is not_ a Git operation, but it is a feature offered by many Git hosting services such as [GitHub](https://github.com/), [GitLab](https://gitlab.com/), and [Bitbucket](https://bitbucket.org/).

Those services "fork" a repo by creating a new copy of the repo and associating it as a "fork" of the original. It's quite literally just a copy that is linked to the original via some metadata.

# PRs From a Fork

When you fork someone's repository on a platform like GitHub, you get a copy of the repository in your account. This is the standard way to contribute to someone else's open-source project. The steps are typically:

1. Fork their repo into your account
2. Clone your fork to your local machine
3. Create a new branch (let's call it `your_feature`)
4. Make changes
5. Commit and push changes to your fork's remote `your_feature` branch
6. Create a pull request to `original_owner/repo` `main` from `your_username/repo` `your_feature`

Then the original owner can review your changes. If they like them, they can merge the changes straight from your fork into their repository.


# Head

You'll see a big scary word in the Git world called [`HEAD`](https://git-scm.com/book/en/v2/Git-Internals-Git-References#ref_the_ref). Branches are references to commits, and `HEAD` is a reference to the branch you're currently on. All this to say, in [Grug](https://grugbrain.dev/) speak:

> `HEAD` mean where me at now

For example, you _should_ be on the `main` branch of your local clone of your fork of the official MegaCorp™ repo. Which means, `HEAD` is pointing to the `main` branch. Like all things in `.git`'s internals, `HEAD` is just stored in a file.

## Assignment

1. Manually check and see what `HEAD` is pointing to from the root of your repo:

```bash
cat .git/HEAD
```

# Reflog

The [`git reflog` command](https://git-scm.com/docs/git-reflog) (pronounced ref-log, not re-flog) is kinda like `git log` but stands for "reference log" and specifically logs the changes to a "reference" that have happened over time.

Reflog uses a different format to show the history of a branch or HEAD: one that's more concerned with the number of steps back in time. For example:

| reflog   | meaning                    |
| -------- | -------------------------- |
| HEAD@{0} | where HEAD is now          |
| HEAD@{1} | where HEAD was 1 move ago  |
| HEAD@{2} | where HEAD was 2 moves ago |
| HEAD@{3} | where HEAD was 3 moves ago |
| ...      | ...                        |
# Delete Branch

Have you ever:

1. Shipped a bug to production (`main branch`)
2. Created a new branch to fix the bug (`fix-bug`)
3. Fixed the bug and committed the changes
4. Switched back to `main`
5. Accidentally deleted the `fix-bug` branch

Yeah, me neither...

# Recovery

So, you've deleted your branch that had a unique commit on it. All is lost!

_Or is it?_

Remember when I mentioned that `git reflog` keeps track of where all of your references have been? Well, it's time to put that to the test.

## Assignment

1. Use `git reflog` to look at where your `HEAD` has been. Find the commit hash that corresponds to the "slander" change that we lost.
2. Remember the [`git cat-file -p` command](https://git-scm.com/docs/git-cat-file) from the first course? Provide it the short commit hash from the reflog.
3. Use the `tree` hash from the commit to find the `blob` hash for the `slander.md` file.
4. Use it one last time to print the contents of the deleted file.
5. Recreate the `slander.md` file in the root of the repo with the same text.
6. Commit that file with a message: `B: recovery`

# Merge

Using Git internals is exceptionally inconvenient. We had to copy/paste and use the `cat-file` command 3 times!

I would not recommend doing it that way, but I wanted to drive home the point that you can always drop down to the plumbing commands if needed.

_Luckily, there is a better way._ The [`git merge`](https://git-scm.com/docs/git-merge) command actually takes a "commitish" as an argument:

```
git merge <commitish>
```

A "commitish" is something that _looks_ like a commit (branch, tag, commit, HEAD@{1})

In other words instead of:

```
git reflog (find the commit sha at HEAD@{1})
git cat-file -p <commit sha>
git cat-file -p <tree sha>
git cat-file -p <blob sha> > slander.md
git add .
git commit -m "B: recovery"
```

We could have just done:

```
git merge HEAD@{1}
```

# Merge

Using Git internals is exceptionally inconvenient. We had to copy/paste and use the `cat-file` command 3 times!

I would not recommend doing it that way, but I wanted to drive home the point that you can always drop down to the plumbing commands if needed.

_Luckily, there is a better way._ The [`git merge`](https://git-scm.com/docs/git-merge) command actually takes a "commitish" as an argument:

```
git merge <commitish>
```

A "commitish" is something that _looks_ like a commit (branch, tag, commit, HEAD@{1})

In other words instead of:

```
git reflog (find the commit sha at HEAD@{1})
git cat-file -p <commit sha>
git cat-file -p <tree sha>
git cat-file -p <blob sha> > slander.md
git add .
git commit -m "B: recovery"
```

We could have just done:

```
git merge HEAD@{1}
```

# Conflicting Changes

Working with Git is a _dream_ when all of the developers on a project are committing changes to _different lines_ of code. Things get a little hairy when changes to the _same lines_ are made _at the same time_ (e.g. one commit isn't the parent of another).

# Merge Conflicts

A merge conflict occurs when two commits _modify the same line_ and Git can't automatically decide which change to keep and which change to discard.

Consider the following commit history:

```bash
    C     feature
  /
A - B     main
```

The `main` branch has a file with these lines:

```go
package main

func isNice(num int) bool {
    return num == 69 // commit B changed this line
}
```

While `feature` has:

```go
package main

func isNice(num int) bool {
    return num == 420 // commit C changed this line
}
```

If we merge `feature` into `main`, Git will detect that the `return` line was changed in both branches independently: which creates a [conflict](https://git-scm.com/docs/git-merge#_how_to_resolve_conflicts).

When a conflict happens (usually as the result of a `merge` or `rebase`) Git will prompt you to _manually_ decide which change to keep. It's okay when the same line is modified in one commit, and then again in a _later_ commit. The problem arises when the same line is modified in two commits that aren't in a parent-child relationship.

# Merge

Conflicting changes on two different branches is not a problem. The problem only arises when you try to _merge_ those branches. When you do, Git will detect the conflict and ask you to resolve it.

# Edit the file

Resolving conflicts is a manual process. When they happen, Git marks the conflicted files and asks you to resolve the conflict by editing the files in your editor.

## Assignment

Open the `customers/all.csv` file in your editor, you should see a nasty bit of text that looks like this:

```
first_name,last_name,company,title
<<<<<<< HEAD
karson,yummy,intercooler,ceo
=======
jayson,gross,htmz,contributor
>>>>>>> main
```

Your editor might even highlight the conflict markers to make it easier to see, but at the end of the day, it's just text. The top section, between the `<<<<<<< HEAD` and `=======` lines, is _our_ branch's version of the file. The bottom section, between the `=======` and `>>>>>>> main` lines, is the version of the file that's on the `main` branch ("theirs" or as I say "Stupid Greg's").

In many cases, you might want to keep one change and discard the other. That's common when you're dealing with code changes. In this case, we're dealing with content, so we want to keep _both_ changes.

Delete the conflict markers and leave both your change and Greg's change in the file. It should look like this:

```
first_name,last_name,company,title
karson,yummy,intercooler,ceo
jayson,gross,htmz,contributor
```

# Ours and Theirs

In a merge conflict:

- **"Ours"** refers to the branch you are on (merging into)
- **"Theirs"** refers to the branch being merged

```bash
# you're on the "ours" branch, the "theirs" branch is "their_branch"
git merge their_branch
```

## Git terminology

Last time, we manually edited the conflicting files. This time, let's use Git's built-in merge resolution tools. It makes use of the terms "ours" and "theirs" to refer to the branches being merged.

## Assignment

You should currently be on the `add_customers` branch with this commit history:

```
A - B - D       main
     \   \
      C - E   add_customers
```

First, `switch` back to `main` branch. Then merge `add_customers` into `main`, this should result in a [fast-forward merge](https://git-scm.com/docs/git-merge#_fast_forward_merge) that brings C-E into `main`.

Delete the `add_customers` branch, we don't need it anymore.

# Multi-conflict

So far, we've only dealt with one conflict at a time. That's small potatoes. Let's see what happens when we have multiple conflicts to resolve.

## Assignment

1. Switch to a new branch off of `main` called `delete_records`.
2. Edit `customers/all.csv` and delete the `jayson,gross,htmz,contributor` record. It should only have the heading line.
3. Edit `orgs/partners.txt` and delete the "Boot.dev" record. It should look like this (note the blank line at the start):

```
partner list

TheStartup
```

4. Commit your changes with a message starting with `F:`.
5. Switch back to `main`. Edit `customers/all.csv` but this time just _change_ the `jayson,gross,htmz,contributor` record to:

```
carson,gross,htmx,creator
```


6. Edit `orgs/partners.txt` and change the "Boot.dev" record to "SalesInc" (a major competitor of MegaCorp that we pretend to be friendly with):

```
partner list
SalesInc
TheStartup
```


7. Commit your changes with a message starting with `G:`. Your history should look like this:

```
                  F   delete_records
                 /
A - B - C - D - E - G   main
```

# Checkout Conflict

We've _manually_ edited files to resolve conflicts, but it turns out Git has some built-in tools to help us out.

The [`git checkout` command](https://www.git-scm.com/docs/git-checkout) can checkout the individual changes during a merge conflict using the `--theirs` or `--ours` flags.

- `--ours` will overwrite the file with the changes from the branch you are currently on and merging into
- `--theirs` will overwrite the file with the changes from the branch you are merging into the current branch

```bash
git checkout --theirs path/to/file
```