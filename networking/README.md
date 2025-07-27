# Networking

![TCP](/images/osi_tcp_ip.png)

## Introduction To Networking

### ***Introduction***

What is Networking?

Networking is the process of connecting two or more devices to share information by communicating through the same protocols.

### Physical Devices

Servers -

Switch - 

Router - this is used to connect to the internet.

### ***Definitions***

* Internet Service Provider (`ISP`) - 
* Transmission Media - The medium through which devices communicate, it can be a wired media like optical fiber and ethernet. It can also be a wireless media like WiFi, Bluetooth and infrared
* Protocol - A set of rules and standards that define how devices on a network communicate with each other
* Node - Any device connected to a network, such as a computer, printer, or router
* Network - A collection of interconnected devices, such as a computer, printers, and servers, that can communicate with each other
* Local Area Network (`LAN`) - connects a network in a local vicinity
* Wide Area Network (`WAN`) - conects a network that is widely a part

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

Network programming used two different IP addresses:
	* IPv4
		* Original Domain
		* 32-bit addresses
		* 0.0.0.0 - 255.255.255.255
		* Dotted quad
	* IPv6
		* 128-bit addresses
		* Eight groups of 4 hex values, seperated by colons
		* Handles plenty of devices
> IPv6 addresses can be shortened
> 0001:0002:0003:0004:0005:0006:0007:0008 can be rewritten as 1:2:3:4:5:6:7:8
		* loop back address for IPv6 is ::1 or 0000:0000:0000:0000:0000:0000:0000:0001

If you programm for both IPv4 and IPv6 it is called a dual-stack configuration.

***IP Protocol Suites***

_TCP_
	* Transmission Control Protocol
	* Streaming
	* Data is sent in sequence
	* Reliable
_UDP_
	* User Datagram Protocol
	* Connectionless
	* Bad packets are not retransmitted, nor ad packets guaranteed to arrive in sequence

---
* Set TCP or UDP when you write netwroking code
* Setup works differently between the two
* TCP/IP is often used to describe all network programming
* TCP and UDP are different protocols with different approaches

***IP Addresses Reserved for Local Networks***

|	  |     |
|:---:|:---:|
| 10.0.0.0 | 10.255.255.255 |
| 172.16.0.0 | 172.31.255.255 |
| 192.168.0.0 | 192.168.255.255 |

Local Router Assigns IP Addresses
	* Each device is asssigned an address in one of thse ranges
	* The address is known as the public address
	* Now two devices are gien the same address
	* IPv6 addresses may also be assigned

Subnet Mask
	* Value is expressed as the address:

## Socket Programming 

The use of C APIs, the following are the requirements for network programming

TCP _Client_

1. `getaddrinfo()`
2. `socket()`
3. `connect()`
4. `send()` and `recv()`
5. `close()`

TCP _Server_

1. `getaddrinfo()`
2. `socket()`
3. `bind()`
4. `listen()`
5. `accept()`
6. `send()` and `recv()`
7. `close()`

UDP _Client_

1. `getaddrinfo()`
2. `socket()`
3. `sendto()` and `recvform()`
4. `close()`

UDP _Server_

1. `getaddrinfo()`
2. `socket()`
3. `bind()`
4. `sendto()` and `recvform()`
5. `close()`

`getaddrinfo(const char *restrict node, const char *restrict service, const struct addrinfo *restrict hints, struct addrinfo **restrict res)` 

`const char *restrict node`
- domain name (`google.com`)
- IPv4 or IPv6 address (`192.168.0.252`)
- Local system (`zero` or `NULL`)

`const char *restrict service`
- Port number (`8080`)
- Service name (`FTP`)

`const struct addrinfo *restrict hints`
- Address of an `struct addrinfo `
- Structure needs to be initialized to 0

`struct addrinfo **restrict res`
- Address of an `struct addrinfo` pointer
- Structure is filled with information about the connection

`struct addinfo`


Example Server:
```c

struct addrinfo hints,*server;  /*Hints specifies the type of socket information */
hints.ai_family = AF_INET;      /* IPv4 Protocol */
hints.ai_socktype = SOCK_STREAM;        /* Specifies TCP Protocol */
hints.ai_flags = 0;
hints.ai_protocol = 0;      /* Since we already mentioned TCP in sock_type it is redundant to specifiy TCP */

getaddrinfo("Hostname/IP","Port/Service",&hints,&server);
/* The *server is used for hold the results of the information */

/* Now a socket files descriptor needs to be opened. The information is now stored in the struct addrinfo *server*/
sock_fd = socket(server->ai_family,server->ai_socktype,server->ai_protocol);

/* Now its time to wrap the socket with the IP address and Port */
bind(sock_fd,server->ai_addr,server->ai_addrlen);

/* Now its time to listen to any incoming requestions with listen */
listen(sock_fd,1);  /* The 1 specifies how many connections that we can listen to */

/* Now its time to connect to the listen request by accepting it */
struct sockaddr client;
socklen_t client_len;
client_len = sizeof(client);
client_fd = accept(sock_fd,&client,&client_len);
/* Upon making a connect and accepting it. It creates a new socket for the server and client to send information back and forth using the send() and recv() APIs */

```

