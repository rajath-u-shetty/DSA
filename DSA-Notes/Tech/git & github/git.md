
# whats a repo?

A repo is essentially just a directory that contains a project (other directories and files). The only difference is that it _also_ contains a hidden `.git` directory. That [hidden directory](https://en.wikipedia.org/wiki/Hidden_file_and_hidden_directory) is where Git stores all of its internal tracking and versioning information for the project.

Creator of Linux and Git - Linus Torvalds

## git commands

In Git, commands are divided into high-level ("porcelain") commands and low-level ("plumbing") commands. The porcelain commands are the ones that you will use most often as a developer to interact with your code. Some porcelain commands are:
we use porcelain commands for 99% of the time.

- `git status`
- `git add`
- `git commit`
- `git push`
- `git pull`
- `git log`

 Some examples of plumbing commands are:

- `git apply`
- `git commit-tree`
- `git hash-object`
## Status

A file can be in one of [several states](https://git-scm.com/book/en/v2/Git-Basics-Recording-Changes-to-the-Repository#_the_very_basics) in a Git repository. Here are a few important ones:

- `untracked`: Not being tracked by Git
- `staged`: Marked for inclusion in the next commit
- `committed`: Saved to the repository's history

The `git status` command shows you the current state of your repo. It will tell you which files are untracked, staged, and committed.

## Staging

We need to stage it (add it to the "index") with the [git add](https://git-scm.com/docs/git-add) command before committing it later.

Without staging, every file in the repository would be included in every commit, but that's often not what you want.

## Commit

After staging a file, we can [commit](https://docs.github.com/en/pull-requests/committing-changes-to-your-project/creating-and-editing-commits/about-commits) it.

A commit is a snapshot of the repository at a given point in time. It's a way to save the state of the repository, and it's how Git keeps track of changes to the project. A commit comes with a message that describes the changes made in the commit.

Here's how to [commit](https://git-scm.com/docs/git-commit) all of your staged files:

```bash
git commit -m "your message here"
```

## Git Log

A Git repo is a (potentially very long) list of commits, where each commit represents the _full state of the repository_ at a given point in time.

The [git log](https://git-scm.com/docs/git-log) command shows a history of the commits in a repository. This is what makes Git a version control system. You can see:

- Who made a commit
- When the commit was made
- What was changed

# A commit hash

Each commit has a unique identifier called a "commit hash". This is a long string of characters that uniquely identifies the commit.

```
5ba786fcc93e8092831c01e71444b9baa2228a4f
```

For convenience, you can refer to any commit or change within Git by using the first `7` characters of its hash. For mine, that's `5ba786f`.
## commit hashes

While commit hashes _are_ derived from their content changes, there's [also some other stuff](https://git-scm.com/book/en/v2/Git-Internals-Git-Objects#_git_commit_objects) that affects the end hash. For example:

- The commit message
- The author's name and email
- The date and time
- Parent (previous) commit hashes
 
 Hash = SHA
Git uses a cryptographic hash function called [SHA-1](https://en.wikipedia.org/wiki/SHA-1) to generate commit hashes.

##  The Plumbing (It's just files all the way down) w

All the data in a Git repository is stored directly in the (hidden) `.git` directory. That includes all the commits, branches, tags, and other objects we'll learn about later.

Git is made up of [objects](https://git-scm.com/book/en/v2/Git-Internals-Git-Objects) that are stored in the `.git/objects` directory. A commit is just a type of object.

eg path - .git/objects/01/dtk3j4cc4343adhbi3t4cdnf

## Cat File

Luckily, Git has a built-in plumbing command, [cat-file](https://git-scm.com/docs/git-cat-file), that allows us to see the contents of a commit without needing to futz around with the object files directly.

```bash
git cat-file -p <hash>
<hash> is the first 4/5 charcters of the commit
```


# Trees and Blobs

Now that we understand some of our plumbing equipment, let's get into the pipes. Here are some terms to know:

- `tree`: git's way of storing a directory
- `blob`: git's way of storing a file

Here's what I got when I inspected my last commit:

```bash
> git cat-file -p 5ba786fcc93e8092831c01e71444b9baa2228a4f

tree 4e507fdc6d9044ccd8a4a3061324c9f711c4667d
author ThePrimeagen <the.primeagen@aol.com> 1705891256 -0700
committer ThePrimeagen <the.primeagen@aol.com> 1705891256 -0700

A: add contents.md
```

Notice that we can see:

- The `tree` object
- The `author`
- The `committer`
- The commit message

However, we _cannot_ see the contents of the `contents.md` file itself! That's because the `blob` object stores it.

for this we can do take the out commit id and then do git-cat for tht
```
git cat-file -p 4e50
```

# Storing Data

Git stores an entire _snapshot_ of files on a _per-commit_ level. This was a surprise to me! I always assumed each commit only stored the _changes_ made in that commit.

## Optimization

While it's true that Git stores entire snapshots, it _does_ have some performance optimizations so that your `.git` directory doesn't get too unbearably large.

- Git [compresses and packs](https://git-scm.com/book/en/v2/Git-Internals-Packfiles) files to store them more efficiently.
- Git deduplicates files that are the same across different commits. If a file doesn't change between commits, Git will only store it once.

## Assignment

1. Use `git cat-file -p` to view the hash of the `blob` for the `titles.md` file in your last commit. Save that hash somewhere in your notes.
2. Add a new directory to your project called `quotes`. Inside, add two files:

`starwars.md`:

```md
* "May the Force be with you"
* "I find your lack of faith disturbing"
* "I am your father"
* "Do or do not. There is no try"
* "I've got a bad feeling about this"
```

# Storing Data

Git stores an entire _snapshot_ of files on a _per-commit_ level. This was a surprise to me! I always assumed each commit only stored the _changes_ made in that commit.

## Optimization

While it's true that Git stores entire snapshots, it _does_ have some performance optimizations so that your `.git` directory doesn't get too unbearably large.

- Git [compresses and packs](https://git-scm.com/book/en/v2/Git-Internals-Packfiles) files to store them more efficiently.
- Git deduplicates files that are the same across different commits. If a file doesn't change between commits, Git will only store it once.


# Git Config

Git stores author information so that when you're making a commit it can track _who_ made the change. Here's how you might update your global [Git configuration](https://git-scm.com/docs/git-config) (don't do this yet):

```bash
git config --add --global user.name "ThePrimeagen"
git config --add --global user.email "the.primeagen@aol.com"
```

Let's take the command apart:

- `git config`: The command to interact with your Git configuration.
- `--add`: Flag stating you want to _add_ a configuration.
- `--global`: Flag stating you want this configuration to be stored globally in your `~/.gitconfig`. The opposite is "local", which stores the configuration in the current repository only.
- `user`: The section.
- `name`: The key within the section.
- `"ThePrimeagen"`: The value you want to set for the key.

### Get

We've used `--list` to see _all_ the configuration values, but the `--get` flag is useful for getting a single value.

```bash
git config --get <key>
```

### Unset

The `--unset` flag is used to remove a configuration value. For example:

```bash
git config --unset <key>
```

### Duplicates

Typically, in a key/value store, like a [Python dictionary](https://docs.python.org/3/tutorial/datastructures.html#dictionaries), you aren't allowed to have duplicate keys. Strangely enough, Git doesn't care.

#### Unset All

The `--unset-all` flag is useful if you ever _really_ want to purge all instances of a key from your configuration. Conversely, the `--unset` flag only works with a single instance of a key.

```bash
git config --unset-all example.key
```

### Remove a section

As I pointed out before, the `webflyx` section is nonsensical because Git doesn't use it for anything. While we _can_ store any key/value pairs we want in our Git configuration, it doesn't mean we _should_.

The `--remove-section` flag is used to remove an entire section from your Git configuration. For example:

```bash
git config --remove-section section
```

# Locations

There are several locations where Git can be configured. From more general to more specific, they are:

- **system**: `/etc/gitconfig`, a file that configures Git for all users on the system
- **global**: `~/.gitconfig`, a file that configures Git for all projects of a user
- **local**: `.git/config`, a file that configures Git for a specific project
- **worktree**: `.git/config.worktree`, a file that configures Git for part of a project

In my experience, 90% of the time you will be using `--global` to set things like your username and email. The other 9% of the time you will be using `--local` to set project-specific configurations. The last 1% of the time you _might_ need to futz with system and worktree configurations, but it's extremely rare.

# Overriding

If you set a configuration in a more specific location, it will override the same configuration in a more general location. For example, if you set `user.name` in the local configuration, it will override the `user.name` set in the global configuration.

![overriding](https://storage.googleapis.com/qvault-webapp-dynamic-assets/course_assets/e4S7M9u.png)


# What is a Branch?

A [Git branch](https://git-scm.com/book/en/v2/Git-Branching-Branches-in-a-Nutshell) allows you to keep track of different changes separately.

For example, let's say you have a big web project and you want to experiment with changing the color scheme. Instead of changing the entire project directly (as of right now, our `master` branch), you can create a new branch called `color_scheme` and work on that branch. When you're done, if you like the changes, you can [merge](https://git-scm.com/book/en/v2/Git-Branching-Basic-Branching-and-Merging) the `color_scheme` branch back into the `master` branch to keep the changes. If you don't like the changes, you can simply delete the `color_scheme` branch and go back to the `master` branch.

## Under the hood

A branch is just a named [pointer](https://en.wikipedia.org/wiki/Pointer_(computer_programming)#:~:text=A%20pointer%20is%20a%20programming,than%20storing%20the%20data%20itself.) to a specific commit. When you create a branch, you are creating a new pointer to a specific commit. The commit that the branch points to is called the tip of the branch.

![commits and branches](https://storage.googleapis.com/qvault-webapp-dynamic-assets/course_assets/iH1kl8l.png)

Because a branch is just a pointer to a commit, they're lightweight and "cheap" resource-wise to create. When you create 10 branches, you're not creating 10 copies of your project on your hard drive.

## Default Branch

We've been using [Git's](https://git-scm.com/) default `master` branch. Interestingly, [GitHub](https://github.com/) (a website where you can remotely store Git projects) recently changed its default branch from `master` to `main`. As a general rule, I recommend using `main` as your default branch if you work primarily with `GitHub`, as we will.

## How to rename a branch

```bash
git branch -m oldname newname
```

# Visualizing Branches

Throughout the rest of this course, we will use text to represent branches and commits. For example:

```
A - B - C  main
```

means a branch called `main` with 3 commits. `C` is the most recent commit (the tip), `B` is the previous commit, and `A` is the commit before that. To represent multiple branches, we'll use multiple lines:

```
    D - E  other_branch
  /
A - B - C  main
``````


# New Branch

You should already be on the `main` branch: your "default" branch. You can always check with `git branch`.

## Two Ways to Create a Branch

```bash
git branch my_new_branch
```

This creates a new branch called `my_new_branch`. The thing is, I rarely use this command because usually I want to create a branch and switch to it immediately. So I use this command instead:

```bash
git switch -c my_new_branch
```

![Copy icon](https://www.boot.dev/img/copy_icon.svg
The [switcommand allows you to switch branches, and the `-c` flag tells Git to create a new branch if it doesn't already exist.

When you create a new branch, it uses the _current commit_ you are on as the branch base. For example, if you're on your `main` branch with 3 commits, `A`, `B`, and `C`, and then you run `git switch -c my_new_branch`, your new branch will look like this:

![branch diagram same commits](https://storage.googleapis.com/qvault-webapp-dynamic-assets/course_assets/oah2FRD.png)


## Switching Branches

We talked about using [git switch](https://git-scm.com/docs/git-switch) to change branches. There's another command that you'll certainly run into because it's been around for a long time and older developers are used to it: [git checkout](https://git-scm.com/docs/git-checkout). `git switch` is a newer command that is meant to be more intuitive and user-friendly. It's recommended to use `git switch` over `git checkout` for simply switching branches.

To switch to a branch called `prime`:

```bash
git switch prime

# or, the old way:
git checkout prime
```

# Log Flags

As you know, `git log` shows you the history of commits in your repo. There are a few flags I like to use from time to time to make the output easier to read.

The first is [--decorate](https://git-scm.com/docs/git-log#Documentation/git-log.txt---decorateshortfullautono). It can be one of:

- `short` (the default)
- `full` (shows the full ref name)
- `no` (no decoration)

Run `git log --decorate=full`. You should see that instead of just using your branch name, it will show the full ref name. A [ref](https://git-scm.com/book/en/v2/Git-Internals-Git-References) is just a pointer to a commit. All branches are refs, but not all refs are branches.

Run `git log --decorate=no`. You should see that the branch names are no longer shown at all.

The second is [--oneline](https://git-scm.com/docs/git-log#Documentation/git-log.txt---oneline). This flag will show you a more compact view of the log. I use this one all the time, it just makes it so much easier to see what's going on.

```bash
git log --oneline
```

# Git Files

KungFu? No, _Gitfu_.

Remember, Git stores all its information in files in the `.git` subdirectory at the root of your project, even information about branches. The "heads" (or "tips") of branches are stored in the `.git/refs/heads` directory. If you `cat` one of the files in that directory, you should be able to see the commit hash that the branch points to.