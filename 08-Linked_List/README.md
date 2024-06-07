# Linked List

A **linked list** is a linear data structure in which elements, called nodes, are stored in a sequence. Each node contains two parts:

1. **Data**: The value or information of the node.
2. **Pointer**: A reference or link to the next node in the sequence.

The last node's pointer is typically `NULL`, indicating the end of the list. Linked lists come in various types:

- **Singly Linked List**: Each node points to the next node.
- **Doubly Linked List**: Each node points to both the next and the previous node.
- **Circular Linked List**: The last node points back to the first node, forming a circle.

## Structure of a Node in C

```c
struct Node {
    int data;
    struct Node* next; // this is known as self-referential structure
};
```

### Basic Operations

1. **Insertion**: Adding a node at the beginning, end, or middle of the list.
2. **Deletion**: Removing a node from the list.
3. **Traversal**: Accessing each node in the list sequentially.

### Problems with Arrays

1. **Fixed Size**: Arrays have a fixed size, defined at creation time, which limits their flexibility. You cannot resize an array without creating a new one and copying elements.
2. **Memory Waste**: If the array is not fully utilized, there can be wasted memory.
3. **Costly Insertion and Deletion**: Inserting or deleting elements in an array involves shifting elements, which is costly in terms of time complexity (`O(n)` for worst-case scenarios).
4. **Contiguous Memory**: Arrays require a contiguous block of

### Simple Statements

- **Linear Search (ls)** works on linked lists because it processes elements sequentially, matching the structure of linked lists which allows traversal from one node to the next.

- **Binary Search (bs)** doesn’t work on linked lists because it relies on quick random access to the middle elements, which linked lists cannot provide efficiently due to their sequential access nature.

```cpp


```
