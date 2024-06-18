# Queue

**Definition**:
A **queue** is a linear data structure that operates on the **First-In-First-Out (FIFO)** principle. The first element added to the queue is the first one to be removed, akin to people waiting in line: the first person to join is the first to leave.

## Usefulness in Data Structures

- **Task Scheduling**: Managing tasks in order of arrival, such as print jobs or CPU processes.
- **Buffering**: Handling streaming data or asynchronous data transfers smoothly.
- **Breadth-First Search (BFS)**: Exploring nodes level by level in graphs and trees.
- **Resource Management**: Ensuring orderly access to shared resources like CPU or network bandwidth.

### Queue Abstract Data Type (ADT)

A queue ADT defines the following operations:

- **Enqueue (Insert)**: Add an element to the rear.
- **Dequeue (Remove)**: Remove and return the front element.
- **Peek (Front)**: View the front element without removing it.
- **IsEmpty**: Check if the queue is empty.
- **IsFull**: Check if the queue is full (for fixed-size implementations).

**Example**:
A printer queue where documents are printed in the order they were sent. The first document sent is the first to be printed.

### Types of Queues

1. **Simple Queue**

   **Definition**: A basic queue where elements are added at the rear and removed from the front. It's a straightforward linear structure without wrapping around.

   **Uses**: Task scheduling, buffering.

   **Example**: A line of customers at a ticket counter.

2. **Circular Queue**

   **Definition**: A queue where the last position is connected back to the first position, forming a circle. This allows the queue to efficiently use space by reusing slots once they are free.

   **Uses**: Circular buffers in streaming applications.

   **Example**: Fixed-size buffer for audio streaming data.

3. **Priority Queue**

   **Definition**: A queue where each element has a priority, and elements are dequeued based on their priority rather than their order in the queue.

   **Uses**: Task scheduling with priorities, Dijkstra's algorithm.

   **Example**: Handling tasks in an operating system with different priorities.

4. **Double-Ended Queue (Deque)**

   **Definition**: A queue in which elements can be added or removed from both the front and the rear.

   **Uses**: Palindrome checking, sliding window algorithms.

   **Example**: Managing sliding window values for maximum or minimum calculations.

### Implementing Queues

Queues can be implemented in several ways:

1. **Array-Based Implementation**

   **Definition**: Uses an array to store elements. It typically involves two indices to track the front and rear of the queue.

   **Pros**: Simple and straightforward to implement.

   **Cons**: Fixed size; requires shifting elements for `dequeue` if implemented simply without circular logic.

   **Example**:
   - Enqueue: Add elements to the end of the array.
   - Dequeue: Remove elements from the beginning.

2. **Linked List-Based Implementation**

   **Definition**: Uses a linked list where each node points to the next element in the queue. The `front` points to the head of the list, and the `rear` points to the tail.

   **Pros**: Dynamic size, no need to shift elements.

   **Cons**: Requires extra memory for pointers; may be slightly slower due to pointer operations.

   **Example**:
   - Enqueue: Add a new node at the end.
   - Dequeue: Remove the node from the front.

### Summary

Queues are a versatile and fundamental data structure crucial for orderly data processing in computing. They can be implemented using arrays for simple, fixed-size solutions or linked lists for more dynamic and flexible applications. Their FIFO nature makes them suitable for various scenarios, including task scheduling, buffering, and graph traversal.
