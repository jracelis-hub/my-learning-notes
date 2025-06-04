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







