
# Rebase

"[Rebase](https://git-scm.com/docs/git-rebase) vs [Merge](https://git-scm.com/docs/git-merge)" is one of the most hotly debated topics in the Git world. A lot of the discussions you'll see online come down to the fact that many developers (yes, even professionals) don't understand the purpose of rebase and use it incorrectly, causing a bunch of Git havoc, and then blame the rebase command.

_It's not Git's fault, it's a skill issue._

## Visualizing Rebase

Say we have this commit history:

```
A - B - C    main
   \
    D - E    feature_branch
```

We're working on `feature_branch`, and want to bring in the changes our team added to `main` so we're not working with a stale branch. We could merge `main` into `feature_branch`, but that would create an additional merge commit. Rebase avoids a merge commit by replaying the commits from `feature_branch` on top of `main`. After a rebase, the history will look like this:

```
A - B - C         main
         \
          D - E   feature_branch
```

# When to Rebase

[git rebase](https://git-scm.com/docs/git-rebase) and [git merge](https://git-scm.com/docs/git-merge) are different tools.

An advantage of merge is that it preserves the true history of the project. It shows when branches were merged and where. One disadvantage is that it can create a lot of merge commits, which can make the history harder to read and understand.

A linear history is generally easier to read, understand, and work with. Some teams enforce the usage of one or the other on their `main` branch, but generally speaking, you'll be able to do whatever you want with your own branches.

# Warning

You should _never_ rebase a public branch (like `main`) onto anything else. Other developers have it checked out, and if you change its history, you'll cause a lot of problems for them.

However, with your own branch, you can rebase onto other branches (including a public branch like `main`) as much as you want.

# Undoing Changes

One of the major benefits of using Git is the ability to undo changes. There are _a lot_ of different ways to do this, but first, we'll start by going back in the commit history without discarding changes.

# Git Reset Soft

The [git reset](https://git-scm.com/docs/git-reset) command can be used to undo the last commit(s) or any changes in the index (staged but not committed changes) and the worktree (unstaged and not committed changes).

```bash
git reset --soft COMMITHASH
```

The `--soft` option is useful if you just want to go back to a previous commit, but keep all of your changes. Committed changes will be uncommitted and staged, while uncommitted changes will remain staged or unstaged as before.

# Git Reset Hard

In the last lesson, we undid a commit but kept the changes. We don't want to keep the changes to `titles.md`, here's how to reset those changes.

```bash
git reset --hard COMMITHASH
```

This is useful if you just want to go back to a previous commit and discard all the changes.

# Danger

I want to stress how **dangerous** this command can be. If you were to simply delete a _committed_ file, it would be trivially easy to recover because it is tracked in Git. However, if you used `git reset --hard` to undo committing that file, it would be deleted for good.

Always be careful when using `git reset --hard`. It's a powerful tool, but it's also a dangerous one.

## Reset to a Specific Commit

If you want to reset back to a specific commit, you can use the [git reset --hard](https://git-scm.com/docs/git-reset) command and provide a commit hash. For example:

```bash
git reset --hard a1b2c3d
```


# Git Remote

Often our frenemies (read: coworkers) make code changes that we need to begrudgingly accept into our pristine bug-free repos. _/s_

This is where the "distributed" in "distributed version control system" comes from. We can have "remotes", which are just external repos with _mostly_ the same Git history as our local repo.

When it comes to Git (the CLI tool), there really isn't a "central" repo. GitHub is just someone else's repo. Only by convention and convenience have we, as developers, started to use GitHub as a "source of truth" for our code.

# Adding a Remote

In git, another repo is called a "remote." The standard convention is that when you're treating the remote as the "authoritative source of truth" (such as GitHub) you would name it the "origin".

By "authoritative source of truth" we mean that it's the one you and your team treat as the "true" repo. It's the one that contains the most up-to-date version of the accepted code.

# Command Syntax

```bash
git remote add <name> <uri>
```

# Fetch

Adding a remote to our Git repo does _not_ mean that we automagically have all the contents of the remote. First, we need to [fetch](https://git-scm.com/docs/git-fetch) the contents (but not yet!).

## Command

```bash
git fetch
```


This downloads copies of all the contents of the `.git/objects` directory (and other book-keeping information) from the remote repository into your current one.

# Making Fetch Happen

Now, to bring the remote `webflyx` repo's info into our `webflyx-local` repo, we have to [fetch](https://git-scm.com/docs/git-fetch) it.

# Not Fetched

Just because we fetched all of the metadata from the remote `webflyx` repo doesn't mean we have all of the files.

# Log Remote

The `git log` command isn't only useful for your _local_ repo. You can log the commits of a _remote_ repo as well!

```bash
git log remote/branch
```

For example, if you wanted to see the commits of a branch named `primeagen` from a remote named `origin` you would run:

```bash
git log origin/primeagen
```

# Merge

Just as we merged branches within a single local repo, we can also merge branches between local and remote repos.

## Syntax

```bash
git merge remote/branch
```

For example, if you wanted to merge the `primeagen` branch of the remote `origin` into your local `main` branch, you would run this inside the local repo while on the `main` branch:

```bash
git merge origin/primeagen
```

# GitHub Repository

[GitHub](https://github.com/) is the most popular website for Git repositories (projects) online. That is, for hosting "remotes" on a central website. GitHub serves several purposes:

- As a backup of all your code on the cloud in case something happens to your computer
- As a central place to share your code and collaborate on it with others
- As a public portfolio for your coding projects

## Git != GitHub

It's important to understand that Git and GitHub are _not the same_! Git is an open-source command line tool for managing code files. GitHub and its primary competitors, [GitLab](https://gitlab.com/) and [Bitbucket](https://bitbucket.org/), are commercial web products that _use_ Git. Their websites give us a way to store our code that's managed by Git.

# GitHub Repo

Just like we created a `webflyx-local` repo and used `webflyx` as a remote, GitHub makes it easy to create "remotes" that are hosted on their site.

## Assignment

1. Create a [new repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-new-repository) on GitHub called `webflyx`. Leave it completely blank, and make sure it's public (for now, you can always change it later).
2. Authenticate your local Git configuration with your GitHub account. I recommend [installing](https://github.com/cli/cli#installation) the [GitHub CLI](https://cli.github.com/). One quick and easy installation method is to use [Webi](https://webinstall.dev/gh) by simply running:

```bash
curl -sS https://webi.sh/gh | sh
```

Then make sure you're authenticated by running this command to [login through your browser](https://docs.github.com/en/github-cli/github-cli/quickstart#prerequisites):

```bash
gh auth login
```

3. Navigate back into your `webflyx` repo locally, it's going to be our "local" repo, you can forget about or delete `webflyx-local` if you want.
4. [Add a remote](https://git-scm.com/docs/git-remote) to your `webflyx` repo that points to the `webflyx-remote` repo you just created. That command should look something like this:

```bash
git remote add origin https://github.com/your-username/webflyx.git
```

# Git Push

The `git push` command pushes (sends) local changes to any "remote" - in our case, GitHub. For example, to push our local `main` branch's commits to the remote `origin`'s `main` branch we would run:

```bash
git push origin main
```


_You need to be authenticated with the remote to push changes, which you should have done in the last lesson._

## Alternative Options

You can also push a local branch to a remote with a _different_ name:

```
git push origin <localbranch>:<remotebranch>
```

_It's less common to do this, but nice to know._

You can also _delete_ a remote branch by pushing an empty branch to it:

```
git push origin :<remotebranch>
```

# Pull

Fetching is nice, but most of the time we want the _actual file changes_ from a remote repo, not just the metadata.

## Command Syntax

`git pull [<remote>/<branch>]`

The syntax `[...]` means that the bracketed remote and branch are optional. If you execute git pull without anything specified it will pull your current branch from the remote repo.

# Pull Requests

On GitHub, a [pull request](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/about-pull-requests) is a way to propose some changes. It's very common to use pull requests if you want to make changes to an open source project, or if you're working on a team.

Pull requests allow team members to see what changes are being proposed and to discuss them before they are merged into the main codebase.

# My Workflow

While on the topic of pull requests, I want to share a note on my simple workflow. 90% of the time, you're only using a handful of git commands to get your coding work done.

## Keep stuff on GitHub

I keep all my serious projects on GitHub. That way if my computer explodes, I have a backup, and if I'm ever on another computer, I can just clone the repo and get back to work.

## Rebase vs Merge

I've configured Git to rebase by default on pull, rather than merge so I keep a linear history. If you want to do the same, you can add this to your global Git config:

```bash
git config --global pull.rebase true
```

## My Solo Workflow

When I'm working by myself, I usually stick to a single branch, `main`. I mostly use Git on solo projects to keep a backup remotely and to keep a history of my changes. I only rarely use separate branches.

1. Make changes to files
2. `git add .` (or `git add <files>` if I only want to add specific files)
3. `git commit -m "a message describing the changes"`
4. `git push origin main`

It really is that simple for most solo work. `git log`, `git reset`, and some others are, of course, useful from time to time, but the above is the core of what I do day-to-day.

# My Team Workflow

When you're working with a _team_, Git gets a bit more involved (and we'll cover more of this in part 2 of this course). Here's what I do:

- Update my local `main` branch with `git pull origin main`
- Checkout a new branch for the changes I want to make with `git switch -c <branchname>`
- Make changes to files
- `git add .`
- `git commit -m "a message describing the changes"`
- `git push origin <branchname>` (I push to the _new_ branch name, not `main`)
- Open a [pull request](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/about-pull-requests) on GitHub to merge my changes into `main`
- Ask a team member to review my pull request
- Once approved, click the "Merge" button on GitHub to merge my changes into `main`
- Delete my feature branch, and repeat with a new branch for the next set of changes