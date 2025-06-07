# Git Notes

## Table of Content

* [_Introduction_](#introduction)
	* [_Setup Environment_](#setup-environment)
        * [_Initilizing Local Environment_](#initilizing-local-environment)
    * [_Creating Branches_](#creating-branches)
* [_Hosting Git to Github_](#hosting-git-to-github)
    * [_Creating SSH Keys for Github_](#creating-ssh-keys-for-github)
* [_Appendix_](#appendix)

## Introduction

### Setup Environment

- `git --global user.name [github username]`
- `git --global user.email [github email]`
- `git --global init.defaultbranch [main]`

> [!NOTE]
> This will be stored in $working_directory/.gitconfig

### Initilizing Local Environment

To begin controlling your working directory with git.  

- `mkdir $working_directory` to make a git directory to work in.
- `mv .gitconfig $working_directory` to have .gitconfig in same location.
- `cd $working_directory` to begin initialzing.
	- if you have working documents already made `mv $files $work_directory`.
- `git init` to initialize your working directory.
	- `git status` to see the current status of local git repository. 

> [!IMPORTANT]
> Contents are not in your git control yet. Must use `git add FILE(s)` to add to _staging_.

Example:

`git add README.md` -> this is now in staging\

WORK FLOW
```
working file -> staging -> commit
working file -> git add file (staging) -> git commit -m "Message"
local repo (git) -> cloud repo (github)

# To Skip Staging From Working
git commit -a -m "Message" 
```

## Creating Branches

Two Methods of Creating Branches:

- `git branch name`
- `git checkout -b name`

- To see the branch created use `git branch` this will list all the branches.
- The * next to the branch name means the current working branch.
- To switch into a new branch use `git switch name` where the name is the name of the branch you want to switch to.

> [!TIP]
> Can also make branch and switching into by using `git switch -c name.`

```
`git switch -c name` this will switch into the -c (created) branch, where branch is name.
```

- To delete a branch `git branch -d name`
- To merge a branch `git merge -m "Message" branch_name`

Must be on main branch to preform the merging.

## Hosting Git to Github

to create a new repository on the command line
```
git init
git add README.md
git commit -m "Message"
git branch -M main
git remote add origin https://github.com/username/repos_name.git
git push -u origin main
```

push an existing repository from the command line
```
git remote add origin https://github.com/username/repos_name.git 
git branch -M main
git push -u origin main
```

### Creating SSH Keys for Github

Step 1: Create local ssh keys 

Example
```
# This will be stored locally probably in $HOME/.ssh/id_ed25519
ssh-keygen -t ed25519 -C [description of what this is for]

# After set up the PID, if you rerun this process it will restart another ssh-agent
eval "$(ssh-agent -s)" 

# then add your key
# if you have multiple keys make sure to add all the keys
ssh-add $HOME/.ssh/id_ed25519 # This is the location of where you keys are

# To see all the keys in your ssh-agent run ssh-add -l
SHA256 ...... [comment]
SHA256 ...... [comment]

# you can verify if process is happening by running
ps 
```

Step 2: Place SSH Keys on Github

- From here you navigate to your github account and the repo you want ssh access to -> settings -> deploy keys -> add deploy key.
- Fill title which is description of where this key sits.
- Copy the **id_ed25519.pub** key from step 1 into the spot that says add keys.

To clone github repo with ssh keys do.

```
# Note you can just copy and paste it from the git hub repo by clicking Code -> SSH
git clone git@github.com:username/repository_name.git
```

To update git local repository to git remote repository use:

```bash
git push remote-name local-name

#EXAMPLE
git push origin main
```

> [!NOTE]
> To find what the local and remote name is `cd .git` and `cat config` this will list out all the configurations of your local repo

Example:
```
[core]
	repositoryformatversion = 0
	filemode = true
	bare = false
	logallrefupdates = true
[remote "origin"]
	url = learning:username/repos_name
	fetch = +refs/heads/*:refs/remotes/origin/*
[branch "main"]
	remote = origin
	merge = refs/heads/main
```

> [!TIP]
> You can also make a config file in `~/.ssh/config` using the keys from github and point it to that specific repo.

Example:
```
vim ~/.ssh/config

Host nameWhatYouWant
    HostName github.com
    User git
    IdentityFile ~/.ssh/id_ed25519 # Make sure this is the key that is on your repo
```

Then to clone/pull/push from git <-> github
```
# Normal Way With SSH Keys
git clone git@github.com:username/repo_name.git

# With ~/.ssh/config File
git clone nameWhatYouWant:username/repo_name.git

# Notice that the git@github.com get replaced with the Host section
# Think of this like how you create a config for ssh to a network device via ssh
# username@domainName/IP
```

> [!WARNING]
> It is always best practice to have keys for each repositiory. Don't use the same pub/private keys for each repository.

## Appendix

|      `git commands`     |      description        |
|:-----------------------:|-------------------------|
|       `git config       |   create a config file  |
|     `git add FILE`      | add **file** to ***staging*** |
| `git commit -m "Description"` | to commit ***ALL*** files from ***staging*** to "main" |
| `git status` | to see status of current git working directory |
| `git log` | to see all commit changes |
| `git init` | to initialize git control for the current working directory | 
| `git rm --cached **FILE**` | to remove from ***staged*** |
| `git restore --staged **FILE**`  | to remove from ***staging*** |
| `git restore **FILE**` | to restore a delete file |
| `git rm **FILE**` | to remove a file from working directory |
| `git mv "**OLD_FILE**" "**NEW_FILE**"` | to rename a file |
| `git reset **commit hash** ` | to reset to that commit |
| `git branch **NAME**` | to create a new branch |
| `git branch` | to show current working branch |
| `git switch **branch NAME**` | to switch to working branch directory |
| `git merge` | to merge a branch to main or branch to branch |
| `git pull` | fetch from and integrate with another erpository or a local branch |
| `git fetch` | to download objects and refs from another repository |
| `git push` | to push a local repository to content to a remote repository |
