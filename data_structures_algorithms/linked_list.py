#!/usr/bin/env python3

# data to hold the data inside the node 
# next_node to pointer to the next node
class Node:
	"""
	An object for storing a single node of a linked list.
	Models two attributes - data and the link to the next node in the list
	"""
	data = None
	next_node = None

	def __init__(self, data):
		self.data = data

	def __repr__(self):
		return "<Node data: %s>" % self.data

class LinkedList:
	"""
	Single linked list
	"""

	def __init__(self):
		self.head = None
	
	def is_empty(self):
		return self.head == None
	
	def size(self):
		"""
		Returns the number of nodes in the list
		Takes 0(n) times
		"""
		current = self.head
		count = 0
		while current != None:
			count += 1
			current = current.next_node
		return count
	
	def add(self, data):
		"""
		Adds a new Node containing data at the head of the list
		Takes O(1) time
		"""
		new_node = Node(data)
		new_node.next_node = self.head
		self.head = new_node
	
	def __repr__(self):
		nodes = []
		current = self.head

		while current:
			if current is self.head:
				nodes.append("[Head: %s]" % current.data)
			elif current.next_node is None:
				nodes.append("[Tail: %s]" % current.data)
			else:
				nodes.append("[%s]" % current.data)

			current = current.next_node
		return '-> '.join(nodes)
