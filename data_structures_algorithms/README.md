## Algorithm

What is an algorithm?

An algorithm is a set of instructions to finish a task.

Algorithm has a clear problem statement.

These are main questions that should be asked when performing an algorithm:
- What is the problem statement?
- What is the input? 
- What is the output?

Requirements:
- The steps of the algorithm need to be in a specific order
- The steps also need to be distinct
- The algorithm should produce a results
- The algorithm should complete in a finite amount of time

To evaluation an algorithm it considers two things:
- Correctness
- Efficency
```
+-------+    +---------+    +--------+
| input | -> | problem | -> | output |
+-------+    +---------+    +--------+
```

Correctness:
- An algorithm is deemed correct if all possible inputs give the expected output
- For every possible input the algorithm ***MUST*** have an output

Efficency:
- Time complexity measures how long the algorithm runs
- Space complexity measure the amount of memory that is taken up in the computer

Linear search - checks each value sequentially
- Does not need to be sorted 
- Input = list of values
- Output = target value

Binary Search - compares value in the middle to 
- Has to be sorted 
- Input sorted list of values
- Output position of the list of the target value we searching for

### Big O Notation

Big O Notation - theoretical definition of the complexity of an algorithm as a function of the size

O(n) - represents bounds of worst case scenario
- O - ordor of magnitute of complexity
- n - a function of the size (all posibilities)

<table>
	<thead align="center">
		<tr>
			<th>Algorithm</th>
			<th>Time Complexity</th>
			<th>Space Complexity</th>
		<tr>
	</thead>
	<tbody align="center">
		<tr>
			<td>Linear Search</th>
			<td>O(n)</th>
			<td>O(1)</th>
		<tr>
		<tr>
			<td>Binary Search</th>
			<td>O(log n)</th>
			<td>O(1)</th>
		<tr>
	</tbody>
</table>

### Runtime of an algorithm

<details>
<summary>Exponents, Logs, Factorial</summary>
Exponents

2<sup>3</sup> = 8

base<sup>exponent</sup> = result

Logs

log<sub>2</sub>8 = 3

log<sub>base</sub>result = exponent

Factorial

> Until a reaches a value of 1

4! = 4 x 3 x 2 x 1 = 24

n! = n(n - 1)(n - 2)...(2)(1)

---
</details>

Runtime per operations vs n

Constant Time - O(1)

Linear Time - O(n)

Logarithmic (Sublinear) Time - O(log n)

Quasilinear Time - O(nlogn)

Quadratic Time - O(n<sup>2</sup>)

Cubic Time - O(n<sup>3</sup>)

Exponential Time - O(x<sup>n</sup>)

Factorial / Combinatoria Runtime

> [!NOTE]
> The evaluation of an algorithm should be always compared to the ***worst case scenario***

Recursion is the method of calling itself to get the desired output
- Recursion always as a base case that it evaluates itself to know a stopping point
	- if not recursion will never end
It is important to have two base cases and an ending condition for each case
1. Base case 1: the stopping point in which the input does not exist 
2. Base case 2: the stoppoing point in which the input does exist

The number times recursion calls itself is called ***Recursive Depth***

Iterative solution
- loop structure of some kind

Recursive solution 
- a set of stopping conditions and a function that calls itself

Recursion is used a lot as it does not change the original data that was given

Space Complexity - a measure of working storage or extra storage grows

Iterative Solution - O(1) constant time

Recursive Solution - O(logn) logarithmic time

> [!NOTE]
> logarithmic time varies per programming language

## Data Structures

Data structure - a data storage format. it is the collection of values and the format 
they are stored in, the relationships between the values in the collection as well as 
the operations applied on the data stored in the structure

### Types of Data Structures

Operations on Data Structures
- Access and read values
- Search for an arbitary value
- Insert values at any point into the structure
- Delete values in the structure

Insert Operation - Linear Time (has to loop through each value)

Appending Operation - Constant Time 

Delete Operation - Linear Time

Array - is a collection of values reference by an index or a key
- order sequentially
- continguous data structure (stored in blocks of memory next to each other)
- homogeneous containers (storage the same data type) ex. `int` (java, C)
- heterogeneous containers (storage any data type) ex. python

```py
array = [1, 3, 4, 5]
index =  0  1  2  3
```
Linked List - linear data structure that is contained in a object called a node
- holds information of the data
- holds reference (memory/pointer) to the next data
- first node in a linked list is the head
- last node in a linked list is the tail

```
linked list = *head -> *node -> *node -> *tail -> NULL
```

Node is a self referential object

Two Types of Linked List:
1. Singly Linked List
	- Only holds data of the reference next node
```
*head -> *node -> *node -> *node -> *tail
```
2. Doubly Node
	- Holds data of the reference next node and node before
```
*head <-> *node <-> *node <-> *node <-> *tail
```
Operations Linked List:

Prepend - adding to the head

Append - adding to the tail

Insert - adding any any point of the linked list
