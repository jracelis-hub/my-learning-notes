# Git Notes

## Introduction

| `git commands`          |   description           |
|:-----------------------:|-------------------------|
| `git --global`          | create a global config file |
| `git add **FILE**`      | add file to ***staging*** |
| `git commit -m "Description"` | to commit ***ALL*** files from ***staging*** to "main" |
| `git status` | to see status of current git working directory |
| `git log` | to see all commit changes |
| `git init` | to initialize git control for the current working directory | 
| `git rm --cached **FILE**` | to remove from ***staged*** |
| `git restore --staged **FILE**`  | to remove from ***staging*** |
| `git restore **FILE**` | to restore a delete file |
| `git rm **FILE**` | to remove a file from working directory |
| `git mv "**OLD_FILE**" "**NEW_FILE**" | to rename a file |
| `git reset **commit hash** ` | to reset to that commit |
| `git branch **NAME**` | to create a new branch |
| `git branch` | to show current working branch |
| `git switch **branch NAME**` | to switch to working branch directory |
| `git merge` |
| `git pull` |
| `git fetch` |


### Setup Environment

* `git --global user.name "Jarron Racelis"`
* `git --global user.email jarron.racelis@gmail.com`
* `git --global init.defaultbranch <name>`

> [!NOTE]
> This will be stored in $CURRENT_DIR/.gitconfig

#### ***Initilizing***

To begin controlling your working directory with git.  

`cd $working_directory` to your working directory and initialize all the contents in the file by using:  

`git init` from here you can check the status of your git by using `git status`\

> [!IMPORTANT]
> Contents are not in your git control yet. Must use `git add **file**` to add to _staging_.

Example:\

`git add README.md` -> this is now in staging\

```
work flow is `working file` -> `staging` -> `commit`\
`file editing` (working file) -> `git add file` (staging) -> `git commit -m` "Description Changes"\
to skip staging from `working file` -> `commit`\
`git commit -a -m "Write Description here"`\ 
```

#### ***Creating Branches*** 

---
Two Methods of Creating Branches: `git branch **name**` or `git checkout -b **name**`\

* To see the branch created use `git branch` this will list all the branches.\
* The \* next to the branch name means the current working branch.\
* To switch into a new branch use `git switch **name**` where the name is the name of the branch you want to switch to.\

> [!TIP]
> Can also make branch and switching into by using `git switch -c **name**.`

```
`git switch -c name` this will switch into the **-c** created branch, where branch is name.\
```

* To delete a branch `git branch -d **name**`
* To merge a branch `git merge -m "**Description**" branch_name`

#### ***Hosting Git to Github***

to create a new repository on the command line
```
git init
git add README.md
git commit -m "First Commit"
git branch -M main
git remote add origin https://github.com/jracelis-hub/git_hub_learning.git
git push -u origin main
```

push an existing repository from the command line
```
git remote add origin https://github.com/jracelis-hub/git_hub_learning.git [url]
git branch -M main
git push -u origin main
```

_Creating SSH Keys for Github_

To create local ssh keys do the following:

```
ssh-keygen -t ed25519 -C jarron.racelis@gmail.com

# This will be stored locally probably in ~/.ssh/id_ed25519
# After set up the PID

eval "$(ssh-agent -s)"

# run ps youll see a new process ID
```

From here you navigate to your github account and the repo you want ssh access to -> settings -> deploy keys -> add deploy key \
Fille the title with a descripton example "jarron home desktop virtual machine"\
then in the keys section add the id_ed25519.pub key\

To update git local repository to git remote repository use:

```bash
git push remote-name local-name

#EXAMPLE

git push origin main
```

> [!NOTE]
> To find what the local and remote name is `cd .git` and `cat config` this will list out all the configurations of your local repo
