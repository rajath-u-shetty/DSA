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