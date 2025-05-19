<div align="center">
<h1 align="center">Networking Notes</h1>

<p align="center">
<img src="github.com/jracelis-hub/my-learning-notes/blob/main/images/osi_tcp_ip.png">
</p>

</div>

## Introduction To Networking

### ***Introduction***

Networking the most important process when it comes to communication. It is the process of connecting two or more computers to share resources, information, and communication.

### ***Definitions***

* Transmission Media - The medium through which devices communicate, it can be a wired media like optical fiber and ethernet. It can also be a wireless media like WiFi, Bluetooth and infrared

* Protocol - A set of rules and standards that define how devices on a network communicate with each other
* Node - Any device connected to a network, such as a computer, printer, or router
* Network - A collection of interconnected devices, such as a computer, printers, and servers, that can communicate with each other

* ***TCP/IP*** - A set of protocols used to communicate over the internet and other networks
* ***VNC*** - Virtual Network Computering
* ***VPN*** - Virtual Private Network: allows for information to be securely sent across a public or unsecured netowrk, such as the internet
* ***SSL*** - Secure Socket Layer
* ***TSL*** - Transport Layer Security
* ***CA*** - Certificate of Authority

Protocols
* ***SSH*** - Secure Shell
* ***ARP*** - Address Resolution Protocol
* ***HTTPS*** - Secure Hypertext Transfer Protocol 
* ***HTTP*** - Hypertext Transfer Protocol
* ***FTP*** - File Transfer Protocol
* ***ICMP*** - Internet Control Message Protocol
* ***SNMP*** - Simple Network Management Protocol
* ***NFS*** - Network File System
* ***SIP*** - Session Initiation Protocol
* ***POP*** - Post Office Protocol
* ***IP*** - Internet Protocol: A unique numerical identifier assigned to each device on a network, used to identify and communicate with other devices
* ***TCP*** - Transmission Control Protocol
* ***UDP*** - User Datagram Protocol
* ***RPC*** - Remote Procedure Call
* ***RDP*** - Remote Desktop Protocol
8 ***VoIP*** - Voice over Internet Protocol

Ports
* 443 - HTTPS
* 80 - HTTP
* 20 - FTP
* 22 - SSH
* 23 - Telnet
* 25 - SMTP
* 53 - DNS

Wifi
* ***WPA*** - Wi-Fi proectect access
* ***ISP*** - Internet Service Provider
* ***NAT*** - Network Address Translation
* ***DNS*** - Domain Name System: A system that translates domain names (such as www.google.com) into IP addresses, allowing devices to locate and connect to websites and otehr network resources
* ***LAN*** - Local Area Network: A network that connects devices within a limited geographical area, such as a home, office, or building
* ***WAN*** - Wide Area Network: A network that connects devices over a large geograpical area, such as a multiple offices in different cities or countries
* ***PAN*** - Personal Area Network
* ***WLAN*** - Wireless Local Area Network
* ***MAC*** - Medica Access Control
* ***DHCP*** - Dynamic Host Configuration Protocol: A protocol that automatically assigns IP addresses and network configuration settings to a device on a network
* ***IPv4*** - Internet Protocol Version 4 (32-bit)
	* 8 bit octets
	* 255.255.255.255
* ***IPv6*** - Internet Protocol Version 6 (128-bit) hexadecimal format
	* 16:16:16:16:16:16:16:16
* ***2.4Ghz & 5Ghz***
* ***LTE*** - Long Term Evolution 
* ***4G*** - Fourth Generation
* ***5G*** - Fifth Generation

* Routers - A networking device that connects multiple networks together and forwards data packets between them
* Firewalls - A security device or software that monitors and controls incoming and outgoing networt traffic, based on a set of predefined security rules
* Switches - A networking device that connects devices on a network and forwards data packets between them
* Server -
* Client -
* Subnet - 

## Sockets

***What is a Socket?***

A socket is an endpoint of communication link between two systems ***client*** and a ***server***, enabling them to exchange data across a network.\

* The `socket()` method allocates and returns a socket fd _(file descriptor)_ or handle, which is used to create a connection.\
* A handle must be closed when done to free resources on the OS side.


***Two types of sockets***

* Listing socket
* Connection socket

_Listening Socket_

Listening is telling the OS that an app is ready to accept TCP connectioins from a given port. The OS then returns a socket handle for apps to refer to that port. From the listening socket, apps _(accept) incoming TCP connections, which is also repsresented as socket handle. 

To create a ***listening socket*** requires at least 3 API calls:

1.) Obtain a socket handle via `socket()`.
2.) Set the listening IP:port via `bind()`.
3.) Create the listening socket via `listen()`.

Then use `accept()` API to wait for incoming TCP connections.\
EXAMPLE
```
# Step 1
fd = socket()
# Step 2
bind( fd, address)
# Step 3
listen(fd)

# fd = handle
while True:
	connect_fd = accept(fd)
	do_somesomething_with(connection_fd)
	close(connection_fd)
```

_Connection Socket_

A connection socket is created from the client side with 2 API calls:

1.) Obtain a socket handle via `socket()`.
2.) Create the connection socket via `connect()`.

EXAMPLE
```
# Step 1
fd = socket()
# Step 2
connect(fd, address)

do_something_with(fd)
close(fd)
```

`socket()` creates a typeless socket; the socket tpye (listening or connection) is determined after the `listen()` or `connect()` call. The `bind()` between `socket()` and `listen()` sets parameters.\
The `setsockopt()` API can set other socket parameters as needed.

_Read and Write_

TCP and UDP provide different types of services but share the same socket API. Which include:
* `send()`
* `rece()`

TCP (Segments)\
For byte-stream-based sockets, each `send/recv` appends to/consumes from the byte stream.

UDP (Datagrams)\
For message-based sockets, each `send/recv` coressponds to a single packet.

On Linux, `send/recv` are just a variant of the more generic `read/write` syscall used for both sockets, disk files, pipes, and etc. Different types of handle sharing the same read/write API is merely a coincidence, it's unlikely to have a piece of code that works for both TCP and UDP, as they are different.

***TCP socket requirements***

* Listening TCP socket:
	* `bind()` & `listen()`
	* `accept()`
	* `close()`
* Using a TCP socket:
	* `read()`
	* `write()`
	* `close()`
* Create a TCP connection: `connect()`

### ***Create a TCP Server***

_Step 1: Obtain a socket handle_

The `socket()` syscall takes 3 integer arguments.
```
int fd = socket(AF_INET, SOCKET_STREAM, 0)
```
> [!NOTE]
> Also can be written as `socket( int domain , int type , int protocol )`
3 Integer Args:

1.) `AF_INET` is for IPv4. Use `AF_INET6` for IPv^ or dual-stack sockets.
2.) `SOCKET_STREAM` is for TCP. USE `SOCK_DGRAM` for UDP
3.) The 3rd agrument is 0 but is also known for different protocalls.

| Protocol | Arguments |
|:---:|:---|
| IPv4+TCP | `socket(AF_INET, SOCK_STREAM, 0)` |
| IPv6+TCP | `socket(AF_INET6, SOCK_STREAM, 0)` |
| IPv4+UDP | `socket(AF_INET, SOCK_DGRAM, 0)` |
| IPv6+UDP | `socket(AF_INET6, SOCK_DRRAM, 0)` |

* Use `man socket` to get a better understanding of the topic.
* Also `man ip` tells you how to create TCP/UDP sockets and the requirements.

_Step 2: Set socket options_

There are many options that change the behavior of a socket, such as TCP no delay, IP QoS, etc. These options are set via the `socksockopt()` API. Like the `bind()` API, this just passes a parameter to the OS as te actual socket has not been created yet.

```
int val=1;
setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
```

* The combination of the 2nd & 3rd arguments specifies which option to set.
* The 4th argument is the option value.
* Different options use different types, so the size of the option value is also needed.

In this case, we set the `SO_REUSEADDR` option to an `int` value of `1`, this option accepts a boolean value of `0` or `1`. 

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






