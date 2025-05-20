# Network Programming in C

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
> 192.168.0.0/16
> fe80::8cc1%9
	* Is not a part of network programming
	* Directs local and network packets

Looback Address
	* Used for testing
	* Consistent on all network devices
	* The IPv4: 127.0.0.1
	* The IPv6: ::1
	* Represents the local computer

Address Have Ports
	* A communication endpoint
	* Tied with service or resource
	* To communicate wover a network, you must know both the address and the port

Port Numbers
	* 16 bits wide
	* 65,536 possible ports

Reserved Ports
	* Ports 1 - 1023 are system ports
	* 1024 - 49151 are registered ports
	* Ports 49152 - 65535 are gynamic, private, or ephemeral (on the fly ports)

To see the list of service ports
	* `cd /etc; less services`
	* `cat /etc/host`

Use terminal command:
	* `ip addr show`
