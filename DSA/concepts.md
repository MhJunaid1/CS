# Data Structures

## Primitive vs Non-Primitive Data Structures

### Primitive Data Structures
Primitive data structures are basic data structures that are directly operated by machine instructions. Examples include:
- Integers
- Floats
- Characters
- Pointers

### Abstract Data Structures (Non-Primitive)
Abstract data structures are derived data structures built on top of primitive data structures. Examples include:
- Arrays
- Stacks
- Queues
- Linked Lists
- Trees
- Graphs
- Hash Tables
- Heaps

## Linear vs Non-Linear Data Structures

### Linear Data Structures
Linear data structures have elements arranged in a sequential order where each element has a unique predecessor and successor, except for the first and last elements. Examples include:
- Arrays
- Linked Lists
- Stacks
- Queues

### Non-Linear Data Structures
Non-linear data structures have elements that are not arranged sequentially. Each element may have one or more direct successors or predecessors. Examples include:
- Trees
- Graphs
- Heaps

## Associative Arrays
Associative arrays, also known as maps, dictionaries, or hash tables, store key-value pairs. Unlike arrays indexed using integers, associative arrays use keys to access values, enabling quick search, insertion, and deletion operations.

Common operations:
- Inserting a key-value pair
- Retrieving the value associated with a given key
- Removing a key-value pair
- Checking if a key is present
- Iterating over all key-value pairs

## Stacks
A stack is an abstract data type that follows the Last-In-First-Out (LIFO) principle. The last element inserted is the first to be removed. Main operations include:
- `push`: Adds an element to the top of the stack
- `pop`: Removes the element from the top of the stack
- `peek`: Returns the top element without removing it

## Queues
A queue is a linear data structure following the First-In-First-Out (FIFO) principle. The first element added is the first to be removed. Main operations include:
- `enqueue`: Adds an element to the back of the queue
- `dequeue`: Removes the element from the front of the queue
- `peek`/`front`: Returns the front element without removing it
- `isEmpty`: Checks if the queue is empty

## Linked Lists
A linked list is a linear data structure with a sequence of nodes, each containing data and a reference to the next node. Unlike arrays, linked lists do not have a fixed size. Main operations include:
- Insertion: Adding a new node at the beginning, end, or any position
- Deletion: Removing a node from the beginning, end, or any position
- Traversal: Accessing each node in order
- Searching: Finding a specific node based on criteria
- Sorting: Arranging nodes in a specific order

## Trees
A tree is a non-linear data structure with nodes, each having a parent (except the root) and zero or more children. Trees represent hierarchical relationships. Common types include:

### Binary Tree
A binary tree allows each node to have at most two children (left and right).

### Binary Search Tree (BST)
A BST is a binary tree where the left child's value is smaller, and the right child's value is greater than the node's value.

### AVL Tree
An AVL tree is a self-balancing BST with balanced left and right subtrees to ensure operations remain efficient.

### Heap
A heap is a binary tree where each node's value is greater than (max heap) or less than (min heap) its children's values.

## Hash Tables
A hash table stores data in an associative array format, using a hash function to map keys to indices in an array. It allows efficient data retrieval, insertion, and deletion.

### Key Features:
- **Hash function**: Maps keys to array indices
- **Collision resolution**: Manages conflicts when multiple keys map to the same index
- **Load factor**: Ratio of stored elements to table slots
- **Rehashing**: Creates a new table and reinserts elements when the load factor is too high
- **Dynamic resizing**: Adjusts table size for performance optimization

### Usage of Hash Tables:
- **Database indexing**: Creates indexes for faster data retrieval
- **Caching**: Stores frequently accessed data for quick access
- **Symbol tables**: Stores variables and values in programming languages
- **Algorithms**: Used in finding duplicates, counting occurrences, grouping items
- **Password storage**: Securely stores hashed passwords

In summary, hash tables are a powerful and widely used data structure in computer programming, offering efficient retrieval, insertion, and deletion of data, with applications in database indexing, caching, symbol tables, and various algorithms.