# Powershell

Powershell is broken to 3 different interfaces:
- `Drives` - drives are 
- `Objects` -
- `Items` - eveything in a drive is represented as an item. An item can many forms, the item can be a ***container*** like a `folder`  or a `registry key`, meaning they can hold other items.

Items
- `Folder` - a directory in a drive
- `File` - a file that holds data
- `Environment Variables` -
- `Registry Keys` -

```powershell
Get-Item C:User\jarro

Get-Item HKCU:

Get-Item Env:

Get-ChildItem C:\Users\jarro\dev\
```

Drives
- `C:` - C drive, also known as the file system. Think of linux with `/` root directory
- `Env:` - environment variables
- `HKLM:` - HKEY_LOCAL_MACHINE which is primary root key in the Windows Registry database that stores system wide configurations
- `HKCU:` - HKEY_CURRENT_USER compared to local machine which is system wide, current user only affect the user profile
- `Variables:` -

To see different `env:` variables in current powershell use the following
```powershell
$env:path
```

Variables

Variables can be denoted with the `$` symbol

To create a variable `$variable_name` `=` `value`
```powershell
$name = "Jarron Racelis"
Write-Output "Hello $name"
Hello Jarron Racelis
```

## Cmdlets

`Cmdlets` are using **Verb**-**Noun** represenation that manipulate drives, items and objects

Notation:
```powershell
Get-ChildItem -Name "*.cpp" 
```

- `Get` is the verb or the action that it will be performing on the noun
- `ChildItem` is the noun that will be getting performed from the verb
- `-Name` is a parameter for `Get-ChildItem` that may include an argument
- `"*.cpp"` is the parameter argument for that parameter

> Notice this gives an output that shows `Property Names`
```powershell
Mode                 LastWriteTime         Length Name          <--- Property Name
----                 -------------         ------ ----
-a----        10/12/2025   7:33 PM            165 containers.cpp <--- Property Values
```

To get a list of cmdlets based on a `verb` or a `noun` do the following:
```powershell
Get-Command -Verb Get

Get-Command -Noun Item
```

To get help on a specific `cmdlet` do:
```powershell
Get-Help Verb-Noun

Get-Help Get-ChildItem
```

> [!NOTE]
> Might need to use `Update-Help` but it is important to use this in admin mode 

For the basics of navigating through powershell use the following `cmdlets` that are similar to shell commands do the following:

- `Get-ChildItem` - `ls` list all items 
- `Set-Location` - `cd` change directory
- `New-Item` - `touch` to create a file 
- `Get-Help` - get help for a specific `cmdlet`
- `Get-Alias` - get list of aliases 
- `Remove-Item` - `rm` item 

To create a directory in 
```powershell
New-Item name_directory -ItemType Directory 
```

Powershell support the pipe `|` symbol similar to linux. What the pipe symbol does it uses the output from the previous command as input for the next command
```powershell
Get-Servce | Out-File "C:\Users\jarron\dev\file.txt"
```
The `cmdlet` out put was piped into a a file called file.txt

## Set Up SSH On Windows

```powershell
Add-WindowsCapability -Online -Name OpenSSH.Server~~~~0.0.1.0
Start-Service sshd
Set-Service -Name sshd -StartupType `Automatic`
```

To check if the service is running

```powershell
Get-Service sshd
netstat -a | findstr :22
```
