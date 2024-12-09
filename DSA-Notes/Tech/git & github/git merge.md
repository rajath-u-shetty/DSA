# Merge

"What's the point of having multiple branches?" you might ask. They're most often used to safely make changes without affecting your (or your _team's_) primary branch. However, once you're happy with your changes, you'll want to [merge](https://git-scm.com/docs/git-merge) them back into the main branch so that they make their way into the final product.

## Visual

Let's say you're in a state where you have two branches, each with their own unique commits:

```
A - B - C    main
   \
    D - E    other_branch
```


If you merge `other_branch` into `main`, Git combines both branches by creating a new commit that has _both_ histories as parents. In the diagram below, `F` is a [merge commit](https://git-scm.com/docs/git-merge#_true_merge) that has `C` and `E` as parents. `F` brings all the changes from `D` and `E` back into the `main` branch.

```
A - B - C - F    main
   \     /
    D - E        other_branch
```

## Assignment

First, switch back to `main`. Next, our `contents.md` file is eerily empty... update it to contain:

```md
# contents

* titles.md: The movie titles in the WebFlyx collection
* classics.csv: A comma-separated list of classic movies
* quotes: A directory of files containing memorable quotes from movies
```


Commit the changes with a message starting with `E:`. We should now have a commit history that looks like this:

```
A - B - C - E    main
         \
           D     add_classics
```


Run `git log --oneline --graph --all` and you should see a nice ASCII art representation of your commit history.

- [git log --graph docs](https://git-scm.com/docs/git-log#Documentation/git-log.txt---graph)
- [git log --all docs](https://git-scm.com/docs/git-log#Documentation/git-log.txt---all)

# Merge Commits

A merge commit is the result of merging two branches together.

Let's say we start with this:

```
A - B - C    main
   \
    D - E    vimchadsonly
```


And we merge `vimchadsonly` into `main` by running this while on `main`:

```bash
git merge vimchadsonly
```


The merge will:

1. Find the "merge base" commit, or "best common ancestor" of the two branches. In this case, `A`.
2. Replays the changes from `main`, starting from the best common ancestor, into a new commit.
3. Replays the changes from `vimchadsonly` onto `main`, starting from the best common ancestor.
4. Records the result as a new commit, in our case, `F`.
5. `F` is special because it has _two parents_, `C` and `E`.

**After:**

```
A - B - C - F    main
   \     /
    D - E        vimchadsonly
```

## Assignment

Your current `webflyx` commit history should look like this:

```
A - B - C - E    main
         \
           D     add_classics
```

Let's get the changes from the `add_classics` branch merged into the `main` branch. You will be presented with a code editor to change the commit message. Update the message to start with `F:`. Aside from that, use the default message. E.g. `F: Merge branch 'add_classics'`.

Save the file, and close the editor. _See the tips below if you don't know how to exit the editor._

Finally, still from the `main` branch run `git log --oneline --decorate --graph --parents`. This should give you a nice visual representation of the merge commit.

Your output from `git log --oneline --decorate --graph --parents` (aside from the hashes) should look _something_ like:

```
*   89629a9 d234104 b8dfd64 (HEAD -> main) F: Merge branch 'add_classics'
|\
| * b8dfd64 fba0999 (tag: 5.8, add_classics) D: add classics
* | d234104 fba0999 (tag: 6.1) E: update contents
|/
* fba0999 1381199 (tag: 3.8, origin/master, origin/main, master) C: add quotes
* 1381199 a21228f (tag: 3.7) B: add titles.md
* a21228f A: add contents.md
```

Each asterisk `*` represents a commit in the repository. There are multiple commit hashes on each line because the `--parents` flag logs the parent hash(es) as well.

- The first line, with these three hashes: `89629a9 d234104 b8dfd64` is our recent merge commit. The first hash, `89629a9` is the merge commit's hash, and the other two are the parent commits.
- The next section is a visual representation of the branch structure. It shows the commits on the `add_classics` branch and the `main` branch before the merge. Notice that they both share a common parent.
- The next three lines are just "normal" commits, each pointing to their parent.
- The last line is the initial commit and therefore has no parent.

# Fast Forward Merge

The simplest type of merge is a [fast-forward merge](https://git-scm.com/docs/git-merge#_fast_forward_merge). Let's say we start with this:

```
      C     delete_vscode
     /
A - B       main
```


And we run this while on `main`:

```bash
git merge delete_vscode
```

Because `delete_vscode` has _all the commits_ that `main` has, Git automatically does a fast-forward merge. It just moves the pointer of the "base" branch to the tip of the "feature" branch:

```
            delete_vscode
A - B - C   main
```

Notice that with a fast-forward merge, no [merge commit](https://git-scm.com/docs/git-merge#_true_merge) is created.

This is a common workflow when working with Git on a team of developers:

1. Create a branch for a new change
2. Make the change
3. Merge the branch back into `main` (or whatever branch your team dubs the "default" branch)
4. Remove the branch
5. Repeat

## Assignment

Because the `add_classics` branch has been merged into `main`, we don't need it anymore.

1. Delete the `add_classics` branch:

```bash
git branch -d add_classics
```

2. Create a new branch off `main` called `update_titles`. You can use [git switch -c](https://git-scm.com/docs/git-switch#Documentation/git-switch.txt--cltnew-branchgt).
3. Add a commit to that branch that updates the `titles.md` file and add "The Curious Case of Benjamin Button" as the final entry in the list of movies. Use `G:` to prefix the commit message.
4. Run `git log --oneline` to make sure the commit is there.
5. Run and submit the CLI tests from the `update_titles` branch.

