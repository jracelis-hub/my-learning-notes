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
- The algorithm should product a results
- The algorithm should complete in a finite of time

To evaluation an algorithm the:
- Correctness
- Efficency
```
+-------+    +---------+    +--------+
| input | -> | problem | -> | output |
+-------+    +---------+    +--------+
```

Correctness:
- An algorithm is deemed correct if all possible inputs give the expected output
- For every possible input the algorithm MUST always terminate

Efficency:
- Time complexity measure of how long the algorithm runs
- Space complexity the amount of memory that is taken up in the computer

Linear search - checks each value sequentially
- Does not need to be sorted 
- Input = list of values
- Output = target value

Binary Search - compares value in the middle to 
- Has to be sorted 
- Input sorted list of values
- Output position of the list of the target value we searching for

Big O Notation - theoretical definition of the complexity of an algorithm as a function of the size

O(n) - represents bounds of worst case scenario
- O - ordor of magnitute of complexity
- n - a function of the size (all posibilities)

<table>
	<thead align="center">
		<tr>
			<th>Algorithm</th>
			<th>Time Complexity</th>
		<tr>
	</thead>
	<tbody align="center">
		<tr>
			<td>Linear Search</th>
			<td>O(n)</th>
		<tr>
		<tr>
			<td>Binary Search</th>
			<td>O(log n)</th>
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

## Data Structures
