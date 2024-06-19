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

```cpp
#include <stdio.h>
#include <stdlib.h>

// Define the Queue structure
struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

// Function to create and initialize the queue
void create(struct Queue *q) {
    printf("Enter the size of the array: ");
    scanf("%d", &q->size);
    
    q->Q = (int *)malloc(q->size * sizeof(int));
    if (q->Q == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    q->front = q->rear = -1;
}

// Function to add an element to the queue
void enqueue(struct Queue *q, int data) {
    if (q->rear == q->size - 1)
        printf("Queue is full\n");
    else {
        q->rear++;
        q->Q[q->rear] = data;
    }
}

// Function to remove an element from the queue
int dequeue(struct Queue *q) {
    int x = -1;
    if (q->rear == q->front)
        printf("Queue is empty\n");
    else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

// Function to display the queue elements
void display(struct Queue q) {
    printf("The elements in the queue are: ");
    for (int i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}

int main() {
    struct Queue q;
    create(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    display(q);

    printf("The deleted value: %d\n", dequeue(&q));

    display(q);

    free(q.Q);  // Free allocated memory

    return 0;
}
```

## Queue in CPP

```cpp
#include <iostream>
#include <cstdlib> // For std::exit

class Queue {
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    // Constructor to initialize queue
    Queue(int sz) {
        size = sz;
        front = rear = -1;
        Q = new int[size];
    }

    // Destructor to free allocated memory
    ~Queue() {
        delete[] Q;
    }

    // Function to add an element to the queue
    void enqueue(int data) {
        if (rear == size - 1) {
            std::cout << "Queue is full\n";
        } else {
            rear++;
            Q[rear] = data;
        }
    }

    // Function to remove an element from the queue
    int dequeue() {
        int x = -1;
        if (rear == front) {
            std::cout << "Queue is empty\n";
        } else {
            front++;
            x = Q[front];
        }
        return x;
    }

    // Function to display queue elements
    void display() {
        std::cout << "The elements in the queue are: ";
        for (int i = front + 1; i <= rear; i++) {
            std::cout << Q[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int size;
    std::cout << "Enter the size of the queue: ";
    std::cin >> size;

    Queue q(size);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    std::cout << "The deleted value: " << q.dequeue() << std::endl;

    q.display();

    return 0;
}

```

### Drawbacks of Queue Implementations

Queues can be implemented using various methods such as simple arrays, circular arrays, and linked lists. Each method has its own drawbacks:

#### 1. **Queue Using Simple Array**

**Definition**:
A simple array-based queue uses a fixed-size array to store elements. `Enqueue` adds elements at the rear, and `Dequeue` removes them from the front.

**Drawbacks**:

- **Fixed Size**: The size of the queue is fixed once created. This limits the queue's capacity and makes it challenging to handle more elements than initially expected without resizing the array, which is complex and time-consuming.

- **Wasted Space**: As elements are dequeued, the front index moves forward, leaving unused space at the beginning of the array. This space cannot be reused unless the entire array is compacted, which is inefficient.

- **Overflow/Underflow**: Managing the conditions for checking if the queue is full or empty can be problematic, and errors can occur if these conditions are not handled properly.

**Diagram**:
```
Enqueue at rear      Dequeue from front
   |                        |
   v                        v
[ ] [ ] [ ] [ ] [ ]    [X] [X] [ ] [ ] [ ]
```

**Example**:
If the queue size is 5, and 3 elements are dequeued, the remaining elements are at the rear, causing unused slots at the front that cannot be reused.

#### 2. **Queue Using Circular Array**

**Definition**:
A circular array-based queue connects the end of the array back to the beginning, forming a circle. This allows for efficient utilization of space.

**Drawbacks**:

- **Complex Indexing**: Managing the circular nature of the queue requires careful handling of the `front` and `rear` pointers. The wrap-around logic can be tricky and prone to errors, especially when the queue is nearly full or empty.

- **Fixed Size**: The size is still fixed, and if the queue needs to grow, resizing a circular array is more complex than resizing a simple array.

- **Memory Overhead**: Additional logic is needed to distinguish between a full and empty queue since both conditions can appear similar (e.g., `front == rear`).

**Diagram**:

```c
Enqueue/Dequeue operations
  front               rear
    |                  |
    v                  v
[ ] [ ] [X] [X] [ ] -> [X] [ ] [X] [ ] [ ]
  ^                          ^
  |                          |
 wrap around logic       wrap around logic
```

**Example**:
If elements are enqueued until the array wraps around, and then dequeued, the `front` and `rear` pointers must be managed to ensure correct indexing within the array bounds.

#### 3. **Queue Using Linked List**

**Definition**:
A linked list-based queue uses nodes where each node points to the next. This allows for dynamic resizing.

**Drawbacks**:

- **Memory Overhead**: Each element requires extra memory for the node pointer, increasing the memory usage compared to array-based implementations.

- **Complexity**: Managing pointers increases the complexity of the operations, including potential issues with memory leaks or dangling pointers if not handled properly.

- **Access Time**: Linked list queues have higher access time for operations compared to arrays due to the overhead of pointer dereferencing.

**Diagram**:

```c
Enqueue/Dequeue operations
  front              rear
    |                 |
    v                 v
[ ] -> [ ] -> [ ] -> [ ] -> [ ]
```

**Example**:
Memory for each node must be dynamically allocated and freed, which can be more error-prone and slower than managing a simple or circular array.

### Summary of Drawbacks

| Implementation          | Drawbacks                                                                                               |
|-------------------------|---------------------------------------------------------------------------------------------------------|
| **Simple Array**        | Fixed size, wasted space after dequeues, overflow/underflow management                                  |
| **Circular Array**      | Complex indexing, fixed size, tricky memory management for full/empty conditions                        |
| **Linked List**         | Memory overhead for pointers, increased complexity, slower access times                                 |

Each implementation has trade-offs, and the choice depends on the specific requirements and constraints of the application, such as memory usage, performance needs, and ease of implementation.
