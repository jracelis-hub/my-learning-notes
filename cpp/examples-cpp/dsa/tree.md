# Tree

Tree is a sebset of graph

A collection of entities called nodes

None linear data structure

the top of the tree is called the root of the tree

```
         1
         O <--- root
	   /   \ <--- link (edge)
	2 O     O 3<--- node
	 /\      \
    /  \      \                   
   O    O      O 6 <--- leaf node
  4      5
```

- each arrow is a link (edge)
- every thing after a root is called a node
- 2 and 3 is a child of 1
- 1 is parent of 2 and 3
- `siblings` - child of same parent
- `leaf` - a node without a child 
- `grandparent` - 1 is grandparent of 4 
- `grandchild` - 4 is grandchild of 1
- `ancestor` the ability to go from one node to another
	- 1 and 2 is ancestor of 5
- `descendent` the reverse of a ancestor
	- 5 is descendent of 1 and 2
- `cousins` if they have the same grandparent
	- 5 and 6 are cousins

can only walk in one direction, they are not bidirectional

tree has n node and n - 1 edges

depth of node = length of path from root to node
	- number of edges in path from root to node

height of node = number of edges in longest path rfom x to leaf
	- height of tree is height of root node

Applications:

1. Storing naturally hierachical data
	- file system
2. Organize data
	- for quick search, insertion, deletion
3. Trie -> dictionary
4. Network routing algorithm

Binary tree - a tree in which each node can have at most 2 children

Complete Binary Tree all levels except possibly the last are completley filled and all nodes are as left as possible

Perfect Binary Tree maximum number of nodes in a binary tree with height h

Balance Binary Tree difference between height of left and right subtree for every node is not more than k mostly 1
- Height of an empty tree = -1
- Height of a tree with 1 node = 0
- Height is based on edges

diff = | hleft - hright |

max number of nodes at level i = 2<sup>i</sup>

Implementation:
1. dynamically
2. array

Binary Serach Tree

a binary tree in which each node, value of all the nodes in left subtree is lesser and value of all the nodes in the right subtree is greater
- has to be all nodes that are bst

array 
- search(x) O(n)
- insert(x) O(1) assuming that there is enough space
- remove(x) O(n)

Linked list
- search(x) O(n)
- insert(x) O(1) at the head and at the tail O(n)
- remove(x) O(n)

binary search in a sorted array in O(logn)

Binary Search Tree (Balanced)
- search(x) O(logn)
- insert(x) O(logn) 
- remove(x) O(logn)
