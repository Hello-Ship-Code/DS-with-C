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

## circular Queue

```cpp
#include <iostream>
#include <cstdlib> // For std::exit

class CircularQueue {
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    // Constructor to initialize queue
    CircularQueue(int sz) {
        size = sz;
        front = rear = 0; // Initialize front and rear to 0
        Q = new int[size];
    }

    // Destructor to free allocated memory
    ~CircularQueue() {
        delete[] Q;
    }

    // Function to add an element to the queue
    void enqueue(int data) {
        if ((rear + 1) % size == front) {
            std::cout << "Queue is full\n";
        } else {
            rear = (rear + 1) % size; // Move rear to the next position
            Q[rear] = data;
        }
    }

    // Function to remove an element from the queue
    int dequeue() {
        int x = -1;
        if (rear == front) {
            std::cout << "Queue is empty\n";
        } else {
            front = (front + 1) % size; // Move front to the next position
            x = Q[front];
        }
        return x;
    }

    // Function to display queue elements
    void display() {
        if (rear == front) {
            std::cout << "Queue is empty\n";
            return;
        }

        std::cout << "The elements in the queue are: ";
        int i = (front + 1) % size;
        while (i != (rear + 1) % size) {
            std::cout << Q[i] << " ";
            i = (i + 1) % size; // Move to the next position
        }
        std::cout << std::endl;
    }
};

int main() {
    int size;
    std::cout << "Enter the size of the queue: ";
    std::cin >> size;

    CircularQueue q(size + 1); // Add one extra space to differentiate full and empty

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

## Queues using Linked List

```cpp

#include <iostream>

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Queue class using linked list
class LinkedListQueue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor to initialize an empty queue
    LinkedListQueue() : front(nullptr), rear(nullptr) {}

    // Destructor to free all nodes in the queue
    ~LinkedListQueue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Function to add an element to the queue
    void enqueue(int data) {
        Node* newNode = new Node{data, nullptr};
        if (rear == nullptr) {
            // If queue is empty, both front and rear will point to the new node
            front = rear = newNode;
        } else {
            // Attach the new node at the end of the queue and move rear to the new node
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to remove an element from the queue
    int dequeue() {
        if (front == nullptr) {
            std::cerr << "Queue is empty\n";
            return -1; // Return a sentinel value indicating empty queue
        }
        int data = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            // If the queue becomes empty, set rear to nullptr as well
            rear = nullptr;
        }
        delete temp;
        return data;
    }

    // Function to display the queue elements
    void display() const {
        if (front == nullptr) {
            std::cout << "Queue is empty\n";
            return;
        }
        std::cout << "The elements in the queue are: ";
        Node* temp = front;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedListQueue q;

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

### Dequeue (Double-Ended Queue)

**Definition**:
A **Dequeue** (also known as **Deque**) stands for **Double-Ended Queue**. It is a generalized version of a queue data structure that allows elements to be added or removed from both the **front** and the **rear** ends. Unlike a simple queue, which follows the **First-In-First-Out (FIFO)** principle, a dequeue does not restrict the end from which data can be enqueued or dequeued.

### Characteristics of a Dequeue

- **Bidirectional Operations**: Supports insertion and deletion operations at both ends.
- **Flexible**: Can function as both a stack (LIFO) and a queue (FIFO).
- **Dynamic Size**: Like a queue, it can grow and shrink dynamically depending on the implementation (linked list or dynamically resized array).

### Types of Dequeues

1. **Input-Restricted Dequeue**:
   - Insertion is allowed only at one end (either front or rear).
   - Deletion is allowed at both ends.

2. **Output-Restricted Dequeue**:
   - Deletion is allowed only at one end.
   - Insertion is allowed at both ends.

### Applications of Dequeue

- **Palindrome Checking**: Efficiently used to check whether a string is a palindrome by comparing elements from both ends.
- **Sliding Window Problems**: Used in algorithms that require maintaining a window of elements, such as finding the maximum or minimum in a sliding window.
- **Task Scheduling**: Helps in managing tasks where insertion and removal from both ends are required.
- **Undo Operations**: Useful in applications like text editors for maintaining a history of actions to support undo/redo operations.

### Diagrammatic Representation

**Typical Dequeue Operations**:

```c
Front <- [Element1] <-> [Element2] <-> [Element3] <-> [Element4] -> Rear
```

- **Insert at Front**: Adds an element at the front.
- **Remove from Front**: Removes an element from the front.
- **Insert at Rear**: Adds an element at the rear.
- **Remove from Rear**: Removes an element from the rear.

### Example in C++

Here's how a dequeue can be implemented using a doubly linked list:

```cpp
#include <iostream>

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Dequeue class using doubly linked list
class Dequeue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor to initialize an empty dequeue
    Dequeue() : front(nullptr), rear(nullptr) {}

    // Destructor to free all nodes in the dequeue
    ~Dequeue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Function to insert an element at the front
    void insertFront(int data) {
        Node* newNode = new Node{data, nullptr, front};
        if (front == nullptr) {
            rear = newNode;
        } else {
            front->prev = newNode;
        }
        front = newNode;
    }

    // Function to insert an element at the rear
    void insertRear(int data) {
        Node* newNode = new Node{data, rear, nullptr};
        if (rear == nullptr) {
            front = newNode;
        } else {
            rear->next = newNode;
        }
        rear = newNode;
    }

    // Function to remove an element from the front
    int deleteFront() {
        if (front == nullptr) {
            std::cerr << "Dequeue is empty\n";
            return -1; // Sentinel value indicating empty dequeue
        }
        int data = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        } else {
            front->prev = nullptr;
        }
        delete temp;
        return data;
    }

    // Function to remove an element from the rear
    int deleteRear() {
        if (rear == nullptr) {
            std::cerr << "Dequeue is empty\n";
            return -1; // Sentinel value indicating empty dequeue
        }
        int data = rear->data;
        Node* temp = rear;
        rear = rear->prev;
        if (rear == nullptr) {
            front = nullptr;
        } else {
            rear->next = nullptr;
        }
        delete temp;
        return data;
    }

    // Function to display dequeue elements from front to rear
    void display() const {
        if (front == nullptr) {
            std::cout << "Dequeue is empty\n";
            return;
        }
        Node* temp = front;
        std::cout << "The elements in the dequeue are: ";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Dequeue dq;

    dq.insertRear(1);
    dq.insertRear(2);
    dq.insertFront(0);
    dq.insertFront(-1);

    dq.display();

    std::cout << "Deleted from front: " << dq.deleteFront() << std::endl;
    std::cout << "Deleted from rear: " << dq.deleteRear() << std::endl;

    dq.display();

    return 0;
}
```

### Example in C

Here's how a dequeue can be implemented using a doubly linked list in C:

```c
#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Dequeue structure using doubly linked list
struct Dequeue {
    struct Node* front;
    struct Node* rear;
};

// Function to create and initialize an empty dequeue
struct Dequeue* createDequeue() {
    struct Dequeue* dq = (struct Dequeue*)malloc(sizeof(struct Dequeue));
    if (dq == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    dq->front = dq->rear = NULL;
    return dq;
}

// Function to insert an element at the front
void insertFront(struct Dequeue* dq, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = dq->front;
    if (dq->front == NULL) {
        dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
    }
    dq->front = newNode;
}

// Function to insert an element at the rear
void insertRear(struct Dequeue* dq, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = dq->rear;
    if (dq->rear == NULL) {
        dq->front = newNode;
    } else {
        dq->rear->next = newNode;
    }
    dq->rear = newNode;
}

// Function to remove an element from the front
int deleteFront(struct Dequeue* dq) {
    if (dq->front == NULL) {
        printf("Dequeue is empty\n");
        return -1; // Sentinel value indicating empty dequeue
    }
    int data = dq->front->data;
    struct Node* temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front == NULL) {
        dq->rear = NULL;
    } else {
        dq->front->prev = NULL;
    }
    free(temp);
    return data;
}

// Function to remove an element from the rear
int deleteRear(struct Dequeue* dq) {
    if (dq->rear == NULL) {
        printf("Dequeue is empty\n");
        return -1; // Sentinel value indicating empty dequeue
    }
    int data = dq->rear->data;
    struct Node* temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear == NULL) {
        dq->front = NULL;
    } else {
        dq->rear->next = NULL;
    }
    free(temp);
    return data;
}

// Function to display dequeue elements from front to rear
void display(struct Dequeue* dq) {
    if (dq->front == NULL) {
        printf("Dequeue is empty\n");
        return;
    }
    struct Node* temp = dq->front;
    printf("The elements in the dequeue are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the dequeue
void freeDequeue(struct Dequeue* dq) {
    struct Node* temp = dq->front;
    while (temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(dq);
}

// Main function to demonstrate dequeue operations
int main() {
    struct Dequeue* dq = createDequeue();

    insertRear(dq, 1);
    insertRear(dq, 2);
    insertFront(dq, 0);
    insertFront(dq, -1);

    display(d

q);

    printf("Deleted from front: %d\n", deleteFront(dq));
    printf("Deleted from rear: %d\n", deleteRear(dq));

    display(dq);

    freeDequeue(dq);

    return 0;
}
```

## Summary

A dequeue is a versatile data structure that supports insertion and deletion at both ends. It provides flexibility and is useful in a variety of applications where bidirectional operations are required.

## Priority Queue

**Definition**:
A **priority queue** is an abstract data structure similar to a regular queue or stack, but where each element is associated with a priority. In a priority queue, elements are removed based on their priority rather than their order of insertion. The element with the highest priority is served before elements with lower priority, regardless of the order in which they were added to the queue.

### Characteristics of Priority Queue

- **Priority-Based Removal**: Elements with higher priority are dequeued before elements with lower priority.
- **Dynamic Order**: Unlike a standard FIFO queue, the order of elements is dynamically determined by their priorities.
- **Customizable Priority**: Priorities can be determined by any criteria, making the data structure very flexible.

### Types of Priority Queues

1. **Max-Priority Queue**:
   - The element with the highest priority (or the largest value) is dequeued first.

   **Example**: A job scheduling system where more critical tasks are processed before less critical ones.

2. **Min-Priority Queue**:
   - The element with the lowest priority (or the smallest value) is dequeued first.

   **Example**: Dijkstra's algorithm, where nodes with the smallest distance are processed first.

### Applications of Priority Queue

- **Task Scheduling**: In operating systems, more critical tasks (e.g., system processes) are given higher priority over less critical ones (e.g., user processes).
- **Graph Algorithms**: Used in algorithms like Dijkstra's shortest path algorithm and Prim's minimum spanning tree algorithm.
- **Event Simulation**: Managing events that need to be processed in a particular order of importance.
- **Data Compression**: Used in Huffman coding for prioritizing the smallest frequencies.

### Example Implementations

#### Using a Sorted List or Array

- **Insertion**: Add the element in a sorted position based on priority.
- **Deletion**: Remove the element from the beginning (highest priority for max-priority queue).

#### Using a Binary Heap

- **Insertion**: Add the element to the end of the heap and adjust (heapify up).
- **Deletion**: Remove the root element (highest priority), replace it with the last element, and adjust (heapify down).

## Diagrammatic Representations

For a **Max-Priority Queue**:

```c
Enqueue (Insertion)
   Priority Queue:
      [8] [7] [5] [3] [1]
      ^        ^
      highest priority

Dequeue (Removal)
   Priority Queue after dequeue:
      [7] [5] [3] [1]
      ^     
      highest priority
```

### Example Code in C++

Here’s a basic implementation of a priority queue using a binary heap in C++:

```cpp
#include <iostream>
#include <vector>
#include <stdexcept>

class MaxPriorityQueue {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] <= heap[parent]) break;
            std::swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }
            if (largest == index) break;

            std::swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    void insert(int data) {
        heap.push_back(data);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) throw std::runtime_error("Priority queue is empty");
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return max;
    }

    bool isEmpty() const {
        return heap.empty();
    }

    void display() const {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxPriorityQueue pq;

    pq.insert(3);
    pq.insert(5);
    pq.insert(7);
    pq.insert(8);
    pq.insert(1);

    pq.display();

    std::cout << "Extracted max: " << pq.extractMax() << std::endl;

    pq.display();

    return 0;
}
```

### Example Code in C

Here’s a basic implementation of a priority queue using a binary heap in C:

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

struct PriorityQueue {
    int heap[MAX_HEAP_SIZE];
    int size;
};

// Function prototypes
void insert(struct PriorityQueue* pq, int data);
int extractMax(struct PriorityQueue* pq);
void heapifyUp(struct PriorityQueue* pq, int index);
void heapifyDown(struct PriorityQueue* pq, int index);
void display(struct PriorityQueue* pq);

int main() {
    struct PriorityQueue pq = { .size = 0 };

    insert(&pq, 3);
    insert(&pq, 5);
    insert(&pq, 7);
    insert(&pq, 8);
    insert(&pq, 1);

    display(&pq);

    printf("Extracted max: %d\n", extractMax(&pq));

    display(&pq);

    return 0;
}

void insert(struct PriorityQueue* pq, int data) {
    if (pq->size == MAX_HEAP_SIZE) {
        printf("Priority queue is full\n");
        return;
    }
    pq->heap[pq->size] = data;
    heapifyUp(pq, pq->size);
    pq->size++;
}

int extractMax(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority queue is empty\n");
        return -1;
    }
    int max = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    heapifyDown(pq, 0);
    return max;
}

void heapifyUp(struct PriorityQueue* pq, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (pq->heap[index] <= pq->heap[parent]) break;
        int temp = pq->heap[index];
        pq->heap[index] = pq->heap[parent];
        pq->heap[parent] = temp;
        index = parent;
    }
}

void heapifyDown(struct PriorityQueue* pq, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < pq->size && pq->heap[left] > pq->heap[largest]) {
            largest = left;
        }
        if (right < pq->size && pq->heap[right] > pq->heap[largest]) {
            largest = right;
        }
        if (largest == index) break;

        int temp = pq->heap[index];
        pq->heap[index] = pq->heap[largest];
        pq->heap[largest] = temp;
        index = largest;
    }
}

void display(struct PriorityQueue* pq) {
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->heap[i]);
    }
    printf("\n");
}
```

## Summary

- **Priority Queue**: A data structure where elements are processed based on their priority.
- **Max-Priority Queue**: Serves the highest priority element first.
- **Min-Priority Queue**: Serves the lowest priority element first.
- **Applications**: Used in scheduling, graph algorithms, event simulation, and more.
- **Implementation**: Can be implemented using sorted arrays, binary heaps, or other structures based on the requirement.

Implementing a queue using two stacks is a common exercise in data structures that demonstrates the versatility and power of stacks. This technique involves using two stacks to simulate the FIFO behavior of a queue. Below is an explanation and implementation of a queue using two stacks, in both C and C++.

## Queues using two stacks

- **Stack**: A data structure that follows the **Last-In-First-Out (LIFO)** principle.
- **Queue**: A data structure that follows the **First-In-First-Out (FIFO)** principle.
- **Using Two Stacks**: By leveraging the LIFO property of stacks, you can simulate FIFO behavior of a queue.

### Basic Idea

1. **Two Stacks**: Use two stacks, `stack1` and `stack2`.
   - **stack1** is used for enqueue operations (pushing elements).
   - **stack2** is used for dequeue operations (popping elements).

2. **Enqueue Operation**: Always push the element onto `stack1`.

3. **Dequeue Operation**:
   - If `stack2` is empty, transfer all elements from `stack1` to `stack2` (reversing their order), and then pop the top element from `stack2`.
   - If `stack2` is not empty, simply pop the top element from `stack2`.

### Example Implementation

#### C++ Implementation

Here’s how to implement a queue using two stacks in C++:

```cpp
#include <iostream>
#include <stack>

class QueueUsingStacks {
private:
    std::stack<int> stack1, stack2;

    // Helper function to transfer elements from stack1 to stack2
    void transferStack1ToStack2() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    // Function to add an element to the queue
    void enqueue(int data) {
        stack1.push(data);
    }

    // Function to remove and return the front element from the queue
    int dequeue() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                std::cerr << "Queue is empty\n";
                return -1; // Sentinel value indicating empty queue
            }
            transferStack1ToStack2();
        }
        int front = stack2.top();
        stack2.pop();
        return front;
    }

    // Function to display the elements of the queue
    void display() {
        if (stack2.empty() && stack1.empty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        // Transfer elements to stack2 for display purpose
        transferStack1ToStack2();
        std::stack<int> temp = stack2;
        std::cout << "The elements in the queue are: ";
        while (!temp.empty()) {
            std::cout << temp.top() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
};

int main() {
    QueueUsingStacks q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    std::cout << "Dequeued: " << q.dequeue() << std::endl;

    q.display();

    return 0;
}
```

#### C Implementation

Here’s how to implement a queue using two stacks in C:

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Queue using two stacks
struct QueueUsingStacks {
    struct Stack stack1;
    struct Stack stack2;
};

// Initialize stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Push element to stack
void push(struct Stack* stack, int data) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

// Pop element from stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1; // Sentinel value indicating empty stack
    }
    return stack->arr[stack->top--];
}

// Initialize queue
void initQueue(struct QueueUsingStacks* queue) {
    initStack(&queue->stack1);
    initStack(&queue->stack2);
}

// Enqueue element to queue
void enqueue(struct QueueUsingStacks* queue, int data) {
    push(&queue->stack1, data);
}

// Dequeue element from queue
int dequeue(struct QueueUsingStacks* queue) {
    if (queue->stack2.top == -1) {
        while (queue->stack1.top != -1) {
            push(&queue->stack2, pop(&queue->stack1));
        }
    }
    return pop(&queue->stack2);
}

// Display queue elements
void display(struct QueueUsingStacks* queue) {
    if (queue->stack1.top == -1 && queue->stack2.top == -1) {
        printf("Queue is empty\n");
        return;
    }

    // Temporary stack to hold elements for display
    struct Stack tempStack;
    initStack(&tempStack);

    // Transfer elements from stack2 to tempStack to display them
    while (queue->stack2.top != -1) {
        push(&tempStack, pop(&queue->stack2));
    }
    while (tempStack.top != -1) {
        printf("%d ", tempStack.arr[tempStack.top]);
        enqueue(queue, pop(&tempStack));
    }

    // Transfer elements from stack1 to tempStack to display them
    while (queue->stack1.top != -1) {
        push(&tempStack, pop(&queue->stack1));
    }
    while (tempStack.top != -1) {
        printf("%d ", tempStack.arr[tempStack.top]);
        enqueue(queue, pop(&tempStack));
    }
    printf("\n");
}

int main() {
    struct QueueUsingStacks queue;
    initQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);

    display(&queue);

    printf("Dequeued: %d\n", dequeue(&queue));

    display(&queue);

    return 0;
}
```

### Detailed Explanation

1. **Initialization**:
   - **C++**: Constructor initializes two empty stacks.
   - **C**: `initStack` initializes the stack by setting `top` to `-1`, and `initQueue` initializes the queue by initializing both stacks.

2. **Enqueue Operation**:
   - **C++**: Push the element onto `stack1`.
   - **C**: Push the element onto `stack1` using `push`.

3. **Dequeue Operation**:
   - **C++**:
     - If `stack2` is empty, transfer all elements from `stack1` to `stack2` by popping from `stack1` and pushing onto `stack2`.
     - Pop the top element from `stack2` and return it.
   - **C**:
     - If `stack2` is empty, transfer elements from `stack1` to `stack2`.
     - Pop the top element from `stack2` and return it.

4. **Display Operation**:
   - **C++**:
     - Transfer elements from `stack1` to `stack2` for display purposes.
     - Display elements from `stack2` using a temporary stack to hold the elements.
   - **C**:
     - Use a temporary stack to hold elements while displaying and ensure the queue state is restored after displaying.

### Summery

- **Purpose**: To simulate FIFO behavior using two LIFO stacks.
- **Advantages**:
  - Demonstrates how stack operations can be used to implement queue behavior.
  - Efficiently handles enqueue and dequeue operations by dividing tasks between two stacks.
- **Drawbacks**:
  - Additional memory overhead for maintaining two stacks.
  - Potential inefficiency if dequeue operations are frequent and require transferring elements between stacks repeatedly.

This approach is a common example of using stacks to achieve queue-like behavior, showing the flexibility of stack operations and providing a good exercise in understanding stack and queue dynamics.
