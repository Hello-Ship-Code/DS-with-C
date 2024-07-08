# Tree's

In data structures, trees are a hierarchical model used to represent and organize data in a way that allows efficient insertion, deletion, and search operations. Below are key terminologies and their definitions related to trees in data structures:

## **Basic Terminologies**

Here's a comprehensive list of basic tree terminologies, incorporating the provided terms:

1. **Tree**: A data structure consisting of nodes, with a single root node and potentially many levels of additional nodes forming a hierarchical structure. Each node may have zero or more child nodes.

2. **Node**: A fundamental part of a tree structure that stores data and has references to child nodes. Each node contains a value and possibly pointers to child nodes.

3. **Root**: The top node of a tree, from which all nodes branch out. There is only one root in a tree.

4. **Edge**: A connection between two nodes in a tree, representing the parent-child relationship.

5. **Child**: A node that is a direct descendant of another node (its parent).

6. **Parent**: A node that has one or more children.

7. **Leaf**: A node with no children, often found at the bottom of a tree.

8. **Subtree**: A portion of a tree that includes a node and all its descendants.

9. **Height**: The length of the longest path from the root to a leaf. The height of a tree is the height of its root node.

10. **Depth**: The length of the path from the root to a particular node. The depth of the root is zero.

11. **Level**: The depth of a node; nodes at the same depth form a level.

12. **Degree of Node**: The number of children a node has. The degree of a tree is the maximum degree of any node in the tree.

13. **Internal Node**: A node with at least one child; not a leaf. Internal nodes are also called non-leaf nodes.

14. **External Node**: A node with no children; also known as a leaf node.

15. **Forest**: A collection of disjoint trees, meaning multiple trees that are not connected to each other.

16. **Sibling**: Nodes that share the same parent are siblings.

17. **Path**: A sequence of nodes and edges connecting a node with a descendant.

18. **Ancestor**: Any node along the path from the root to a particular node.

19. **Descendant**: Any node that is reachable from a particular node through a sequence of edges.

20. **Binary Tree**: A tree where each node has at most two children, often referred to as the left and right child.

21. **Balanced Tree**: A tree in which the height of the left and right subtrees of every node differs by no more than one.

22. **Complete Tree**: A binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

23. **Full Tree**: A binary tree in which every node other than the leaves has two children.

24. **Perfect Tree**: A binary tree in which all interior nodes have two children and all leaves have the same depth.

### **Specialized Trees**

1. **Binary Search Tree (BST)**: A binary tree in which each node has a value, and every node's left child has a value less than its parent, while the right child's value is greater.

2. **Balanced Tree**: A tree where the height of the two subtrees of any node differ by no more than one.

3. **AVL Tree**: A self-balancing binary search tree where the difference in heights of the left and right subtrees is at most one for all nodes.

4. **Red-Black Tree**: A binary search tree with an extra bit of data per node (its color), which ensures the tree remains balanced during insertions and deletions.

5. **B-Tree**: A self-balancing tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time. Used extensively in databases and file systems.

6. **Heap**: A specialized tree-based data structure that satisfies the heap property; in a max heap, for any given node, the value of the node is greater than or equal to the values of its children.

7. **Trie**: A tree-like data structure used for storing a dynamic set of strings, where the keys are usually strings.

8. **Suffix Tree**: A compressed trie of all the suffixes of a given text, useful for various string operations.

### **Traversal Methods**

1. **In-order Traversal**: Visit the left subtree, the root, and the right subtree. (Used in binary search trees to get sorted order.)

2. **Pre-order Traversal**: Visit the root, the left subtree, and the right subtree.

3. **Post-order Traversal**: Visit the left subtree, the right subtree, and then the root.

4. **Level-order Traversal**: Visit nodes level by level from the root downwards, also known as breadth-first traversal.

These terminologies and concepts are fundamental for understanding and working with trees in data structures.

### **Tree Representation and Explanation**

A **tree** is a hierarchical data structure consisting of nodes connected by edges. It starts with a root node and branches out to additional nodes, forming a parent-child relationship. Here's a representation of a simple binary tree and its explanation:

#### **Graphical Representation**

```cpp
        A
       / \
      B   C
     / \   \
    D   E   F
```

### **Explanation**

1. **Nodes**:
   - Each item in the tree is called a node.
   - In this tree, **A**, **B**, **C**, **D**, **E**, and **F** are nodes.

2. **Root**:
   - The root is the topmost node in the tree.
   - **A** is the root node here.

3. **Edges**:
   - An edge connects a parent node to a child node.
   - For example, edges connect **A** to **B**, **A** to **C**, etc.

4. **Parent and Child**:
   - A parent node has one or more child nodes directly connected to it.
   - **A** is the parent of **B** and **C**.
   - **B** is the parent of **D** and **E**.

5. **Leaf**:
   - A leaf node is a node with no children.
   - **D**, **E**, and **F** are leaf nodes.

6. **Subtree**:
   - A subtree is a portion of the tree consisting of a node and all its descendants.
   - For instance, **B** and all its children (**D**, **E**) form a subtree.

7. **Levels**:
   - The level of a node is the number of edges from the root to the node.
   - **A** is at level 0, **B** and **C** are at level 1, and **D**, **E**, and **F** are at level 2.

8. **Depth**:
   - The depth of a node is the distance from the root to that node.
   - **B** has a depth of 1, **D** has a depth of 2.

9. **Height**:
   - The height of a tree is the number of edges on the longest downward path from the root to a leaf.
   - This tree's height is 2.

### **Summary**

In this simple binary tree:

- **A** is the root.
- **B** and **C** are children of **A**.
- **D** and **E** are children of **B**.
- **F** is a child of **C**.
- **D**, **E**, and **F** are leaves.
- The height of the tree is 2.

Each node except the root has exactly one parent, and each node may have zero or more children.

### Definitions and Representations for Number of Binary Trees and Catalan Numbers

#### Number of Binary Trees

**Definition**: The number of distinct binary trees that can be formed with `n` nodes is given by the Catalan number. For `n` nodes, the count is represented by the `n`-th Catalan number \( C_n \).

Here are the corrected formulas for markdown format:

Sure, here is the markdown with the formulas formatted using `$$` for display mode:

### Catalan Number

**Definition**: The Catalan number is a sequence of natural numbers that appears in various counting problems, often involving recursively defined structures. It represents the number of ways to correctly match parentheses, the number of rooted binary trees, the number of paths along the edges of a grid that do not pass above the diagonal, etc.

**Formula**:
$C_n = \frac{1}{n+1} \binom{2n}{n} = \frac{(2n)!}{(n+1)!n!}$
Where $\binom{2n}{n}$ is a binomial coefficient.

**Recursive Formula**:
$C_0 = 1$
$C_{n+1} = \sum_{i=0}^{n} C_i C_{n-i}$

**Representation**:

- **Catalan Numbers**:

  $C_0 = 1, \; C_1 = 1, \; C_2 = 2, \; C_3 = 5, \; C_4 = 14, \; C_5 = 42, \; C_6 = 132, \; \ldots$
  
- **Visual Representation**:
  - **Parentheses Matching**: For $n = 3$, the 5 valid combinations are:

    ```text
    ((())), (()()), (())(), ()(()), ()()()
    ```

  - **Binary Trees**: For $n = 3$ nodes, the 5 binary trees can be visualized as:

    ```text
      Tree 1         Tree 2       Tree 3        Tree 4         Tree 5
         1             1            1             2              3
          \             \            \           / \            /
           2             3            2         1   3          1
            \           /              \                     / \
             3         2                3                   2   3
    ```

  - **Grid Paths**: For $n = 2$, the number of paths from the bottom-left to the top-right of a 2x2 grid without crossing above the diagonal is 2:

    ```text
     .__.
    |  /|
    |/ _|
    ```

### Applications of Catalan Numbers

1. **Binary Trees**: Counting the number of distinct binary trees with $n$ nodes.
2. **Parentheses Combinations**: Number of ways to correctly match $n$ pairs of parentheses.
3. **Grid Paths**: Number of paths along the edges of a grid that do not pass above the diagonal.
4. **Polygon Triangulation**: Number of ways to triangulate a convex polygon with $n+2$ sides.

### Examples and Calculation

**Example Calculation for $C_3$**:

- Using the formula:
  $C_3 = \frac{1}{3+1} \binom{6}{3} = \frac{1}{4} \times 20 = 5$

- Using the recursive definition:
  $C_0 = 1$
  $C_1 = C_0 \cdot C_0 = 1$
  $C_2 = C_0 \cdot C_1 + C_1 \cdot C_0 = 1 + 1 = 2$
  $C_3 = C_0 \cdot C_2 + C_1 \cdot C_1 + C_2 \cdot C_0 = 1 \cdot 2 + 1 \cdot 1 + 2 \cdot 1 = 2 + 1 + 2 = 5$

### Summary

- The number of binary trees for $n$ nodes corresponds to the $n$-th Catalan number.
- Catalan numbers have a wide range of applications in combinatorial mathematics and computer science.

## Steps to Calculate the Number of Labeled Binary Trees

To determine the number of distinct binary trees that can be generated using labeled nodes, we need to consider both the number of binary tree structures possible with $( n )$ unlabeled nodes and the permutations of the labeled nodes.

1. **Count the Number of Unlabeled Binary Trees**: The number of unlabeled binary trees with $( n )$ nodes is given by the $( n )-th$ Catalan number, $( C_n )$. The formula for the \( n \)-th Catalan number is: $C_n = \frac{1}{n+1} \binom{2n}{n} = \frac{(2n)!}{(n+1)!n!}$

2. **Count the Number of Permutations of Labeled Nodes**:
   For $( n )$ labeled nodes, the number of permutations is \( n! \).

3. **Combine Both Counts**:
   The total number of distinct labeled binary trees is the product of the number of unlabeled binary trees and the number of permutations of the labeled nodes:

Number of labeled binary trees = $C_n \times n!$

### Example for $( n = 3)$

1. **Number of Unlabeled Binary Trees**:

$C_3 = \frac{1}{3+1} \binom{6}{3} = \frac{1}{4} \cdot 20 = 5$

1. **Number of Permutations of 3 Labeled Nodes**:

$3! = 6$

1. **Total Number of Labeled Binary Trees**

Number of labeled binary trees = $C_3 \times 3! = 5 \times 6 = 30$

### General Formula

For $( n )$ labeled nodes, the number of distinct labeled binary trees is:

Number of labeled binary trees = $\frac{2nC_n}{n+1} \times n!$

Simplifying, we get:

Number of labeled binary trees = $\frac{(2n)!}{(n+1)!}$

This formula allows you to calculate the number of distinct labeled binary trees for any given $\( n \)$ labeled nodes.

---

## Height of binary tree

- if we are given Nodes of binary tree. We can determine minimum and maximum  height. We can generate a formulae.

$\log_2 (n+1) - 1 \leq height \leq n -1$

## Number of nodes in a binary tree

- if we are given height of binary tree. We can determine minimum and maximum  nodes. We can generate a formulae.

$h + 1 \leq n \leq 2^{h+1} - 1$

### Strict (Full) Binary Tree

A strict binary tree, also known as a **full binary tree** or a **proper binary tree**, is a type of binary tree in which every node has either 0 or 2 children. This means that no node in a strict binary tree has only one child.

In a strict binary tree:

- If there are $( n )$ nodes in total, the number of leaves (external nodes) $( E )$ is: $E = \frac{n + 1}{2}$
- The number of internal nodes $( I )$ is: $I = \frac{n - 1}{2}$
- If there are $( I )$ internal nodes, there are $( I + 1 )$ external nodes (leaves).

## Height of strict binary tree

- if we are given Nodes of binary tree. We can determine minimum and maximum  height. We can generate a formulae.

$\log_2 (n+1) - 1 \leq height \leq \frac{n -1}{2}$

## Number of nodes in a strict binary tree

- if we are given height of binary tree. We can determine minimum and maximum  nodes. We can generate a formulae.

$2^{h+1} \leq n \leq 2^{h+1} - 1$

## internal vs external node

$ E = ( I + 1)$

### N-ary Trees

An **N-ary tree** is a tree data structure in which each node has at most \( N \) children. In other words, each node can have zero or more children, but no more than \( N \) children. N-ary trees generalize the concept of binary trees, which are a specific case of N-ary trees with \( N = 2 \).

### Strict N-ary Trees

A **strict N-ary tree**, also known as a **full N-ary tree**, is an N-ary tree in which every internal node has exactly \( N \) children or no children at all. This means that every non-leaf node must have \( N \) children.

### Key Properties of N-ary and Strict N-ary Trees

1. **Number of Nodes**:
   - In a general N-ary tree, the number of nodes can vary widely based on the structure and completeness of the tree.
   - In a strict N-ary tree, if the tree has \( I \) internal nodes, the number of total nodes \( T \) is:
     \[
     T = (N - 1) \times I + 1
     \]

2. **Number of Leaves (External Nodes)**:
   - For a strict N-ary tree, the number of leaves \( L \) can be determined by the number of internal nodes \( I \):
     \[
     L = (N - 1) \times I + 1
     \]

3. **Height of the Tree**:
   - The height \( h \) of an N-ary tree is the number of edges on the longest path from the root to a leaf. For a strict N-ary tree, the height depends on the number of levels filled completely.

4. **Example of a Strict N-ary Tree**:
   - For \( N = 3 \) (a ternary tree):
     - Each internal node has exactly 3 children.
     - If the tree has 2 levels of internal nodes (excluding the root), it will have \( 1 + 3 + 9 = 13 \) nodes in total.

## height vs Nodes

## Height of strict n - binary tree

- if we are given Nodes of binary tree. We can determine minimum and maximum  height. We can generate a formulae.

$\log_m [n(m-1)+ 1] - 1 \leq height \leq \frac{n - 1}{m}$  
m = n - binary tree  
n = Total number of nodes

## Number of nodes in a strict n - binary tree

- if we are given height of binary tree. We can determine minimum and maximum  nodes. We can generate a formulae.

$mh+ 1 \leq nodes \leq \frac{n^{h+1} - 1}{n - 1}$

## internal node vs external node

$E = (n - 1)I +1$

## Array representation of Binary tree

```c
        a
       / \
      b   c
     / \ / \
    d  e f  g

```

element  = $i$  
left child = $2 * i$  
right child = $2 * i + 1$  
parent = $\left\lfloor \frac{i-1}{2} \right\rfloor$

## linked representation of binary tree

```c
        a
       / \
      b   c
     / \ / \
    d  e f  g

```

Node = $[Left-child, Node, Right-Child]$

```c
struct Node{
   struct Node *leftchild;
   int data;
   struct Node *rightchild;
};
```

### Full Binary Tree

A **full binary tree** (also known as a **strict binary tree** or **proper binary tree**) is a type of binary tree in which every node other than the leaves has exactly two children.

#### Diagram of a Full Binary Tree

```c
        a
       / \
      b   c
     / \ / \
    d  e f  g
```

In this tree:

- Every node has either 0 or 2 children.
- All internal nodes have exactly two children.

### Complete Binary Tree

A **complete binary tree** is a type of binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

#### Diagram of a Complete Binary Tree

```c
        a
       / \
      b   c
     / \ / 
    d  e f  
```

In this tree:

- All levels except the last are completely filled.
- Nodes in the last level are as far left as possible.

## Strict (Full) Binary Tree vs. Complete Binary Tree

### Strict (Full) Binary Trees

- **Definition**: A strict or full binary tree is a binary tree in which every node has either 0 or 2 children.
- **Characteristics**:
  - All internal nodes have exactly two children.
  - Leaves (external nodes) are all at the same level or one level above.

Example:

```c
        a
       / \
      b   c
     / \ / \
    d  e f  g
```

- **Properties**:
  - Number of internal nodes \( I \) and external nodes (leaves) \( E \):
    \[
    E = I + 1
    \]
  - Total number of nodes \( T \):
    \[
    T = 2I + 1
    \]

### Complete Binary Trees

- **Definition**: A complete binary tree is a binary tree in which all levels, except possibly the last, are completely filled, and all nodes are as far left as possible.
- **Characteristics**:
  - All levels are fully filled except possibly the last level.
  - Nodes in the last level are as far left as possible.

Example:

```c
        a
       / \
      b   c
     / \ / 
    d  e f  
```

- **Properties**:
  - Height \( h \) of a complete binary tree with \( n \) nodes:
    \[
    h = \lfloor \log_2 n \rfloor
    \]
  - Number of nodes at the last level can vary, but they are all left-aligned.

### Tree Traversal

Tree traversal refers to the process of visiting (checking or updating) each node in a tree data structure, exactly once. There are several methods of tree traversal, each with different properties and use cases. The most common tree traversal methods are:

1. **Pre-order Traversal**
2. **In-order Traversal**
3. **Post-order Traversal**
4. **Level-order Traversal**

#### 1. Pre-order Traversal

In pre-order traversal, the nodes are recursively visited in this order:

- Visit the root node.
- Traverse the left subtree.
- Traverse the right subtree.

Example:

For the tree:

```c
        a
       / \
      b   c
     / \ / \
    d  e f  g
```

Pre-order traversal: `a, b, d, e, c, f, g`

#### 2. In-order Traversal

In in-order traversal, the nodes are recursively visited in this order:

- Traverse the left subtree.
- Visit the root node.
- Traverse the right subtree.

Example:

For the tree:

```c
        a
       / \
      b   c
     / \ / \
    d  e f  g
```

In-order traversal: `d, b, e, a, f, c, g`

#### 3. Post-order Traversal

In post-order traversal, the nodes are recursively visited in this order

- Traverse the left subtree.
- Traverse the right subtree.
- Visit the root node.

Example:

For the tree:

```c
        a
       / \
      b   c
     / \ / \
    d  e f  g
```

Post-order traversal: `d, e, b, f, g, c, a`

#### 4. Level-order Traversal

In level-order traversal, also known as breadth-first traversal, the nodes are visited level by level from left to right. This is typically implemented using a queue.

Example:

For the tree:

```c
        a
       / \
      b   c
     / \ / \
    d  e f  g
```

Level-order traversal: `a, b, c, d, e, f, g`

```cpp
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

// Define the structure of a queue
struct Queue {
    int size;
    int front;
    int rear;
    struct Node **Q;
};

// Function to create and initialize the queue
void create(struct Queue *q, int size) {
    q->size = size;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
    if (q->Q == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    q->front = q->rear = 0;
}

// Function to add an element to the queue
void enqueue(struct Queue *q, struct Node *data) {
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is full\n");
    else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = data;
    }
}

// Function to remove an element from the queue
struct Node *dequeue(struct Queue *q) {
    struct Node *x = NULL;
    if (q->rear == q->front)
        printf("Queue is empty\n");
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

// Function to check if the queue is empty
int isEmpty(struct Queue q) {
    return q.front == q.rear;
}

// Function to create a binary tree
void T_create() {
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter the Root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q)) {
        p = dequeue(&q);
        printf("Enter the left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("Enter the right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

// Function for preorder traversal of the tree
void preorder(struct Node *p) {
    if (p) {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

// Function for inorder traversal of the tree
void inorder(struct Node *p) {
    if (p) {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

// Function for postorder traversal of the tree
void postorder(struct Node *p) {
    if (p) {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

int main() {
    T_create();
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}

```

## In Cpp

```cpp
#include <iostream>
#include <queue>
using namespace std;

// Define the structure of a tree node
struct Node {
    Node *lchild;
    int data;
    Node *rchild;
};

// Define the root globally
Node* root = nullptr;

// Function to create a binary tree
void T_create() {
    Node *p, *t;
    int x;
    queue<Node*> q;

    cout << "Enter the Root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.push(root);

    while (!q.empty()) {
        p = q.front();
        q.pop();
        cout << "Enter the left child of " << p->data << ": ";
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.push(t);
        }

        cout << "Enter the right child of " << p->data << ": ";
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.push(t);
        }
    }
}

// Function for preorder traversal of the tree
void preorder(Node* p) {
    if (p) {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

// Function for inorder traversal of the tree
void inorder(Node* p) {
    if (p) {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

// Function for postorder traversal of the tree
void postorder(Node* p) {
    if (p) {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}

int main() {
    T_create();
    cout << "Preorder traversal: ";
    preorder(root);
    cout << "\n";

    cout << "Inorder traversal: ";
    inorder(root);
    cout << "\n";

    cout << "Postorder traversal: ";
    postorder(root);
    cout << "\n";

    return 0;
}
```

## Using Iterative  

```cpp
#include <iostream>
using namespace std;

// Define the structure of a tree node
struct Node {
    Node *lchild;
    int data;
    Node *rchild;
};

// Define the root globally
Node* root = nullptr;

// Define the structure of a queue node
struct QueueNode {
    Node* treeNode;
    QueueNode* next;
};

// Define the queue class
class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(Node* node) {
        QueueNode* temp = new QueueNode;
        temp->treeNode = node;
        temp->next = nullptr;
        if (front == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    Node* dequeue() {
        if (front == nullptr) {
            return nullptr;
        }
        Node* node = front->treeNode;
        QueueNode* temp = front;
        front = front->next;
        delete temp;
        return node;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

// Define the stack class
class Stack {
private:
    struct StackNode {
        Node* treeNode;
        StackNode* next;
    };
    StackNode* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(Node* node) {
        StackNode* temp = new StackNode;
        temp->treeNode = node;
        temp->next = top;
        top = temp;
    }

    Node* pop() {
        if (top == nullptr) {
            return nullptr;
        }
        Node* node = top->treeNode;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return node;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

// Function to create a binary tree
void T_create() {
    Node *p, *t;
    int x;
    Queue q;

    cout << "Enter the Root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.enqueue(root);

    while (!q.isEmpty()) {
        p = q.dequeue();
        cout << "Enter the left child of " << p->data << ": ";
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }

        cout << "Enter the right child of " << p->data << ": ";
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

// Iterative preorder traversal
void iterativePreorder(Node* root) {
    if (root == nullptr) return;

    Stack stk;
    stk.push(root);

    while (!stk.isEmpty()) {
        Node* node = stk.pop();
        cout << node->data << " ";

        if (node->rchild) {
            stk.push(node->rchild);
        }
        if (node->lchild) {
            stk.push(node->lchild);
        }
    }
}

// Iterative inorder traversal
void iterativeInorder(Node* root) {
    Stack stk;
    Node* current = root;

    while (current != nullptr || !stk.isEmpty()) {
        while (current != nullptr) {
            stk.push(current);
            current = current->lchild;
        }

        current = stk.pop();
        cout << current->data << " ";

        current = current->rchild;
    }
}

// Iterative postorder traversal
void iterativePostorder(Node* root) {
    if (root == nullptr) return;

    Stack stk1, stk2;
    stk1.push(root);

    while (!stk1.isEmpty()) {
        Node* node = stk1.pop();
        stk2.push(node);

        if (node->lchild) {
            stk1.push(node->lchild);
        }
        if (node->rchild) {
            stk1.push(node->rchild);
        }
    }

    while (!stk2.isEmpty()) {
        Node* node = stk2.pop();
        cout << node->data << " ";
    }
}

void level_order(struct Node *root)
{
   struct Queue q;
   create(&q,100);

   printf("%d ",root->data);
   enqueue(&q,root);

   while(!isEmpty(q))
   {
      root = dequeue(q);
      if(root->lchild)
      {
         printf("%d ",root->lchild->data);
         enqueue(&q,root->lchild);
      }
      if(root->rchild)
      {
         printf("%d ",root->rchild->data);
         enqueue(&q,root->rchild);
      }
   }
}


int count(struct Node *root)
{
   if(root)
      return count(root->lchild)+count(root->rchild)+1;
   return 0;
}

int height(struct Node *root)
{
   int x,y=0;
   if(root == NULL)
      return 0;
   x = height(root->lchild);
   y = height(root->rchild);
   if(x > y )
      return x + 1;
   else
      return y + 1;
}

// Function to count nodes with a specific degree
int countDegree(struct Node *root, int degree) {
    if (root == NULL)
        return 0;

    int count = 0;
    if (degree == 0 && root->lchild == NULL && root->rchild == NULL)
        count = 1;
    else if (degree == 1 && ((root->lchild != NULL && root->rchild == NULL) || (root->lchild == NULL && root->rchild != NULL)))
        count = 1;
    else if (degree == 2 && root->lchild != NULL && root->rchild != NULL)
        count = 1;

    return count + countDegree(root->lchild, degree) + countDegree(root->rchild, degree);
}


int main() {
    T_create();

    cout << "Iterative Preorder traversal: ";
    iterativePreorder(root);
    cout << "\n";

    cout << "Iterative Inorder traversal: ";
    iterativeInorder(root);
    cout << "\n";

    cout << "Iterative Postorder traversal: ";
    iterativePostorder(root);
    cout << "\n";

    return 0;
}

```

## Binary search Trees

A Binary Search Tree (BST) is a data structure that facilitates fast lookup, addition, and deletion of items. Each node in a BST has at most two children, referred to as the left child and the right child. For each node:

- The left subtree contains only nodes with keys less than the node’s key.
- The right subtree contains only nodes with keys greater than the node’s key.

Here's how we can insert and delete nodes in a BST, both recursively and iteratively, and perform a binary search with a key. The code will be provided in both C and C++ with comments.

### C Program

```c
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int key;
    struct Node* left, *right;
};

// Create a new node
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Recursive insert function
struct Node* insertRecursive(struct Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insertRecursive(node->left, key);
    else if (key > node->key)
        node->right = insertRecursive(node->right, key);

    // return the (unchanged) node pointer
    return node;
}

// Iterative insert function
struct Node* insertIterative(struct Node* node, int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;

    struct Node* parent = NULL, *current = node;

    // Find the parent node
    while (current != NULL) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    // If the tree is empty, new node becomes the root
    if (parent == NULL)
        return newNode;

    // Otherwise, attach new node to the parent node
    if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    return node;
}

// Recursive delete function
struct Node* deleteNodeRecursive(struct Node* root, int key) {
    if (root == NULL) return root;

    // Recur down the tree
    if (key < root->key)
        root->left = deleteNodeRecursive(root->left, key);
    else if (key > root->key)
        root->right = deleteNodeRecursive(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor
        struct Node* temp = minValueNode(root->right);

        root->key = temp->key;
        root->right = deleteNodeRecursive(root->right, temp->key);
    }
    return root;
}

// Iterative delete function
struct Node* deleteNodeIterative(struct Node* root, int key) {
    struct Node* parent = NULL;
    struct Node* current = root;

    while (current != NULL && current->key != key) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL) return root;

    if (current->left == NULL || current->right == NULL) {
        struct Node* newCurrent;

        if (current->left == NULL)
            newCurrent = current->right;
        else
            newCurrent = current->left;

        if (parent == NULL)
            return newCurrent;

        if (current == parent->left)
            parent->left = newCurrent;
        else
            parent->right = newCurrent;

        free(current);
    } else {
        struct Node* parentOfMin = NULL;
        struct Node* min = current->right;

        while (min->left != NULL) {
            parentOfMin = min;
            min = min->left;
        }

        if (parentOfMin != NULL)
            parentOfMin->left = min->right;
        else
            current->right = min->right;

        current->key = min->key;
        free(min);
    }

    return root;
}

// Find the node with the minimum key value
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Search for a key in the BST
struct Node* search(struct Node* root, int key) {
    while (root != NULL && root->key != key) {
        if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

// Inorder traversal of the BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insertRecursive(root, 50);
    root = insertRecursive(root, 30);
    root = insertRecursive(root, 20);
    root = insertRecursive(root, 40);
    root = insertRecursive(root, 70);
    root = insertRecursive(root, 60);
    root = insertRecursive(root, 80);

    printf("Inorder traversal: ");
    inorder(root);

    printf("\nDelete 20\n");
    root = deleteNodeRecursive(root, 20);
    printf("Inorder traversal: ");
    inorder(root);

    printf("\nDelete 30\n");
    root = deleteNodeIterative(root, 30);
    printf("Inorder traversal: ");
    inorder(root);

    printf("\nDelete 50\n");
    root = deleteNodeRecursive(root, 50);
    printf("Inorder traversal: ");
    inorder(root);

    struct Node* searchNode = search(root, 60);
    if (searchNode != NULL)
        printf("\nNode with key 60 found\n");
    else
        printf("\nNode with key 60 not found\n");

    return 0;
}
```

### C++ Program

```cpp
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int key;
    Node* left, *right;
};

// Create a new node
Node* newNode(int item) {
    Node* temp = new Node();
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Recursive insert function
Node* insertRecursive(Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insertRecursive(node->left, key);
    else if (key > node->key)
        node->right = insertRecursive(node->right, key);

    // return the (unchanged) node pointer
    return node;
}

// Iterative insert function
Node* insertIterative(Node* node, int key) {
    Node* newNode = new struct Node();
    newNode->key = key;
    newNode->left = newNode->right = NULL;

    Node* parent = NULL, *current = node;

    // Find the parent node
    while (current != NULL) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    // If the tree is empty, new node becomes the root
    if (parent == NULL)
        return newNode;

    // Otherwise, attach new node to the parent node
    if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    return node;
}

// Recursive delete function
Node* deleteNodeRecursive(Node* root, int key) {
    if (root == NULL) return root;

    // Recur down the tree
    if (key < root->key)
        root->left = deleteNodeRecursive(root->left, key);
    else if (key > root->key)
        root->right = deleteNodeRecursive(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor
        Node* temp = minValueNode(root->right);

        root->key = temp->key;
        root->right = deleteNodeRecursive(root->right, temp->key);
    }
    return root;
}

// Iterative delete function
Node* deleteNodeIterative(Node* root, int key) {
    Node* parent = NULL;
    Node* current =

 root;

    while (current != NULL && current->key != key) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL) return root;

    if (current->left == NULL || current->right == NULL) {
        Node* newCurrent;

        if (current->left == NULL)
            newCurrent = current->right;
        else
            newCurrent = current->left;

        if (parent == NULL)
            return newCurrent;

        if (current == parent->left)
            parent->left = newCurrent;
        else
            parent->right = newCurrent;

        delete current;
    } else {
        Node* parentOfMin = NULL;
        Node* min = current->right;

        while (min->left != NULL) {
            parentOfMin = min;
            min = min->left;
        }

        if (parentOfMin != NULL)
            parentOfMin->left = min->right;
        else
            current->right = min->right;

        current->key = min->key;
        delete min;
    }

    return root;
}

// Find the node with the minimum key value
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Search for a key in the BST
Node* search(Node* root, int key) {
    while (root != NULL && root->key != key) {
        if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

// Inorder traversal of the BST
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insertRecursive(root, 50);
    root = insertRecursive(root, 30);
    root = insertRecursive(root, 20);
    root = insertRecursive(root, 40);
    root = insertRecursive(root, 70);
    root = insertRecursive(root, 60);
    root = insertRecursive(root, 80);

    cout << "Inorder traversal: ";
    inorder(root);

    cout << "\nDelete 20\n";
    root = deleteNodeRecursive(root, 20);
    cout << "Inorder traversal: ";
    inorder(root);

    cout << "\nDelete 30\n";
    root = deleteNodeIterative(root, 30);
    cout << "Inorder traversal: ";
    inorder(root);

    cout << "\nDelete 50\n";
    root = deleteNodeRecursive(root, 50);
    cout << "Inorder traversal: ";
    inorder(root);

    Node* searchNode = search(root, 60);
    if (searchNode != NULL)
        cout << "\nNode with key 60 found\n";
    else
        cout << "\nNode with key 60 not found\n";

    return 0;
}
```
