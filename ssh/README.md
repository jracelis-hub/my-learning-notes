#

SSH

_SSH Config Setup_

* Create ssh key by doing `ssh-keygen -t ed25519 -C email`
* To copy ssh keys do `ssh-copy-id -i $HOME/.ssh/id_ed25515_domain_name.pub` username@domain_name or username@IP
	* On _Windows_ cat id_ed25519 | ssh username@hostname "cat >> ~/.ssh/authorized_keys"
* Create ssh config in `$HOME/.ssh/config`

> [!TIP]
> Make sure you `chmod 600 $HOME/.ssh/config` to file restrict

Example of config file format
```
# Just thing of a normal host as username@domain_name or host@IP
Host nickname
	Hostname IP or domain_name
	User username
	Port port_number
	IdentityFile $HOME/.ssh/id_ed25519 # The Identityfile points to the 
	StrictHostKeyChecking no
	PasswordAuthentication
```
