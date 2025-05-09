<div align="center">
<h1 align="center">Networking Notes</h1>

<p align="center">
<img src="https://github.com/jracelis-hub/my-learning-notes/blob/main/images/osi_tcp_ip.png">
</p>

</div>

## Introduction To Networking

### ***Introduction***

Networking the most important process when it comes to communication. It is the process of connecting two or more computers to share resources, information, and communication.


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








