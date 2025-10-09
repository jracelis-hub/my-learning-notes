# Concurrency Design

### Issues

Race conditions - A part of the code where the shared resources are being accesed
- Occurence: When two more procees try to acces the same resource at the same time without proper coordination

Mutex or Mutual Exclusion

Since a process has all the same allocated memory space and resources

Deadlock - when two or more processes are waiting for each otehr to release resources, and none can proceed.

Thread blocking - when a thread is unable to continue its work because its waiting fora resource that's currently unavailable

### Program

A set of instructions stored on `disk` that defines what can be done.

Think of it like a cookbook(`Operating System`) where each page(`disk`) is a different recipe(`program`) and each recipe has a set of instructions(`process`)

### Process

A process is the program execution of running the program

The process is the action of following the instruction of the specific recipe defined on the page(`disk`). This requires the ingredients(`stack`) and other resources to be able to run the process. The the person(`thread`) running the process is the thread.

All process has at least one thread of control but a process can also have more than one thread of control

A normal single process application is running the process as is without any specific libraries.

A way to support multi-processes in C is utilizing `fork()` and `exec()`

- `fork()` - duplicates the parent process creating a child process
- `exec()` - replaces its code with a new program

Example:
```c
#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();

	if ( pid == 0 ) printf("Hello from the child\n");
	else printf("Hello from the parent\n");

	return 0;
}

/* Output
$ ./a.out
Hello world
Hello world
*/
```

### Threads

Thread is the smallest unit of execution within the process. Threads share the same memory and resources of the process but have independent execution flows

Think of a thread as a person cooking. The person is following the recipe(`process`) but is preforming each small task(`thread`) to finish cooking the item.

Exmaple: 
1. cut onions, carrots, celery
2. heat up pan
3. oil pan and cook onions, carrots, and celery
4. add tomato sauce

The thread is the person doing each task... Step 1... Step 2. The person could only do it one at a time there for its a single thread.

But let's say you have another person where one person is cutting the onions and the other person is cutting the carrots. That would be two threads as each person is doing their own sub task within the process for efficiency.


### I/O Multiplexing

Event loop mechanism - waits for a specific event for it to prompt the other event to start 
