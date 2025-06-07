# Git Notes

## ***Table of Contents***
* [***Introduction***](#introduction)
	* [***Setup Environment***](#setup-environment)
		* [***Initilizing Local Environment***](#initilizing-local-environment)

## ***Introduction***

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

### ***Setup Environment***

* `git --global user.name [github username]`
* `git --global user.email [github email]`
* `git --global init.defaultbranch [main]`

> [!NOTE]
> This will be stored in $current_directory/.gitconfig

#### ***Initilizing Local Environment***

To begin controlling your working directory with git.  

* `mkdir $working_directory` to make a git directory to work in.
* `mv .gitconfig $working_directory` to have .gitconfig in same location.
* `cd $working_directory` to begin initialzing.
	* if you have working documents already made `mv $files $work_directory`.
* `git init` to initialize your working directory.
	* `git status` to see the current status of local git repository. 


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

Must be on main branch to preform the merging.

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

* From here you navigate to your github account and the repo you want ssh access to -> settings -> deploy keys -> add deploy key.
* Fill title which is description of where this key sits.
* Copy the **id_ed25519.pub** key from step 1 into the spot that says add keys.

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
